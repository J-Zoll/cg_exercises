#include <cglib/rt/object.h>
#include <cglib/rt/raytracing_context.h>

Object::Object() :
	material(new Material()),
	texture_mapping(new ZeroMapping())
{
	material->k_d = std::shared_ptr<ConstTexture>(new ConstTexture(glm::vec3(0.18f)));
}

bool Object::
intersect(Ray const& ray, Intersection* isect) const
{
	// transform ray in object space
	const Ray ray_local = transform_ray(ray, transform_world_to_object);
	Intersection isect_local;
	if (geo->intersect(ray_local, &isect_local)) {
		*isect = transform_intersection(isect_local, transform_object_to_world, transform_object_to_world_normal);
		isect->t = glm::length(ray.origin-isect->position);
		return true;
	}
	return false;
}

void Object::
compute_shading_info(Intersection* isect)
{
	cg_assert(isect);
	if (RaytracingContext::get_active()->params.transform_objects) 
	{
		Intersection isect_local = transform_intersection(*isect, transform_world_to_object, transform_world_to_object_normal);
		texture_mapping->compute_tangent_space(&isect_local);

		isect_local.uv = get_uv(isect_local);
		isect_local.material.evaluate(*material, isect_local);
		isect_local.shading_normal = transform_direction_to_object_space(isect_local.material.normal,
			isect_local.normal, isect_local.tangent, isect_local.bitangent);

		*isect = transform_intersection(isect_local, transform_object_to_world, transform_object_to_world_normal);
	}
	else
	{
		texture_mapping->compute_tangent_space(isect);
		isect->uv = get_uv(*isect);
		isect->material.evaluate(*material, *isect);
		isect->shading_normal = transform_direction_to_object_space(isect->material.normal,
			isect->normal, isect->tangent, isect->bitangent);
	}
}

void Object::
compute_shading_info(const Ray rays[4], Intersection* isect)
{
	cg_assert(isect);
	if (RaytracingContext::get_active()->params.transform_objects) 
	{
		Intersection isect_local = transform_intersection(*isect, transform_world_to_object, transform_world_to_object_normal);
		texture_mapping->compute_tangent_space(&isect_local);
		isect_local.uv = get_uv(isect_local);

		Ray rays_local[4];
		for (int i = 0; i < 4; ++i) {
			rays_local[i] = transform_ray(rays[i], transform_world_to_object);
		}
		isect_local.dudv = compute_uv_aabb_size(rays_local, isect_local);
		isect_local.material.evaluate(*material, isect_local);
		isect_local.shading_normal = transform_direction_to_object_space(isect_local.material.normal,
			isect_local.normal, isect_local.tangent, isect_local.bitangent);

		*isect = transform_intersection(isect_local, transform_object_to_world, transform_object_to_world_normal);
	}
	else 
	{
		texture_mapping->compute_tangent_space(isect);
		isect->uv = get_uv(*isect);
		isect->dudv = compute_uv_aabb_size(rays, *isect);
		isect->material.evaluate(*material, *isect);
		isect->shading_normal = transform_direction_to_object_space(isect->material.normal,
			isect->normal, isect->tangent, isect->bitangent);
	}
}

void Object::
get_intersection_uvs(glm::vec3 const positions[4], Intersection const& isect, glm::vec2 uvs[4])
{
	for (int i = 0; i < 4; ++i)
	{
		Intersection isect_corner = isect;
		isect_corner.position = positions[i];
		uvs[i] = get_uv(isect_corner);
	}

	for (int k = 0; k < 2; ++k)
	{
		glm::vec2 duvs[2];
		for (int j = 0; j < 2; ++j) {
			duvs[j] = uvs[2*k+j]-isect.uv;
		}
		if (glm::dot(duvs[0], duvs[1]) > 0) {
			int m = glm::length(duvs[0]) < glm::length(duvs[1]) ? 0 : 1;
			uvs[2*k+0] = isect.uv + duvs[m];
			uvs[2*k+1] = isect.uv - duvs[m];
		}
	}
}

