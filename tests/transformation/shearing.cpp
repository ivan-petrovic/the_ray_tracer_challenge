//
// Created by ivan on 14.10.2020..
//
#include "Tuple.h"
#include "Matrix4x4.h"

bool test_shearing_moves_x_in_proportions_to_y();

bool test_shearing_moves_x_in_proportions_to_z();

bool test_shearing_moves_y_in_proportions_to_x();

bool test_shearing_moves_y_in_proportions_to_z();

bool test_shearing_moves_z_in_proportions_to_x();

bool test_shearing_moves_z_in_proportions_to_y();

int main() {
    if (
            test_shearing_moves_x_in_proportions_to_y() &&
            test_shearing_moves_x_in_proportions_to_z() &&
            test_shearing_moves_y_in_proportions_to_x() &&
            test_shearing_moves_y_in_proportions_to_z() &&
            test_shearing_moves_z_in_proportions_to_x() &&
            test_shearing_moves_z_in_proportions_to_y()
            )
        return 0;

    return 1;
}

bool test_shearing_moves_x_in_proportions_to_y() {
    mn::Matrix4x4 M = mn::shearing(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    mn::Point p = mn::make_point(2.0f, 3.0f, 4.0f);

    return M * p == mn::make_point(5.0f, 3.0f, 4.0f);
}

bool test_shearing_moves_x_in_proportions_to_z() {
    mn::Matrix4x4 M = mn::shearing(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    mn::Point p = mn::make_point(2.0f, 3.0f, 4.0f);

    return M * p == mn::make_point(6.0f, 3.0f, 4.0f);
}

bool test_shearing_moves_y_in_proportions_to_x() {
    mn::Matrix4x4 M = mn::shearing(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
    mn::Point p = mn::make_point(2.0f, 3.0f, 4.0f);

    return M * p == mn::make_point(2.0f, 5.0f, 4.0f);
}

bool test_shearing_moves_y_in_proportions_to_z() {
    mn::Matrix4x4 M = mn::shearing(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    mn::Point p = mn::make_point(2.0f, 3.0f, 4.0f);

    return M * p == mn::make_point(2.0f, 7.0f, 4.0f);
}

bool test_shearing_moves_z_in_proportions_to_x() {
    mn::Matrix4x4 M = mn::shearing(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    mn::Point p = mn::make_point(2.0f, 3.0f, 4.0f);

    return M * p == mn::make_point(2.0f, 3.0f, 6.0f);
}

bool test_shearing_moves_z_in_proportions_to_y() {
    mn::Matrix4x4 M = mn::shearing(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    mn::Point p = mn::make_point(2.0f, 3.0f, 4.0f);

    return M * p == mn::make_point(2.0f, 3.0f, 7.0f);
}
