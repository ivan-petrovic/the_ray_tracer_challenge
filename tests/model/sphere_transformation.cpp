//
// Created by ivan on 16.10.2020..
//
#include "model/Sphere.h"
#include "Matrix4x4.h"

bool spheres_default_transformation();
bool changing_a_spheres_transformation();

int main() {
    if (spheres_default_transformation() && changing_a_spheres_transformation()) return 0;
    return 1;
}

bool spheres_default_transformation() {
    mn::Sphere sphere;

    return sphere.transform() == mn::identity();
}

bool changing_a_spheres_transformation() {
    mn::Sphere sphere;
    mn::Matrix4x4 T = mn::translation(2.0, 3.0, 4.0);
    sphere.transform(T);

    return sphere.transform() == T;
}
