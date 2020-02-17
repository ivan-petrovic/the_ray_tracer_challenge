#include "Matrix2x2.h"


void Matrix2x2::set_row_by_row(
    float m00_, float m01_,
    float m10_, float m11_
) {
    m00 = m00_; m01 = m01_;
    m10 = m10_; m11 = m11_;
}

// Compute the determinant of the 4x4 portion of the matrix
float determinant(const Matrix2x2 &m) {
    return m.m00*m.m11 - m.m01*m.m10;
}
