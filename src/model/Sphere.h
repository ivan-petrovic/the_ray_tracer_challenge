//
// Created by ivan on 15.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_SPHERE_H
#define THE_RAY_TRACER_CHALLENGE_SPHERE_H

#include "Object.h"

namespace mn {

    class Sphere : public Object {
    public:
        Sphere() : Object() /*, _radius(1.0) */ {}

//        [[nodiscard]] double radius() const { return _radius; }
//
//        void radius(double r) { _radius = r; }

        // We assume world_point is on the sphere.
        // For example it is ray sphere intersection point.
        [[nodiscard]] Vector normal_at(const Point &world_point) const {
            Point object_point = inverse(_transform) * world_point;
            Vector object_normal = object_point /* - mn::point(0.0, 0.0, 0.0) */;
            Vector world_normal = transpose(inverse(_transform)) * object_normal;
            world_normal.w = 0.0;
            world_normal.normalize();
            return world_normal;
        }

//    private:
//        double _radius;
    };

}
#endif //THE_RAY_TRACER_CHALLENGE_SPHERE_H
