//
// Created by ivan on 14.10.2020..
//
#include "Tuple.h"
#include "Matrix4x4.h"

bool test_multiplying_by_a_translation_matrix();

bool test_multiplying_by_the_inverse_of_a_translation_matrix();

bool test_translation_does_not_affect_vectors();


int main() {
    if (
            test_multiplying_by_a_translation_matrix() &&
            test_multiplying_by_the_inverse_of_a_translation_matrix() &&
            test_translation_does_not_affect_vectors()
            )
        return 0;

    return 1;
}

bool test_multiplying_by_a_translation_matrix() {
    mn::Matrix4x4 T = mn::translation(5.0, -3.0, 2.0);
    mn::Point p = mn::point(-3.0, 4.0, 5.0);
    mn::Point expected = mn::point(2.0, 1.0, 7.0);

    return T * p == expected;
}

bool test_multiplying_by_the_inverse_of_a_translation_matrix() {
    mn::Matrix4x4 T = mn::translation(5.0, -3.0, 2.0);
    mn::Point p = mn::point(-3.0, 4.0, 5.0);
    mn::Point expected = mn::point(-8.0, 7.0, 3.0);

    return (mn::inverse(T) * p) == expected;
}

bool test_translation_does_not_affect_vectors() {
    mn::Matrix4x4 T = mn::translation(5.0, -3.0, 2.0);
    mn::Vector v = mn::vector(-3.0, 4.0, 5.0);

    return (T * v) == v;
}
