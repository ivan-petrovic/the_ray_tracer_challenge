//
// Created by ivan on 15.10.2020..
//
#include "Ray.h"
#include "model/Plane.h"

bool intersect_with_a_ray_parallel_to_the_plane();

bool intersect_with_a_coplanar_ray();

bool a_ray_intersecting_a_plane_from_above();

bool a_ray_intersecting_a_plane_from_above_case2();

bool a_ray_intersecting_a_plane_from_below();

bool a_ray_intersecting_a_plane_from_below_case2();

int main() {
    if (
            intersect_with_a_ray_parallel_to_the_plane() &&
            intersect_with_a_coplanar_ray() &&
            a_ray_intersecting_a_plane_from_above() &&
            a_ray_intersecting_a_plane_from_above_case2() &&
            a_ray_intersecting_a_plane_from_below() &&
            a_ray_intersecting_a_plane_from_below_case2()
            )
        return 0;
    return 1;
}

bool intersect_with_a_ray_parallel_to_the_plane() {
    mn::Plane plane;
    mn::Ray ray(mn::make_point(0.0, 10.0, 0.0), mn::make_vector(0.0, 0.0, 1.0));

    mn::Intersections result;
    plane.local_intersect(ray, result);

    return result.count() == 0;
}

bool intersect_with_a_coplanar_ray() {
    mn::Plane plane;
    mn::Ray ray(mn::make_point(0.0, 0.0, 0.0), mn::make_vector(0.0, 0.0, 1.0));

    mn::Intersections result;
    plane.local_intersect(ray, result);

    return result.count() == 0;
}

bool a_ray_intersecting_a_plane_from_above() {
    mn::Plane plane;
    mn::Ray ray(mn::make_point(0.0, 1.0, 0.0), mn::make_vector(0.0, -1.0, 0.0));

    mn::Intersections result;
    plane.local_intersect(ray, result);

    if (result.count() != 1) return false;
    if (result[0].t != 1.0) return false;
    if (result[0].object != &plane) return false;

    return true;
}

bool a_ray_intersecting_a_plane_from_above_case2() {
    mn::Plane plane;
    mn::Ray ray(mn::make_point(0.0, 1.0, 0.0), mn::make_vector(0.0, 1.0, 0.0));

    mn::Intersections result;
    plane.local_intersect(ray, result);

    if (result.count() != 1) return false;
    if (result[0].t != -1.0) return false;
    if (result[0].object != &plane) return false;

    return true;
}

bool a_ray_intersecting_a_plane_from_below() {
    mn::Plane plane;
    mn::Ray ray(mn::make_point(0.0, -1.0, 0.0), mn::make_vector(0.0, 1.0, 0.0));

    mn::Intersections result;
    plane.local_intersect(ray, result);

    if (result.count() != 1) return false;
    if (result[0].t != 1.0) return false;
    if (result[0].object != &plane) return false;

    return true;
}

bool a_ray_intersecting_a_plane_from_below_case2() {
    mn::Plane plane;
    mn::Ray ray(mn::make_point(0.0, -1.0, 0.0), mn::make_vector(0.0, -1.0, 0.0));

    mn::Intersections result;
    plane.local_intersect(ray, result);

    if (result.count() != 1) return false;
    if (result[0].t != -1.0) return false;
    if (result[0].object != &plane) return false;

    return true;
}
