//
// Created by ivan on 16.10.2020..
//
#include "Ray.h"
#include "../model/TestObject.h"
#include "intersection/intersect.h"

bool intersecting_a_scaled_object_with_a_ray();

bool intersecting_a_translated_object_with_a_ray();

int main() {
    if (
            intersecting_a_scaled_object_with_a_ray() &&
            intersecting_a_translated_object_with_a_ray()
            )
        return 0;
    return 1;
}

bool intersecting_a_scaled_object_with_a_ray() {
    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::TestObject object;
    object.transform(mn::scaling(2.0, 2.0, 2.0));

    mn::Intersections result;
    mn::intersect(ray, object, result);

    if (object.saved_ray.origin() != mn::make_point(0.0, 0.0, -2.5)) return false;
    if (object.saved_ray.direction() != mn::make_vector(0.0, 0.0, 0.5)) return false;

    return true;
}

bool intersecting_a_translated_object_with_a_ray() {
    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::TestObject object;
    object.transform(mn::translation(5.0, 0.0, 0.0));

    mn::Intersections result;
    mn::intersect(ray, object, result);

    if (object.saved_ray.origin() != mn::make_point(-5.0, 0.0, -5.0)) return false;
    if (object.saved_ray.direction() != mn::make_vector(0.0, 0.0, 1.0)) return false;

    return true;
}
