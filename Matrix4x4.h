#ifndef __MATRIX4X4_INCLUDED__
#define __MATRIX4X4_INCLUDED__

// #include "Vector4.h"
class Vector4;
class Matrix3x3;

class Matrix4x4 {
public:

// Public data
    
    // I have choosen 0 based index, to match book's decision
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;

// Public operations

    void set_row_by_row(
        float m00_, float m01_, float m02_, float m03_,
        float m10_, float m11_, float m12_, float m13_,
        float m20_, float m21_, float m22_, float m23_,
        float m30_, float m31_, float m32_, float m33_
    );

    // Check equality
    bool operator ==(const Matrix4x4 &a) const;
    bool operator !=(const Matrix4x4 &a) const;
    
    // Set to identity
    void identity();
};

// Operator* is used to concatenate (multiply) matrices,
// and to transform a point.

Matrix4x4 operator*(const Matrix4x4 &a, const Matrix4x4 &b);
Vector4 operator*(const Matrix4x4 &m, const Vector4 &p);

// Operator *= for conformace to C++ standards

Matrix4x4 &operator*=(Matrix4x4 &a, const Matrix4x4 &b);
Vector4 &operator*=(const Matrix4x4 &m, Vector4 &p);

// Compute the transpose of a matrix

Matrix4x4 transpose(const Matrix4x4 &m);

// Compute the determinant of the 4x4 portion of the matrix
float determinant(const Matrix4x4 &m);

Matrix3x3 submatrix(const Matrix4x4 &m, int row, int col);

float cofactor(const Matrix4x4 &m, int row, int col);

Matrix4x4 inverse(const Matrix4x4 &m);

Matrix4x4 translation(float dx, float dy, float dz);

Matrix4x4 scaling(float sx, float sy, float sz);

#endif // __MATRIX4X4_INCLUDED__
