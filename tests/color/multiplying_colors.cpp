//
// Created by ivan on 11.10.2020..
//
#include "Tuple.h"

// Multiplying a color by a scalar
int main() {
    mn::Tuple color1 = mn::color(1.0, 0.2, 0.4);
    mn::Tuple color2 = mn::color(0.9, 1.0, 0.1);
    mn::Tuple expected = mn::color(0.9, 0.2, 0.04);

    mn::Tuple actual1 = color1 * color2;
    mn::Tuple actual2 = mn::hadamard(color2, color1);

    if (mn::epsilon_equal(actual1, expected) && mn::epsilon_equal(actual2, expected)) return 0;
    return 1;
}
