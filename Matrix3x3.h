#ifndef __MATRIX3X3_INCLUDED__
#define __MATRIX3X3_INCLUDED__

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
};

#endif // __MATRIX3X3_INCLUDED__
