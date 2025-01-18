#include <cglib/rt/bvh.h>

#include <cglib/rt/triangle_soup.h>

#include <cglib/core/image.h>
#include <complex>

/*
 * Create a 1 dimensional normalized gauss kernel
 *
 * Parameters:
 *  - sigma:       the parameter of the gaussian
 *  - kernel_size: the size of the kernel (has to be odd)
 *  - kernel:      an array with size kernel_size elements that
 *                 has to be filled with the kernel values
 *
 */
void Image::create_gaussian_kernel_1d(
    float sigma,
    int kernel_size,
    float *kernel)
{
    cg_assert(kernel_size % 2 == 1);

    // TODO: calculate filter values as described on the exercise sheet.
    // Make sure your kernel is normalized

    float sum = 0.0f;
    int half_size = kernel_size / 2;
    float sigma_squared = 2.0f * sigma * sigma;

    // calculate kernel values
    for (int i = 0; i < kernel_size; ++i)
    {
        int x = i - half_size;
        kernel[i] = std::exp(-x * x / sigma_squared) / (std::sqrt(2.0f * M_PI) * sigma);
        sum += kernel[i];
    }

    // normalize kernel
    for (int i = 0; i < kernel_size; ++i)
    {
        kernel[i] /= sum;
    }
}

/*
 * Create a 2 dimensional quadratic and normalized gauss kernel
 *
 * Parameters:
 *  - sigma:       the parameter of the gaussian
 *  - kernel_size: the size of the kernel (has to be odd)
 *  - kernel:      an array with kernel_size*kernel_size elements that
 *                 has to be filled with the kernel values
 */
void Image::create_gaussian_kernel_2d(
    float sigma,
    int kernel_size,
    float *kernel)
{
    cg_assert(kernel_size % 2 == 1);

    // TODO: calculate filter values as described on the exercise sheet.
    // Make sure your kernel is normalized

    float sum = 0.0f;
    int half_size = kernel_size / 2;
    float sigma_squared = 2.0f * sigma * sigma;

    // calculate kernel values
    for (int j = 0; j < kernel_size; ++j)
    {
        for (int i = 0; i < kernel_size; ++i)
        {
            int x = i - half_size;
            int y = j - half_size;
            kernel[j * kernel_size + i] = std::exp(-(x * x + y * y) / sigma_squared) / (M_PI * sigma_squared);
            sum += kernel[j * kernel_size + i];
        }
    }

    // normalize kernel
    for (int j = 0; j < kernel_size; ++j)
    {
        for (int i = 0; i < kernel_size; ++i)
        {
            kernel[j * kernel_size + i] /= sum;
        }
    }
}

/*
 * Convolve an image with a 2d filter kernel
 *
 * Parameters:
 *  - kernel_size: the size of the 2d-kernel
 *  - kernel:      the 2d-kernel with kernel_size*kernel_size elements
 *  - wrap_mode:   needs to be known to handle repeating
 *                 textures correctly
 */
void Image::filter(Image *target, int kernel_size, float *kernel, WrapMode wrap_mode) const
{
    cg_assert(kernel_size % 2 == 1 && "kernel size should be odd.");
    cg_assert(kernel_size > 0 && "kernel size should be greater than 0.");
    cg_assert(target);
    cg_assert(target->getWidth() == m_width && target->getHeight() == m_height);

    for (int n = 0; n < m_height; ++n)
    {
        for (int m = 0; m < m_width; ++m)
        {
            glm::vec4 color(0.0f);

            for (int j = 0; j < kernel_size; ++j)
            {
                for (int i = 0; i < kernel_size; ++i)
                {
                    int x_offset = i - kernel_size / 2;
                    int y_offset = j - kernel_size / 2;
                    glm::vec4 pixel = getPixel(m + x_offset, n + y_offset, wrap_mode);
                    color += pixel * kernel[j * kernel_size + i];
                }
            }

            target->setPixel(m, n, color);
        }
    }
}

/*
 * Convolve an image with a separable 1d filter kernel
 *
 * Parameters:
 *  - kernel_size: the size of the 1d kernel
 *  - kernel:      the 1d-kernel with kernel_size elements
 *  - wrap_mode:   needs to be known to handle repeating
 *                 textures correctly
 */
