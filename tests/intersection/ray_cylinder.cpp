//
// Created by ivan on 5.12.2020..
//

#include "Ray.h"
#include "model/Cylinder.h"

bool ray_misses_a_cylinder(mn::Point origin, mn::Vector direction);

bool ray_strikes_a_cylinder(mn::Point origin, mn::Vector direction, double t1, double t2);

bool intersecting_a_constrained_cylinder(mn::Point origin, mn::Vector direction, int count);

bool intersecting_the_caps_of_a_closed_cylinder(mn::Point origin, mn::Vector direction, int count);

int main() {
    if (!ray_misses_a_cylinder(
            mn::make_point(1.0, 0.0, 0.0),
            mn::make_vector(0.0, 1.0, 0.0))
            )
        return 1;
    if (!ray_misses_a_cylinder(
            mn::make_point(0.0, 0.0, 0.0),
            mn::make_vector(0.0, 1.0, 0.0))
            )
        return 1;
    if (!ray_misses_a_cylinder(
            mn::make_point(0.0, 0.0, -5.0),
            mn::make_vector(1.0, 1.0, 1.0))
            )
        return 1;

    if (!ray_strikes_a_cylinder(
            mn::make_point(1.0, 0.0, -5.0),
            mn::make_vector(0.0, 0.0, 1.0),
            5.0, 5.0)
            )
        return 1;
    if (!ray_strikes_a_cylinder(
            mn::make_point(0.0, 0.0, -5.0),
            mn::make_vector(0.0, 0.0, 1.0),
            4.0, 6.0)
            )
        return 1;
    if (!ray_strikes_a_cylinder(
            mn::make_point(0.5, 0.0, -5.0),
            mn::make_vector(0.1, 1.0, 1.0),
            6.80798, 7.08872)
            )
        return 1;

    if (!intersecting_a_constrained_cylinder(
            mn::make_point(0.0, 1.5, 0.0),
            mn::make_vector(0.1, 1.0, 1.0),
            0)
            )
        return 1;
    if (!intersecting_a_constrained_cylinder(
            mn::make_point(0.0, 3.0, -5.0),
            mn::make_vector(0.0, 0.0, 1.0),
            0)
            )
        return 1;
    if (!intersecting_a_constrained_cylinder(
            mn::make_point(0.0, 0.0, 0.0),
            mn::make_vector(0.0, 0.0, 1.0),
            0)
            )
        return 1;
    if (!intersecting_a_constrained_cylinder(
            mn::make_point(0.0, 2.0, -5.0),
            mn::make_vector(0.0, 0.0, 1.0),
            0)
            )
        return 1;
    if (!intersecting_a_constrained_cylinder(
            mn::make_point(0.0, 1.0, -5.0),
            mn::make_vector(0.0, 0.0, 1.0),
            0)
            )
        return 1;
    if (!intersecting_a_constrained_cylinder(
            mn::make_point(0.0, 1.5, -2.0),
            mn::make_vector(0.0, 0.0, 1.0),
            2)
            )
        return 1;

    if (!intersecting_the_caps_of_a_closed_cylinder(
            mn::make_point(0.0, 3.0, 0.0),
            mn::make_vector(0.0, -1.0, 0.0),
            2)
            )
        return 1;
    if (!intersecting_the_caps_of_a_closed_cylinder(
            mn::make_point(0.0, 3.0, -2.0),
            mn::make_vector(0.0, -1.0, 2.0),
            2)
            )
        return 1;
    if (!intersecting_the_caps_of_a_closed_cylinder(
            mn::make_point(0.0, 4.0, -2.0),
            mn::make_vector(0.0, -1.0, 1.0),
            2) // corner case
            )
        return 1;
    if (!intersecting_the_caps_of_a_closed_cylinder(
            mn::make_point(0.0, 0.0, -2.0),
            mn::make_vector(0.0, 1.0, 2.0),
            2)
            )
        return 1;
    if (!intersecting_the_caps_of_a_closed_cylinder(
            mn::make_point(0.0, -1.0, -2.0),
            mn::make_vector(0.0, 1.0, 1.0),
            2) // corner case
            )
        return 1;

    return 0;
}

bool ray_strikes_a_cylinder(mn::Point origin, mn::Vector direction, double t1, double t2) {
    mn::Cylinder cylinder;
    direction.normalize();
    mn::Ray ray(origin, direction);

    mn::Intersections result;
    cylinder.local_intersect(ray, result);

    if (result.count() != 2) return false;
    if (!mn::epsilon_equal(result[0].t, t1, 0.00001)) return false;
    if (!mn::epsilon_equal(result[1].t, t2, 0.00001)) return false;

    return true;
}

bool ray_misses_a_cylinder(mn::Point origin, mn::Vector direction) {
    mn::Cylinder cylinder;
    direction.normalize();
    mn::Ray ray(origin, direction);

    mn::Intersections result;
    cylinder.local_intersect(ray, result);

    return result.count() == 0;
}

bool intersecting_a_constrained_cylinder(mn::Point origin, mn::Vector direction, int count) {
    mn::Cylinder cylinder;
    cylinder.minimum(1.0);
    cylinder.maximum(2.0);
    direction.normalize();
    mn::Ray ray(origin, direction);

    mn::Intersections result;
    cylinder.local_intersect(ray, result);

    return result.count() == count;
}

bool intersecting_the_caps_of_a_closed_cylinder(mn::Point origin, mn::Vector direction, int count) {
    mn::Cylinder cylinder;
    cylinder.minimum(1.0);
    cylinder.maximum(2.0);
    cylinder.closed(true);

    direction.normalize();
    mn::Ray ray(origin, direction);

    mn::Intersections result;
    cylinder.local_intersect(ray, result);

    return result.count() == count;
}
