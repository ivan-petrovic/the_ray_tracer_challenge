//
// Created by ivan on 15.10.2020..
//
#include "Ray.h"

int main() {
    mn::Vector origin = mn::point(1.0f, 2.0f, 3.0f);
    mn::Vector direction = mn::vector(4.0f, 5.0f, 6.0f);
    mn::Ray ray(origin, direction);

    if (ray.origin() == origin && ray.direction() == direction) return 0;
    return 1;
}