void Image::filter_separable(Image *target, int kernel_size, float *kernel, WrapMode wrap_mode) const
{
    cg_assert(kernel_size % 2 == 1 && "kernel size should be odd.");
    cg_assert(kernel_size > 0 && "kernel size should be greater than 0.");
    cg_assert(target);
    cg_assert(target->getWidth() == m_width && target->getHeight() == m_height);

    // TODO: realize the 2d convolution with two
    // convolutions of the image with a 1d-kernel.
    // convolve the image horizontally and then convolve
    // the result vertically (or vise-versa).
    //
    // use the methods getPixel(x, y, wrap_mode) and
    // setPixel(x, y, value) to get and set pixels of an image

    Image temp(m_width, m_height);
    temp.clear();

    // horizontal convolution
    for (int n = 0; n < m_height; ++n)
    {
        for (int m = 0; m < m_width; ++m)
        {
            glm::vec4 color(0.0f);

            for (int i = 0; i < kernel_size; ++i)
            {
                int x_offset = i - kernel_size / 2;
                glm::vec4 pixel = getPixel(m + x_offset, n, wrap_mode);
                color += pixel * kernel[i];
            }

            temp.setPixel(m, n, color);
        }
    }

    // vertical convolution
    for (int n = 0; n < m_height; ++n)
    {
        for (int m = 0; m < m_width; ++m)
        {
            glm::vec4 color(0.0f);

            for (int j = 0; j < kernel_size; ++j)
            {
                int y_offset = j - kernel_size / 2;
                glm::vec4 pixel = temp.getPixel(m, n + y_offset, wrap_mode);
                color += pixel * kernel[j];
            }

            target->setPixel(m, n, color);
        }
    }
}

/**
 * Reorder triangle indices in the vector triangle_indices
 * in the range [first_triangle_idx, first_triangle_idx+num_triangles-1]
 * so that the range is split in two sets where all triangles in the first set
 * are "less than equal" than the median, and all triangles in the second set
 * are "greater than equal" the median.
 *
 * Ordering ("less than") is defined by the ordering of triangle
 * bounding box centers along the given axis.
 *
 * Triangle indices within a set need not be sorted.
 *
 * The resulting sets must have an equal number of elements if num_triangles
 * is even. Otherwise, one of the sets must have one more element.
 *
 * For example, 8 triangles must be split 4-4. 7 Triangles must be split
 * 4-3 or 3-4.
 *
 * Parameters:
 *  - first_triangle_idx: The index of the first triangle in the given range.
 *  - num_triangles:      The number of triangles in the range.
 *  - axis:               The sort axis. 0 is X, 1 is Y, 2 is Z.
 *
 * Return value:
 *  - The number of triangles in the first set.
 */
int BVH::reorder_triangles_median(
    int first_triangle_idx,
    int num_triangles,
    int axis)
{
    cg_assert(first_triangle_idx < static_cast<int>(triangle_indices.size()));
    cg_assert(first_triangle_idx >= 0);
    cg_assert(num_triangles <= static_cast<int>(triangle_indices.size() - first_triangle_idx));
    cg_assert(num_triangles > 1);
    cg_assert(axis >= 0);
    cg_assert(axis < 3);

    // for each triangle, calculate the center of the bounding box
    std::vector<float> triangle_centers;
    for (int i = first_triangle_idx; i < first_triangle_idx + num_triangles; i++)
    {
        int triangle_index = triangle_indices[i];
        float min = FLT_MAX;
        float max = -FLT_MAX;
        for (int j = 0; j < 3; j++)
        {
            min = std::min(min, triangle_soup.vertices[triangle_index * 3 + j][axis]);
            max = std::max(max, triangle_soup.vertices[triangle_index * 3 + j][axis]);
        }
        float center = (min + max) / 2.0f;
        triangle_centers.push_back(center);
    }

    // sort the triangle intices in the given range according to the centers
    std::vector<std::pair<int, float>> center_mappings;
    for (int i = 0; i < num_triangles; i++)
    {
        center_mappings.push_back(std::make_pair(triangle_indices[first_triangle_idx + i], triangle_centers[i]));
    }
    std::sort(center_mappings.begin(), center_mappings.end(), [](const std::pair<int, float> &a, const std::pair<int, float> &b)
              { return a.second < b.second; });
    for (int i = 0; i < num_triangles; i++)
    {
        triangle_indices[first_triangle_idx + i] = center_mappings[i].first;
    }

    // return the number of triangles up to the median
    return num_triangles / 2;
}

/*
 * Build a BVH recursively using the object median split heuristic.
 *
 * This method must first fully initialize the current node, and then
 * potentially split it.
 *
 * A node must not be split if it contains MAX_TRIANGLES_IN_LEAF triangles or
 * less. No leaf node may be empty. All nodes must have either two or no
 * children.
 *
 * Use reorder_triangles_median to perform the split in triangle_indices.
 * Split along X for depth 0. Then, proceed in the order Y, Z, X, Y, Z, X, Y, ..
 *
 * Parameters:
 *  - node_idx:           The index of the node to be split.
 *  - first_triangle_idx: An index into the array triangle_indices. It points
 *                        to the first triangle contained in the current node.
 *  - num_triangles:      The number of triangles contained in the current node.
 */
