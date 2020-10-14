//
// Created by ivan on 5.10.2020..
//
#include "Tuple.h"

// vector() creates tuples with w = 0.0
int main() {
    double x = 4.3, y = -4.2, z = 3.1, w = 0.0;
    mn::Tuple t = mn::vector(x, y, z);

    if (t.x == x && t.y == y && t.z == z && t.w == w && mn::is_vector(t) && mn::is_not_point(t))
        return 0;

    return 1;
}
