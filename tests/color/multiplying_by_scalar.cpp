//
// Created by ivan on 6.10.2020..
//
#include "Tuple.h"

// Multiplying a color by a scalar
int main() {
    mn::Tuple color = mn::color(0.2, 0.3, 0.4);
    mn::Tuple expected = mn::color(0.4, 0.6, 0.8);

    mn::Tuple actual = color * 2.0;

    if (actual == expected) return 0;
    return 1;
}
