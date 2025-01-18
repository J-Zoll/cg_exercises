#include <cglib/rt/intersection.h>
#include <cglib/rt/object.h>
#include <cglib/rt/ray.h>
#include <cglib/rt/raytracing_context.h>
#include <cglib/rt/render_data.h>
#include <cglib/rt/renderer.h>
#include <cglib/rt/texture.h>
#include <cglib/rt/texture_mapping.h>
#include <cglib/core/thread_local_data.h>

#include <cglib/core/image.h>
#include <cglib/core/glmstream.h>
#include <cglib/core/assert.h>

#include <algorithm>

// my includes
#include <cglib/rt/transform.h>
#include <cglib/rt/intersection_tests.h>


// -----------------------------------------------------------------------------

/*
 * Evaluates a texture for the given uv-coordinate without filtering.
 *
 * This method transformes the uv-coordinate into a st-coordinate and
 * rounds down to integer pixel values.
 *
 * The parameter level in [0, mip_levels.size()-1] is the miplevel of
 * the texture that is to be evaluated.
 */
glm::vec4 ImageTexture::
evaluate_nearest(int level, glm::vec2 const& uv) const
{
	cg_assert(level >= 0 && level < static_cast<int>(mip_levels.size()));
	cg_assert(mip_levels[level]);

	// TODO: compute the st-coordinates for the given uv-coordinates and mipmap level
	int s = uv.x * mip_levels[level]->getWidth();
    int t = uv.y * mip_levels[level]->getHeight();

	// get the value of pixel (s, t) of miplevel level
	return get_texel(level, s, t);
}

// -----------------------------------------------------------------------------

/*
 * Implement clamping here.
 *
 * The input "val" may be arbitrary, including negative and very large positive values.
 * The method shall always return a value in [0, size).
 * Out-of-bounds inputs must be clamped to the nearest boundary.
 */
int ImageTexture::
wrap_clamp(int val, int size)
{
	cg_assert(size > 0);
	if (val < 0) {
        return 0;
    } else if (val >= size) {
        return size - 1;
    } else {
        return val;
    }
}

/*
 * Implement repeating here.
 *
 * The input "val" may be arbitrary, including negative and very large positive values.
 * The method shall always return a value in [0, size).
 * Out-of-bounds inputs must be mapped back into [0, size) so that 
 * the texture repeats infinitely.
 */
int ImageTexture::
wrap_repeat(int val, int size)
{
	cg_assert(size > 0);

    if (val < 0) {
        while (val < 0) {
            val += size;
        }
    } else if (val >= size) {
        val = val % size;
    }

    return val;
}


// -----------------------------------------------------------------------------


/*
 * Implement bilinear filtering here.
 *
 * Use mip_levels[level] as the image to filter.
 * The input uv coordinates may be arbitrary, including values outside [0, 1).
 *
 * Callers of this method must guarantee that level is valid, and
 * that mip_levels[level] is properly initialized. Compare the assertions.
 *
 * The color of a texel is to be interpreted as the color at the texel center.
 */
glm::vec4 ImageTexture::
evaluate_bilinear(int level, glm::vec2 const& uv) const
{
	cg_assert(level >= 0 && level < static_cast<int>(mip_levels.size()));
	cg_assert(mip_levels[level]);

    float s = uv.x * mip_levels[level]->getWidth();
    float t = uv.y * mip_levels[level]->getHeight();

    switch (wrap_mode) {
        case TextureWrapMode::CLAMP:
            s = wrap_clamp(s, mip_levels[level]->getWidth());
            t = wrap_clamp(t, mip_levels[level]->getHeight());
            break;
        case TextureWrapMode::REPEAT:
            s = wrap_repeat(s, mip_levels[level]->getWidth());
            t = wrap_repeat(t, mip_levels[level]->getHeight());
            break;
        default:
            break;
    }

    int s0 = std::floor(s);
    int t0 = std::floor(t);
    int s1 = std::ceil(s);
    int t1 = std::ceil(t);

    glm::vec4 c00 = get_texel(level, s0, t0);
    glm::vec4 c01 = get_texel(level, s0, t1);
    glm::vec4 c10 = get_texel(level, s1, t0);
    glm::vec4 c11 = get_texel(level, s1, t1);

    float ds = s - s0;
    float dt = t - t0;

    glm::vec4 c0 = c00 * (1 - ds) + c10 * ds;
    glm::vec4 c1 = c01 * (1 - ds) + c11 * ds;

    return c0 * (1 - dt) + c1 * dt;
}

