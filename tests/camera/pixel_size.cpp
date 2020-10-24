//
// Created by ivan on 23.10.2020..
//
#include "Camera.h"

bool the_pixel_size_for_a_horizontal_canvas();
bool the_pixel_size_for_a_vertical_canvas();

int main() {
    if (the_pixel_size_for_a_horizontal_canvas() && the_pixel_size_for_a_vertical_canvas()) return 0;
    return 1;
}

bool the_pixel_size_for_a_horizontal_canvas() {
    mn::Camera camera(200, 125, mn::kPiOver2);

    return mn::epsilon_equal(camera.pixel_size(), 0.01);
}

bool the_pixel_size_for_a_vertical_canvas() {
    mn::Camera camera(125, 200, mn::kPiOver2);

    return mn::epsilon_equal(camera.pixel_size(), 0.01);
}
