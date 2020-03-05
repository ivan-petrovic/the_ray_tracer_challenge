#ifndef __POINT_LIGHT_H_INCLUDED__
#define __POINT_LIGHT_H_INCLUDED__

#include "Vector4.h"
#include "Color.h"

class PointLight {
public:
    Vector4 position;
    Color intensity;

    PointLight(Vector4 position_, Color intensity_) : position(position_), intensity(intensity_) {}
};

#endif // __POINT_LIGHT_H_INCLUDED__
