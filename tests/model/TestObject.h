//
// Created by ivan on 26.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_TEST_OBJECT_H
#define THE_RAY_TRACER_CHALLENGE_TEST_OBJECT_H

#include <memory>
#include "model/Object.h"

namespace mn {

    class TestObject : public Object {
    public:
        TestObject() : Object(), saved_ray() {}

        void local_intersect(const Ray &object_ray, Intersections &intersections) const override {
            saved_ray.origin(object_ray.origin());
            saved_ray.direction(object_ray.direction());
        }

        // We assume object_point is on the object.
        // For example it is ray-object intersection point.
        [[nodiscard]] Vector local_normal_at(const Point &object_point) const override {
            return object_point;
        }

        mutable Ray saved_ray;

    };

    inline std::unique_ptr<Object> make_test_object() {
        return std::make_unique<TestObject>();
    }

}

#endif //THE_RAY_TRACER_CHALLENGE_TEST_OBJECT_H
