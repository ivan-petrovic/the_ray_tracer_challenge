//
// Created by ivan on 16.10.2020..
//
#include "Ray.h"
#include "model/Sphere.h"
#include "intersection/intersect.h"

bool intersection_encapsulates_t_and_object();

bool aggregating_intersections();

bool intersect_sets_the_object_on_the_intersection();

int main() {
    if (
            intersection_encapsulates_t_and_object() &&
            aggregating_intersections() &&
            intersect_sets_the_object_on_the_intersection()
            )
        return 0;
    return 1;
}

bool intersection_encapsulates_t_and_object() {
    mn::Sphere sphere;
    mn::Intersection i{3.5, &sphere};

    if (i.t != 3.5) return false;
    if (i.object != &sphere) return false;

    return true;
}

bool aggregating_intersections() {
    mn::Sphere sphere;

    mn::Intersections xs;
    xs.add(1.0, &sphere);
    xs.add(2.0, &sphere);

    if (xs.count() != 2) return false;
    if (xs[0].t != 1.0) return false;
    if (xs[1].t != 2.0) return false;

    return true;
}

bool intersect_sets_the_object_on_the_intersection() {
    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;

    mn::Intersections result;
    mn::intersect(ray, sphere, result);

    if (result.count() != 2) return false;
    if (result[0].object != &sphere) return false;
    if (result[1].object != &sphere) return false;

    return true;
}
