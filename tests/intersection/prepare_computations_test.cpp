//
// Created by ivan on 21.10.2020..
//
#include "Ray.h"
#include "model/Sphere.h"
#include "model/Plane.h"
#include "intersection/intersect.h"

bool precomputing_the_state_of_an_intersection();

bool the_hit_when_an_intersection_occurs_on_the_outside();

bool the_hit_when_an_intersection_occurs_on_the_inside();

bool the_hit_should_offset_the_point();

bool precomputing_the_reflection_vector();

int main() {
    if (
            precomputing_the_state_of_an_intersection() &&
            the_hit_when_an_intersection_occurs_on_the_outside() &&
            the_hit_when_an_intersection_occurs_on_the_inside() &&
            the_hit_should_offset_the_point() &&
            precomputing_the_reflection_vector()
            )
        return 0;
    return 1;
}

bool precomputing_the_state_of_an_intersection() {
    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;
    mn::Intersection intersection{4.0, &sphere};

    mn::Hit hit_data = mn::prepare_computations(intersection, ray);

    if (hit_data.t != intersection.t) return false;
    if (hit_data.object != intersection.object) return false;
    if (hit_data.point != mn::make_point(0.0, 0.0, -1.0)) return false;
    if (hit_data.eye != mn::make_vector(0.0, 0.0, -1.0)) return false;
    if (hit_data.normal != mn::make_vector(0.0, 0.0, -1.0)) return false;

    return true;
}

bool the_hit_when_an_intersection_occurs_on_the_outside() {
    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;
    mn::Intersection intersection{4.0, &sphere};

    mn::Hit hit_data = mn::prepare_computations(intersection, ray);

    return !hit_data.inside;
}

bool the_hit_when_an_intersection_occurs_on_the_inside() {
    mn::Ray ray(mn::make_point(0.0, 0.0, 0.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;
    mn::Intersection intersection{1.0, &sphere};

    mn::Hit hit_data = mn::prepare_computations(intersection, ray);

    if (hit_data.t != intersection.t) return false;
    if (hit_data.object != intersection.object) return false;
    if (hit_data.point != mn::make_point(0.0, 0.0, 1.0)) return false;
    if (hit_data.eye != mn::make_vector(0.0, 0.0, -1.0)) return false;
    if (!hit_data.inside) return false;
    // normal would have been (0, 0, 1), but is inverted
    if (hit_data.normal != mn::make_vector(0.0, 0.0, -1.0)) return false;

    return true;
}

bool the_hit_should_offset_the_point() {
    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;
    sphere.transform(mn::translation(0.0, 0.0, 1.0));

    mn::Intersection intersection{5.0, &sphere};

    mn::Hit hit_data = mn::prepare_computations(intersection, ray);

    if (hit_data.over_point.z >= -mn::kEpsilon / 2.0) return false;
    if (hit_data.point.z <= hit_data.over_point.z) return false;

    return true;
}

bool precomputing_the_reflection_vector() {
    mn::Plane plane;
    const double sqrt_of_2 = std::sqrt(2.0);
    mn::Ray ray(
            mn::make_point(0.0, 1.0, -1.0),
            mn::make_vector(0.0, -sqrt_of_2 / 2.0, sqrt_of_2 / 2.0)
    );
    mn::Intersection intersection{sqrt_of_2, &plane};

    mn::Hit hit = mn::prepare_computations(intersection, ray);

    return hit.reflect_v == mn::make_vector(0.0, sqrt_of_2 / 2.0, sqrt_of_2 / 2.0);
}
