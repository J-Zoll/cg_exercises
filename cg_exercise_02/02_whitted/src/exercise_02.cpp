#include <cglib/rt/renderer.h>
#include <cglib/rt/intersection_tests.h>
#include <cglib/rt/raytracing_context.h>
#include <cglib/rt/intersection.h>
#include <cglib/rt/ray.h>
#include <cglib/rt/scene.h>
#include <cglib/rt/light.h>
#include <cglib/rt/material.h>
#include <cglib/rt/render_data.h>

/*
 * TODO: implement a ray-sphere intersection test here.
 * The sphere is defined by its center and radius.
 *
 * Return true, if (and only if) the ray intersects the sphere.
 * In this case, also fill the parameter t with the distance such that
 *    ray_origin + t * ray_direction
 * is the intersection point.
 */
bool intersect_sphere(
    glm::vec3 const& ray_origin,    // starting point of the ray
    glm::vec3 const& ray_direction, // direction of the ray
    glm::vec3 const& center,        // position of the sphere
    float radius,                   // radius of the sphere
    float* t)                       // output parameter which contains distance to the hit point
{
    cg_assert(t);
	cg_assert(std::fabs(glm::length(ray_direction) - 1.f) < EPSILON);

    float a = glm::dot(ray_direction, ray_direction);
    float b = 2.f * glm::dot(ray_direction, ray_origin - center);
    float c = glm::dot(ray_origin - center, ray_origin - center) - radius * radius;


    float discriminant = b * b - 4 * a * c;

    // negative discriminant => no intersection
    if (discriminant < 0) {
        return false;
    }
    
    // discriminant equals 0 => one intersection
    if (discriminant == 0) {
        *t = -b / (2 * a);
        return true;
    }

    // positive discriminant => two intersections
    float t1 = (-b + sqrt(discriminant)) / (2 * a);
    float t2 = (-b - sqrt(discriminant)) / (2 * a);


    // check if the intersections are in front of the ray
    if (t1 < 0 && t2 < 0) {
        // both intersections are behind the ray
        return false;
    }
    
    if (t1 < 0) {
        // only t2 is in front of the ray
        *t = t2;
        return true;
    }

    if (t2 < 0) {
        // only t1 is in front of the ray
        *t = t1;
        return true;
    }

    // both intersections are in front of the ray => take the closer one
    *t = std::min(t1, t2);
    return true;
}

/*
 * emission characteristic of a spotlight
 */
glm::vec3 SpotLight::getEmission(
		glm::vec3 const& omega // world space direction
		) const
{
	cg_assert(std::fabs(glm::length(omega) - 1.f) < EPSILON);
    float cos_theta = glm::dot(omega, this->direction);
	return this->getPower() * (this->falloff + 2) * std::pow(std::max(0.f, cos_theta), this->falloff);
}

glm::vec3 evaluate_phong(
	RenderData &data,			// class containing raytracing information
	MaterialSample const& mat,	// the material at position
	glm::vec3 const& P,			// world space position
	glm::vec3 const& N,			// normal at the position (already normalized)
	glm::vec3 const& V)			// view vector (already normalized)
{
	cg_assert(std::fabs(glm::length(N) - 1.f) < EPSILON);
	cg_assert(std::fabs(glm::length(V) - 1.f) < EPSILON);

	glm::vec3 contribution(0.f);

	// iterate over lights and sum up their contribution
	for (auto& light_uptr : data.context.get_active_scene()->lights) 
	{
		// TODO: calculate the (normalized) direction to the light
		const Light *light = light_uptr.get();
        glm::vec3 l = light->getPosition();
		// glm::vec3 L(0.0f, 1.0f, 0.0f);
        glm::vec3 L = glm::normalize(l - P);

		float visibility = 1.f;
		if (data.context.params.shadows) {
			// TODO: check if light source is visible
            visibility = visible(data, P, light->getPosition()) ? 1.f : 0.f;
		}

        float cos_theta = glm::dot(N, L);
        float orthogonality = cos_theta > 0 ? 1.f : 0.f;
        glm::vec3 emitted_light = (light->getEmission(-L) * visibility * orthogonality) / static_cast<float>(std::pow(glm::length(l - P), 2));

		glm::vec3 diffuse(0.f);
		if (data.context.params.diffuse) {
			// TODO: compute diffuse component of phong model
            diffuse = emitted_light * mat.k_d * std::max(0.f, cos_theta);
		}

		glm::vec3 specular(0.f);
		if (data.context.params.specular) {
			// TODO: compute specular component of phong model
            glm::vec3 R_L = 2 * cos_theta * N - L;
            float cos_psi = glm::dot(R_L, V);
            specular = emitted_light * mat.k_s * std::pow(std::max(0.f, cos_psi), mat.n);
        }

		glm::vec3 ambient(0.f);
        if (data.context.params.ambient) {
            ambient = light->getPower() * mat.k_a / static_cast<float>(std::pow(glm::length(l - P), 2));
        }

		// TODO: modify this and implement the phong model as specified on the exercise sheet
		contribution += diffuse + specular + ambient;
	}

	return contribution;
}

