//
// Created by ivan on 5.10.2020..
//
#include <cmath>
#include "rtc.h"
#include "constants.h"

namespace mn {

    bool is_point(Tuple &t) {
        return t.w == 1.0;
    }

    bool is_not_point(Tuple &t) {
        return t.w != 1.0;
    }

    bool is_vector(Tuple &t) {
        return t.w == 0.0;
    }

    bool is_not_vector(Tuple &t) {
        return t.w != 0.0;
    }

    // Factory method for making points
    Tuple point(double x, double y, double z) {
        return Tuple(x, y, z, 1.0);
    }

    // Factory method for making vectors
    Tuple vector(double x, double y, double z) {
        return Tuple(x, y, z, 0.0);
    }

    // Zero vector
    Tuple zero() {
        return Tuple(0.0, 0.0, 0.0, 0.0);
    }

    // Factory method for making colors
    Tuple color(double red, double green, double blue, double alpha) {
        return Tuple(red, green, blue, alpha);
    }

    bool epsilon_equal(double a, double b) {
        return std::abs(a - b) < epsilon;
    }

    bool epsilon_equal(const Tuple &a, const Tuple &b) {
        bool rez =
                (std::abs(a.x - b.x) < epsilon) &&
                (std::abs(a.y - b.y) < epsilon) &&
                (std::abs(a.z - b.z) < epsilon) &&
                (std::abs(a.w - b.w) < epsilon);
        return rez;
    }

//    bool operator !=(const Vector4 &a) const {
//        const float EPSILON = 0.0001f;
//        return (abs(x - a.x) > EPSILON) || (abs(y - a.y) > EPSILON) || (abs(z - a.z) > EPSILON);
//    }

}
