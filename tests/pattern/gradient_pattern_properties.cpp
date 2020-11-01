//
// Created by ivan on 29.10.2020..
//

#include "pattern/GradientPattern.h"

bool a_gradient_linearly_interpolates_between_colors();

int main() {
    if (a_gradient_linearly_interpolates_between_colors()) return 0;
    return 1;
}

bool a_gradient_linearly_interpolates_between_colors() {
    mn::Color black = mn::make_color(0.0, 0.0, 0.0);
    mn::Color white = mn::make_color(1.0, 1.0, 1.0);

    mn::GradientPattern pattern(white, black);

    if (pattern.pattern_at(mn::make_point(0.0, 0.0, 0.0)) != white) return false;
    if (pattern.pattern_at(mn::make_point(0.25, 0.0, 0.0)) != mn::make_color(0.75, 0.75, 0.75)) return false;
    if (pattern.pattern_at(mn::make_point(0.5, 0.0, 0.0)) != mn::make_color(0.5, 0.5, 0.5)) return false;
    if (pattern.pattern_at(mn::make_point(0.75, 0.0, 0.0)) != mn::make_color(0.25, 0.25, 0.25)) return false;

    return true;
}
