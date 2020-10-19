//
// Created by ivan on 18.10.2020..
//
#include "lighting.h"

namespace mn {

    Color lighting(
            const Material &material,
            const PointLight &light,
            const Point &position,
            const Vector &eye,
            const Vector &normal
    ) {
        Color ambient, diffuse, specular;
        Color black = mn::color(0.0, 0.0, 0.0);

        // combine the surface color with the light's color/intensity
        Color effective_color = material.color() * light.intensity();

        // find the direction to the light source
        Vector light_vector = normalize(light.position() - position);

        // compute the ambient contribution
        ambient = effective_color * material.ambient();

        // light_dot_normal represents the cosine of the angle between the
        // light vector and the normal vector. A negative number means the
        // light is on the other side of the surface.
        double light_dot_normal = dot(light_vector, normal);

        if (light_dot_normal < 0.0) {
            diffuse = black;
            specular = black;
        } else {
            // compute the diffuse contribution
            diffuse = effective_color * material.diffuse() * light_dot_normal;

            // reflect_dot_eye represents the cosine of the angle between the
            // reflection vector and the eye vector. A negative number means the
            // light reflects away from the eye.
            Vector reflect_vector = reflect(light_vector, normal);
            double reflect_dot_eye = dot(reflect_vector, eye);

            if (reflect_dot_eye <= 0.0) {
                specular = black;
            } else {
                // compute the specular contribution
                double factor = std::pow(reflect_dot_eye, material.shininess());
                specular = light.intensity() * material.specular() * factor;
            }
        }

        return ambient + diffuse + specular;
    }

}
