//
// Created by ivan on 13.10.2020..
//
#include "Matrix4x4.h"

// Test transposing 4x4 matrix
bool test_transposing_a_matrix();
bool test_transposing_the_identity_matrix();

int main() {
    if (test_transposing_a_matrix() && test_transposing_the_identity_matrix()) return 0;
    return 1;
}

bool test_transposing_a_matrix() {
    mn::Matrix4x4 A{}, expected{};
    A.set_row_by_row(
            0.0, 9.0, 3.0, 0.0,
            9.0, 8.0, 0.0, 8.0,
            1.0, 8.0, 5.0, 3.0,
            0.0, 0.0, 5.0, 8.0
    );
    expected.set_row_by_row(
            0.0, 9.0, 1.0, 0.0,
            9.0, 8.0, 8.0, 0.0,
            3.0, 0.0, 5.0, 5.0,
            0.0, 8.0, 3.0, 8.0
    );

    return mn::transpose(A) == expected;
}

bool test_transposing_the_identity_matrix() {
    mn::Matrix4x4 I{};
    I.identity();

    return mn::transpose(I) == I;
}
