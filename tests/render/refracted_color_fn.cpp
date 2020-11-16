//
// Created by ivan on 1.11.2020..
//
#include "Tuple.h"
#include "Material.h"
#include "model/Plane.h"
#include "light/PointLight.h"
#include "../pattern/TestPattern.h"
#include "render.h"
#include "World.h"

bool the_refracted_color_with_an_opaque_surface();

bool the_refracted_color_at_a_maximum_recursive_depth();

bool the_refracted_color_under_total_internal_reflection();

bool the_refracted_color_with_a_refracted_ray();

int main() {
    if (
            the_refracted_color_with_an_opaque_surface() &&
            the_refracted_color_at_a_maximum_recursive_depth() &&
            the_refracted_color_under_total_internal_reflection() &&
            the_refracted_color_with_a_refracted_ray()
            )
        return 0;

    return 1;
}

bool the_refracted_color_with_an_opaque_surface() {
    mn::World world;
    mn::make_default_world(world);

    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));

    // mn::Intersection intersection{4.0, world.objects()[0].get()};

    mn::Intersections intersections;
    intersections.add(4.0, world.objects()[0].get());
    intersections.add(6.0, world.objects()[0].get());

    mn::Hit hit = mn::prepare_computations(intersections[0], ray, intersections);

    mn::Color color = mn::refracted_color(world, hit, 5);

    return color == mn::make_color(0.0, 0.0, 0.0);
}

bool the_refracted_color_at_a_maximum_recursive_depth() {
    mn::World world;
    mn::make_default_world(world);
    world.objects()[0]->material().transparency(1.0);
    world.objects()[0]->material().refractive_index(1.5);

    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));

    mn::Intersections intersections;
    intersections.add(4.0, world.objects()[0].get());
    intersections.add(6.0, world.objects()[0].get());

    mn::Hit hit = mn::prepare_computations(intersections[0], ray, intersections);

    mn::Color color = mn::refracted_color(world, hit, 0);

    return color == mn::make_color(0.0, 0.0, 0.0);
}

bool the_refracted_color_under_total_internal_reflection() {
    mn::World world;
    mn::make_default_world(world);
    world.objects()[0]->material().transparency(1.0);
    world.objects()[0]->material().refractive_index(1.5);

    const double half_sqrt_of_2 = std::sqrt(2.0) / 2;
    mn::Ray ray(
            mn::make_point(0.0, 0.0, half_sqrt_of_2),
            mn::make_vector(0.0, 1.0, 0.0)
    );

    mn::Intersections intersections;
    intersections.add(-half_sqrt_of_2, world.objects()[0].get());
    intersections.add(half_sqrt_of_2, world.objects()[0].get());

    // NOTE: This time you're inside the sphere, so you need
    // to look at the second intersection, intersections[1], not intersections[0]
    mn::Hit hit = mn::prepare_computations(intersections[1], ray, intersections);

    mn::Color color = mn::refracted_color(world, hit, 5);

    return color == mn::make_color(0.0, 0.0, 0.0);
}

bool the_refracted_color_with_a_refracted_ray() {
    mn::World world;
    mn::make_default_world(world);
    world.objects()[0]->material().ambient(1.0);
    world.objects()[0]->material().set_pattern(mn::make_test_pattern());

    world.objects()[1]->material().transparency(1.0);
    world.objects()[1]->material().refractive_index(1.5);

    mn::Ray ray(
            mn::make_point(0.0, 0.0, 0.1),
            mn::make_vector(0.0, 1.0, 0.0)
    );

    mn::Intersections intersections;
    intersections.add(-0.9899, world.objects()[0].get());
    intersections.add(-0.4899, world.objects()[1].get());
    intersections.add(0.4899, world.objects()[1].get());
    intersections.add(0.9899, world.objects()[0].get());

    mn::Hit hit = mn::prepare_computations(intersections[2], ray, intersections);

    mn::Color color = mn::refracted_color(world, hit, 5);

    // in the book: 0.04725
    return mn::epsilon_equal(color, mn::make_color(0.0, 0.99888, 0.04722), 0.00001);
}
