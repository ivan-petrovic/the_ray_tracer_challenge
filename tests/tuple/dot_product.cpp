//
// Created by ivan on 8.10.2020..
//
#include "Tuple.h"

int main() {
    mn::Tuple a = mn::make_vector(1.0f, 2.0f, 3.0f);
    mn::Tuple b = mn::make_vector(2.0f, 3.0f, 4.0f);
    double expected = 20.0;

    if (mn::dot(a, b) == expected) return 0;
    return 1;
}
