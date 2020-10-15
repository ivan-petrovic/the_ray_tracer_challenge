//
// Created by ivan on 14.10.2020..
//
#include "Tuple.h"
#include "Matrix4x4.h"

bool test_scaling_applied_to_a_point();

bool test_scaling_applied_to_a_vector();

bool test_multiplying_by_the_inverse_of_a_scaling_matrix();

bool test_reflection_is_scaling_by_a_negative_value();


int main() {
    if (
            test_scaling_applied_to_a_point() &&
            test_scaling_applied_to_a_vector() &&
            test_multiplying_by_the_inverse_of_a_scaling_matrix() &&
            test_reflection_is_scaling_by_a_negative_value()
            )
        return 0;

    return 1;
}

bool test_scaling_applied_to_a_point() {
    mn::Matrix4x4 M = mn::scaling(2.0, 3.0, 4.0);
    mn::Point p = mn::point(-4.0, 6.0, 8.0);
    mn::Point expected = mn::point(-8.0, 18.0, 32.0);

    return M * p == expected;
}

bool test_scaling_applied_to_a_vector() {
    mn::Matrix4x4 M = mn::scaling(2.0, 3.0, 4.0);
    mn::Vector v = mn::vector(-4.0, 6.0, 8.0);
    mn::Vector expected = mn::vector(-8.0, 18.0, 32.0);

    return M * v == expected;
}

bool test_multiplying_by_the_inverse_of_a_scaling_matrix() {
    mn::Matrix4x4 M = mn::scaling(2.0, 3.0, 4.0);
    mn::Vector v = mn::vector(-4.0, 6.0, 8.0);
    mn::Vector expected = mn::vector(-2.0, 2.0, 2.0);

    return mn::inverse(M) * v == expected;
}

bool test_reflection_is_scaling_by_a_negative_value() {
    mn::Matrix4x4 M = mn::scaling(-1.0, 1.0, 1.0);
    mn::Vector p = mn::point(2.0, 3.0, 4.0);
    mn::Vector expected = mn::point(-2.0, 3.0, 4.0);

    return M * p == expected;
}
