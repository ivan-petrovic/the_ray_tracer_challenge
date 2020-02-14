#include <stdexcept>
#include "m3x3.h"

M3x3::M3x3() {
    set_by_row(
        0, 0, 0,
        0, 0, 0,
        0, 0, 0
    );
}

void M3x3::set_by_row(
    float m00, float m01, float m02,
    float m10, float m11, float m12,
    float m20, float m21, float m22
) {
    _m00 = m00; _m01 = m01; _m02 = m02;
    _m10 = m10; _m11 = m11; _m12 = m12;
    _m20 = m20; _m21 = m21; _m22 = m22;
}

float M3x3::get(int row, int col) const {
    switch (row) {
        case 0: switch (col) {
            case 0: return _m00;
            case 1: return _m01;
            case 2: return _m02;
        }
        case 1: switch (col) {
            case 0: return _m10;
            case 1: return _m11;
            case 2: return _m12;
        }
        case 2: switch (col) {
            case 0: return _m20;
            case 1: return _m21;
            case 2: return _m22;
        }
    }
    throw std::invalid_argument( "M3x3::get index out of bounds" );
}
