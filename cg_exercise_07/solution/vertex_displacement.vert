#version 330

layout(location = 0) in vec2 POSITION; // position of the current vertex in the 2-dimensional patch grid

uniform ivec2 instanced_patch_mask_and_shift; // used to compute the global vertex coordinate from the patch instance id
uniform float instanced_patch_size;           // local size of one patch instance, used to compute the global vertex coordinate from the patch instance id

uniform mat4 MVP;             // terrain space to clip space
uniform mat4 model_matrix;    // terrain space to world space
uniform mat3 normal_matrix;   // terrain space to world space

uniform sampler2D HeightMap;           // height map with unscaled height values, stored in the red component
uniform vec2 one_over_height_map_size; // 1 / textureSize(HeightMap)
uniform float height_scaling;          // height scaling, guaranteed to be identical in terrain space and world space

out vec3 world_position;             // world-space position
out vec3 world_normal_interpolated;  // world-space normal
out vec2 grid_coord;                 // passed-through height field coordinate for fragment shader, do not modify

void main(void)
{
	// height field coordinate in grid units, where one height map pixel corresponds to one square unit
	grid_coord = POSITION + instanced_patch_size * vec2(gl_InstanceID & instanced_patch_mask_and_shift.x, gl_InstanceID >> instanced_patch_mask_and_shift.y);

	// position in local terrain space
	vec3 local_position = vec3(grid_coord.x, 0.0, grid_coord.y);

	// TODO: compute vertically displaced position in local terrain space
    float height = texture(HeightMap, grid_coord * one_over_height_map_size).r * height_scaling;
    local_position = vec3(grid_coord.x, height, grid_coord.y);


	// normal in local terrain space
	vec3 local_normal = vec3(0.0, 1.0, 0.0);

	// TODO: compute the actual normal of the displaced surface in local terrain space
    float height_left = texture(HeightMap, (grid_coord + vec2(-1.0, 0.0)) * one_over_height_map_size).r * height_scaling;
    float height_right = texture(HeightMap, (grid_coord + vec2(1.0, 0.0)) * one_over_height_map_size).r * height_scaling;
    float height_down = texture(HeightMap, (grid_coord + vec2(0.0, -1.0)) * one_over_height_map_size).r * height_scaling;
    float height_up = texture(HeightMap, (grid_coord + vec2(0.0, 1.0)) * one_over_height_map_size).r * height_scaling;

    vec3 tangent_x = vec3(2.0, height_right - height_left, 0.0);
    vec3 tangent_z = vec3(0.0, height_up - height_down, 2.0);
    local_normal = normalize(cross(tangent_z, tangent_x));


	// TODO: transform from terrain space to required spaces
    // transform to world space
    world_position = (model_matrix * vec4(local_position, 1.0)).xyz;
    world_normal_interpolated = normalize(normal_matrix * local_normal);

    // transform to clip spaces
    gl_Position = MVP * vec4(local_position, 1.0);
}
