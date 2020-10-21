//
// Created by ivan on 6.10.2020..
//
#include "Tuple.h"

// Adding colors
int main() {
    mn::Tuple c1 = mn::make_color(0.9, 0.6, 0.75);
    mn::Tuple c2 = mn::make_color(0.7, 0.1, 0.25);
    mn::Tuple expected = mn::make_color(1.6, 0.7, 1.0);

    mn::Tuple actual = c1 + c2;

    if (actual == expected) return 0;
    return 1;
}
