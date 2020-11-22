//
// Created by ivan on 22.11.2020..
//
#include "Ray.h"
#include "model/Cube.h"

bool ray_intersects_a_cube(mn::Point origin, mn::Vector direction, double t1, double t2);

bool ray_misses_a_cube(mn::Point origin, mn::Vector direction);

int main() {
    if (!ray_intersects_a_cube(
            mn::make_point(5.0, 0.5, 0.0),
            mn::make_vector(-1.0, 0.0, 0.0),
            4.0, 6.0)
            )
        return 1;
    if (!ray_intersects_a_cube(
            mn::make_point(-5.0, 0.5, 0.0),
            mn::make_vector(1.0, 0.0, 0.0),
            4.0, 6.0)
            )
        return 1;
    if (!ray_intersects_a_cube(
            mn::make_point(0.5, 5.0, 0.0),
            mn::make_vector(0.0, -1.0, 0.0),
            4.0, 6.0)
            )
        return 1;
    if (ray_intersects_a_cube(
            mn::make_point(0.5, -5.0, 0.0),
            mn::make_vector(0.0, 1.0, 0.0),
            4.0, 6.0)
            )
        return 0;
    if (!ray_intersects_a_cube(
            mn::make_point(0.5, 0.0, 5.0),
            mn::make_vector(0.0, 0.0, -1.0),
            4.0, 6.0)
            )
        return 1;
    if (!ray_intersects_a_cube(
            mn::make_point(0.5, 0.0, -5.0),
            mn::make_vector(0.0, 0.0, 1.0),
            4.0, 6.0)
            )
        return 1;
    if (!ray_intersects_a_cube(
            mn::make_point(0.0, 0.5, 0.0),
            mn::make_vector(0.0, 0.0, 1.0),
            -1.0, 1.0)
            )
        return 1;

    if (!ray_misses_a_cube(
            mn::make_point(-2.0, 0.0, 0.0),
            mn::make_vector(0.2673, 0.5345, 0.8018))
            )
        return 1;
    if (!ray_misses_a_cube(
            mn::make_point(0.0, -2.0, 0.0),
            mn::make_vector(0.8018, 0.2673, 0.5345))
            )
        return 1;
    if (!ray_misses_a_cube(
            mn::make_point(0.0, 0.0, -2.0),
            mn::make_vector(0.5345, 0.8018, 0.2673))
            )
        return 1;
    if (!ray_misses_a_cube(
            mn::make_point(2.0, 0.0, 2.0),
            mn::make_vector(0.0, 0.0, -1.0))
            )
        return 1;
    if (!ray_misses_a_cube(
            mn::make_point(0.0, 2.0, 2.0),
            mn::make_vector(0.0, -1.0, 0.0))
            )
        return 1;
    if (!ray_misses_a_cube(
            mn::make_point(2.0, 2.0, 0.0),
            mn::make_vector(-1.0, 0.0, 0.0))
            )
        return 1;

    return 0;
}

bool ray_intersects_a_cube(mn::Point origin, mn::Vector direction, double t1, double t2) {
    mn::Cube cube;
    mn::Ray ray(origin, direction);

    mn::Intersections result;
    cube.local_intersect(ray, result);

    if (result.count() != 2) return false;
    if (result[0].t != t1) return false;
    if (result[1].t != t2) return false;

    return true;
}

bool ray_misses_a_cube(mn::Point origin, mn::Vector direction) {
    mn::Cube cube;
    mn::Ray ray(origin, direction);

    mn::Intersections result;
    cube.local_intersect(ray, result);

    return result.count() == 0;
}
