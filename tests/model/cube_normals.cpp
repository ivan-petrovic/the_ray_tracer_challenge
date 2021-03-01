//
// Created by ivan on 22.11.2020..
//
#include "model/Cube.h"

bool the_normal_on_the_surface_of_a_cube(mn::Point point, mn::Vector normal);

int main() {
    if (!the_normal_on_the_surface_of_a_cube(
            mn::make_point(1.0, 0.5, -0.8),
            mn::make_vector(1.0, 0.0, 0.0))
            )
        return 1;
    if (!the_normal_on_the_surface_of_a_cube(
            mn::make_point(-1.0, -0.2, 0.9),
            mn::make_vector(-1.0, 0.0, 0.0))
            )
        return 1;
    if (!the_normal_on_the_surface_of_a_cube(
            mn::make_point(-0.4, 1.0, -0.1),
            mn::make_vector(0.0, 1.0, 0.0))
            )
        return 1;
    if (!the_normal_on_the_surface_of_a_cube(
            mn::make_point(0.3, -1.0, -0.7),
            mn::make_vector(0.0, -1.0, 0.0))
            )
        return 1;
    if (!the_normal_on_the_surface_of_a_cube(
            mn::make_point(-0.6, 0.3, 1.0),
            mn::make_vector(0.0, 0.0, 1.0))
            )
        return 1;
    if (!the_normal_on_the_surface_of_a_cube(
            mn::make_point(0.4, 0.4, -1.0),
            mn::make_vector(0.0, 0.0, -1.0))
            )
        return 1;
    if (!the_normal_on_the_surface_of_a_cube(
            mn::make_point(1.0, 1.0, 1.0),
            mn::make_vector(1.0, 0.0, 0.0))
            )
        return 1;
    if (!the_normal_on_the_surface_of_a_cube(
            mn::make_point(-1.0, -1.0, -1.0),
            mn::make_vector(-1.0, 0.0, 0.0))
            )
        return 1;

    return 0;
}

bool the_normal_on_the_surface_of_a_cube(mn::Point point, mn::Vector normal) {
    mn::Cube cube;

    mn::Vector n = cube.local_normal_at(point, {});

    return n == normal;
}
