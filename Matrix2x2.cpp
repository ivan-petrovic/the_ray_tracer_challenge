#include "Matrix2x2.h"


void Matrix2x2::set_row_by_row(
    float m00_, float m01_,
    float m10_, float m11_
) {
    m00 = m00_; m01 = m01_;
    m10 = m10_; m11 = m11_;
}

bool Matrix2x2::operator ==(const Matrix2x2 &a) const {
    return m00 == a.m00 && m01 == a.m01 &&
           m10 == a.m10 && m11 == a.m11;
}

// Compute the determinant of the 4x4 portion of the matrix
float determinant(const Matrix2x2 &m) {
    return m.m00*m.m11 - m.m01*m.m10;
}
