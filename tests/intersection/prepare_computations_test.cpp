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

bool the_under_point_is_offset_below_the_surface();

bool precomputing_the_reflection_vector();

bool finding_n1_and_n2_at_various_intersections(int index, double n1, double n2);

int main() {
    if (
            precomputing_the_state_of_an_intersection() &&
            the_hit_when_an_intersection_occurs_on_the_outside() &&
            the_hit_when_an_intersection_occurs_on_the_inside() &&
            the_hit_should_offset_the_point() &&
            the_under_point_is_offset_below_the_surface() &&
            precomputing_the_reflection_vector() &&
            finding_n1_and_n2_at_various_intersections(0, 1.0, 1.5) &&
            finding_n1_and_n2_at_various_intersections(1, 1.5, 2.0) &&
            finding_n1_and_n2_at_various_intersections(2, 2.0, 2.5) &&
            finding_n1_and_n2_at_various_intersections(3, 2.5, 2.5) &&
            finding_n1_and_n2_at_various_intersections(4, 2.5, 1.5) &&
            finding_n1_and_n2_at_various_intersections(5, 1.5, 1.0)
            )
        return 0;
    return 1;
}

bool precomputing_the_state_of_an_intersection() {
    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;
    mn::Intersection intersection{4.0, &sphere};

    mn::Intersections intersections;
    mn::Hit hit_data = mn::prepare_computations(intersection, ray, intersections);

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

    mn::Intersections intersections;
    mn::Hit hit_data = mn::prepare_computations(intersection, ray, intersections);

    return !hit_data.inside;
}

bool the_hit_when_an_intersection_occurs_on_the_inside() {
    mn::Ray ray(mn::make_point(0.0, 0.0, 0.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;
    mn::Intersection intersection{1.0, &sphere};

    mn::Intersections intersections;
    mn::Hit hit_data = mn::prepare_computations(intersection, ray, intersections);

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
    mn::Intersections intersections;
    mn::Hit hit_data = mn::prepare_computations(intersection, ray, intersections);

    if (hit_data.over_point.z >= -mn::kEpsilon / 2.0) return false;
    if (hit_data.point.z <= hit_data.over_point.z) return false;

    return true;
}

bool the_under_point_is_offset_below_the_surface() {
    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Sphere sphere;
    sphere.transform(mn::translation(0.0, 0.0, 1.0));

    mn::Intersection intersection{5.0, &sphere};
    mn::Intersections intersections;
    mn::Hit hit_data = mn::prepare_computations(intersection, ray, intersections);

    if (hit_data.under_point.z <= mn::kEpsilon / 2.0) return false;
    if (hit_data.point.z >= hit_data.under_point.z) return false;

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
    mn::Intersections intersections;
    mn::Hit hit = mn::prepare_computations(intersection, ray, intersections);

    return hit.reflect_v == mn::make_vector(0.0, sqrt_of_2 / 2.0, sqrt_of_2 / 2.0);
}

bool finding_n1_and_n2_at_various_intersections(int index, double n1, double n2) {
    auto A = mn::make_glass_sphere();
    A->transform(mn::scaling(2.0, 2.0, 2.0));
    A->material().refractive_index(1.5);

    auto B = mn::make_glass_sphere();
    B->transform(mn::translation(0.0, 0.0, -0.25));
    B->material().refractive_index(2.0);

    auto C = mn::make_glass_sphere();
    C->transform(mn::translation(0.0, 0.0, 0.25));
    C->material().refractive_index(2.5);

    mn::Ray ray(
            mn::make_point(0.0, 0.0, -4.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );
    mn::Intersections intersections;
    intersections.add(2.00, A.get());
    intersections.add(2.75, B.get());
    intersections.add(3.25, C.get());
    intersections.add(4.75, B.get());
    intersections.add(5.25, C.get());
    intersections.add(6.00, A.get());

    mn::Hit hit = mn::prepare_computations(intersections[index], ray, intersections);

    return hit.n1 == n1 && hit.n2 == n2;
}
