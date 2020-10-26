//
// Created by ivan on 15.10.2020..
//
#include "Ray.h"
#include "model/Sphere.h"
#include "intersection/intersect.h"

bool ray_intersects_sphere_at_two_points();

bool ray_intersects_sphere_at_a_tangent();

bool ray_misses_a_sphere();

bool ray_originates_inside_a_sphere();

bool sphere_is_behind_a_ray();

int main() {
    if (
            ray_intersects_sphere_at_two_points() &&
            ray_intersects_sphere_at_a_tangent() &&
            ray_misses_a_sphere() &&
            ray_originates_inside_a_sphere() &&
            sphere_is_behind_a_ray()
            )
        return 0;
    return 1;
}

bool ray_intersects_sphere_at_two_points() {
    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;

    mn::Intersections result;
    sphere.local_intersect(ray, result);

    if (result.count() != 2) return false;
    if (result[0].t != 4.0) return false;
    if (result[1].t != 6.0) return false;

    return true;
}

bool ray_intersects_sphere_at_a_tangent() {
    mn::Ray ray(mn::make_point(0.0, 1.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;

    mn::Intersections result;
    sphere.local_intersect(ray, result);

    if (result.count() != 2) return false;
    if (result[0].t != 5.0) return false;
    if (result[1].t != 5.0) return false;

    return true;
}

bool ray_misses_a_sphere() {
    mn::Ray ray(mn::make_point(0.0, 2.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;

    mn::Intersections result;
    sphere.local_intersect(ray, result);

    if (result.count() != 0) return false;
    return true;
}

bool ray_originates_inside_a_sphere() {
    mn::Ray ray(mn::make_point(0.0, 0.0, 0.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;

    mn::Intersections result;
    sphere.local_intersect(ray, result);

    if (result.count() != 2) return false;
    if (result[0].t != -1.0) return false;
    if (result[1].t != 1.0) return false;

    return true;
}

bool sphere_is_behind_a_ray() {
    mn::Ray ray(mn::make_point(0.0, 0.0, 5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;

    mn::Intersections result;
    sphere.local_intersect(ray, result);

    if (result.count() != 2) return false;
    if (result[0].t != -6.0) return false;
    if (result[1].t != -4.0) return false;

    return true;
}
