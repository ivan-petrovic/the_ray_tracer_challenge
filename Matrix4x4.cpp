#include "Matrix4x4.h"
#include "Matrix3x3.h"
#include "Vector4.h"

void Matrix4x4::set_row_by_row(
    float m00_, float m01_, float m02_, float m03_,
    float m10_, float m11_, float m12_, float m13_,
    float m20_, float m21_, float m22_, float m23_,
    float m30_, float m31_, float m32_, float m33_
){
    m00 = m00_; m01 = m01_; m02 = m02_; m03 = m03_;
    m10 = m10_; m11 = m11_; m12 = m12_; m13 = m13_;
    m20 = m20_; m21 = m21_; m22 = m22_; m23 = m23_;
    m30 = m30_; m31 = m31_; m32 = m32_; m33 = m33_;
}

// bool Matrix4x4::operator ==(const Matrix4x4 &a) const {
//     return m00 == a.m00 && m01 == a.m01 && m02 == a.m02 && m03 == a.m03 &&
//            m10 == a.m10 && m11 == a.m11 && m12 == a.m12 && m13 == a.m13 &&
//            m20 == a.m20 && m21 == a.m21 && m22 == a.m22 && m23 == a.m23 &&
//            m30 == a.m30 && m31 == a.m31 && m32 == a.m32 && m33 == a.m33;
// }

bool Matrix4x4::operator ==(const Matrix4x4 &a) const {
    const float EPSILON = 0.0001f;

    return abs(m00 - a.m00) < EPSILON && abs(m01 - a.m01) < EPSILON && abs(m02 - a.m02) < EPSILON && abs(m03 - a.m03) < EPSILON &&
           abs(m10 - a.m10) < EPSILON && abs(m11 - a.m11) < EPSILON && abs(m12 - a.m12) < EPSILON && abs(m13 - a.m13) < EPSILON &&
           abs(m20 - a.m20) < EPSILON && abs(m21 - a.m21) < EPSILON && abs(m22 - a.m22) < EPSILON && abs(m23 - a.m23) < EPSILON &&
           abs(m30 - a.m30) < EPSILON && abs(m31 - a.m31) < EPSILON && abs(m32 - a.m32) < EPSILON && abs(m33 - a.m33) < EPSILON;
}

bool Matrix4x4::operator !=(const Matrix4x4 &a) const {
    return m00 != a.m00 || m01 != a.m01 || m02 != a.m02 || m03 != a.m03 ||
           m10 != a.m10 || m11 != a.m11 || m12 != a.m12 || m13 != a.m13 ||
           m20 != a.m20 || m21 != a.m21 || m22 != a.m22 || m23 != a.m23 ||
           m30 != a.m30 || m31 != a.m31 || m32 != a.m32 || m33 != a.m33;
}

// Set the matrix to identity

void Matrix4x4::identity() {
    m00 = 1.0f; m01 = 0.0f; m02 = 0.0f; m03 = 0.0f;
    m10 = 0.0f; m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
    m20 = 0.0f; m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
    m30 = 0.0f; m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
}

Matrix4x4 operator*(const Matrix4x4 &a, const Matrix4x4 &b) {
    Matrix4x4 r;

    r.m00 = a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30;
    r.m01 = a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31;
    r.m02 = a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32;
    r.m03 = a.m00*b.m03 + a.m01*b.m13 + a.m02*b.m23 + a.m03*b.m33;

    r.m10 = a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20 + a.m13*b.m30;
    r.m11 = a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31;
    r.m12 = a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22 + a.m13*b.m32;
    r.m13 = a.m10*b.m03 + a.m11*b.m13 + a.m12*b.m23 + a.m13*b.m33;

    r.m20 = a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20 + a.m23*b.m30;
    r.m21 = a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21 + a.m23*b.m31;
    r.m22 = a.m20*b.m02 + a.m21*b.m12 + a.m22*b.m22 + a.m23*b.m32;
    r.m23 = a.m20*b.m03 + a.m21*b.m13 + a.m22*b.m23 + a.m23*b.m33;

    r.m30 = a.m30*b.m00 + a.m31*b.m10 + a.m32*b.m20 + a.m33*b.m30;
    r.m31 = a.m30*b.m01 + a.m31*b.m11 + a.m32*b.m21 + a.m33*b.m31;
    r.m32 = a.m30*b.m02 + a.m31*b.m12 + a.m32*b.m22 + a.m33*b.m32;
    r.m33 = a.m30*b.m03 + a.m31*b.m13 + a.m32*b.m23 + a.m33*b.m33;

    return r;
}

