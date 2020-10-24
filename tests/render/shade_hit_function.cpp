//
// Created by ivan on 22.10.2020..
//
#include "Tuple.h"
#include "Material.h"
#include "light/PointLight.h"
#include "render.h"
#include "World.h"

bool shading_an_intersection();

bool shading_an_intersection_from_the_inside();

bool shading_an_intersection_in_shadow();

int main() {
    if (
            shading_an_intersection() &&
            shading_an_intersection_from_the_inside() &&
            shading_an_intersection_in_shadow()
            )
        return 0;

    return 1;
}

bool shading_an_intersection() {
    mn::World world;
    mn::make_default_world(world);

    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Intersection intersection{4.0, world.objects()[0].get()}; // first object in world

    mn::Hit hit = mn::prepare_computations(intersection, ray);

    mn::Color color = mn::shade_hit(world, hit);

    return mn::epsilon_equal(color, mn::make_color(0.38066, 0.47583, 0.2855), 0.00001);
}

bool shading_an_intersection_from_the_inside() {
    mn::World world;
    mn::make_default_world(world);
    world.light(mn::PointLight(mn::make_point(0.0, 0.25, 0.0), mn::make_color(1.0, 1.0, 1.0)));

    mn::Ray ray(mn::make_point(0.0, 0.0, 0.0), mn::make_vector(0.0, 0.0, 1.0));
    mn::Intersection intersection{0.5, world.objects()[1].get()}; // second object in world

    mn::Hit hit = mn::prepare_computations(intersection, ray);

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
    mn::Hit hit = mn::prepare_computations(intersection, ray);

    mn::Color color = mn::shade_hit(world, hit);
    return color == mn::make_color(0.1, 0.1, 0.1);
}
