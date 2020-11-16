//
// Created by ivan on 1.11.2020..
//
#include "Tuple.h"
#include "Material.h"
#include "model/Plane.h"
#include "light/PointLight.h"
#include "render.h"
#include "World.h"

bool the_reflected_color_for_a_non_reflective_material();

bool the_reflected_color_for_a_reflective_material();

bool the_reflected_color_at_a_maximum_recursive_depth();

int main() {
    if (
            the_reflected_color_for_a_non_reflective_material() &&
            the_reflected_color_for_a_reflective_material() &&
            the_reflected_color_at_a_maximum_recursive_depth()
            )
        return 0;

    return 1;
}

bool the_reflected_color_for_a_non_reflective_material() {
    mn::World world;
    mn::make_default_world(world);

    mn::Ray ray(mn::make_point(0.0, 0.0, 0.0), mn::make_vector(0.0, 0.0, 1.0));

    world.objects()[1]->material().ambient(1.0);
    mn::Intersection intersection{1.0, world.objects()[1].get()};
    mn::Intersections intersections;
    mn::Hit hit = mn::prepare_computations(intersection, ray, intersections);

    mn::Color color = mn::reflected_color(world, hit);

    return color == mn::make_color(0.0, 0.0, 0.0);
}

bool the_reflected_color_for_a_reflective_material() {
    mn::World world;
    mn::make_default_world(world);

    auto plane = mn::make_plane();
    plane->material().reflective(0.5);
    plane->transform(mn::translation(0.0, -1.0, 0.0));
    world.add_object(plane);

    const double sqrt_of_2 = std::sqrt(2.0);
    const double half_sqrt_of_2 = std::sqrt(2.0) / 2.0;
    mn::Ray ray(
            mn::make_point(0.0, 0.0, -3.0),
            mn::make_vector(0.0, -half_sqrt_of_2, half_sqrt_of_2));

    mn::Intersection intersection{sqrt_of_2, world.objects()[2].get()};
    mn::Intersections intersections;
    mn::Hit hit = mn::prepare_computations(intersection, ray, intersections);

    mn::Color color = mn::reflected_color(world, hit);

    return mn::epsilon_equal(color, mn::make_color(0.19032, 0.2379, 0.14274), 0.0001);
}

bool the_reflected_color_at_a_maximum_recursive_depth() {
    mn::World world;
    mn::make_default_world(world);

    auto plane = mn::make_plane();
    plane->material().reflective(0.5);
    plane->transform(mn::translation(0.0, -1.0, 0.0));
    world.add_object(plane);

    const double sqrt_of_2 = std::sqrt(2.0);
    const double half_sqrt_of_2 = std::sqrt(2.0) / 2.0;
    mn::Ray ray(
            mn::make_point(0.0, 0.0, -3.0),
            mn::make_vector(0.0, -half_sqrt_of_2, half_sqrt_of_2));

    mn::Intersection intersection{sqrt_of_2, world.objects()[2].get()};
    mn::Intersections intersections;
    mn::Hit hit = mn::prepare_computations(intersection, ray, intersections);

    mn::Color color = mn::reflected_color(world, hit, 0);

    return color == mn::make_color(0.0, 0.0, 0.0);
}
