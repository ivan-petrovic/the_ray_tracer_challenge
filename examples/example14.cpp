//
// Created by ivan on 1.3.2021..
// Chapter 15: Smooth triangles and OBJ files
//
#include "Tuple.h"
#include "Matrix4x4.h"
#include "Ray.h"
#include "obj_parser/OBJ_Parser.h"
#include "model/Cylinder.h"
#include "Canvas.h"
#include "canvas_to_file/PPM.h"
#include "Camera.h"
#include "render.h"
#include "World.h"


int main() {
    mn::OBJ_Parser parser;
    parser.parse_file("teapot-low.obj");

    auto group = mn::make_group();
    auto g = dynamic_cast<mn::Group *>(group.get());

    auto obj = parser.obj_to_group();

    for (auto object : obj.objects()) {
        g->add_child(object);
    }

    mn::Point light_position = mn::make_point(-10.0, 10.0, -10.0);
    mn::Color light_color = mn::make_color(1.0, 1.0, 1.0);
    auto p_light = std::make_unique<mn::PointLight>(light_position, light_color);

    mn::World world;
    world.set_light(p_light);
    world.add_object(group);

    mn::Camera camera(600, 300, mn::kPi / 3.0);
    camera.transform(
            mn::view_transform(
                    mn::make_point(24.0, 16.0, -8.0),
                    mn::make_point(0.0, 0.0, 0.0),
                    mn::make_vector(0.0, 1.0, 0.0)
            )
    );

    mn::Canvas canvas(camera.horizontal_size(), camera.vertical_size());
    mn::render(camera, world, canvas);

    mn::PPM ppm;
    ppm.canvas_to_ppm(canvas, "smooth_triangles.ppm");

    return 0;
}
