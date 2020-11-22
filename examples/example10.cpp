//
// Created by ivan on 22.11.2020..
// Chapter 12: Cubes
//
#include "Tuple.h"
#include "Matrix4x4.h"
#include "Ray.h"
#include "pattern/Checker3DPattern.h"
#include "model/Cube.h"
#include "model/Plane.h"
#include "light/PointLight.h"
#include "Canvas.h"
#include "canvas_to_file/PPM.h"
#include "Camera.h"
#include "render.h"
#include "World.h"

int main() {
    auto floor = mn::make_plane();
    floor->material().set_pattern(mn::make_checker3d_pattern(
            mn::make_color(0.0, 0.0, 0.0),
            mn::make_color(1.0, 1.0, 1.0)
    ));
//    floor->material().color(mn::make_color(0.0, 0.0, 0.3));
    floor->material().reflective(0.8);

    mn::Matrix4x4 leg_scale = mn::scaling(0.1, 1.0, 0.1);

    auto leg1 = mn::make_cube();
    leg1->transform(mn::translation(1.5, 1.0, 1.5) * leg_scale);
    leg1->material().color(mn::make_color(0.8, 0.0, 0.0));

    auto leg2 = mn::make_cube();
    leg2->transform(mn::translation(-1.5, 1.0, 1.5) * leg_scale);
    leg2->material().color(mn::make_color(0.0, 0.8, 0.0));

    auto leg3 = mn::make_cube();
    leg3->transform(mn::translation(-1.5, 1.0, -1.5) * leg_scale);
    leg3->material().color(mn::make_color(0.0, 0.0, 0.8));

    auto leg4 = mn::make_cube();
    leg4->transform(mn::translation(1.5, 1.0, -1.5) * leg_scale);
    leg4->material().color(mn::make_color(0.8, 0.8, 0.0));

    auto table_top = mn::make_cube();
    table_top->transform(mn::translation(0.0, 2.0, 0.0) * mn::scaling(1.7, 0.1, 1.7));
    table_top->material().color(mn::make_color(0.8, 0.8, 0.8));

    mn::Point light_position = mn::make_point(-10.0, 10.0, -10.0);
    mn::Color light_color = mn::make_color(1.0, 1.0, 1.0);
    auto p_light = std::make_unique<mn::PointLight>(light_position, light_color);

    mn::World world;
    world.set_light(p_light);
    world.add_object(floor);
    world.add_object(leg1);
    world.add_object(leg2);
    world.add_object(leg3);
    world.add_object(leg4);
    world.add_object(table_top);

    mn::Camera camera(600, 300, mn::kPi / 3.0);
    camera.transform(
            mn::view_transform(
                    mn::make_point(6.0, 4.0, -6.0),
                    mn::make_point(0.0, 1.0, 0.0),
                    mn::make_vector(0.0, 1.0, 0.0)
            )
    );

    mn::Canvas canvas(camera.horizontal_size(), camera.vertical_size());
    mn::render(camera, world, canvas);

    mn::PPM ppm;
    ppm.canvas_to_ppm(canvas, "table.ppm");

    return 0;
}