Matrix4x4 &operator*=(Matrix4x4 &a, const Matrix4x4 &b) {
    a = a * b;
    return a;
}

Vector4 operator*(const Matrix4x4 &m, const Vector4 &p) {
    return Vector4(
        m.m00*p.x + m.m01*p.y + m.m02*p.z + m.m03*p.w,
        m.m10*p.x + m.m11*p.y + m.m12*p.z + m.m13*p.w,
        m.m20*p.x + m.m21*p.y + m.m22*p.z + m.m23*p.w,
        m.m30*p.x + m.m31*p.y + m.m32*p.z + m.m33*p.w
    );
}

Vector4 &operator*=(const Matrix4x4 &m, Vector4 &p) {
    p = m * p;
    return p;
}

// Compute the transpose of a matrix:
// turn its rows into columns
Matrix4x4 transpose(const Matrix4x4 &m) {
    Matrix4x4 r;

    r.m00 = m.m00; r.m01 = m.m10; r.m02 = m.m20; r.m03 = m.m30;
    r.m10 = m.m01; r.m11 = m.m11; r.m12 = m.m21; r.m13 = m.m31;
    r.m20 = m.m02; r.m21 = m.m12; r.m22 = m.m22; r.m23 = m.m32;
    r.m30 = m.m03; r.m31 = m.m13; r.m32 = m.m23; r.m33 = m.m33;

    return r;  
}

// Compute the determinant of the 4x4 portion of the matrix
float determinant(const Matrix4x4 &m) {
    return
        m.m00 * cofactor(m,0,0) +
        m.m01 * cofactor(m,0,1) +
        m.m02 * cofactor(m,0,2) +
        m.m03 * cofactor(m,0,3);
}

Matrix3x3 submatrix(const Matrix4x4 &m, int row, int col) {
    Matrix3x3 r;

    if(row == 0) {
        if(col == 0) {
            r.m00 = m.m11; r.m01 = m.m12; r.m02 = m.m13;
            r.m10 = m.m21; r.m11 = m.m22; r.m12 = m.m23;
            r.m20 = m.m31; r.m21 = m.m32; r.m22 = m.m33;
        }
        if(col == 1) {
            r.m00 = m.m10; r.m01 = m.m12; r.m02 = m.m13;
            r.m10 = m.m20; r.m11 = m.m22; r.m12 = m.m23;
            r.m20 = m.m30; r.m21 = m.m32; r.m22 = m.m33;
        }
        if(col == 2) {
            r.m00 = m.m10; r.m01 = m.m11; r.m02 = m.m13;
            r.m10 = m.m20; r.m11 = m.m21; r.m12 = m.m23;
            r.m20 = m.m30; r.m21 = m.m31; r.m22 = m.m33;
        }
        if(col == 3) {
            r.m00 = m.m10; r.m01 = m.m11; r.m02 = m.m12;
            r.m10 = m.m20; r.m11 = m.m21; r.m12 = m.m22;
            r.m20 = m.m30; r.m21 = m.m31; r.m22 = m.m32;
        }
    }

    if(row == 1) {
        if(col == 0) {
            r.m00 = m.m01; r.m01 = m.m02; r.m02 = m.m03;
            r.m10 = m.m21; r.m11 = m.m22; r.m12 = m.m23;
            r.m20 = m.m31; r.m21 = m.m32; r.m22 = m.m33;
        }
        if(col == 1) {
            r.m00 = m.m00; r.m01 = m.m02; r.m02 = m.m03;
            r.m10 = m.m20; r.m11 = m.m22; r.m12 = m.m23;
            r.m20 = m.m30; r.m21 = m.m32; r.m22 = m.m33;
        }
        if(col == 2) {
            r.m00 = m.m00; r.m01 = m.m01; r.m02 = m.m03;
            r.m10 = m.m20; r.m11 = m.m21; r.m12 = m.m23;
            r.m20 = m.m30; r.m21 = m.m31; r.m22 = m.m33;
        }
        if(col == 3) {
            r.m00 = m.m00; r.m01 = m.m01; r.m02 = m.m02;
            r.m10 = m.m20; r.m11 = m.m21; r.m12 = m.m22;
            r.m20 = m.m30; r.m21 = m.m31; r.m22 = m.m32;
        }
    }

    if(row == 2) {
        if(col == 0) {
            r.m00 = m.m01; r.m01 = m.m02; r.m02 = m.m03;
            r.m10 = m.m11; r.m11 = m.m12; r.m12 = m.m13;
            r.m20 = m.m31; r.m21 = m.m32; r.m22 = m.m33;
        }
        if(col == 1) {
            r.m00 = m.m00; r.m01 = m.m02; r.m02 = m.m03;
            r.m10 = m.m10; r.m11 = m.m12; r.m12 = m.m13;
            r.m20 = m.m30; r.m21 = m.m32; r.m22 = m.m33;
        }
        if(col == 2) {
            r.m00 = m.m00; r.m01 = m.m01; r.m02 = m.m03;
            r.m10 = m.m10; r.m11 = m.m11; r.m12 = m.m13;
            r.m20 = m.m30; r.m21 = m.m31; r.m22 = m.m33;
        }
        if(col == 3) {
            r.m00 = m.m00; r.m01 = m.m01; r.m02 = m.m02;
            r.m10 = m.m10; r.m11 = m.m11; r.m12 = m.m12;
            r.m20 = m.m30; r.m21 = m.m31; r.m22 = m.m32;
        }
    }

    if(row == 3) {
        if(col == 0) {
            r.m00 = m.m01; r.m01 = m.m02; r.m02 = m.m03;
            r.m10 = m.m11; r.m11 = m.m12; r.m12 = m.m13;
            r.m20 = m.m21; r.m21 = m.m22; r.m22 = m.m23;
        }
        if(col == 1) {
            r.m00 = m.m00; r.m01 = m.m02; r.m02 = m.m03;
            r.m10 = m.m10; r.m11 = m.m12; r.m12 = m.m13;
            r.m20 = m.m20; r.m21 = m.m22; r.m22 = m.m23;
        }
        if(col == 2) {
            r.m00 = m.m00; r.m01 = m.m01; r.m02 = m.m03;
            r.m10 = m.m10; r.m11 = m.m11; r.m12 = m.m13;
            r.m20 = m.m20; r.m21 = m.m21; r.m22 = m.m23;
        }
        if(col == 3) {
            r.m00 = m.m00; r.m01 = m.m01; r.m02 = m.m02;
            r.m10 = m.m10; r.m11 = m.m11; r.m12 = m.m12;
            r.m20 = m.m20; r.m21 = m.m21; r.m22 = m.m22;
        }
    }

    return r;
}