// -----------------------------------------------------------------------------

/*
 * This method creates a mipmap hierarchy for
 * the texture.
 *
 * This is done by iteratively reducing the
 * dimenison of a mipmap level and averaging
 * pixel values until the size of a mipmap
 * level is [1, 1].
 *
 * The original data of the texture is stored
 * in mip_levels[0].
 *
 * You can allocale memory for a new mipmap level 
 * with dimensions (size_x, size_y) using
 *		mip_levels.emplace_back(new Image(size_x, size_y));
 */
void ImageTexture::
create_mipmap()
{
	/* this are the dimensions of the original texture/image */
	int size_x = mip_levels[0]->getWidth();
	int size_y = mip_levels[0]->getHeight();

	cg_assert("must be power of two" && !(size_x & (size_x - 1)));
	cg_assert("must be power of two" && !(size_y & (size_y - 1)));

    while (size_x > 1 || size_y > 1) {
        size_x = std::max(1, size_x / 2);
        size_y = std::max(1, size_y / 2);

        mip_levels.emplace_back(new Image(size_x, size_y));
    }

    for (int i = 1; i < mip_levels.size(); ++i) {
        for (int x = 0; x < mip_levels[i]->getWidth(); ++x) {
            for (int y = 0; y < mip_levels[i]->getHeight(); ++y) {
                int x0 = 2 * x;
                int y0 = 2 * y;
                int x1 = std::min(2 * x + 1, mip_levels[i - 1]->getWidth() - 1);
                int y1 = std::min(2 * y + 1, mip_levels[i - 1]->getHeight() - 1);

                glm::vec4 c00 = get_texel(i - 1, x0, y0);
                glm::vec4 c01 = get_texel(i - 1, x0, y1);
                glm::vec4 c10 = get_texel(i - 1, x1, y0);
                glm::vec4 c11 = get_texel(i - 1, x1, y1);

                glm::vec4 c = (c00 + c01 + c10 + c11) / 4.0f;
                set_texel(i, x, y, c);
            }
        }
    }
}

/*
 * Compute the dimensions of the pixel footprint's AABB in uv-space.
 *
 * First intersect the four rays through the pixel corners with
 * the tangent plane at the given intersection.
 *
 * Then the given code computes uv-coordinates for these
 * intersection points.
 *
 * Finally use the uv-coordinates and compute the AABB in
 * uv-space. 
 *
 * Return width (du) and height (dv) of the AABB.
 *
 */
glm::vec2 Object::
compute_uv_aabb_size(const Ray rays[4], Intersection const& isect)
{
	// TODO: compute intersection positions
	glm::vec3 intersection_positions[4] = {
		isect.position, isect.position, isect.position, isect.position
	};

	for (int i = 0; i < 4; ++i) {
		// todo: compute intersection positions using a ray->plane
		// intersection
        float* t = new float();
        if (intersect_plane(rays[i].origin, rays[i].direction, isect.position, isect.normal, t)) {
            intersection_positions[i] = rays[i].origin + rays[i].direction * (*t);
        }
	}

	// compute uv coordinates from intersection positions
	glm::vec2 intersection_uvs[4];
	get_intersection_uvs(intersection_positions, isect, intersection_uvs);

	// TODO: compute dudv = length of sides of AABB in uv space
	glm::vec2 dudv = glm::vec2(0.0f);

    for (int i = 0; i < 4; ++i) {
        glm::vec2 duv = intersection_uvs[(i + 1) % 4] - intersection_uvs[i];
        dudv.x = std::max(dudv.x, std::abs(duv.x));
        dudv.y = std::max(dudv.y, std::abs(duv.y));
    }

    return dudv;
}

/*
 * Implement trilinear filtering at a given uv-position.
 *
 * Transform the AABB dimensions dudv in st-space and
 * take the maximal coordinate as the 1D footprint size T.
 *
 * Determine mipmap levels i and i+1 such that
 *		texel_size(i) <= T <= texel_size(i+1)
 *
 *	Hint: use std::log2(T) for that.
 *
 *	Perform bilinear filtering in both mipmap levels and
 *	linearly interpolate the resulting values.
 *
 */
