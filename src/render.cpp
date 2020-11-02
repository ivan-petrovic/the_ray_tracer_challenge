//
// Created by ivan on 24.10.2020..
//
#include "render.h"

namespace mn {

    Color lighting(
            const Material &material,
            const Object &object,
            const PointLight &light,
            const Point &position,
            const Vector &eye,
            const Vector &normal,
            bool in_shadow
    ) {
        Color c;
        if (material.has_pattern()) {
            // c = material.pattern().stripe_at(position);
            c = pattern_at_object(material.pattern(), object, position);
        } else {
            c = material.color();
        }
        Color ambient, diffuse, specular;
        Color black = mn::make_color(0.0, 0.0, 0.0);

        // combine the surface color with the light's color/intensity
        Color effective_color = c * light.intensity();

        // find the direction to the light source
        Vector light_vector = normalize(light.position() - position);

        // compute the ambient contribution
        ambient = effective_color * material.ambient();

        if (in_shadow) return ambient;

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

    Color shade_hit(const World &world, const Hit &hit, int remaining) {
        bool in_shadow = is_shadowed(world, hit.over_point);
        Color surface = lighting(
                hit.object->material(),
                *hit.object,
                world.light(),
                hit.over_point,
                hit.eye,
                hit.normal,
                in_shadow
        );
        Color reflected = reflected_color(world, hit, remaining);

        return surface + reflected;
    }

    Color color_at(const World &world, const Ray &ray, int remaining) {
        Intersections intersections;
        intersect(ray, world, intersections);

        Intersection intersection = find_hit(intersections);
        if (intersection.object == nullptr) {
            return make_color(0.0, 0.0, 0.0); // black
        }

        Hit hit = prepare_computations(intersection, ray);
        return shade_hit(world, hit, remaining);
    }

    void render(const Camera &camera, const World &world, Canvas &canvas) {
        for (int y = 0; y < camera.vertical_size(); ++y) {
            for (int x = 0; x < camera.horizontal_size(); ++x) {
                Ray ray = camera.ray_for_pixel(x, y);
                Color color = color_at(world, ray);
                canvas.write_pixel(x, y, color);
            }
        }
    }

    bool is_shadowed(const World &world, const Point &point) {
        Vector direction = world.light().position() - point;
        double distance = direction.magnitude();
        direction.normalize();

        Ray ray(point, direction);
        Intersections intersections;
        intersect(ray, world, intersections);

        Intersection intersection = find_hit(intersections);
        if (intersection.object != nullptr && intersection.t < distance) {
            return true;
        }

        return false;
    }

    Color pattern_at_object(const Pattern &pattern, const Object &object, const Point &world_point) {
        Point object_point = inverse(object.transform()) * world_point;
        Point pattern_point = inverse(pattern.transform()) * object_point;

        return pattern.pattern_at(pattern_point);
    }

    Color reflected_color(const World &world, const Hit &hit, int remaining) {
        if (remaining <= 0)
            return make_color(0.0, 0.0, 0.0); // black

        if (hit.object->material().reflective() == 0.0)
            return make_color(0.0, 0.0, 0.0); // black

        Ray reflect_ray(hit.over_point, hit.reflect_v);
        Color color = color_at(world, reflect_ray, remaining - 1);

        return color * hit.object->material().reflective();
    }

}
