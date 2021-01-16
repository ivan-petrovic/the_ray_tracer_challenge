//
// Created by ivan on 5.12.2020..
//

#include "model/Cylinder.h"

bool the_normal_vector_on_a_cylinder(mn::Point point, mn::Vector normal);
bool the_normal_vector_on_end_caps_of_a_cylinder(mn::Point point, mn::Vector normal);

int main() {
    if (!the_normal_vector_on_a_cylinder(
            mn::make_point(1.0, 0.0, 0.0),
            mn::make_vector(1.0, 0.0, 0.0))
            )
        return 1;
    if (!the_normal_vector_on_a_cylinder(
            mn::make_point(0.0, 5.0, -1.0),
            mn::make_vector(0.0, 0.0, -1.0))
            )
        return 1;
    if (!the_normal_vector_on_a_cylinder(
            mn::make_point(0.0, -2.0, 1.0),
            mn::make_vector(0.0, 0.0, 1.0))
            )
        return 1;
    if (!the_normal_vector_on_a_cylinder(
            mn::make_point(-1.0, 1.0, 0.0),
            mn::make_vector(-1.0, 0.0, 0.0))
            )
        return 1;

    if (!the_normal_vector_on_end_caps_of_a_cylinder(
            mn::make_point(0.0, 1.0, 0.0),
            mn::make_vector(0.0, -1.0, 0.0))
            )
        return 1;
    if (!the_normal_vector_on_end_caps_of_a_cylinder(
            mn::make_point(0.5, 1.0, 0.0),
            mn::make_vector(0.0, -1.0, 0.0))
            )
        return 1;
    if (!the_normal_vector_on_end_caps_of_a_cylinder(
            mn::make_point(0.0, 1.0, 0.5),
            mn::make_vector(0.0, -1.0, 0.0))
            )
        return 1;
    if (!the_normal_vector_on_end_caps_of_a_cylinder(
            mn::make_point(0.0, 2.0, 0.0),
            mn::make_vector(0.0, 1.0, 0.0))
            )
        return 1;
    if (!the_normal_vector_on_end_caps_of_a_cylinder(
            mn::make_point(0.5, 2.0, 0.0),
            mn::make_vector(0.0, 1.0, 0.0))
            )
        return 1;
    if (!the_normal_vector_on_end_caps_of_a_cylinder(
            mn::make_point(0.0, 2.0, 0.5),
            mn::make_vector(0.0, 1.0, 0.0))
            )
        return 1;

    return 0;
}

bool the_normal_vector_on_a_cylinder(mn::Point point, mn::Vector normal) {
    mn::Cylinder cylinder;

    mn::Vector n = cylinder.local_normal_at(point);

    return n == normal;
}

bool the_normal_vector_on_end_caps_of_a_cylinder(mn::Point point, mn::Vector normal) {
    mn::Cylinder cylinder;
    cylinder.minimum(1.0);
    cylinder.maximum(2.0);
    cylinder.closed(true);

    mn::Vector n = cylinder.local_normal_at(point);

    return n == normal;
}
