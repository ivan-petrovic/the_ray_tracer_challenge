#include <stdexcept>
#include "m4x4.h"
#include "Vector4.h"

M4x4::M4x4() {
    set_by_row(
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0
    );
}

void M4x4::set_by_row(
    float m00, float m01, float m02, float m03,
    float m10, float m11, float m12, float m13,
    float m20, float m21, float m22, float m23,
    float m30, float m31, float m32, float m33
) {
    _m00 = m00; _m01 = m01; _m02 = m02; _m03 = m03;
    _m10 = m10; _m11 = m11; _m12 = m12; _m13 = m13;
    _m20 = m20; _m21 = m21; _m22 = m22; _m23 = m23;
    _m30 = m30; _m31 = m31; _m32 = m32; _m33 = m33;
}

float M4x4::get(int row, int col) const {
    switch (row) {
        case 0: switch (col) {
            case 0: return _m00;
            case 1: return _m01;
            case 2: return _m02;
            case 3: return _m03;
        }
        case 1: switch (col) {
            case 0: return _m10;
            case 1: return _m11;
            case 2: return _m12;
            case 3: return _m13;
        }
        case 2: switch (col) {
            case 0: return _m20;
            case 1: return _m21;
            case 2: return _m22;
            case 3: return _m23;
        }
        case 3: switch (col) {
            case 0: return _m30;
            case 1: return _m31;
            case 2: return _m32;
            case 3: return _m33;
        }
    }
    throw std::invalid_argument( "M4x4::get index out of bounds" );
}

void M4x4::set(int row, int col, float value) {
    switch (row) {
        case 0: switch (col) {
            case 0: _m00 = value; return;
            case 1: _m01 = value; return;
            case 2: _m02 = value; return;
            case 3: _m03 = value; return;
        }
        case 1: switch (col) {
            case 0: _m10 = value; return;
            case 1: _m11 = value; return;
            case 2: _m12 = value; return;
            case 3: _m13 = value; return;
        }
        case 2: switch (col) {
            case 0: _m20 = value; return;
            case 1: _m21 = value; return;
            case 2: _m22 = value; return;
            case 3: _m23 = value; return;
        }
        case 3: switch (col) {
            case 0: _m30 = value; return;
            case 1: _m31 = value; return;
            case 2: _m32 = value; return;
            case 3: _m33 = value; return;
        }
    }
    throw std::invalid_argument( "M4x4::set index out of bounds" );    
}

bool M4x4::equal(const M4x4 & other) const {
    return
        _m00 == other._m00 &&
        _m01 == other._m01 &&
        _m02 == other._m02 &&
        _m03 == other._m03 &&

        _m10 == other._m10 &&
        _m11 == other._m11 &&
        _m12 == other._m12 &&
        _m13 == other._m13 &&

        _m20 == other._m20 &&
        _m21 == other._m21 &&
        _m22 == other._m22 &&
        _m23 == other._m23 &&

        _m30 == other._m30 &&
        _m31 == other._m31 &&
        _m32 == other._m32 &&
        _m33 == other._m33;
}

M4x4 M4x4::multiply(const M4x4 & other) const {
    M4x4 result;

    for (int row = 0; row <= 3; row += 1) {
        for (int col = 0; col <= 3; col += 1) {
            float value =
                (*this).get(row, 0) * other.get(0, col) +
                (*this).get(row, 1) * other.get(1, col) +
                (*this).get(row, 2) * other.get(2, col) +
                (*this).get(row, 3) * other.get(3, col);
            result.set(row, col, value);
        }
    }

    return result;
}

Vector4 M4x4::multiply(const Vector4 & other) const {
    Vector4 result(
        (*this).get(0, 0) * other.x +
        (*this).get(0, 1) * other.y +
        (*this).get(0, 2) * other.z +
        (*this).get(0, 3) * other.w,
        
        (*this).get(1, 0) * other.x +
        (*this).get(1, 1) * other.y +
        (*this).get(1, 2) * other.z +
        (*this).get(1, 3) * other.w,
        
        (*this).get(2, 0) * other.x +
        (*this).get(2, 1) * other.y +
        (*this).get(2, 2) * other.z +
        (*this).get(2, 3) * other.w,
        
        (*this).get(3, 0) * other.x +
        (*this).get(3, 1) * other.y +
        (*this).get(3, 2) * other.z +
        (*this).get(3, 3) * other.w
    );

    return result;
}