void BVH::
    build_bvh(int node_idx, int first_triangle_idx, int num_triangles, int depth)
{
    cg_assert(node_idx <= triangle_soup.num_triangles * 2);
    cg_assert(num_triangles > 0);
    cg_assert(node_idx >= 0);
    cg_assert(node_idx < static_cast<int>(nodes.size()));
    cg_assert(depth >= 0);

    // TODO: Implement recursive build.
    nodes[node_idx].triangle_idx = first_triangle_idx;
    nodes[node_idx].num_triangles = num_triangles;
    nodes[node_idx].aabb.min = glm::vec3(FLT_MAX);
    nodes[node_idx].aabb.max = glm::vec3(-FLT_MAX);
    nodes[node_idx].left = -1;
    nodes[node_idx].right = -1;

    // extend the AABB of the node to contain all triangles
    for (int i = first_triangle_idx; i < first_triangle_idx + num_triangles; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            nodes[node_idx].aabb.extend(triangle_soup.vertices[triangle_indices[i] * 3 + j]);
        }
    }

    // split the node if it contains more than MAX_TRIANGLES_IN_LEAF triangles
    if (num_triangles > MAX_TRIANGLES_IN_LEAF)
    {
        int axis = depth % 3;
        int num_triangles_left = reorder_triangles_median(first_triangle_idx, num_triangles, axis);

        // create left child node
        nodes[node_idx].left = nodes.size();
        nodes.push_back(Node());
        build_bvh(nodes[node_idx].left, first_triangle_idx, num_triangles_left, depth + 1);

        // create right child node
        nodes[node_idx].right = nodes.size();
        nodes.push_back(Node());
        build_bvh(nodes[node_idx].right, first_triangle_idx + num_triangles_left, num_triangles - num_triangles_left, depth + 1);
    }
}

/*
 * Intersect the BVH recursively, returning the nearest intersection if
 * there is one.
 *
 * Caution: BVH nodes may overlap.
 *
 * Parameters:
 *  - ray:                  The ray to intersect the BVH with.
 *  - idx:                  The node to be intersected.
 *  - nearest_intersection: The distance to the intersection point, if an
 *                          intersection was found. Must not be changed
 *                          otherwise.
 *  - isect:                The intersection, if one was found. Must not be
 *                          changed otherwise.
 *
 * Return value:
 *  true if an intersection was found, false otherwise.
 */
bool BVH::
    intersect_recursive(const Ray &ray, int idx, float *nearest_intersection, Intersection *isect) const
{
    cg_assert(nearest_intersection);
    cg_assert(isect);
    cg_assert(idx >= 0);
    cg_assert(idx < static_cast<int>(nodes.size()));

    const Node &n = nodes[idx];

    // This is a leaf node. Intersect all triangles.
    if (n.left < 0)
    {
        glm::vec3 bary(0.f);
        bool hit = false;
        for (int i = 0; i < n.num_triangles; i++)
        {
            int x = triangle_indices[n.triangle_idx + i];
            float dist;
            glm::vec3 b;
            if (intersect_triangle(ray.origin, ray.direction,
                                   triangle_soup.vertices[x * 3 + 0],
                                   triangle_soup.vertices[x * 3 + 1],
                                   triangle_soup.vertices[x * 3 + 2],
                                   b, dist))
            {
                hit = true;
                if (dist <= *nearest_intersection)
                {
                    *nearest_intersection = dist;
                    bary = b;
                    cg_assert(x >= 0);
                    if (isect)
                        triangle_soup.fill_intersection(isect, x, *nearest_intersection, bary);
                }
            }
        }
        return hit;
    }

    // This is an inner node. Recurse into child nodes.
    else
    {
        // TODO: Implement recursive traversal here.
        // check if the ray intersects the AABB of the left child node
        float t_min_left = 0.0f;
        float t_max_left = FLT_MAX;
        bool hit_left = nodes[n.left].aabb.intersect(ray, t_min_left, t_max_left);

        // check if the ray intersects the AABB of the right child node
        float t_min_right = 0.0f;
        float t_max_right = FLT_MAX;
        bool hit_right = nodes[n.right].aabb.intersect(ray, t_min_right, t_max_right);

        if (hit_left && hit_right)
        {
            // if both children are hit, traverse the closer one first
            if (t_min_left < t_min_right)
            {
                if (intersect_recursive(ray, n.left, nearest_intersection, isect))
                {
                    // only traverse the other child if the nearest intersection is closer than the current distance
                    if (*nearest_intersection > t_min_right)
                    {
                        return intersect_recursive(ray, n.right, nearest_intersection, isect);
                    }

                    return true;
                }
                return intersect_recursive(ray, n.right, nearest_intersection, isect);
            }
            else
            {
                if (intersect_recursive(ray, n.right, nearest_intersection, isect))
                {
                    // only traverse the other child if the nearest intersection is closer than the current distance
                    if (*nearest_intersection > t_min_left)
                    {
                        return intersect_recursive(ray, n.left, nearest_intersection, isect);
                    }

                    return true;
                }
                return intersect_recursive(ray, n.left, nearest_intersection, isect);
            }
        }
        else if (hit_left)
        {
            return intersect_recursive(ray, n.left, nearest_intersection, isect);
        }
        else if (hit_right)
        {
            return intersect_recursive(ray, n.right, nearest_intersection, isect);
        }
    }
    return false;
}

// CG_REVISION 8c58412a25ac2367c053bfa840ee81b320bdd315
