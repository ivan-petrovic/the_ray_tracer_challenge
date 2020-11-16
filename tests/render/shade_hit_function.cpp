//
// Created by ivan on 22.10.2020..
//
#include "Tuple.h"
#include "Material.h"
#include "model/Plane.h"
#include "light/PointLight.h"
#include "render.h"
#include "World.h"

bool shading_an_intersection();

bool shading_an_intersection_from_the_inside();

bool shading_an_intersection_in_shadow();

bool shade_hit_with_a_reflective_material();

bool shade_hit_with_a_transparent_material();

bool shade_hit_with_a_reflective_transparent_material();

int main() {
    if (
            shading_an_intersection() &&
            shading_an_intersection_from_the_inside() &&
            shading_an_intersection_in_shadow() &&
            shade_hit_with_a_reflective_material() &&
            shade_hit_with_a_transparent_material() &&
            shade_hit_with_a_reflective_transparent_material()
            )
        return 0;

    return 1;
}

bool shading_an_intersection() {
    mn::World world;
    mn::make_default_world(world);

    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Intersection intersection{4.0, world.objects()[0].get()}; // first object in world

    mn::Intersections intersections;
    mn::Hit hit = mn::prepare_computations(intersection, ray, intersections);

    mn::Color color = mn::shade_hit(world, hit);

    return mn::epsilon_equal(color, mn::make_color(0.38066, 0.47583, 0.2855), 0.00001);
}

bool shading_an_intersection_from_the_inside() {
    mn::World world;
    mn::make_default_world(world);
    world.light(mn::PointLight(mn::make_point(0.0, 0.25, 0.0), mn::make_color(1.0, 1.0, 1.0)));

    mn::Ray ray(mn::make_point(0.0, 0.0, 0.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Intersection intersection{0.5, world.objects()[1].get()}; // second object in world

    mn::Intersections intersections;
    mn::Hit hit = mn::prepare_computations(intersection, ray, intersections);

    mn::Color color = mn::shade_hit(world, hit);

    return mn::epsilon_equal(color, mn::make_color(0.90498, 0.90498, 0.90498), 0.00001);
}

bool shading_an_intersection_in_shadow() {
    mn::World world;
    auto p_light = std::make_unique<mn::PointLight>(
            mn::make_point(0.0, 0.0, -10.0),
            mn::make_color(1.0, 1.0, 1.0)
    );
    world.set_light(p_light);

    auto s1 = mn::make_sphere();
    world.add_object(s1);

    auto s2 = mn::make_sphere();
    s2->transform(mn::translation(0.0, 0.0, 10.0));
    world.add_object(s2);

    mn::Ray ray(mn::make_point(0.0, 0.0, 5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Intersection intersection{4.0, world.objects()[1].get()}; // second object in world
    mn::Intersections intersections;
    mn::Hit hit = mn::prepare_computations(intersection, ray, intersections);

    mn::Color color = mn::shade_hit(world, hit);
    return color == mn::make_color(0.1, 0.1, 0.1);
}

bool shade_hit_with_a_reflective_material() {
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

    mn::Color color = mn::shade_hit(world, hit);

    return mn::epsilon_equal(color, mn::make_color(0.87677, 0.92436, 0.82918), 0.0001);
}

bool shade_hit_with_a_transparent_material() {
    mn::World world;
    mn::make_default_world(world);

    auto floor = mn::make_plane();
    floor->transform(mn::translation(0.0, -1.0, 0.0));
    floor->material().transparency(0.5);
    floor->material().refractive_index(1.5);
    world.add_object(floor);

    auto ball = mn::make_sphere();
    ball->material().color(mn::make_color(1.0, 0.0, 0.0));
    ball->material().ambient(0.5);
    ball->transform(mn::translation(0.0, -3.5, -0.5));
    world.add_object(ball);

    const double sqrt_of_2 = std::sqrt(2.0);
    const double half_sqrt_of_2 = std::sqrt(2.0) / 2.0;
    mn::Ray ray(
            mn::make_point(0.0, 0.0, -3.0),
            mn::make_vector(0.0, -half_sqrt_of_2, half_sqrt_of_2));

    mn::Intersections intersections;
    intersections.add(sqrt_of_2, world.objects()[2].get());
    mn::Hit hit = mn::prepare_computations(intersections[0], ray, intersections);

    mn::Color color = mn::shade_hit(world, hit, 5);

    return mn::epsilon_equal(color, mn::make_color(0.93642, 0.68642, 0.68642), 0.00001);
}

bool shade_hit_with_a_reflective_transparent_material() {
    mn::World world;
    mn::make_default_world(world);

    auto floor = mn::make_plane();
    floor->transform(mn::translation(0.0, -1.0, 0.0));
    floor->material().reflective(0.5);
    floor->material().transparency(0.5);
    floor->material().refractive_index(1.5);
    world.add_object(floor);

    auto ball = mn::make_sphere();
    ball->material().color(mn::make_color(1.0, 0.0, 0.0));
    ball->material().ambient(0.5);
    ball->transform(mn::translation(0.0, -3.5, -0.5));
    world.add_object(ball);

    const double sqrt_of_2 = std::sqrt(2.0);
    const double half_sqrt_of_2 = std::sqrt(2.0) / 2.0;
    mn::Ray ray(
            mn::make_point(0.0, 0.0, -3.0),
            mn::make_vector(0.0, -half_sqrt_of_2, half_sqrt_of_2));

    mn::Intersections intersections;
    intersections.add(sqrt_of_2, world.objects()[2].get());
    mn::Hit hit = mn::prepare_computations(intersections[0], ray, intersections);

    mn::Color color = mn::shade_hit(world, hit, 5);

    return mn::epsilon_equal(color, mn::make_color(0.93391, 0.69643, 0.69243), 0.00001);
}
