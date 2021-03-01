//
// Created by ivan on 26.10.2020..
//

#include "model/Plane.h"

bool the_normal_of_a_plane_is_constant_everywhere();

int main() {
    if (the_normal_of_a_plane_is_constant_everywhere()) return 0;
    return 1;
}

bool the_normal_of_a_plane_is_constant_everywhere() {
    mn::Plane plane;

    mn::Vector n1 = plane.local_normal_at(mn::make_point(0.0, 0.0, 0.0), {});
    mn::Vector n2 = plane.local_normal_at(mn::make_point(10.0, 0.0, -10.0), {});
    mn::Vector n3 = plane.local_normal_at(mn::make_point(-5.0, 0.0, 150.0), {});

    if (n1 != mn::make_vector(0.0, 1.0, 0.0)) return false;
    if (n2 != mn::make_vector(0.0, 1.0, 0.0)) return false;
    if (n3 != mn::make_vector(0.0, 1.0, 0.0)) return false;

    return true;
}
