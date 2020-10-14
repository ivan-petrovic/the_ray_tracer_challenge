//
// Created by ivan on 12.10.2020..
//
#include "Matrix4x4.h"

// Create 4x4 matrix
int main() {
    mn::Matrix4x4 m{};
    m.set_row_by_row(
            1.0, 2.0, 3.0, 4.0,
            5.5, 6.5, 7.5, 8.5,
            9.0, 10.0, 11.0, 12.0,
            13.5, 14.5, 15.5, 16.5
    );

    if (m.m00 == 1.0 && m.m03 == 4.0 &&
        m.m10 == 5.5 && m.m12 == 7.5 &&
        m.m22 == 11.0 && m.m30 == 13.5 &&
        m.m32 == 15.5
    ) return 0;

    return 1;
}
