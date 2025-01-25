#include <cglib/core/image.h>

#include <cglib/gl/scene_graph.h>
#include <cglib/gl/prefilter_envmap.h>

#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>

/*
 * Create a sphere flake node and its 5 children.
 * Recurse if number_of_remaining_recursions > 0.
 */
std::shared_ptr<SceneGraphNode> buildSphereFlakeSceneGraph(
    const std::shared_ptr<GLObjModel> &model, // the geometric model associated with this node (a sphere)
    float sphere_model_radius,                // the radius of the sphere in local coordinates (hint: should remain constant throughout the recursion)
    float size_factor,                        // growth/shrink factor of the spheres for each recursion level
    int number_of_remaining_recursions)       // the number of remaining recursions
{
    // TODO: create root SceneGraphNode and set model
    auto root = std::make_shared<SceneGraphNode>();
    // root->model = ...;
    root->model = model;

    // TODO: only create children if there are remaining recursions
    if (number_of_remaining_recursions <= 0)
    {
        return root;
    }

    float child_radius = sphere_model_radius * size_factor;
    float translation_distance = sphere_model_radius + child_radius;

    // translations
    std::array<glm::vec3, 5> translations = {
        glm::vec3(0.f, translation_distance, 0.f),  // +y
        glm::vec3(-translation_distance, 0.f, 0.f), // -x
        glm::vec3(translation_distance, 0.f, 0.f),  // +x
        glm::vec3(0.f, 0.f, translation_distance),  // +z
        glm::vec3(0.f, 0.f, -translation_distance)  // -z
    };

    // rotations axis
    std::array<glm::vec3, 5> rotations = {
        glm::vec3(0.f, 1.f, 0.f), // y-axis
        glm::vec3(0.f, 0.f, 1.f), // z-axis
        glm::vec3(0.f, 0.f, 1.f), // z-axis
        glm::vec3(1.f, 0.f, 0.f), // x-axis
        glm::vec3(1.f, 0.f, 0.f)  // x-axis
    };

    // rotations angles
    std::array<float, 5> angles = {
        0.f,
        90.f,
        -90.f,
        90.f,
        -90.f};

    // TODO: create 5 child nodes
    for (int i = 0; i < 5; ++i)
    {
        // TODO: create sphere flake sub graph for each child
        // auto subgraph = buildSphereFlakeSceneGraph(...);
        auto subgraph = buildSphereFlakeSceneGraph(model, sphere_model_radius, size_factor, number_of_remaining_recursions - 1);

        glm::mat4 translation = glm::translate(glm::mat4(1.f), translations[i]);
        glm::mat4 scale = glm::scale(glm::mat4(1.f), glm::vec3(size_factor));
        glm::mat4 rotation = glm::rotate(glm::mat4(1.f), glm::radians(angles[i]), rotations[i]);

        auto child = std::make_shared<SceneGraphNode>();
        child->node_to_parent = translation * rotation * scale;
        child->parent_to_node = glm::inverse(child->node_to_parent);
        child->model = model;

        child->children = subgraph->children;
        root->children.push_back(child);
    }

    return root;
}

/*
 * Traverse the scene graph and collect all models.
 * Recursivly computes the world transformation for each model.
 */
void SceneGraphNode::collectTransformedModels(
    std::vector<TransformedModel> &transformed_models, // list that contains all models when traversal is complete
    const glm::mat4 &parent_to_world,                  // the world transformation of the parent of this node
    const glm::mat4 &world_to_parent)                  // the inverse world transformation of this node's parent
    const
{
    // TODO: compute node_to_world and world_to_node transformation matrices for this node
    glm::mat4 node_to_world = parent_to_world * node_to_parent;
    glm::mat4 world_to_node = glm::inverse(node_to_world);

    // TODO: add this node's model to the list of transformed models
    // transformed_models.push_back(TransformedModel(...));
    transformed_models.push_back(TransformedModel(node_to_world, world_to_node, model.get()));

    // TODO: recursively transform and add the models of all children (subgraphs)
    for (auto &child : children)
    {
        child->collectTransformedModels(transformed_models, node_to_world, world_to_node);
    }
}

/*
 * Perform animation by traversing the scene graph recursively
 * and rotating each scene graph node around the y-axis (in object space).
 */
void animateSphereFlake(
    SceneGraphNode &node,  // the current node of the traversal
    float angle_increment) // the incremental rotation angle
{
    // TODO: compute incremental rotation matrix for the given node node
    // glm::mat4 rotation = glm::rotate(glm::mat4(1.f), angle_increment, ...);
    glm::mat4 rotation = glm::rotate(glm::mat4(1.f), angle_increment, glm::vec3(0.f, 1.f, 0.f));

    // TODO: compute the parent-relative transformation matrices for this node
    // node.node_to_parent = ...
    // node.parent_to_node = ...
    node.node_to_parent = rotation * node.node_to_parent;
    node.parent_to_node = glm::transpose(node.node_to_parent);

    // TODO: recursively animate child subgraphs
    for (auto &child : node.children)
    {
        animateSphereFlake(*child, angle_increment);
    }
}

