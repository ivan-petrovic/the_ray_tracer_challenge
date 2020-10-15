//
// Created by ivan on 15.10.2020..
//
#include "math_util.h"
#include "Tuple.h"
#include "Matrix4x4.h"

bool test_rotating_a_point_around_x_axis();

bool test_inverse_of_a_x_rotation_rotates_in_the_opposite_direction();

bool test_rotating_a_point_around_y_axis();

bool test_rotating_a_point_around_z_axis();

int main() {
    if (
            test_rotating_a_point_around_x_axis() &&
            test_inverse_of_a_x_rotation_rotates_in_the_opposite_direction() &&
            test_rotating_a_point_around_y_axis() &&
            test_rotating_a_point_around_z_axis()
            )
        return 0;

    return 1;
}

bool test_rotating_a_point_around_x_axis() {
    mn::Matrix4x4 half_quarter = mn::rotation_x(mn::deg_to_rad(45.0));
    mn::Matrix4x4 full_quarter = mn::rotation_x(mn::deg_to_rad(90.0));
    mn::Point p = mn::point(0.0, 1.0, 0.0);

    double HALF_SQRT_OF_2 = std::sqrt(2) / 2;

    if (!mn::epsilon_equal(half_quarter * p, mn::point(0.0, HALF_SQRT_OF_2, HALF_SQRT_OF_2))) return false;
    if (!mn::epsilon_equal(full_quarter * p, mn::point(0.0, 0.0, 1.0))) return false;

    return true;
}

bool test_inverse_of_a_x_rotation_rotates_in_the_opposite_direction() {
    mn::Matrix4x4 half_quarter = mn::rotation_x(mn::deg_to_rad(45.0));
    mn::Point p = mn::point(0.0, 1.0, 0.0);

    double HALF_SQRT_OF_2 = std::sqrt(2) / 2;;

    if (!mn::epsilon_equal(mn::inverse(half_quarter) * p, mn::point(0.0, HALF_SQRT_OF_2, -HALF_SQRT_OF_2)))
        return false;
    return true;
}

bool test_rotating_a_point_around_y_axis() {
    mn::Matrix4x4 half_quarter = mn::rotation_y(mn::deg_to_rad(45.0));
    mn::Matrix4x4 full_quarter = mn::rotation_y(mn::deg_to_rad(90.0));
    mn::Point p = mn::point(0.0, 0.0, 1.0);

    double HALF_SQRT_OF_2 = std::sqrt(2) / 2;;

    if (!mn::epsilon_equal(half_quarter * p, mn::point(HALF_SQRT_OF_2, 0.0, HALF_SQRT_OF_2))) return false;
    if (!mn::epsilon_equal(full_quarter * p, mn::point(1.0, 0.0, 0.0))) return false;

    return true;
}

bool test_rotating_a_point_around_z_axis() {
    mn::Matrix4x4 half_quarter = mn::rotation_z(mn::deg_to_rad(45.0));
    mn::Matrix4x4 full_quarter = mn::rotation_z(mn::deg_to_rad(90.0));
    mn::Point p = mn::point(0.0, 1.0, 0.0);

    double HALF_SQRT_OF_2 = std::sqrt(2) / 2;;

    if (!mn::epsilon_equal(half_quarter * p, mn::point(-HALF_SQRT_OF_2, HALF_SQRT_OF_2, 0.0))) return false;
    if (!mn::epsilon_equal(full_quarter * p, mn::point(-1.0, 0.0, 0.0))) return false;

    return true;
}
