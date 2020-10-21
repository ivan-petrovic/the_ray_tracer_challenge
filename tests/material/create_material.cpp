//
// Created by ivan on 18.10.2020..
//
#include "Material.h"

bool the_default_material();

int main() {
    if (the_default_material()) return 0;
    return 1;
}

bool the_default_material() {
    mn::Material material{};
    mn::make_default_material(material);

    if (material.color() != mn::make_color(1.0, 1.0, 1.0)) return false;
    if (material.ambient() != 0.1) return false;
    if (material.diffuse() != 0.9) return false;
    if (material.specular() != 0.9) return false;
    if (material.shininess() != 200.0) return false;

    return true;
}
