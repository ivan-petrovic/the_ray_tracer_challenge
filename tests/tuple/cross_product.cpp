//
// Created by ivan on 8.10.2020..
//
#include "Tuple.h"

bool cross_product_case1();

bool cross_product_case2();

int main() {
    if (cross_product_case1() && cross_product_case2()) return 0;
    return 1;
}

bool cross_product_case1() {
    mn::Tuple a = mn::vector(1.0f, 2.0f, 3.0f);
    mn::Tuple b = mn::vector(2.0f, 3.0f, 4.0f);

    mn::Tuple expected = mn::vector(-1.0f, 2.0f, -1.0);

    if (mn::cross(a, b) == expected) return true;
    return false;
}

bool cross_product_case2() {
    mn::Tuple a = mn::vector(1.0f, 2.0f, 3.0f);
    mn::Tuple b = mn::vector(2.0f, 3.0f, 4.0f);

    mn::Tuple expected = mn::vector(1.0f, -2.0f, 1.0);

    if (mn::cross(b, a) == expected) return true;
    return false;
}
