//
// Created by ivan on 16.10.2020..
//
#include <algorithm>
#include "Intersections.h"

namespace mn {

    void Intersections::sort() {
        std::sort(
                _intersections.begin(),
                _intersections.end(),
                [](const Intersection &a, const Intersection &b) -> bool { return a.t < b.t; }
        );
    }

    void intersect(const Ray &ray, const Sphere &sphere, Intersections &intersections) {
        Ray ray2 = ray.transform(inverse(sphere.transform()));

        // the vector from the sphere's center, to the ray origin
        // remember: the sphere is centered at the world origin
        Vector sphere_to_ray = ray2.origin() - point(0.0, 0.0, 0.0);

        double a = dot(ray2.direction(), ray2.direction());
        double b = 2.0 * dot(ray2.direction(), sphere_to_ray);
        double c = dot(sphere_to_ray, sphere_to_ray) - 1;

        double discriminant = b * b - 4.0 * a * c;

        if (discriminant < 0.0) return; // no intersection

        double sqrt_discriminant = std::sqrt(discriminant);
        double one_over_2a = 0.5 / a;

        double t1 = (-b - sqrt_discriminant) * one_over_2a;
        double t2 = (-b + sqrt_discriminant) * one_over_2a;

        intersections.add(t1, &sphere);
        intersections.add(t2, &sphere);
    }

    Intersection hit(Intersections &intersections) {
        // no intersection
        if (intersections.count() == 0) return Intersection{0.0, nullptr};

        intersections.sort();

        for (int i = 0; i < intersections.count(); i += 1) {
            if (intersections[i].t < 0.0) continue;
            return intersections[i];
        }

        // no non-negative t value, so no intersection
        return Intersection{0.0, nullptr};
    }

}
