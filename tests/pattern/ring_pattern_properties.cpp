//
// Created by ivan on 29.10.2020..
//

#include "pattern/RingPattern.h"

bool a_ring_should_extend_in_both_x_and_z();

int main() {
    if (a_ring_should_extend_in_both_x_and_z()) return 0;
    return 1;
}

bool a_ring_should_extend_in_both_x_and_z() {
    mn::Color black = mn::make_color(0.0, 0.0, 0.0);
    mn::Color white = mn::make_color(1.0, 1.0, 1.0);

    mn::RingPattern pattern(white, black);

    if (pattern.pattern_at(mn::make_point(0.0, 0.0, 0.0)) != white) return false;
    if (pattern.pattern_at(mn::make_point(1.0, 0.0, 0.0)) != black) return false;
    if (pattern.pattern_at(mn::make_point(0.0, 0.0, 1.0)) != black) return false;
    // 0.708 = just slightly more than sqrt(2) / 2
    if (pattern.pattern_at(mn::make_point(0.708, 0.0, 0.708)) != black) return false;

    return true;
}
