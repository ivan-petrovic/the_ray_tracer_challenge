//
// Created by ivan on 16.10.2020..
//
#include "Ray.h"
#include "model/Sphere.h"
#include "intersection/Intersections.h"

bool intersecting_a_scaled_sphere_with_a_ray();

bool intersecting_a_translated_sphere_with_a_ray();

int main() {
    if (
            intersecting_a_scaled_sphere_with_a_ray() &&
            intersecting_a_translated_sphere_with_a_ray()
            )
        return 0;
    return 1;
}

bool intersecting_a_scaled_sphere_with_a_ray() {
    mn::Ray ray(mn::point(0.0, 0.0, -5.0), mn::vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;
    sphere.transform(mn::scaling(2.0, 2.0, 2.0));

    mn::Intersections result;
    mn::intersect(ray, sphere, result);

    if (result.count() != 2) return false;
    if (result[0].t != 3.0) return false;
    if (result[1].t != 7.0) return false;

    return true;
}

bool intersecting_a_translated_sphere_with_a_ray() {
    mn::Ray ray(mn::point(0.0, 0.0, -5.0), mn::vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;
    sphere.transform(mn::translation(5.0, 0.0, 0.0));

    mn::Intersections result;
    mn::intersect(ray, sphere, result);

    if (result.count() != 0) return false;
    return true;
}
