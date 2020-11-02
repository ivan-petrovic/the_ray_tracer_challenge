//
// Created by ivan on 24.10.2020..
// Chapter 10: Patterns
//
#include "Tuple.h"
#include "Matrix4x4.h"
#include "Ray.h"
#include "pattern/Checker3DPattern.h"
#include "model/Sphere.h"
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
    floor->material().reflective(0.8);

    auto ball = mn::make_sphere();
    ball->transform(mn::translation(-0.5, 1.0, 2.5));
    ball->material().color(mn::make_color(0.5, 0.1, 0.1));
    ball->material().reflective(0.1);

    mn::Point light_position = mn::make_point(-10.0, 10.0, -10.0);
    mn::Color light_color = mn::make_color(1.0, 1.0, 1.0);
    auto p_light = std::make_unique<mn::PointLight>(light_position, light_color);

    mn::World world;
    world.set_light(p_light);
    world.add_object(floor);
    world.add_object(ball);

    mn::Camera camera(600, 300, mn::kPi / 3.0);
    camera.transform(
            mn::view_transform(
                    mn::make_point(0.0, 1.5, -5.0),
                    mn::make_point(0.0, 1.0, 0.0),
                    mn::make_vector(0.0, 1.0, 0.0)
            )
    );

    mn::Canvas canvas(camera.horizontal_size(), camera.vertical_size());
    mn::render(camera, world, canvas);

    mn::PPM ppm;
    ppm.canvas_to_ppm(canvas, "reflection.ppm");

    return 0;
}
