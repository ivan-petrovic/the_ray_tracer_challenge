//
// Created by ivan on 23.10.2020..
//
#include "Camera.h"

bool constructing_a_ray_through_the_center_of_the_canvas();

bool constructing_a_ray_through_a_corner_of_the_canvas();

bool constructing_a_ray_when_the_camera_is_transformed();

int main() {
    if (
            constructing_a_ray_through_the_center_of_the_canvas() &&
            constructing_a_ray_through_a_corner_of_the_canvas() &&
            constructing_a_ray_when_the_camera_is_transformed()
            )
        return 0;
    return 1;
}

bool constructing_a_ray_through_the_center_of_the_canvas() {
    mn::Camera camera(201, 101, mn::kPiOver2);

    mn::Ray ray = camera.ray_for_pixel(100, 50);

    if (ray.origin() != mn::make_point(0.0, 0.0, 0.0)) return false;
    if (ray.direction() != mn::make_vector(0.0, 0.0, -1.0)) return false;

    return true;
}

bool constructing_a_ray_through_a_corner_of_the_canvas() {
    mn::Camera camera(201, 101, mn::kPiOver2);

    mn::Ray ray = camera.ray_for_pixel(0, 0);

    if (ray.origin() != mn::make_point(0.0, 0.0, 0.0)) return false;
    if (!mn::epsilon_equal(ray.direction(), mn::make_vector(0.66519, -0.33259, -0.66851), 0.0001)) return false;

    return true;
}

bool constructing_a_ray_when_the_camera_is_transformed() {
    mn::Camera camera(201, 101, mn::kPiOver2);
    camera.transform(mn::rotation_y(mn::kPiOver2 / 2.0) * mn::translation(0.0, -2.0, 5.0));

    mn::Ray ray = camera.ray_for_pixel(100, 50);

    if (ray.origin() != mn::make_point(0.0, 2.0, -5.0)) return false;
    const double half_sqrt_of_2 = std::sqrt(2.0) / 2;
    if (!mn::epsilon_equal(ray.direction(), mn::make_vector(half_sqrt_of_2, 0.0, -half_sqrt_of_2))) return false;

    return true;
}
