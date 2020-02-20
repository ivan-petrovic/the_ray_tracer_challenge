#include "Matrix3x3.h"
#include "Matrix2x2.h"

void Matrix3x3::set_row_by_row(
    float m00_, float m01_, float m02_,
    float m10_, float m11_, float m12_,
    float m20_, float m21_, float m22_
) {
    m00 = m00_; m01 = m01_; m02 = m02_;
    m10 = m10_; m11 = m11_; m12 = m12_;
    m20 = m20_; m21 = m21_; m22 = m22_;
}

bool Matrix3x3::operator ==(const Matrix3x3 &a) const {
    return m00 == a.m00 && m01 == a.m01 && m02 == a.m02 &&
           m10 == a.m10 && m11 == a.m11 && m12 == a.m12 &&
           m20 == a.m20 && m21 == a.m21 && m22 == a.m22;
}

// Compute the determinant of the matrix
float determinant(const Matrix3x3 &m) {
    return
        m.m00 * m.m11 * m.m22 +
        m.m01 * m.m12 * m.m20 +
        m.m02 * m.m10 * m.m21 -
        m.m01 * m.m10 * m.m22 -
        m.m00 * m.m12 * m.m21 -
        m.m02 * m.m11 * m.m20;
}


Matrix2x2 submatrix(const Matrix3x3 &m, int row, int col) {
    Matrix2x2 r;

    if(row == 0) {
        if(col == 0) { r.m00 = m.m11; r.m01 = m.m12; r.m10 = m.m21; r.m11 = m.m22; }
        if(col == 1) { r.m00 = m.m10; r.m01 = m.m12; r.m10 = m.m20; r.m11 = m.m22; }
        if(col == 2) { r.m00 = m.m10; r.m01 = m.m11; r.m10 = m.m20; r.m11 = m.m21; }
    }

    if(row == 1) {
        if(col == 0) { r.m00 = m.m01; r.m01 = m.m02; r.m10 = m.m21; r.m11 = m.m22; }
        if(col == 1) { r.m00 = m.m00; r.m01 = m.m02; r.m10 = m.m20; r.m11 = m.m22; }
        if(col == 2) { r.m00 = m.m00; r.m01 = m.m01; r.m10 = m.m20; r.m11 = m.m21; }
    }

    if(row == 2) {
        if(col == 0) { r.m00 = m.m01; r.m01 = m.m02; r.m10 = m.m11; r.m11 = m.m12; }
        if(col == 1) { r.m00 = m.m00; r.m01 = m.m02; r.m10 = m.m10; r.m11 = m.m12; }
        if(col == 2) { r.m00 = m.m00; r.m01 = m.m01; r.m10 = m.m10; r.m11 = m.m11; }
    }

    return r;
}

float minor(const Matrix3x3 &m, int row, int col) {
    return determinant(submatrix(m, row, col));
}

float cofactor(const Matrix3x3 &m, int row, int col) {
    float cofactor_sign = ((row + col) % 2 == 0) ? 1 : -1;
    return cofactor_sign * determinant(submatrix(m, row, col));
}
