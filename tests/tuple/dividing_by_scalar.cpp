//
// Created by ivan on 6.10.2020..
//
#include "Tuple.h"

bool dividing_a_tuple_by_a_scalar();

// Dividing tuples by scalar
int main() {
    if (dividing_a_tuple_by_a_scalar()) return 0;
    return 1;
}

bool dividing_a_tuple_by_a_scalar() {
    mn::Tuple v(1.0f, -2.0f, 3.0f, -4.0f);
    mn::Tuple expected(0.5f, -1.0f, 1.5f, -2.0f);

    mn::Tuple actual = v / 2.0f;

    if (actual == expected) return true;
    return false;
}
