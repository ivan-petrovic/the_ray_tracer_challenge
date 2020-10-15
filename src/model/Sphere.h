//
// Created by ivan on 15.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_SPHERE_H
#define THE_RAY_TRACER_CHALLENGE_SPHERE_H

#include "Tuple.h"
// #include "Matrix4x4.h"
// #include "Material.h"

namespace mn {

    class Sphere {
    public:
        Sphere() : _origin(point(0.0, 0.0, 0.0)), _radius(1.0) { /* transform.identity(); */ }

        [[nodiscard]] Point origin() const { return _origin; }

        void origin(const Point &p) { _origin = p; }

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
        Point _origin;
        double _radius;
//        Matrix4x4 transform;
//        Material material;

    };

}
#endif //THE_RAY_TRACER_CHALLENGE_SPHERE_H
