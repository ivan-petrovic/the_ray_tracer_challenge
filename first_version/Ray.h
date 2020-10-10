#ifndef __RAY_H_INCLUDED__
#define __RAY_H_INCLUDED__

#include "Vector4.h"
#include "Matrix4x4.h"

class Ray {
public:
    Vector4 origin;
    Vector4 direction;

    Ray(Vector4 origin_, Vector4 direction_) : origin(origin_), direction(direction_) {}
    Vector4 position(float t) { return origin + t * direction; }
    Ray transform(const Matrix4x4 & m) const { return Ray(m * origin, m * direction); }
};

#endif // __RAY_H_INCLUDED__
