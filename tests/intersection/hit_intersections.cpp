//
// Created by ivan on 16.10.2020..
//
#include "Ray.h"
#include "model/Sphere.h"
#include "intersection/intersect.h"

bool the_hit_when_all_intersections_have_positive_t();

bool the_hit_when_some_intersections_have_negative_t();

bool the_hit_when_all_intersections_have_negative_t();

bool the_hit_is_always_the_lowest_non_negative_intersection();

int main() {
    if (
            the_hit_when_all_intersections_have_positive_t() &&
            the_hit_when_some_intersections_have_negative_t() &&
            the_hit_when_all_intersections_have_negative_t() &&
            the_hit_is_always_the_lowest_non_negative_intersection()
            )
        return 0;
    return 1;
}


bool the_hit_when_all_intersections_have_positive_t() {
    mn::Sphere sphere;
    mn::Intersections intersections;
    intersections.add(1.0, &sphere);
    intersections.add(2.0, &sphere);

    mn::Intersection intersection = mn::find_hit(intersections);

    if (intersection.t != 1.0) return false;
    if (intersection.object != &sphere) return false;

    return true;
}

bool the_hit_when_some_intersections_have_negative_t() {
    mn::Sphere sphere;
    mn::Intersections intersections;
    intersections.add(-1.0, &sphere);
    intersections.add(1.0, &sphere);

    mn::Intersection intersection = mn::find_hit(intersections);

    if (intersection.t != 1.0) return false;
    if (intersection.object != &sphere) return false;

    return true;
}

bool the_hit_when_all_intersections_have_negative_t() {
    mn::Sphere sphere;
    mn::Intersections intersections;
    intersections.add(-1.0, &sphere);
    intersections.add(-2.0, &sphere);

    mn::Intersection intersection = mn::find_hit(intersections);

    if (intersection.t != 0.0) return false;
    if (intersection.object != nullptr) return false;

    return true;
}

bool the_hit_is_always_the_lowest_non_negative_intersection() {
    mn::Sphere sphere1;
    mn::Sphere sphere2;
    mn::Intersections intersections;
    intersections.add(5.0, &sphere1);
    intersections.add(7.0, &sphere1);
    intersections.add(-3.0, &sphere2);
    intersections.add(2.0, &sphere2);

    mn::Intersection intersection = mn::find_hit(intersections);

    if (intersection.t != 2.0) return false;
    if (intersection.object != &sphere2) return false;

    return true;
}
