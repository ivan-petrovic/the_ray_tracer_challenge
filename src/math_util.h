//
// Created by ivan on 6.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_MATH_UTIL_H
#define THE_RAY_TRACER_CHALLENGE_MATH_UTIL_H

#include <cmath>

namespace mn {

    // Pi related constants
    inline constexpr double kPi{3.14159265};
    inline constexpr double k2Pi = kPi * 2.0;
    inline constexpr double kPiOver2 = kPi / 2.0;
    inline constexpr double k1OverPi = 1.0 / kPi;
    inline constexpr double k1Over2Pi = 1.0 / k2Pi;
    inline constexpr double kPiOver180 = kPi / 180.0;
    inline constexpr double k180OverPi = 180.0 / kPi;

    inline constexpr double kEpsilon{0.000001};
    inline constexpr double kInfinity{1e10};

    inline bool epsilon_equal(double a, double b, double e = kEpsilon) { return std::abs(a - b) < e; }

    // Convert between degrees and radians
    inline double deg_to_rad(double deg) { return deg * kPiOver180; }
    inline double rad_to_deg(double rad) { return rad * k180OverPi; }

}
#endif //THE_RAY_TRACER_CHALLENGE_MATH_UTIL_H
