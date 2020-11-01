//
// Created by ivan on 24.10.2020..
// Chapter 10: Patterns
//
#include "Tuple.h"
#include "Matrix4x4.h"
#include "Ray.h"
#include "pattern/StripedPattern.h"
#include "pattern/Checker3DPattern.h"
#include "pattern/RingPattern.h"
#include "pattern/GradientPattern.h"
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
            mn::make_color(0.0, 0.8, 0.0),
            mn::make_color(0.0, 0.0, 0.8)
    ));

    auto wall = mn::make_plane();
    wall->transform(mn::translation(0.0, 0.0, 5.0) * mn::rotation_x(mn::deg_to_rad(-90.0)));
    wall->material().set_pattern(mn::make_striped_pattern(
            mn::make_color(0.5, 0.1, 0.0),
            mn::make_color(0.0, 0.1, 0.5)
    ));
    wall->material().pattern().transform(mn::rotation_y(mn::deg_to_rad(30.0)));

    auto middle = mn::make_sphere();
    middle->transform(mn::translation(-0.5, 0.7, 0.5) *
                      mn::rotation_y(mn::kPi / 4.0));
    middle->material().set_pattern(mn::make_ring_pattern(
            mn::make_color(1.0, 1.0, 1.0),
            mn::make_color(0.1, 0.0, 0.5)
    ));
    middle->material().pattern().transform(
            mn::scaling(0.3, 0.3, 0.3) *
            mn::rotation_z(mn::kPi / 4.0)
    );

    auto right = mn::make_sphere();
    right->transform(mn::translation(1.5, 0.5, -0.5) * mn::scaling(0.5, 0.5, 0.5));
    right->material().set_pattern(mn::make_gradient_pattern(
            mn::make_color(0.5, 0.0, 0.0),
            mn::make_color(0.5, 0.5, 0.0)
    ));

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
    world.add_object(wall);
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
