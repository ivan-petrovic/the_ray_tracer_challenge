//
// Created by ivan on 22.10.2020..
//
#include "Tuple.h"
#include "Material.h"
#include "light/PointLight.h"
#include "light/lighting.h"
#include "World.h"

bool the_color_when_a_ray_misses();

bool the_color_when_a_ray_hits();

bool the_color_with_an_intersection_behind_the_ray();

int main() {
    if (
            the_color_when_a_ray_misses() &&
            the_color_when_a_ray_hits() &&
            the_color_with_an_intersection_behind_the_ray()
            )
        return 0;

    return 1;
}

bool the_color_when_a_ray_misses() {
    mn::World world;
    mn::make_default_world(world);

    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 1.0, 0.0));

    mn::Color color = mn::color_at(world, ray);

    return color == mn::make_color(0.0, 0.0, 0.0);
}

bool the_color_when_a_ray_hits() {
    mn::World world;
    mn::make_default_world(world);

    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));

    mn::Color color = mn::color_at(world, ray);

    return mn::epsilon_equal(color, mn::make_color(0.38066, 0.47583, 0.2855), 0.00001);
}

bool the_color_with_an_intersection_behind_the_ray() {
    mn::World world;
    mn::make_default_world(world);

    world.objects()[0]->material().ambient(0.5); // outer - the first object in world
    world.objects()[1]->material().ambient(1.0); // inner - the second object in world

    mn::Ray ray(mn::make_point(0.0, 0.0, 0.75), mn::make_vector(0.0, 0.0, -1.0));

    mn::Color color = mn::color_at(world, ray);

    return color == world.objects()[1]->material().color();
}
