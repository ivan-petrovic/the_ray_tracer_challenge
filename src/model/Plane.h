//
// Created by ivan on 26.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_PLANE_H
#define THE_RAY_TRACER_CHALLENGE_PLANE_H

#include <memory>
#include "Object.h"

namespace mn {

    // We assume it is xz plane
    class Plane : public Object {
    public:
        Plane() : Object() {}

        void local_intersect(const Ray &object_ray, Intersections &intersections) const override {
            // empty set - no intersections
            if (epsilon_equal(object_ray.direction().y, 0.0)) return;

            double t = - object_ray.origin().y / object_ray.direction().y;
            intersections.add(t, this);
        }

        // We assume object_point is on the plane.
        // For example it is ray-plane intersection point.
        [[nodiscard]] Vector local_normal_at(const Point &object_point, Intersection intersection) const override {
            return mn::make_vector(0.0, 1.0, 0.0);
        }

    };

    inline std::unique_ptr<Object> make_plane() {
        return std::make_unique<Plane>();
    }

}

#endif //THE_RAY_TRACER_CHALLENGE_PLANE_H
