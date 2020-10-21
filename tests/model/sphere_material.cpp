//
// Created by ivan on 18.10.2020..
//
#include "model/Sphere.h"
#include "Material.h"

bool sphere_has_a_default_material();

bool sphere_can_be_assigned_a_material();

int main() {
    if (
            sphere_has_a_default_material() &&
            sphere_can_be_assigned_a_material())
        return 0;
    return 1;
}

bool sphere_has_a_default_material() {
    mn::Sphere sphere;
    mn::Material material{};
    mn::make_default_material(material);

    return sphere.material() == material;
}

bool sphere_can_be_assigned_a_material() {
    mn::Sphere sphere;
    mn::Material material{};
    mn::make_default_material(material);
    material.ambient(1.0);

    // sphere.material(material);
    sphere.material().ambient(1.0);

    return sphere.material() == material;
}
