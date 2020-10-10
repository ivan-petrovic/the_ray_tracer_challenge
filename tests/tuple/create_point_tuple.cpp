//
// Created by ivan on 5.10.2020..
//
#include "Tuple.h"
#include "rtc.h"

// A tuple with w = 1.0 is a point
int main() {
    double x = 4.3, y = -4.2, z = 3.1, w = 1.0;
    mn::Tuple t(x, y, z, w);

    if (t.x == x && t.y == y && t.z == z && t.w == w && mn::is_point(t) && mn::is_not_vector(t))
        return 0;

    return 1;
}
