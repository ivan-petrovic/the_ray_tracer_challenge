#include <stdexcept>
#include "m2x2.h"

M2x2::M2x2() {
    set_by_row(
        0, 0,
        0, 0
    );
}

void M2x2::set_by_row(
    float m00, float m01,
    float m10, float m11
) {
    _m00 = m00; _m01 = m01;
    _m10 = m10; _m11 = m11;
}

float M2x2::get(int row, int col) const {
    switch (row) {
        case 0: switch (col) {
            case 0: return _m00;
            case 1: return _m01;
        }
        case 1: switch (col) {
            case 0: return _m10;
            case 1: return _m11;
        }
    }
    throw std::invalid_argument( "M2x2::get index out of bounds" );
}
