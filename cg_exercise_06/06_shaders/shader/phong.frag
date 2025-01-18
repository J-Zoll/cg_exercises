#version 330

uniform sampler2D tex; // the texture containing the diffuse material parameter k_d

#define MAX_LIGHT_COUNT 16
uniform int light_count;                        // the number of lights (always smaller than MAX_LIGHT_COUNT)
uniform vec3 light_world_pos[MAX_LIGHT_COUNT];  // the position of the lights in world space
uniform vec3 light_intensity[MAX_LIGHT_COUNT];  // the intensity of the lights

uniform vec3 k_s; // the specular material parameter
uniform float n;  // phong exponent of the material

uniform vec3 cam_world_pos; // the camera position in world space

in vec3 world_position;            // the (interpolated) world space position corresponding to the fragment
in vec3 world_normal_interpolated; // the (interpolated) world space normal
in vec2 tex_coord;                 // the (interpolated) uv coordinate

out vec4 frag_color; // the resulting color value (will be written into the framebuffer)

void
main()
{
    // TODO: read k_d from texture
    // Read the diffuse material parameter k_d from the texture
    vec3 k_d = texture(tex, tex_coord).rgb;
    
    // Initialize the color as black (no light contribution)
    vec3 color = vec3(0.0);
    
    // TODO: iterate over all lights and accumulate illumination
    // according the the phong illumination model on the exercise sheet
    // Iterate over all light sources and accumulate their contributions
    for (int i = 0; i < light_count; ++i)
    {
        // Calculate the vector from the fragment to the light source
        vec3 L = normalize(light_world_pos[i] - world_position);
        
        // Calculate the normalized normal vector
        vec3 N = normalize(world_normal_interpolated);
        
        // Calculate the diffuse term (Lambertian reflection)
        float diffuse = max(dot(N, L), 0.0);
        
        // Calculate the reflection vector
        vec3 R = reflect(-L, N);
        
        // Calculate the view direction vector
        vec3 V = normalize(cam_world_pos - world_position);
        
        // Calculate the specular term using the Phong exponent
        float specular = pow(max(dot(R, V), 0.0), n);
        
        // Compute the illumination from this light
        vec3 illumination = light_intensity[i] * (k_d * diffuse + k_s * specular) / length(light_world_pos[i] - world_position);
        
        // Accumulate the illumination for the fragment color
        color += illumination;
    }
    
    // Set the fragment color
    frag_color = vec4(color, 1.0);
}
