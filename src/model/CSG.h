//
// Created by ivan on 3.3.2021..
//

#ifndef THE_RAY_TRACER_CHALLENGE_GROUP_H
#define THE_RAY_TRACER_CHALLENGE_GROUP_H

#include <vector>
#include <memory>
#include "Object.h"
#include "../Ray.h"
#include "../intersection/intersect.h"

namespace mn {

    class CSG : public Object {
    public:
        static const int UNION = 1;
        static const int INTERSECTION = 2;
        static const int DIFFERENCE = 4;

        CSG() : Object(), _operation(UNION), _left(nullptr), _right(nullptr) {}

        CSG(int o, Object *l, Object *r) : Object(), _operation(o), _left(l), _right(r) {
            _left->set_parent(this);
            _right->set_parent(this);
        }

        [[nodiscard]] const Object *left() const { return _left; }

        [[nodiscard]] const Object *right() const { return _right; }

        [[nodiscard]] int operation() const { return _operation; }

        void left(Object *p_object) {
            _left = p_object;
            p_object->set_parent(this);
        }

        void right(Object *p_object) {
            _right = p_object;
            p_object->set_parent(this);
        }

        bool includes(const Object *obj) const override {
            if (_left->includes(obj)) return true;
            if (_right->includes(obj)) return true;
            return false;
        }

        void filter_intersections(const Intersections &intersections, Intersections &out) const {
            // begin outside of both children
            bool in_left = false;
            bool in_right = false;

            for (int i = 0; i < intersections.count(); ++i) {
                // if intersection.object is part of the "left" child. then left_hit is true
                bool left_hit = _left->includes(intersections[i].object);

                if (intersection_allowed(_operation, left_hit, in_left, in_right)) {
                    out.add(intersections[i].t, intersections[i].object);
                }

                // depending on which object was hit, toggle either in_left or in_right
                if (left_hit) {
                    in_left = !in_left;
                } else {
                    in_right = !in_right;
                }
            }
        }

        void local_intersect(const Ray &object_ray, Intersections &intersections) const override {
            Intersections left_and_right_xs;
            intersect(object_ray, *_left, left_and_right_xs);
            intersect(object_ray, *_right, left_and_right_xs);
            left_and_right_xs.sort();

            filter_intersections(left_and_right_xs, intersections);
        }

        // This should not be called.
        // Consider throwing an exception. For now return zero vector.
        [[nodiscard]] Vector local_normal_at(const Point &object_point, Intersection intersection) const override {
            return mn::make_vector(0.0, 0.0, 0.0);
        }

    private:
        int _operation;
        Object *_left;
        Object *_right;
    };

    inline std::unique_ptr<Object> make_csg(int o, Object *l, Object *r) {
        return std::make_unique<CSG>(o, l, r);
    }

}

#endif //THE_RAY_TRACER_CHALLENGE_SPHERE_H
