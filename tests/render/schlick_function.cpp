//
// Created by ivan on 15.11.2020..
//
#include "Tuple.h"
#include "Material.h"
#include "model/Plane.h"
#include "render.h"
#include "World.h"

bool the_schlick_approximation_under_total_internal_reflection();

bool the_schlick_approximation_with_a_perpendicular_viewing_angle();

bool the_schlick_approximation_with_small_angle_and_n2_greater_than_n1();

int main() {
    if (
            the_schlick_approximation_under_total_internal_reflection() &&
            the_schlick_approximation_with_a_perpendicular_viewing_angle() &&
            the_schlick_approximation_with_small_angle_and_n2_greater_than_n1()
            )
        return 0;

    return 1;
}

bool the_schlick_approximation_under_total_internal_reflection() {
    auto sphere = mn::make_glass_sphere();

    const double half_sqrt_of_2 = std::sqrt(2.0) / 2;
    mn::Ray ray(
            mn::make_point(0.0, 0.0, half_sqrt_of_2),
            mn::make_vector(0.0, 1.0, 0.0)
    );

    mn::Intersections intersections;
    intersections.add(-half_sqrt_of_2, sphere.get());
    intersections.add(half_sqrt_of_2, sphere.get());

    mn::Hit hit = mn::prepare_computations(intersections[1], ray, intersections);

    double reflectance = mn::schlick(hit);

    return reflectance == 1.0;
}

bool the_schlick_approximation_with_a_perpendicular_viewing_angle() {
    auto sphere = mn::make_glass_sphere();

    mn::Ray ray(
            mn::make_point(0.0, 0.0, 0.0),
            mn::make_vector(0.0, 1.0, 0.0)
    );

    mn::Intersections intersections;
    intersections.add(-1.0, sphere.get());
    intersections.add(1.0, sphere.get());

    mn::Hit hit = mn::prepare_computations(intersections[1], ray, intersections);

    double reflectance = mn::schlick(hit);

    return mn::epsilon_equal(reflectance, 0.04);
}

bool the_schlick_approximation_with_small_angle_and_n2_greater_than_n1() {
    auto sphere = mn::make_glass_sphere();

    mn::Ray ray(
            mn::make_point(0.0, 0.99, -2.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );

    mn::Intersections intersections;
    intersections.add(1.8589, sphere.get());

    mn::Hit hit = mn::prepare_computations(intersections[0], ray, intersections);

    double reflectance = mn::schlick(hit);

    return mn::epsilon_equal(reflectance, 0.48873);
}
