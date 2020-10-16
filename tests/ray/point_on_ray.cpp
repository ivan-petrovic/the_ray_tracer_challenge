//
// Created by ivan on 15.10.2020..
//
#include "Ray.h"

// Computing point on the ray
int main() {
    mn::Ray ray(mn::point(2.0, 3.0, 4.0), mn::vector(1.0, 0.0, 0.0));

    if (
            ray.position(0.0) == mn::point(2.0, 3.0, 4.0) &&
            ray.position(1.0) == mn::point(3.0, 3.0, 4.0) &&
            ray.position(-1.0) == mn::point(1.0, 3.0, 4.0) &&
            ray.position(2.5) == mn::point(4.5, 3.0, 4.0)
            )
        return 0;

    return 1;
}