glm::vec3 evaluate_reflection(
	RenderData &data,			// class containing raytracing information
	int depth,					// the current recursion depth
	glm::vec3 const& P,			// world space position
	glm::vec3 const& N,			// normal at the position (already normalized)
	glm::vec3 const& V)			// view vector (already normalized)
{
	// TODO: calculate reflective contribution by constructing and shooting a reflection ray.
	glm::vec3 R = reflect(V, N);
    glm::vec3 o = P + data.context.params.ray_epsilon * R;
    Ray reflection_ray(o, R);
    return trace_recursive(data, reflection_ray, depth + 1);
}

glm::vec3 evaluate_transmission(
	RenderData &data,			// class containing raytracing information
	int depth,					// the current recursion depth
	glm::vec3 const& P,			// world space position
	glm::vec3 const& N,			// normal at the position (already normalized)
	glm::vec3 const& V,			// view vector (already normalized)
	float eta)					// the relative refraction index
{
	// TODO: calculate transmissive contribution by constructing and shooting a transmission ray.
    glm::vec3 T(0.f);
    bool transmission_possible = refract(V, N, eta, &T);
    if (!transmission_possible) {
        return glm::vec3(0.f);
    }
    glm::vec3 o = P + data.context.params.ray_epsilon * T;
    Ray transmission_ray(o, T);
    return trace_recursive(data, transmission_ray, depth + 1);
}

glm::vec3 handle_transmissive_material_single_ior(
	RenderData &data,			// class containing raytracing information
	int depth,					// the current recursion depth
	glm::vec3 const& P,			// world space position
	glm::vec3 const& N,			// normal at the position (already normalized)
	glm::vec3 const& V,			// view vector (already normalized)
	float eta)					// the relative refraction index
{
	if (data.context.params.fresnel) {
		float fresnel_factor = fresnel(V, N, eta);
        glm::vec3 reflection = evaluate_reflection(data, depth, P, N, V);
        glm::vec3 transmission = evaluate_transmission(data, depth, P, N, V, eta);
        return fresnel_factor * reflection + (1 - fresnel_factor) * transmission;
	}
	else {
		// just regular transmission
		return evaluate_transmission(data, depth, P, N, V, eta);
	}
}

glm::vec3 handle_transmissive_material(
	RenderData &data,					// class containing raytracing information
	int depth,							// the current recursion depth
	glm::vec3 const& P,					// world space position
	glm::vec3 const& N,					// normal at the position (already normalized)
	glm::vec3 const& V,					// view vector (already normalized)
	glm::vec3 const& eta_of_channel)	// relative refraction index of red, green and blue color channel
{
	if (data.context.params.dispersion && !(eta_of_channel[0] == eta_of_channel[1] && eta_of_channel[0] == eta_of_channel[2])) {
		// TODO: split ray into 3 rays (one for each color channel) and implement dispersion here
		glm::vec3 contribution(0.f);
        for (int i = 0; i < 3; i++) {
            float eta = eta_of_channel[i];
            contribution[i] = handle_transmissive_material_single_ior(data, depth, P, N, V, eta)[i];
        }
        return contribution;
	}
	else {
		// dont handle transmission, take average refraction index instead.
		const float eta = 1.f/3.f*(eta_of_channel[0]+eta_of_channel[1]+eta_of_channel[2]);
		return handle_transmissive_material_single_ior(data, depth, P, N, V, eta);
	}
	return glm::vec3(0.f);
}
// CG_REVISION 8c58412a25ac2367c053bfa840ee81b320bdd315