/*
 * compute a prefiltered environment map for diffuse
 * illumination for the given environment map
 */
std::shared_ptr<Image>
prefilter_environment_diffuse(Image const &img)
{
    const int width = img.getWidth();
    const int height = img.getHeight();
    glm::ivec2 size(width, height); // Size of the image as glm::ivec2
    auto filtered = std::make_shared<Image>(width, height);

    // For all texels in the environment map
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            // Compute normal direction for the current texel
            glm::ivec2 coord(x, y);
            glm::vec3 N = direction_from_lonlat_coord(coord, size);

            glm::vec3 diffuseColor(0.0f); // Accumulate diffuse color
            float weightSum = 0.0f;       // Accumulate weights

            // Integrate over all incident directions
            for (int dy = 0; dy < height; ++dy)
            {
                for (int dx = 0; dx < width; ++dx)
                {
                    // Compute incident direction
                    glm::ivec2 sampleCoord(dx, dy);
                    glm::vec3 wi = direction_from_lonlat_coord(sampleCoord, size);

                    // Calculate solid angle
                    float solidAngle = solid_angle_from_lonlat_coord(sampleCoord, size);

                    // Lambertian diffuse term (N · ωi)
                    float cosTheta = glm::dot(N, wi);
                    if (cosTheta > 0.0f) // Only consider contributions where cosTheta > 0
                    {
                        // Get the radiance value from the environment map
                        glm::vec3 radiance = img.getPixel(dx, dy);

                        // Accumulate weighted radiance
                        diffuseColor += radiance * cosTheta * solidAngle;
                        weightSum += cosTheta * solidAngle;
                    }
                }
            }

            // Normalize the accumulated value
            if (weightSum > 0.0f)
            {
                diffuseColor /= weightSum;
            }

            // Extend diffuseColor (RGB) to RGBA by adding alpha = 1.0
            glm::vec4 filteredPixel(diffuseColor, 1.0f);

            // Write the filtered value into the prefiltered map
            filtered->setPixel(x, y, filteredPixel);
        }
    }

    return filtered;
}

/*
 * compute a prefiltered environment map for specular
 * illumination for the given environment map and
 * phong exponent
 */
std::shared_ptr<Image>
prefilter_environment_specular(Image const &img, float n)
{
    const int width = img.getWidth();
    const int height = img.getHeight();
    glm::ivec2 size(width, height); // Size of the image as glm::ivec2

    auto filtered = std::make_shared<Image>(width, height);

    // For all texels in the envmap...
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            // Compute reflection direction for the current texel
            glm::ivec2 coord(x, y);
            glm::vec3 R = direction_from_lonlat_coord(coord, size);

            glm::vec3 specularColor(0.0f); // Accumulate specular color
            float weightSum = 0.0f;        // Accumulate weights

            // ... integrate over all incident directions.
            for (int dy = 0; dy < height; ++dy)
            {
                for (int dx = 0; dx < width; ++dx)
                {
                    // Compute incident direction
                    glm::ivec2 sampleCoord(dx, dy);
                    glm::vec3 wi = direction_from_lonlat_coord(sampleCoord, size);

                    // Calculate solid angle
                    float solidAngle = solid_angle_from_lonlat_coord(sampleCoord, size);

                    // Compute the Phong BRDF term (R · ωi)^n
                    float cosAlpha = glm::dot(R, wi);
                    if (cosAlpha > 0.0f) // Only consider contributions where cosAlpha > 0
                    {
                        float phongWeight = std::pow(cosAlpha, n);

                        // Get the radiance value from the environment map
                        glm::vec3 radiance = img.getPixel(dx, dy);

                        // Accumulate weighted radiance
                        specularColor += radiance * phongWeight * solidAngle;
                        weightSum += phongWeight * solidAngle;
                    }
                }
            }

            // Normalize the accumulated value
            if (weightSum > 0.0f)
            {
                specularColor /= weightSum;
            }

            // Extend specularColor (RGB) to RGBA by adding alpha = 1.0
            glm::vec4 filteredPixel(specularColor, 1.0f);

            // Write the filtered value into the prefiltered map
            filtered->setPixel(x, y, filteredPixel);
        }
    }

    return filtered;
}

// CG_REVISION d4ab32bd208749f2d2b1439e25d16e642b039298