//
// Created by ivan on 12.10.2020..
//
#include "Matrix4x4.h"

bool test_multiply_a_matrix_by_identity_matrix();
bool test_multiply_a_identity_matrix_by_a_tuple();

int main() {
    if (test_multiply_a_matrix_by_identity_matrix() && test_multiply_a_identity_matrix_by_a_tuple()) return 0;
    return 1;
}

bool test_multiply_a_matrix_by_identity_matrix() {
    mn::Matrix4x4 A{};
    A.set_row_by_row(
            0.0f, 1.0f, 2.0f, 4.0f,
            1.0f, 2.0f, 4.0f, 8.0f,
            2.0f, 4.0f, 8.0f, 16.0f,
            4.0f, 8.0f, 16.0f, 32.0f
    );

    return (A * mn::identity()) == A;
}

bool test_multiply_a_identity_matrix_by_a_tuple() {
    mn::Matrix4x4 I{};
    I.identity();
    mn::Tuple p{1.0, 2.0, 3.0, 4.0};

    return (I * p) == p;
}
