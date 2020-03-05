#ifndef __LIGHTING_H_INCLUDED__
#define __LIGHTING_H_INCLUDED__

#include "Vector4.h"
#include "Color.h"
#include "Material.h"
#include "PointLight.h"

Color lighting(
    const Material &material,
    const PointLight &light,
    const Vector4 &position,
    const Vector4 &eyev,
    const Vector4 &normalv
);

#endif // __LIGHTING_H_INCLUDED__