// compute texel footprint in uv-space
glm::vec2 Object::
compute_uv_aabb_size(const Ray rays[4], Intersection const& isect)
{
	// TODO: compute intersection positions 
	glm::vec3 intersection_positions[4] = {
		isect.position, isect.position, isect.position, isect.position
	};

	for (int i = 0; i < 4; ++i) {
		float t;
		if (intersect_plane(rays[i].origin, rays[i].direction, isect.position, isect.normal, &t)) {
			intersection_positions[i] = rays[i].origin + t * rays[i].direction;
		}
	}

	// compute uv coordinates from intersection positions
	glm::vec2 intersection_uvs[4];
	get_intersection_uvs(intersection_positions, isect, intersection_uvs);
		
	// TODO: compute dudv = length of sides of AABB in uv space
	glm::vec2 min_uv = isect.uv;
	glm::vec2 max_uv = isect.uv;
	for (int i = 0; i < 4; ++i) {
		min_uv = glm::min(min_uv, intersection_uvs[i]);
		max_uv = glm::max(max_uv, intersection_uvs[i]);
	}
	cg_assert(glm::all(glm::lessThanEqual(min_uv, max_uv)));

	return max_uv-min_uv;
}

glm::vec2 Object::
get_uv(Intersection const& isect)
{
	return texture_mapping->get_uv(isect);
}

void Object::
set_transform_object_to_world(glm::mat4 const& T)
{
	transform_object_to_world = T;

	transform_world_to_object = glm::inverse(T);
	transform_object_to_world_normal = glm::transpose(transform_world_to_object);
	transform_world_to_object_normal = glm::transpose(transform_object_to_world);
}

std::unique_ptr<Object> create_sphere(
		glm::vec3 const& center,
		float radius,
		glm::vec2 const& scale_uv)
{
	std::unique_ptr<Object> object(new Object());
	object->geo = std::make_shared<Sphere>(center, radius);
	object->texture_mapping = std::make_shared<SphericalMapping>(center, scale_uv);
	return object;
}

std::unique_ptr<Object> create_plane(
		glm::vec3 const& center,
		glm::vec3 const& normal,
		glm::vec3 const& tangent,
		glm::vec3 const& bitangent,
		glm::vec2 const& scale_uv)
{
	cg_assert(glm::distance(normal,glm::normalize(glm::cross(
					glm::normalize(tangent),
					glm::normalize(bitangent)))) < 1e-4);

	std::unique_ptr<Object> object(new Object());
	object->geo = std::make_shared<Plane>(center, normal);
	object->texture_mapping = std::make_shared<PlanarMapping>(
			center, normal, tangent, bitangent, scale_uv);
	return object;
}

std::unique_ptr<Object> create_plane(
		glm::vec3 const& center,
		glm::vec3 const& normal)
{
	glm::vec3 bitangent = glm::vec3(0.0f);
	if (std::fabs(normal.x) > std::fabs(normal.z)) { 
		bitangent = glm::vec3(-normal.y, normal.x, 0.f);
	} else {
		bitangent = glm::vec3(0.f, -normal.z, normal.y);
	}
	
	bitangent = glm::normalize(bitangent);
	glm::vec3 const tangent = glm::cross(bitangent, normal);
	return create_plane(center, normal, tangent, bitangent);
}

std::unique_ptr<Object> create_plane(
		glm::vec3 const& center,
		glm::vec3 const& normal,
		glm::vec3 const& tangent,
		glm::vec2 const& scale_uv)
{
	const glm::vec3 bitangent = glm::normalize(glm::cross(glm::normalize(normal), glm::normalize(tangent)));
	return create_plane(center, glm::normalize(normal), glm::normalize(tangent), bitangent, scale_uv);
}

std::unique_ptr<Object> create_quad(
		glm::vec3 const& center,
		glm::vec3 const& normal,
		glm::vec3 const& e0,
		glm::vec3 const& e1,
		glm::vec2 const& scale_uv)
{
	cg_assert(glm::distance(normal, glm::normalize(glm::cross(
					glm::normalize(e0),
					glm::normalize(e1)))) < 1e-4);

	std::unique_ptr<Object> object(new Object());
	object->geo = std::make_shared<Quad>(center, e0, e1);
	object->texture_mapping = std::make_shared<PlanarMapping>(
			center-0.5f*e0-0.5f*e1, normal, e0, e1, scale_uv);
	return object;
}
