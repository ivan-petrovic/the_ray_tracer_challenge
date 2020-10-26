//
// Created by ivan on 18.10.2020..
//
#include "model/Sphere.h"

bool normal_on_a_sphere_at_a_point_on_the_x_axis();

bool normal_on_a_sphere_at_a_point_on_the_y_axis();

bool normal_on_a_sphere_at_a_point_on_the_z_axis();

bool normal_on_a_sphere_at_a_non_axial_point();

bool the_normal_is_a_normalized_vector();

int main() {
    if (
            normal_on_a_sphere_at_a_point_on_the_x_axis() &&
            normal_on_a_sphere_at_a_point_on_the_y_axis() &&
            normal_on_a_sphere_at_a_point_on_the_z_axis() &&
            normal_on_a_sphere_at_a_non_axial_point() &&
            the_normal_is_a_normalized_vector()
            )
        return 0;
    return 1;
}

bool normal_on_a_sphere_at_a_point_on_the_x_axis() {
    mn::Sphere sphere;
    mn::Vector n = sphere.local_normal_at(mn::make_point(1.0, 0.0, 0.0));

    return n == mn::make_vector(1.0, 0.0, 0.0);
}

bool normal_on_a_sphere_at_a_point_on_the_y_axis() {
    mn::Sphere sphere;
    mn::Vector n = sphere.local_normal_at(mn::make_point(0.0, 1.0, 0.0));

    return n == mn::make_vector(0.0, 1.0, 0.0);
}

bool normal_on_a_sphere_at_a_point_on_the_z_axis() {
    mn::Sphere sphere;
    mn::Vector n = sphere.local_normal_at(mn::make_point(0.0, 0.0, 1.0));

    return n == mn::make_vector(0.0, 0.0, 1.0);
}

bool normal_on_a_sphere_at_a_non_axial_point() {
    mn::Sphere sphere;
    const double sqrt_of_3 = std::sqrt(3.0);
    mn::Vector n = sphere.local_normal_at(mn::make_point(sqrt_of_3 / 3, sqrt_of_3 / 3, sqrt_of_3 / 3));

    return n == mn::make_vector(sqrt_of_3 / 3, sqrt_of_3 / 3, sqrt_of_3 / 3);
}

bool the_normal_is_a_normalized_vector() {
    mn::Sphere sphere;
    const double sqrt_of_3 = std::sqrt(3.0);
    mn::Vector n = sphere.local_normal_at(mn::make_point(sqrt_of_3 / 3, sqrt_of_3 / 3, sqrt_of_3 / 3));

    return n == mn::normalize(n);
}
