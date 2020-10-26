//
// Created by ivan on 15.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_SPHERE_H
#define THE_RAY_TRACER_CHALLENGE_SPHERE_H

#include <memory>
#include "Object.h"
// #include "../intersection/Intersections.h"
#include "../Ray.h"

namespace mn {

    class Sphere : public Object {
    public:
        Sphere() : Object() {}

        void local_intersect(const Ray &object_ray, Intersections &intersections) const override {
            // the vector from the object's center, to the ray origin
            // remember: the object is centered at the world origin
            Vector object_to_ray = object_ray.origin() - make_point(0.0, 0.0, 0.0);

            double a = dot(object_ray.direction(), object_ray.direction());
            double b = 2.0 * dot(object_ray.direction(), object_to_ray);
            double c = dot(object_to_ray, object_to_ray) - 1;

            double discriminant = b * b - 4.0 * a * c;

            if (discriminant < 0.0) return; // no intersection

            double sqrt_discriminant = std::sqrt(discriminant);
            double one_over_2a = 0.5 / a;

            double t1 = (-b - sqrt_discriminant) * one_over_2a;
            double t2 = (-b + sqrt_discriminant) * one_over_2a;

            intersections.add(t1, this);
            intersections.add(t2, this);
        }

        // We assume object_point is on the sphere.
        // For example it is ray-sphere intersection point.
        [[nodiscard]] Vector local_normal_at(const Point &object_point) const override {
            // We need to lose w = 1; for vectors it should be w = 0
            // That's why we subtract origin point
            return object_point - mn::make_point(0.0, 0.0, 0.0);
        }

    };

    inline std::unique_ptr<Object> make_sphere() {
//        std::unique_ptr<Object> ptr_obj(nullptr);
//        ptr_obj = std::make_unique<Sphere>();
//        return ptr_obj;
        return std::make_unique<Sphere>();
    }

}
#endif //THE_RAY_TRACER_CHALLENGE_SPHERE_H
