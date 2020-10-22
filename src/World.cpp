//
// Created by ivan on 20.10.2020..
//
#include "Tuple.h"
#include "World.h"

namespace mn {

    void make_default_world(World &world) {
        auto p_light = std::make_unique<PointLight>();
        p_light->position(mn::make_point(-10.0, 10.0, -10.0));
        p_light->intensity(mn::make_color(1.0, 1.0, 1.0));
        world.set_light(p_light);

        auto s1 = make_sphere();
        s1->material().color(mn::make_color(0.8, 1.0, 0.6));
        s1->material().ambient(0.1);
        s1->material().diffuse(0.7);
        s1->material().specular(0.2);
        s1->material().shininess(200.0);
        world.add_object(s1);

        auto s2 = make_sphere();
        s2->transform(scaling(0.5, 0.5, 0.5));
        world.add_object(s2);
    }

}
