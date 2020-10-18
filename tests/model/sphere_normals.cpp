//
// Created by ivan on 18.10.2020..
//
#include "model/Sphere.h"

bool normal_on_a_sphere_at_a_point_on_the_x_axis();

bool normal_on_a_sphere_at_a_point_on_the_y_axis();

bool normal_on_a_sphere_at_a_point_on_the_z_axis();

bool normal_on_a_sphere_at_a_non_axial_point();

bool the_normal_is_a_normalized_vector();

bool computing_the_normal_on_a_translated_sphere();

bool computing_the_normal_on_a_transformed_sphere();

int main() {
    if (
            normal_on_a_sphere_at_a_point_on_the_x_axis() &&
            normal_on_a_sphere_at_a_point_on_the_y_axis() &&
            normal_on_a_sphere_at_a_point_on_the_z_axis() &&
            normal_on_a_sphere_at_a_non_axial_point() &&
            the_normal_is_a_normalized_vector() &&
            computing_the_normal_on_a_translated_sphere() &&
            computing_the_normal_on_a_transformed_sphere())
        return 0;
    return 1;
}

bool normal_on_a_sphere_at_a_point_on_the_x_axis() {
    mn::Sphere sphere;
    mn::Vector n = sphere.normal_at(mn::point(1.0, 0.0, 0.0));

    return n == mn::vector(1.0, 0.0, 0.0);
}

bool normal_on_a_sphere_at_a_point_on_the_y_axis() {
    mn::Sphere sphere;
    mn::Vector n = sphere.normal_at(mn::point(0.0, 1.0, 0.0));

    return n == mn::vector(0.0, 1.0, 0.0);
}

bool normal_on_a_sphere_at_a_point_on_the_z_axis() {
    mn::Sphere sphere;
    mn::Vector n = sphere.normal_at(mn::point(0.0, 0.0, 1.0));

    return n == mn::vector(0.0, 0.0, 1.0);
}

bool normal_on_a_sphere_at_a_non_axial_point() {
    mn::Sphere sphere;
    const double sqrt_of_3 = std::sqrt(3.0);
    mn::Vector n = sphere.normal_at(mn::point(sqrt_of_3 / 3, sqrt_of_3 / 3, sqrt_of_3 / 3));

    return n == mn::vector(sqrt_of_3 / 3, sqrt_of_3 / 3, sqrt_of_3 / 3);
}

bool the_normal_is_a_normalized_vector() {
    mn::Sphere sphere;
    const double sqrt_of_3 = std::sqrt(3.0);
    mn::Vector n = sphere.normal_at(mn::point(sqrt_of_3 / 3, sqrt_of_3 / 3, sqrt_of_3 / 3));

    return n == mn::normalize(n);
}

bool computing_the_normal_on_a_translated_sphere() {
    mn::Sphere sphere;
    sphere.transform(mn::translation(0.0, 1.0, 0.0));

    const double half_sqrt_of_2 = std::sqrt(2.0) / 2;
    mn::Vector n = sphere.normal_at(mn::point(0.0, 1.0 + half_sqrt_of_2, -half_sqrt_of_2));

    return mn::epsilon_equal(n, mn::vector(0.0, half_sqrt_of_2, -half_sqrt_of_2));
}

bool computing_the_normal_on_a_transformed_sphere() {
    mn::Sphere sphere;
    sphere.transform(mn::scaling(1.0, 0.5, 1.0) * mn::rotation_z(mn::kPi/5));

    const double half_sqrt_of_2 = std::sqrt(2.0) / 2;
    mn::Vector n = sphere.normal_at(mn::point(0.0, half_sqrt_of_2, -half_sqrt_of_2));

    return mn::epsilon_equal(n, mn::vector(0.0, 0.97014, -0.24254), 0.00001);
}
