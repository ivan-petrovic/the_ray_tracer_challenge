//
// Created by ivan on 24.10.2020..
// Chapter 10: Patterns
//
#include "Tuple.h"
#include "Matrix4x4.h"
#include "Ray.h"
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
    floor->material().color(mn::make_color(1.0, 0.9, 0.9));
    floor->material().specular(0);

    auto middle = mn::make_sphere();
    middle->transform(mn::translation(-0.5, 0.0, 0.5));
    middle->material().set_pattern(mn::make_striped_pattern(
            mn::make_color(0.5, 0.0, 0.0),
            mn::make_color(0.0, 0.0, 0.5)
    ));
    middle->material().pattern().transform(mn::scaling(0.1, 0.1, 0.1));
    middle->material().color(mn::make_color(0.1, 1.0, 0.5));
    middle->material().diffuse(0.7);
    middle->material().specular(0.3);

    auto right = mn::make_sphere();
    right->transform(mn::translation(1.5, 0.5, -0.5) * mn::scaling(0.5, 0.5, 0.5));
    right->material().color(mn::make_color(0.5, 1.0, 0.1));
    right->material().diffuse(0.7);
    right->material().specular(0.3);

    auto left = mn::make_sphere();
    left->transform(mn::translation(-1.5, 0.33, -0.75) * mn::scaling(0.33, 0.33, 0.33));
    left->material().color(mn::make_color(1.0, 0.8, 0.1));
    left->material().diffuse(0.7);
    left->material().specular(0.3);

    mn::Point light_position = mn::make_point(-10.0, 10.0, -10.0);
    mn::Color light_color = mn::make_color(1.0, 1.0, 1.0);
    auto p_light = std::make_unique<mn::PointLight>(light_position, light_color);

    mn::World world;
    world.set_light(p_light);
    world.add_object(floor);
    world.add_object(middle);
    world.add_object(right);
    world.add_object(left);

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
    ppm.canvas_to_ppm(canvas, "patterns.ppm");

    return 0;
}
