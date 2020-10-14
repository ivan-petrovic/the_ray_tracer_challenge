//
// Created by ivan on 6.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_MATH_UTIL_H
#define THE_RAY_TRACER_CHALLENGE_MATH_UTIL_H

#include <cmath>

namespace mn {

    inline constexpr double pi{3.14159};
    inline constexpr double epsilon{0.000001};

    inline bool epsilon_equal(double a, double b, double e = epsilon) { return std::abs(a - b) < e; }

}
#endif //THE_RAY_TRACER_CHALLENGE_MATH_UTIL_H