float cofactor(const Matrix4x4 &m, int row, int col) {
    float cofactor_sign = ((row + col) % 2 == 0) ? 1 : -1;
    return cofactor_sign * determinant(submatrix(m, row, col));
}

Matrix4x4 inverse(const Matrix4x4 &m) {
    Matrix4x4 r;
    float det = determinant(m);

    // r.m00 = cofactor(m,0,0)/det; r.m01 = cofactor(m,0,1)/det; r.m02 = cofactor(m,0,2)/det; r.m03 = cofactor(m,0,3)/det;
    // r.m10 = cofactor(m,1,0)/det; r.m11 = cofactor(m,1,1)/det; r.m12 = cofactor(m,1,2)/det; r.m13 = cofactor(m,1,3)/det;
    // r.m20 = cofactor(m,2,0)/det; r.m21 = cofactor(m,2,1)/det; r.m22 = cofactor(m,2,2)/det; r.m23 = cofactor(m,2,3)/det;
    // r.m30 = cofactor(m,3,0)/det; r.m31 = cofactor(m,3,1)/det; r.m32 = cofactor(m,3,2)/det; r.m33 = cofactor(m,3,3)/det;

    // return transpose(r);

    // transpose while calculating
    r.m00 = cofactor(m,0,0)/det; r.m10 = cofactor(m,0,1)/det; r.m20 = cofactor(m,0,2)/det; r.m30 = cofactor(m,0,3)/det;
    r.m01 = cofactor(m,1,0)/det; r.m11 = cofactor(m,1,1)/det; r.m21 = cofactor(m,1,2)/det; r.m31 = cofactor(m,1,3)/det;
    r.m02 = cofactor(m,2,0)/det; r.m12 = cofactor(m,2,1)/det; r.m22 = cofactor(m,2,2)/det; r.m32 = cofactor(m,2,3)/det;
    r.m03 = cofactor(m,3,0)/det; r.m13 = cofactor(m,3,1)/det; r.m23 = cofactor(m,3,2)/det; r.m33 = cofactor(m,3,3)/det;

    return r;
}

Matrix4x4 translation(float dx, float dy, float dz) {
    Matrix4x4 r;
    r.identity();
    r.m03 = dx;
    r.m13 = dy;
    r.m23 = dz;

    return r;
}

Matrix4x4 scaling(float sx, float sy, float sz) {
    Matrix4x4 r;
    r.identity();
    r.m00 = sx;
    r.m11 = sy;
    r.m22 = sz;

    return r;
}
