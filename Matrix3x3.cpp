#include "Matrix3x3.h"


void Matrix3x3::set_row_by_row(
    float m00_, float m01_, float m02_,
    float m10_, float m11_, float m12_,
    float m20_, float m21_, float m22_
) {
    m00 = m00_; m01 = m01_; m02 = m02_;
    m10 = m10_; m11 = m11_; m12 = m12_;
    m20 = m20_; m21 = m21_; m22 = m22_;
}
