//
// Created by ivan on 6.10.2020..
//
#include "Tuple.h"

// Adding two tuples
int main() {
    mn::Tuple a = mn::point(3.0, -2.0, 5.0);
    mn::Tuple b = mn::vector(-2.0, 3.0, 1.0);
    mn::Tuple expected(1.0, 1.0, 6.0, 1.0);

    mn::Tuple c = a + b;

    if (c == expected) return 0;

    return 1;
}
