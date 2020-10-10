//
// Created by ivan on 5.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_RTC_H
#define THE_RAY_TRACER_CHALLENGE_RTC_H

#include "Tuple.h"

namespace mn {

    bool is_point(Tuple &t);

    bool is_not_point(Tuple &t);

    bool is_vector(Tuple &t);

    bool is_not_vector(Tuple &t);

    Tuple point(double x, double y, double z);

    Tuple vector(double x, double y, double z);

    Tuple color(double r, double g, double b, double a = 0.0);

    Tuple zero();

    bool epsilon_equal(double a, double b);

    bool epsilon_equal(const Tuple &a, const Tuple &b);

}

#endif //THE_RAY_TRACER_CHALLENGE_RTC_H
