//
// Created by ivan on 3.2.2021..
// Chapter 14: Groups
//
#include "Tuple.h"
#include "Matrix4x4.h"
#include "Ray.h"
#include "model/Sphere.h"
#include "model/Cylinder.h"
#include "model/Group.h"
#include "light/PointLight.h"
#include "Canvas.h"
#include "canvas_to_file/PPM.h"
#include "Camera.h"
#include "render.h"
#include "World.h"

mn::Sphere hexagon_corner() {
    mn::Sphere corner;
    corner.transform(mn::translation(0.0, 0.0, -1.0) * mn::scaling(0.25, 0.25, 0.25));

    return corner;
}

mn::Cylinder hexagon_edge() {
    mn::Cylinder edge;
    edge.minimum(0.0);
    edge.maximum(1.0);
    edge.transform(
            mn::translation(0.0, 0.0, -1.0) *
            mn::rotation_y(-mn::kPi / 6.0) *
            mn::rotation_z(-mn::kPiOver2) *
            mn::scaling(0.25, 1.0, 0.25));

    return edge;
}

mn::Group hexagon_side(mn::Sphere *sphere, mn::Cylinder *cylinder) {
    mn::Group side;
    side.add_child(sphere);
    side.add_child(cylinder);

    return side;
}


int main() {
    mn::Sphere sph = hexagon_corner();
    mn::Cylinder cyl = hexagon_edge();
    mn::Group side[6];

    auto hex = mn::make_group();

    auto group = dynamic_cast<mn::Group *>(hex.get());
    for (int i = 0; i < 6; ++i) {
        side[i] = hexagon_side(&sph, &cyl);
        side[i].transform(mn::rotation_y(i * mn::kPi / 3.0));
        group->add_child(&side[i]);
    }

    mn::Point light_position = mn::make_point(-10.0, 10.0, -10.0);
    mn::Color light_color = mn::make_color(1.0, 1.0, 1.0);
    auto p_light = std::make_unique<mn::PointLight>(light_position, light_color);

    mn::World world;
    world.set_light(p_light);
    world.add_object(hex);

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
    ppm.canvas_to_ppm(canvas, "groups.ppm");

    return 0;
}
