//
// Created by ivan on 12.10.2020..
//
#include "Matrix4x4.h"

// Test matrix-tuple multiplication
int main() {
    mn::Matrix4x4 A{};
    A.set_row_by_row(
            1.0, 2.0, 3.0, 4.0,
            2.0, 4.0, 4.0, 2.0,
            8.0, 6.0, 4.0, 1.0,
            0.0, 0.0, 0.0, 1.0
    );
    mn::Tuple b(1.0, 2.0, 3.0, 1.0);
    mn::Tuple expected(18.0, 24.0, 33.0, 1.0);

    mn::Tuple actual = A * b;

    if (actual == expected) return 0;
    return 1;
}
