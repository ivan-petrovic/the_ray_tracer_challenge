//
// Created by ivan on 27.10.2020..
//

#include "pattern/Checker3DPattern.h"

bool checkers_should_repeat_in_x();

bool checkers_should_repeat_in_y();

bool checkers_should_repeat_in_z();

int main() {
    if (
            checkers_should_repeat_in_x() &&
            checkers_should_repeat_in_y() &&
            checkers_should_repeat_in_z()
            )
        return 0;
    return 1;
}

bool checkers_should_repeat_in_x() {
    mn::Color black = mn::make_color(0.0, 0.0, 0.0);
    mn::Color white = mn::make_color(1.0, 1.0, 1.0);

    mn::Checker3DPattern pattern(white, black);

    if (pattern.pattern_at(mn::make_point(0.0, 0.0, 0.0)) != white) return false;
    if (pattern.pattern_at(mn::make_point(0.99, 0.0, 0.0)) != white) return false;
    if (pattern.pattern_at(mn::make_point(1.01, 0.0, 0.0)) != black) return false;
    return true;
}

bool checkers_should_repeat_in_y() {
    mn::Color black = mn::make_color(0.0, 0.0, 0.0);
    mn::Color white = mn::make_color(1.0, 1.0, 1.0);

    mn::Checker3DPattern pattern(white, black);

    if (pattern.pattern_at(mn::make_point(0.0, 0.0, 0.0)) != white) return false;
    if (pattern.pattern_at(mn::make_point(0.0, 0.99, 0.0)) != white) return false;
    if (pattern.pattern_at(mn::make_point(0.0, 1.01, 0.0)) != black) return false;
    return true;
}

bool checkers_should_repeat_in_z() {
    mn::Color black = mn::make_color(0.0, 0.0, 0.0);
    mn::Color white = mn::make_color(1.0, 1.0, 1.0);

    mn::Checker3DPattern pattern(white, black);

    if (pattern.pattern_at(mn::make_point(0.0, 0.0, 0.0)) != white) return false;
    if (pattern.pattern_at(mn::make_point(0.0, 0.0, 0.99)) != white) return false;
    if (pattern.pattern_at(mn::make_point(0.0, 0.0, 1.01)) != black) return false;
    return true;
}
