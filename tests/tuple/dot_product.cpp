//
// Created by ivan on 8.10.2020..
//
#include "Tuple.h"
#include "rtc.h"

int main() {
    mn::Tuple a = mn::vector(1.0f, 2.0f, 3.0f);
    mn::Tuple b = mn::vector(2.0f, 3.0f, 4.0f);
    double expected = 20.0;

    if (mn::dot(a, b) == expected) return 0;
    return 1;
}
