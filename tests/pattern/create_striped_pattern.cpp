//
// Created by ivan on 27.10.2020..
//

#include "pattern/StripedPattern.h"

int main() {
    mn::Color black = mn::make_color(0.0, 0.0, 0.0);
    mn::Color white = mn::make_color(1.0, 1.0, 1.0);

    mn::StripedPattern pattern(white, black);

    if (pattern.a() == white && pattern.b() == black) return 0;
    return 1;
}
