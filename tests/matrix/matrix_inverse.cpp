//
// Created by ivan on 14.10.2020..
//
#include "Matrix4x4.h"

bool test_inverse_of_a_matrix_case1();

bool test_inverse_of_a_matrix_case2();

bool test_inverse_of_a_matrix_case3();

bool test_inverse_of_a_matrix_case4();

// Test calculating inverse of 4x4 matrix
int main() {
    if (
            test_inverse_of_a_matrix_case1() &&
            test_inverse_of_a_matrix_case2() &&
            test_inverse_of_a_matrix_case3() &&
            test_inverse_of_a_matrix_case4()
            )
        return 0;
    return 1;
}

bool test_inverse_of_a_matrix_case1() {
    mn::Matrix4x4 M{};
    M.set_row_by_row(
            -5.0, 2.0, 6.0, -8.0,
            1.0, -5.0, 1.0, 8.0,
            7.0, 7.0, -6.0, -7.0,
            1.0, -3.0, 7.0, 4.0
    );

    mn::Matrix4x4 expected{};
    expected.set_row_by_row(
            116.0 / 532.0, 240.0 / 532.0, 128.0 / 532.0, -24.0 / 532.0,
            -430.0 / 532.0, -775.0 / 532.0, -236.0 / 532.0, 277.0 / 532.0,
            -42.0 / 532.0, -119.0 / 532.0, -28.0 / 532.0, 105.0 / 532.0,
            -278.0 / 532.0, -433.0 / 532.0, -160.0 / 532.0, 163.0 / 532.0
    );

    mn::Matrix4x4 actual = inverse(M);

    return actual == expected;
}

bool test_inverse_of_a_matrix_case2() {
    mn::Matrix4x4 M{};
    M.set_row_by_row(
            8.0, -5.0, 9.0, 2.0,
            7.0, 5.0, 6.0, 1.0,
            -6.0, 0.0, 9.0, 6.0,
            -3.0, 0.0, -9.0, -4.0
    );

    mn::Matrix4x4 expected{};
    expected.set_row_by_row(
            -0.15385, -0.15385, -0.28205, -0.53846,
            -0.07692, 0.12308, 0.02564, 0.03077,
            0.35897, 0.35897, 0.43590, 0.92308,
            -0.69231, -0.69231, -0.76923, -1.92308
    );

    mn::Matrix4x4 actual = inverse(M);

    return mn::epsilon_equal(actual, expected, 0.00001);
}


bool test_inverse_of_a_matrix_case3() {
    mn::Matrix4x4 M{};
    M.set_row_by_row(
            9.0, 3.0, 0.0, 9.0,
            -5.0, -2.0, -6.0, -3.0,
            -4.0, 9.0, 6.0, 4.0,
            -7.0, 6.0, 6.0, 2.0
    );

    mn::Matrix4x4 expected{};
    expected.set_row_by_row(
            -0.04074, -0.07778, 0.14444, -0.22222,
            -0.07778, 0.03333, 0.36667, -0.33333,
            -0.02901, -0.14630, -0.10926, 0.12963,
            0.17778, 0.06667, -0.26667, 0.33333
    );

    mn::Matrix4x4 actual = inverse(M);

    return mn::epsilon_equal(actual, expected, 0.00001);
}

bool test_inverse_of_a_matrix_case4() {
    mn::Matrix4x4 A{};
    A.set_row_by_row(
            3.0, -9.0, 7.0, 3.0,
            3.0, -8.0, 2.0, -9.0,
            -4.0, 4.0, 4.0, 1.0,
            -6.0, 5.0, -1.0, 1.0
    );
    mn::Matrix4x4 B{};
    B.set_row_by_row(
            8.0, 2.0, 2.0, 2.0,
            3.0, -1.0, 7.0, 0.0,
            7.0, 0.0, 5.0, 4.0,
            6.0, -2.0, 0.0, 5.0
    );

    mn::Matrix4x4 C = A * B;

    return mn::epsilon_equal(C * inverse(B), A);
}
