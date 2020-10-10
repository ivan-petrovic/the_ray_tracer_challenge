//
// Created by ivan on 6.10.2020..
//
#include "Tuple.h"

bool multiplying_a_tuple_by_a_scalar();

bool multiplying_a_tuple_by_a_fraction();

// Multiplying tuples by scalar
int main() {
    if (multiplying_a_tuple_by_a_scalar() && multiplying_a_tuple_by_a_fraction()) return 0;
    return 1;
}

bool multiplying_a_tuple_by_a_scalar() {
    mn::Tuple v(1.0, -2.0, 3.0, -4.0);
    mn::Tuple expected(3.5, -7.0, 10.5, -14.0);

    mn::Tuple actual = 3.5 * v;

    if (actual == expected) return true;
    return false;
}

bool multiplying_a_tuple_by_a_fraction() {
    mn::Tuple v(1.0, -2.0, 3.0, -4.0);
    mn::Tuple expected(0.5, -1.0, 1.5, -2.0);

    mn::Tuple actual = 0.5 * v;

    if (actual == expected) return true;
    return false;
}
