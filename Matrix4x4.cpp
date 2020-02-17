#include "Matrix4x4.h"
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

bool Matrix4x4::operator ==(const Matrix4x4 &a) const {
    return m00 == a.m00 && m01 == a.m01 && m02 == a.m02 && m03 == a.m03 &&
           m10 == a.m10 && m11 == a.m11 && m12 == a.m12 && m13 == a.m13 &&
           m20 == a.m20 && m21 == a.m21 && m22 == a.m22 && m23 == a.m23 &&
           m30 == a.m30 && m31 == a.m31 && m32 == a.m32 && m33 == a.m33;
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
    return 0;
}

