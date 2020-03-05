#ifndef __SPHERE_H_INCLUDED__
#define __SPHERE_H_INCLUDED__

#include "Vector4.h"
#include "Matrix4x4.h"
#include "Material.h"

class Sphere {
public:
    Vector4 origin;
    float radius;
    Matrix4x4 transform;
    Material material;

    Sphere() : origin(make_point(0.0f, 0.0f, 0.0f)), radius(1.0f) { transform.identity(); }
    Vector4 normal_at(Vector4 world_point) {
        Vector4 object_point = inverse(transform) * world_point;
        Vector4 object_normal = object_point - make_point(0.0f, 0.0f, 0.0f);
        Vector4 world_normal = transpose(inverse(transform)) * object_normal;
        world_normal.w = 0.0f;
        world_normal.normalize();
        return world_normal;
    }
};

#endif // __SPHERE_H_INCLUDED__
