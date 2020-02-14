#ifndef _M4X4_INCLUDE_
#define _M4X4_INCLUDE_

#include "Vector4.h"

class M4x4 {
public:
    M4x4();
    void set_by_row(
        float m00, float m01, float m02, float m03,
        float m10, float m11, float m12, float m13,
        float m20, float m21, float m22, float m23,
        float m30, float m31, float m32, float m33
    );
    float get(int row, int col) const;
    void set(int row, int col, float value);
    bool equal(const M4x4 & other) const;
    M4x4 multiply(const M4x4 & other) const;
    Vector4 multiply(const Vector4 & other) const;
private:
    float
        _m00, _m01, _m02, _m03,
        _m10, _m11, _m12, _m13,
        _m20, _m21, _m22, _m23,
        _m30, _m31, _m32, _m33;
};

#endif // _M4X4_INCLUDE_
