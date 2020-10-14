//
// Created by ivan on 13.10.2020..
//
#include "Matrix4x4.h"

// Test 4x4 matrix determinant
bool test_matrix4x4_determinant();
bool test_matrix_is_invertible();
bool test_matrix_is_not_invertible();

int main() {
    if (test_matrix4x4_determinant() && test_matrix_is_invertible() && test_matrix_is_not_invertible()) return 0;
    return 1;
}

bool test_matrix4x4_determinant() {
    mn::Matrix4x4 M{};
    M.set_row_by_row(
            -2.0, -8.0, 3.0, 5.0,
            -3.0, 1.0, 7.0, 3.0,
            1.0, 2.0, -9.0, 6.0,
            -6.0, 7.0, 7.0, -9.0
    );
    double expected = -4071.0;

    return M.determinant() == expected;
}

bool test_matrix_is_invertible() {
    mn::Matrix4x4 M{};
    M.set_row_by_row(
            6.0, 4.0, 4.0, 4.0,
            5.0, 5.0, 7.0, 6.0,
            4.0, -9.0, 3.0, -7.0,
            9.0, 1.0, 7.0, -6.0
    );
    double expected = -2120.0;

    // determinant != 0 means that a matrix is invertible
    return mn::determinant(M) == expected;
}

bool test_matrix_is_not_invertible() {
    mn::Matrix4x4 M{};
    M.set_row_by_row(
            -4.0, 2.0, -2.0, -3.0,
            9.0, 6.0, 2.0, 6.0,
            0.0, -5.0, 1.0, -5.0,
            0.0, 0.0, 0.0, 0.0
    );

    // determinant == 0 means that a matrix is not invertible
    return mn::determinant(M) == 0.0;
}
