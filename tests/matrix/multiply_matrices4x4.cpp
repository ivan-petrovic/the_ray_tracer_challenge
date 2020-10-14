//
// Created by ivan on 12.10.2020..
//
#include "Matrix4x4.h"

// Test 4x4 matrices multiplication
int main() {
    mn::Matrix4x4 m1{}, m2{}, expected{};
    m1.set_row_by_row(
            1.0, 2.0, 3.0, 4.0,
            5.0, 6.0, 7.0, 8.0,
            9.0, 8.0, 7.0, 6.0,
            5.0, 4.0, 3.0, 2.0
    );
    m2.set_row_by_row(
            -2.0, 1.0, 2.0, 3.0,
            3.0, 2.0, 1.0, -1.0,
            4.0, 3.0, 6.0, 5.0,
            1.0, 2.0, 7.0, 8.0
    );
    expected.set_row_by_row(
            20.0, 22.0, 50.0, 48.0,
            44.0, 54.0, 114.0, 108.0,
            40.0, 58.0, 110.0, 102.0,
            16.0, 26.0, 46.0, 42.0
    );

    mn::Matrix4x4 actual = m1 * m2;

    if (actual == expected) return 0;
    return 1;
}
