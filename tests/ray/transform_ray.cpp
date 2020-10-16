//
// Created by ivan on 16.10.2020..
//
#include "Ray.h"
#include "Matrix4x4.h"

bool translating_a_ray();

bool scaling_a_ray();

int main() {
    if (translating_a_ray() && scaling_a_ray()) return 0;
    return 1;
}

bool translating_a_ray() {
    mn::Ray ray(mn::point(1.0, 2.0, 3.0), mn::vector(0.0, 1.0, 0.0));
    mn::Matrix4x4 T = mn::translation(3.0, 4.0, 5.0);

    mn::Ray result = mn::transform(ray, T);

    if (result.origin() != mn::point(4.0, 6.0, 8.0)) return false;
    if (result.direction() != mn::vector(0.0, 1.0, 0.0)) return false;

    return true;
}

bool scaling_a_ray() {
    mn::Ray ray(mn::point(1.0, 2.0, 3.0), mn::vector(0.0, 1.0, 0.0));
    mn::Matrix4x4 S = mn::scaling(2.0, 3.0, 4.0);

    mn::Ray result = mn::transform(ray, S);

    if (result.origin() != mn::point(2.0, 6.0, 12.0)) return false;
    if (result.direction() != mn::vector(0.0, 3.0, 0.0)) return false;

    return true;
}

