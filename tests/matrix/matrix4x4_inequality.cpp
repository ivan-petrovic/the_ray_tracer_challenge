//
// Created by ivan on 12.10.2020..
//
#include "Matrix4x4.h"

// Test 4x4 matrix equality
int main() {
    mn::Matrix4x4 m1{}, m2{};
    m1.set_row_by_row(
            1.0, 2.0, 3.0, 4.0,
            5.0, 6.0, 7.0, 8.0,
            9.0, 8.0, 7.0, 6.0,
            5.0, 4.0, 3.0, 2.0
    );
    m2.set_row_by_row(
            2.0, 3.0, 4.0, 5.0,
            6.0, 7.0, 8.0, 9.0,
            8.0, 7.0, 6.0, 5.0,
            4.0, 3.0, 2.0, 1.0
    );

    if (m1 != m2) return 0;
    return 1;
}
