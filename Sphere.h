#ifndef __SPHERE_H_INCLUDED__
#define __SPHERE_H_INCLUDED__

#include "Vector4.h"

class Sphere {
public:
    Vector4 origin;
    float radius;

    Sphere() : origin(make_point(0.0f, 0.0f, 0.0f)), radius(1.0f) {}
};

#endif // __SPHERE_H_INCLUDED__
