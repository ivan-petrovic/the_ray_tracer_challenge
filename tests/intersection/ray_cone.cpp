//
// Created by ivan on 16.1.2020..
//

#include "Ray.h"
#include "model/Cone.h"

bool intersecting_a_cone_with_a_ray(mn::Point origin, mn::Vector direction, double t1, double t2);

bool intersecting_a_cone_with_a_parallel_ray();

bool intersecting_an_end_point_of_a_cone(mn::Point origin, mn::Vector direction, int count);

int main() {
    if (!intersecting_a_cone_with_a_ray(
            mn::make_point(0.0, 0.0, -5.0),
            mn::make_vector(0.0, 0.0, 1.0),
            5.0, 5.0)
            )
        return 1;
    if (!intersecting_a_cone_with_a_ray(
            mn::make_point(0.0, 0.0, -5.0),
            mn::make_vector(1.0, 1.0, 1.0),
            8.66025, 8.66025)
            )
        return 1;
    if (!intersecting_a_cone_with_a_ray(
            mn::make_point(1.0, 1.0, -5.0),
            mn::make_vector(-0.5, -1.0, 1.0),
            4.55006, 49.44994)
            )
        return 1;

    if (!intersecting_a_cone_with_a_parallel_ray())
        return 1;

    if (!intersecting_an_end_point_of_a_cone(
            mn::make_point(0.0, 0.0, -5.0),
            mn::make_vector(0.0, 1.0, 0.0),
            0)
            )
        return 1;
    if (!intersecting_an_end_point_of_a_cone(
            mn::make_point(0.0, 0.0, -0.25),
            mn::make_vector(0.0, 1.0, 1.0),
            2)
            )
        return 1;
    if (!intersecting_an_end_point_of_a_cone(
            mn::make_point(0.0, 0.0, -0.25),
            mn::make_vector(0.0, 1.0, 0.0),
            4)
            )
        return 1;

    return 0;
}

bool intersecting_a_cone_with_a_ray(mn::Point origin, mn::Vector direction, double t1, double t2) {
    mn::Cone cone;
    direction.normalize();
    mn::Ray ray(origin, direction);

    mn::Intersections result;
    cone.local_intersect(ray, result);

    if (result.count() != 2) return false;
    if (!mn::epsilon_equal(result[0].t, t1, 0.00001)) return false;
    if (!mn::epsilon_equal(result[1].t, t2, 0.00001)) return false;

    return true;
}

bool intersecting_a_cone_with_a_parallel_ray() {
    mn::Cone cone;
    mn::Vector direction = mn::normalize(mn::make_vector(0.0, 1.0, 1.0));
    mn::Ray ray(mn::make_point(0.0, 0.0, -1.0), direction);

    mn::Intersections result;
    cone.local_intersect(ray, result);

    if (result.count() != 1) return false;
    if (!mn::epsilon_equal(result[0].t, 0.35355, 0.00001)) return false;

    return true;
}

bool intersecting_an_end_point_of_a_cone(mn::Point origin, mn::Vector direction, int count) {
    mn::Cone cone;
    cone.minimum(-0.5);
    cone.maximum(0.5);
    cone.closed(true);

    direction.normalize();
    mn::Ray ray(origin, direction);

    mn::Intersections result;
    cone.local_intersect(ray, result);

    return result.count() == count;
}
