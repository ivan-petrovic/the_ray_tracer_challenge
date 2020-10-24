//
// Created by ivan on 24.10.2020..
//

#include "Tuple.h"
#include "Material.h"
#include "light/PointLight.h"
#include "render.h"
#include "World.h"

bool there_is_no_shadow_when_nothing_is_collinear_with_point_and_light();

bool the_shadow_when_an_object_is_between_the_point_and_the_light();

bool there_is_no_shadow_when_an_object_is_behind_the_light();

bool there_is_no_shadow_when_an_object_is_behind_the_point();

int main() {
    if (
            there_is_no_shadow_when_nothing_is_collinear_with_point_and_light() &&
            the_shadow_when_an_object_is_between_the_point_and_the_light() &&
            there_is_no_shadow_when_an_object_is_behind_the_light() &&
            there_is_no_shadow_when_an_object_is_behind_the_point()
            )
        return 0;

    return 1;
}

bool there_is_no_shadow_when_nothing_is_collinear_with_point_and_light() {
    mn::World world;
    mn::make_default_world(world);
    mn::Point point = mn::make_point(0.0, 10.0, 0.0);

    return !mn::is_shadowed(world, point);
}

bool the_shadow_when_an_object_is_between_the_point_and_the_light() {
    mn::World world;
    mn::make_default_world(world);
    mn::Point point = mn::make_point(10.0, -10.0, 10.0);

    return mn::is_shadowed(world, point);
}

bool there_is_no_shadow_when_an_object_is_behind_the_light() {
    mn::World world;
    mn::make_default_world(world);
    mn::Point point = mn::make_point(-20.0, 20.0, -20.0);

    return !mn::is_shadowed(world, point);
}

bool there_is_no_shadow_when_an_object_is_behind_the_point() {
    mn::World world;
    mn::make_default_world(world);
    mn::Point point = mn::make_point(-2.0, 2.0, -2.0);

    return !mn::is_shadowed(world, point);
}
