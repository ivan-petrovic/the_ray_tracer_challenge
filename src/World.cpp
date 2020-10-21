//
// Created by ivan on 20.10.2020..
//
#include "Tuple.h"
#include "World.h"

namespace mn {

    void make_default_world(World &world) {
        world.light(PointLight(mn::make_point(-10.0, 10.0, -10.0), mn::make_color(1.0, 1.0, 1.0)));

        Sphere s1;
        Material m1(mn::make_color(0.8, 1.0, 0.6), 0.1, 0.7, 0.2, 200.0);
        s1.material(m1);

        Sphere s2;
        s2.transform(scaling(0.5, 0.5, 0.5));

        world.add(s1);
        world.add(s2);
    }

}
