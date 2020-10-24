//
// Created by ivan on 23.10.2020..
//
#include "render.h"

bool rendering_a_world_with_a_camera();

int main() {
    if (rendering_a_world_with_a_camera())return 0;
    return 1;
}

bool rendering_a_world_with_a_camera() {
    mn::World world;
    mn::make_default_world(world);

    mn::Camera camera(11, 11, mn::kPiOver2);

    mn::Point from = mn::make_point(0.0, 0.0, -5.0);
    mn::Point to = mn::make_point(0.0, 0.0, 0.0);
    mn::Vector up = mn::make_vector(0.0, 1.0, 0.0);

    camera.transform(mn::view_transform(from, to, up));

    mn::Canvas canvas(camera.horizontal_size(), camera.vertical_size());
    mn::render(camera, world, canvas);

    return mn::epsilon_equal(canvas.pixel_at(5, 5), mn::make_color(0.38066, 0.47583, 0.2855), 0.00001);
}
