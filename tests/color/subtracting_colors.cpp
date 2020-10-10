//
// Created by ivan on 6.10.2020..
//
#include "Tuple.h"
#include "rtc.h"

// Subtracting colors
int main() {
    mn::Tuple c1 = mn::color(0.9, 0.6, 0.75);
    mn::Tuple c2 = mn::color(0.7, 0.1, 0.25);
    mn::Tuple expected = mn::color(0.2, 0.5, 0.5);

    mn::Tuple actual = c1 - c2;

    if (mn::epsilon_equal(actual, expected)) return 0;
    return 1;
}
