//
// Created by ivan on 18.10.2020..
//
#include "TestObject.h"
#include "Material.h"

bool the_default_material();

bool assigning_a_material();

int main() {
    if (the_default_material() && assigning_a_material()) return 0;
    return 1;
}

bool the_default_material() {
    mn::TestObject object;
    mn::Material material{};
    mn::make_default_material(material);

    return object.material() == material;
}

bool assigning_a_material() {
    mn::TestObject object;
    mn::Material material{};
    mn::make_default_material(material);
    material.ambient(1.0);

    object.material(material);

    return object.material() == material;
}
