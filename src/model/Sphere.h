//
// Created by ivan on 15.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_SPHERE_H
#define THE_RAY_TRACER_CHALLENGE_SPHERE_H

#include "Object.h"

namespace mn {

    class Sphere : public Object {
    public:
        Sphere() : Object(), _radius(1.0) {}

        [[nodiscard]] double radius() const { return _radius; }

        void radius(double r) { _radius = r; }

//        Vector4 normal_at(Vector4 world_point) {
//            Vector4 object_point = inverse(transform) * world_point;
//            Vector4 object_normal = object_point - make_point(0.0f, 0.0f, 0.0f);
//            Vector4 world_normal = transpose(inverse(transform)) * object_normal;
//            world_normal.w = 0.0f;
//            world_normal.normalize();
//            return world_normal;
//        }

    private:
        double _radius;
    };

}
#endif //THE_RAY_TRACER_CHALLENGE_SPHERE_H
