//
// Created by ivan on 6.10.2020..
//
#include "Tuple.h"

bool subtracting_a_vector_from_the_zero_vector();

bool negating_a_vector();

// Negating tuples
int main() {
    if (subtracting_a_vector_from_the_zero_vector() && negating_a_vector()) return 0;
    return 1;
}

bool subtracting_a_vector_from_the_zero_vector() {
    mn::Tuple zero = mn::zero();
    mn::Tuple v = mn::make_vector(1.0, -2.0, 3.0);
    mn::Tuple expected = mn::make_vector(-1.0, 2.0, -3.0);

    mn::Tuple actual = zero - v;

    if (actual == expected) return true;
    return false;
}

bool negating_a_vector() {
    mn::Tuple v = mn::make_vector(1.0, -2.0, 3.0);
    mn::Tuple expected = mn::make_vector(-1.0, 2.0, -3.0);

    mn::Tuple actual = -v;

    if (actual == expected) return true;
    return false;
}
