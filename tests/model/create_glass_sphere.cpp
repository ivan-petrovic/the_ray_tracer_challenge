//
// Created by ivan on 22.10.2020..
//
#include "model/Sphere.h"

bool create_glass_sphere();

int main() {
    if (create_glass_sphere()) return 0;
    return 1;
}

bool create_glass_sphere() {
    auto sphere = mn::make_glass_sphere();

    if (sphere->transform() != mn::identity()) return false;
    if (sphere->material().transparency() != 1.0) return false;
    if (sphere->material().refractive_index() != 1.5) return false;

    return true;
}