glm::vec4 ImageTexture::
evaluate_trilinear(glm::vec2 const& uv, glm::vec2 const& dudv) const
{
    float s = uv.x * mip_levels[0]->getWidth();
    float t = uv.y * mip_levels[0]->getHeight();

    float T = std::max(dudv.x, dudv.y);
    int i = std::floor(std::log2(T));
    i = std::max(0, std::min(i, static_cast<int>(mip_levels.size()) - 2));

    glm::vec4 c0 = evaluate_bilinear(i, glm::vec2(s, t));
    glm::vec4 c1 = evaluate_bilinear(i + 1, glm::vec2(s, t));

    float t0 = std::pow(2, i);
    float t1 = std::pow(2, i + 1);
    float alpha = (T - t0) / (t1 - t0);

    return c0 * (1 - alpha) + c1 * alpha;
}

// -----------------------------------------------------------------------------

/*
 * Transform the given direction d using the matrix transform.
 *
 * The output direction must be normalized, even if d is not.
 */
glm::vec3 transform_direction(glm::mat4 const& transform, glm::vec3 const& d)
{
    glm::vec4 d_4d = glm::vec4(d, 0.0f);
    glm::vec4 d_transformed = transform * d_4d;
    return glm::normalize(glm::vec3(d_transformed));
}

/*
 * Transform the given position p using the matrix transform.
 */
glm::vec3 transform_position(glm::mat4 const& transform, glm::vec3 const& p)
{
	glm::vec4 p_4d = glm::vec4(p, 1.0f);
    glm::vec4 p_transformed = transform * p_4d;
    return glm::normalize(glm::vec3(p_transformed));
}

/*
 * Intersect with the ray, but do so in object space.
 *
 * First, transform ray into object space. Use the methods you have
 * implemented for this.
 * Then, intersect the object with the transformed ray.
 * Finally, make sure you transform the intersection back into world space.
 *
 * isect is guaranteed to be a valid pointer.
 * The method shall return true if an intersection was found and false otherwise.
 *
 * isect must be filled properly if an intersection was found.
 */
bool Object::
intersect(Ray const& ray, Intersection* isect) const
{
	cg_assert(isect);

	if (RaytracingContext::get_active()->params.transform_objects) {
		// TODO: transform ray, intersect object, transform intersection
		// information back

        Ray ray_t = transform_ray(ray, transform_world_to_object);
        if (geo->intersect(ray_t, isect)) {
            *isect = transform_intersection(*isect, transform_object_to_world, transform_object_to_world_normal);
            isect->t = glm::length(ray.origin - isect->position);
            return true;
        } else {
            return false;
        }
	}
	return geo->intersect(ray, isect);
}


/*
 * Transform a direction from tangent space to object space.
 *
 * Tangent space is a right-handed coordinate system where
 * the tangent is your thumb, the normal is the index finger, and
 * the bitangent is the middle finger.
 *
 * normal, tangent, and bitangent are given in object space.
 * Build a matrix that rotates d from tangent space into object space.
 * Then, transform d with this matrix to obtain the result.
 * 
 * You may assume that normal, tangent, and bitangent are normalized
 * to length 1.
 *
 * The output vector must be normalized to length 1, even if d is not.
 */
glm::vec3 transform_direction_to_object_space(
	glm::vec3 const& d, 
	glm::vec3 const& normal, 
	glm::vec3 const& tangent, 
	glm::vec3 const& bitangent)
{
	cg_assert(std::fabs(glm::length(normal)    - 1.0f) < 1e-4f);
	cg_assert(std::fabs(glm::length(tangent)   - 1.0f) < 1e-4f);
	cg_assert(std::fabs(glm::length(bitangent) - 1.0f) < 1e-4f);

    glm::mat3 TBN = glm::mat3(tangent, bitangent, normal);
    glm::mat3 TBN_inv = glm::transpose(TBN);
    glm::vec3 d_transformed = TBN_inv * d;
    return glm::normalize(d_transformed);
}

// -----------------------------------------------------------------------------

// Optional bonus assignment! The fourier scene uses evaluate_bilinear(..)
// for displaying amplitude, phase and result images so you need a working
// solution for the bilinear filtering!
//
// Spectrum and reconstruction are 2D memory blocks of the same size [sx, sy]
// in row major layout, i.e one row of size sx after the other. 
//
// Spectrum contains the complex fourier-coefficients \hat{x}_{kl}.
//
// Reconstruct the original grayscale image using fourier transformation!
void DiscreteFourier2D::reconstruct(
	int M, int N,
	std::complex<float> const* spectrum,
	std::complex<float>	* reconstruction)
{
}
// CG_REVISION 8c58412a25ac2367c053bfa840ee81b320bdd315
