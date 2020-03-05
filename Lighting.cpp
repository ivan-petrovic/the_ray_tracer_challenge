#include "Lighting.h"
#include <iostream>

Color lighting(
    const Material &material,
    const PointLight &light,
    const Vector4 &position,
    const Vector4 &eyev,
    const Vector4 &normalv
) { 
    Color ambient, diffuse, specular;
    Color black(0.0f, 0.0f, 0.0f);

    // combine the surface color with the light's color/intensity
    Color effective_color = material.color * light.intensity;

    // find the direction to the light source
    Vector4 lightv = normalize(light.position - position);

    // compute the ambient contribution
    ambient = effective_color * material.ambient;

    // light_dot_normal represents the cosine of the angle between the
    // light vector and the normal vector. A negative number means the
    // light is on the othere side of the surface.
    float light_dot_normal = lightv * normalv;
    
    if (light_dot_normal < 0.0f) {
        diffuse = black;
        specular = black;
    
    } else {
        // compute the diffuse contribution
        diffuse = effective_color * material.diffuse * light_dot_normal;

        // reflect_dot_eye represents the cosine of the angle between the
        // reflection vector and the eye vector. A negative number means the
        // light reflects away from the eye.
        Vector4 reflectv = reflect(-lightv, normalv);
        float reflect_dot_eye = reflectv * eyev;

        if (reflect_dot_eye < 0.0f) {
            specular = black;
        } else {
            // compute the specular contribution
            float factor = pow(reflect_dot_eye, material.shininess);
            specular = light.intensity * material.specular * factor;
        }
    }

    return ambient + diffuse + specular;
}
