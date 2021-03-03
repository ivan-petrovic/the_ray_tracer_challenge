//
// Created by ivan on 3.3.2020..
// Chapter 16: Constructive Solid Geometry
//
#include "Tuple.h"
#include "Matrix4x4.h"
#include "Ray.h"
#include "pattern/Checker3DPattern.h"
#include "model/Sphere.h"
#include "model/Cube.h"
#include "model/CSG.h"
#include "light/PointLight.h"
#include "Canvas.h"
#include "canvas_to_file/PPM.h"
#include "Camera.h"
#include "render.h"
#include "World.h"

int main() {
    auto cube = mn::make_cube();
    cube->material().color(mn::make_color(1.0, 1.0, 0.0));
    cube->material().ambient(0.3);
    cube->material().diffuse(0.6);

    auto sphere = mn::make_sphere();
    sphere->material().color(mn::make_color(1.0, 0.0, 0.0));
    sphere->material().ambient(0.3);
    sphere->material().diffuse(0.6);
    sphere->transform(mn::translation(0.5, 0.5, -0.5));

    auto csg1 = mn::make_csg(mn::CSG::UNION, cube.get(), sphere.get());
//    csg1->transform(mn::translation(-3.5, 0.0, -1.0));

//    auto csg2 = mn::make_csg(mn::CSG::DIFFERENCE, cube.get(), sphere.get());
//    csg2->transform(mn::translation(1.5, 0.0, 1.0));

    mn::Point light_position = mn::make_point(-10.0, 10.0, -10.0);
    mn::Color light_color = mn::make_color(1.0, 1.0, 1.0);
    auto p_light = std::make_unique<mn::PointLight>(light_position, light_color);

    mn::World world;
    world.set_light(p_light);
    world.add_object(csg1);
//    world.add_object(csg2);

    mn::Camera camera(800, 400, mn::kPi / 3.0);
    camera.transform(
            mn::view_transform(
                    mn::make_point(5.0, 3.5, -8.0),
                    mn::make_point(0.0, 0.0, 0.0),
                    mn::make_vector(0.0, 1.0, 0.0)
            )
    );

    mn::Canvas canvas(camera.horizontal_size(), camera.vertical_size());
    mn::render(camera, world, canvas);

    mn::PPM ppm;
    ppm.canvas_to_ppm(canvas, "csg.ppm");

    return 0;
}
