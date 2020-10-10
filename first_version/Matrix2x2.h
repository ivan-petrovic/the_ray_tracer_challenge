#ifndef __MATRIX2X2_INCLUDED__
#define __MATRIX2X2_INCLUDED__

class Matrix2x2 {
public:
    float m00, m01;
    float m10, m11;

    void set_row_by_row(
        float m00_, float m01_,
        float m10_, float m11_
    );

    // Check equality
    bool operator ==(const Matrix2x2 &a) const;
};

// Compute the determinant of the matrix
float determinant(const Matrix2x2 &m);

#endif // __MATRIX2X2_INCLUDED__