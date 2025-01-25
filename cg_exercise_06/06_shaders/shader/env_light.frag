#version 330

uniform samplerCube EnvironmentTextureDiffuse;  // environment map, prefiltered for lookup of diffuse lighting
uniform samplerCube EnvironmentTextureGlossy;   // environment map, prefiltered for lookup of specular lighting

uniform vec3 cam_world_pos;    // the camera position in world space
uniform vec3 diffuse_color;    // k_d
uniform vec3 specular_color;   // k_s

in vec3 world_position;              // position of the vertex in world space
in vec3 world_normal_interpolated;   // normal of the vertex in world space

out vec4 frag_color;

void main (void)
{
    vec3 N = normalize(world_normal_interpolated);
    vec3 V = normalize(cam_world_pos - world_position);
    vec3 R = reflect(-V, N);
    vec3 Ld = texture(EnvironmentTextureDiffuse, N).rgb;
    vec3 Ls = texture(EnvironmentTextureGlossy, R).rgb;
    vec3 color = diffuse_color * Ld + specular_color * Ls;
    frag_color = vec4(color, 1.0);
}

