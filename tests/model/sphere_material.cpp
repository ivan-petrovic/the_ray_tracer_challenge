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
    mn::Material material;

    if (sphere.material().color() != material.color()) return false;
    if (sphere.material().ambient() != material.ambient()) return false;
    if (sphere.material().diffuse() != material.diffuse()) return false;
    if (sphere.material().specular() != material.specular()) return false;
    if (sphere.material().shininess() != material.shininess()) return false;

    return true;
}

bool sphere_can_be_assigned_a_material() {
    mn::Sphere sphere;
    mn::Material material;
    material.ambient(1.0);

    sphere.material(material);

    if (sphere.material().color() != material.color()) return false;
    if (sphere.material().ambient() != material.ambient()) return false;
    if (sphere.material().diffuse() != material.diffuse()) return false;
    if (sphere.material().specular() != material.specular()) return false;
    if (sphere.material().shininess() != material.shininess()) return false;

    return true;
}
