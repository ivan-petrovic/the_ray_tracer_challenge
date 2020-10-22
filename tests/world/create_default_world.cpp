//
// Created by ivan on 20.10.2020..
//
#include "World.h"

int main() {
    mn::World world;
    mn::make_default_world(world);

    mn::PointLight expected_light(mn::make_point(-10.0, 10.0, -10.0), mn::make_color(1.0, 1.0, 1.0));
    mn::Material m1(mn::make_color(0.8, 1.0, 0.6), 0.1, 0.7, 0.2, 200.0);

    if (
            world.light() == expected_light &&
            world.objects()[0]->material() == m1 &&
            world.objects()[1]->transform() == mn::scaling(0.5, 0.5, 0.5)
            )
        return 0;
    return 1;
}
