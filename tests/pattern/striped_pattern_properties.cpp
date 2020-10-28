//
// Created by ivan on 27.10.2020..
//

#include "pattern/StripedPattern.h"

bool a_stripe_pattern_is_constant_in_y();

bool a_stripe_pattern_is_constant_in_z();

bool a_stripe_pattern_alternates_in_x();

int main() {
    if (
            a_stripe_pattern_is_constant_in_y() &&
            a_stripe_pattern_is_constant_in_z() &&
            a_stripe_pattern_alternates_in_x()
            )
        return 0;
    return 1;
}

bool a_stripe_pattern_is_constant_in_y() {
    mn::Color black = mn::make_color(0.0, 0.0, 0.0);
    mn::Color white = mn::make_color(1.0, 1.0, 1.0);

    mn::StripedPattern pattern(white, black);

    if (pattern.pattern_at(mn::make_point(0.0, 0.0, 0.0)) != white) return false;
    if (pattern.pattern_at(mn::make_point(0.0, 1.0, 0.0)) != white) return false;
    if (pattern.pattern_at(mn::make_point(0.0, 2.0, 0.0)) != white) return false;
    return true;
}

bool a_stripe_pattern_is_constant_in_z() {
    mn::Color black = mn::make_color(0.0, 0.0, 0.0);
    mn::Color white = mn::make_color(1.0, 1.0, 1.0);

    mn::StripedPattern pattern(white, black);

    if (pattern.pattern_at(mn::make_point(0.0, 0.0, 0.0)) != white) return false;
    if (pattern.pattern_at(mn::make_point(0.0, 0.0, 1.0)) != white) return false;
    if (pattern.pattern_at(mn::make_point(0.0, 0.0, 2.0)) != white) return false;
    return true;
}

bool a_stripe_pattern_alternates_in_x() {
    mn::Color black = mn::make_color(0.0, 0.0, 0.0);
    mn::Color white = mn::make_color(1.0, 1.0, 1.0);

    mn::StripedPattern pattern(white, black);

    if (pattern.pattern_at(mn::make_point(0.0, 0.0, 0.0)) != white) return false;
    if (pattern.pattern_at(mn::make_point(0.9, 0.0, 0.0)) != white) return false;
    if (pattern.pattern_at(mn::make_point(1.0, 0.0, 0.0)) != black) return false;
    if (pattern.pattern_at(mn::make_point(-0.1, 0.0, 0.0)) != black) return false;
    if (pattern.pattern_at(mn::make_point(-1.0, 0.0, 0.0)) != black) return false;
    if (pattern.pattern_at(mn::make_point(-1.1, 0.0, 0.0)) != white) return false;

    return true;
}
