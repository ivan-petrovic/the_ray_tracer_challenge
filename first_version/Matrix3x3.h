#ifndef __MATRIX3X3_INCLUDED__
#define __MATRIX3X3_INCLUDED__

class Matrix2x2;

class Matrix3x3 {
public:
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;

    void set_row_by_row(
        float m00_, float m01_, float m02_,
        float m10_, float m11_, float m12_,
        float m20_, float m21_, float m22_
    );

    // Check equality
    bool operator ==(const Matrix3x3 &a) const;
};

// Compute the determinant of the matrix
float determinant(const Matrix3x3 &m);

Matrix2x2 submatrix(const Matrix3x3 &m, int row, int col);

float minor(const Matrix3x3 &m, int row, int col);

float cofactor(const Matrix3x3 &m, int row, int col);

#endif // __MATRIX3X3_INCLUDED__
