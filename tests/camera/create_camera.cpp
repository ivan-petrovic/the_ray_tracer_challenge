//
// Created by ivan on 22.10.2020..
//
#include "Camera.h"

bool the_default_camera();

int main() {
    if (the_default_camera()) return 0;
    return 1;
}

bool the_default_camera() {
    int h_size = 160, v_size = 120;
    double fov = mn::kPiOver2;
    mn::Camera camera(h_size, v_size, fov);

    if (camera.horizontal_size() != h_size) return false;
    if (camera.vertical_size() != v_size) return false;
    if (camera.field_of_view() != fov) return false;
    if (camera.transform() != mn::identity()) return false;

    return true;
}
