#version 330

layout(location = 0) in vec3 POSITION; // position of the vertex in object space
layout(location = 1) in vec3 NORMAL;   // normal of the vertex in object space
layout(location = 2) in vec2 TEXCOORD; // uv coordinates of the vertex

uniform mat4 MVP;              // the model-view-projection matrix
uniform mat4 model_matrix;     // the world transformation of the model
uniform mat3 normal_matrix;    // the world transformation for normals

out vec3 world_position;              // position of the vertex in world space
out vec3 world_normal_interpolated;   // normal of the vertex in world space
out vec2 tex_coord;                   // uv coordinates of the vertex

void
main()
{
	// TODO: correctly set gl_Position, world_position, world_normal_interpolated, tex_coord
    // Set gl_Position using the MVP matrix
    gl_Position = MVP * vec4(POSITION, 1.0);
	
    // Transform the position to world space using the model matrix
    world_position = vec3(model_matrix * vec4(POSITION, 1.0));
	
    // Transform the normal to world space using the normal matrix
	world_normal_interpolated = normalize(normal_matrix * NORMAL);
	
    // Pass the texture coordinates directly
	tex_coord = TEXCOORD;
}
