#ifndef __MATERIAL_H_INCLUDED__
#define __MATERIAL_H_INCLUDED__

#include "Color.h"

class Material {
public:
    Color color;
    float ambient, diffuse, specular, shininess;

    Material() : 
        color(Color(1.0f, 1.0f, 1.0f)), ambient(0.1f),
        diffuse(0.9f), specular(0.9f), shininess(200.0f) {}
};

#endif // __MATERIAL_H_INCLUDED__
