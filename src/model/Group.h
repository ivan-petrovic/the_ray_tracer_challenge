//
// Created by ivan on 31.01.2021..
//

#ifndef THE_RAY_TRACER_CHALLENGE_GROUP_H
#define THE_RAY_TRACER_CHALLENGE_GROUP_H

#include <vector>
#include <memory>
#include "Object.h"
#include "../Ray.h"
#include "../intersection/intersect.h"

namespace mn {

    class Group : public Object {
    public:
        Group() : Object() {}
        [[nodiscard]] const std::vector<Object*> &objects() const { return _objects; }
        void add_child(Object* p_object) {
            _objects.push_back(p_object);
            p_object->set_parent(this);
        }
        bool empty() { return _objects.empty(); }

        void local_intersect(const Ray &object_ray, Intersections &intersections) const override {
            for (const Object* object : _objects) {
                intersect(object_ray, *object, intersections);
            };

            intersections.sort();
        }

        // This should not be called.
        // Consider throwing an exception. For now return zero vector.
        [[nodiscard]] Vector local_normal_at(const Point &object_point) const override {
            return mn::make_vector(0.0, 0.0, 0.0);
        }

    private:
        std::vector<Object*> _objects;
    };

    inline std::unique_ptr<Object> make_group() {
        return std::make_unique<Group>();
    }

}
#endif //THE_RAY_TRACER_CHALLENGE_SPHERE_H
