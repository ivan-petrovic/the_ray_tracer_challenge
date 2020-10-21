//
// Created by ivan on 15.10.2020..
//
#include "Tuple.h"
#include "Matrix4x4.h"

bool test_individual_transformations_applied_in_sequence();

bool test_chained_transformations_must_be_applied_in_reverse_order();

int main() {
    if (
            test_individual_transformations_applied_in_sequence() &&
            test_chained_transformations_must_be_applied_in_reverse_order()
            )
        return 0;

    return 1;
}

bool test_individual_transformations_applied_in_sequence() {
    mn::Matrix4x4 R = mn::rotation_x(mn::deg_to_rad(90.0));
    mn::Matrix4x4 S = mn::scaling(5.0, 5.0, 5.0);
    mn::Matrix4x4 T = mn::translation(10.0, 5.0, 7.0);

    mn::Point p = mn::make_point(1.0, 0.0, 1.0);

    // Apply rotation first
    mn::Point p2 = R * p;
    if (!mn::epsilon_equal(p2, mn::make_point(1.0, -1.0, 0.0))) return false;

    // Then apply scaling
    mn::Point p3 = S * p2;
    if (!mn::epsilon_equal(p3, mn::make_point(5.0, -5.0, 0.0))) return false;

    // Then apply translation
    mn::Point p4 = T * p3;
    if (!mn::epsilon_equal(p4, mn::make_point(15.0, 0.0, 7.0))) return false;

    return true;
}

bool test_chained_transformations_must_be_applied_in_reverse_order() {
    mn::Matrix4x4 R = mn::rotation_x(mn::deg_to_rad(90.0));
    mn::Matrix4x4 T = mn::translation(10.0, 5.0, 7.0);
    mn::Matrix4x4 S = mn::scaling(5.0, 5.0, 5.0);

    mn::Point p = mn::make_point(1.0, 0.0, 1.0);

    mn::Matrix4x4 M = T * S * R;

    if (!mn::epsilon_equal(M * p, mn::make_point(15.0, 0.0, 7.0))) return false;

    return true;
}

