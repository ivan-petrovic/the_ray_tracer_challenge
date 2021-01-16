//
// Created by ivan on 5.12.2020..
// Chapter 12: Cylinders and cones
//
#include "Tuple.h"
#include "Matrix4x4.h"
#include "Ray.h"
#include "pattern/Checker3DPattern.h"
#include "model/Cylinder.h"
#include "model/Cone.h"
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

    auto cylinder1 = mn::make_cylinder();
    cylinder1->material().color(mn::make_color(0.8, 0.0, 0.0));

    auto cylinder2 = mn::make_cylinder();
    auto cyl2 = dynamic_cast<mn::Cylinder*>(cylinder2.get());
    cyl2->minimum(0.5);
    cyl2->maximum(2.5);
    cylinder2->transform(mn::translation(2.0, 0.0, 0.0) * mn::scaling(0.5, 0.5, 0.5));
    cylinder2->material().color(mn::make_color(0.0, 0.8, 0.0));

    auto cone = mn::make_cone();
    auto cone1 = dynamic_cast<mn::Cone*>(cone.get());
    cone1->minimum(-0.5);
    cone1->maximum(1.5);
    // cone1->closed(true);
    cone->transform(mn::translation(-2.0, 1.0, -1.5));
    cone->material().color(mn::make_color(0.4, 0.8, 0.0));

    mn::Point light_position = mn::make_point(-10.0, 10.0, -10.0);
    mn::Color light_color = mn::make_color(1.0, 1.0, 1.0);
    auto p_light = std::make_unique<mn::PointLight>(light_position, light_color);

    mn::World world;
    world.set_light(p_light);
    world.add_object(floor);
    world.add_object(cylinder1);
    world.add_object(cylinder2);
    world.add_object(cone);

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
    ppm.canvas_to_ppm(canvas, "cylinders.ppm");

    return 0;
}
