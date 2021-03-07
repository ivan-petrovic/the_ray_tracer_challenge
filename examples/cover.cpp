//
// Created by ivan on 7.3.2020..
// Cover Page of the Book: The Ray Tracer Challenge
//
#include "Tuple.h"
#include "Matrix4x4.h"
#include "Ray.h"
#include "pattern/Checker3DPattern.h"
#include "model/Plane.h"
#include "model/Sphere.h"
#include "model/Cube.h"
#include "Canvas.h"
#include "canvas_to_file/PPM.h"
#include "Camera.h"
#include "render.h"
#include "World.h"

int main() {
    // =======================================================
    // the camera
    // =======================================================
    mn::Camera camera(1024, 1024, 0.785);
    camera.transform(
            mn::view_transform(
                    mn::make_point(-6.0, 6.0, -10.0),
                    mn::make_point(6.0, 0.0, 6.0),
                    mn::make_vector(-0.45, 1.0, 0.0)
            )
    );

    // =======================================================
    // light sources
    // =======================================================
    mn::Point light_position = mn::make_point(50.0, 100.0, -50.0);
    mn::Color light_intensity = mn::make_color(1.0, 1.0, 1.0);
    auto p_light = std::make_unique<mn::PointLight>(light_position, light_intensity);

    // an optional second light for additional illumination
    // multiple lights not supported - yet :)
    // mn::Point light_position1 = mn::make_point(-400.0, 50.0, -10.0);
    // mn::Color light_intensity1 = mn::make_color(0.2, 0.2, 0.2);
    // auto p_light1 = std::make_unique<mn::PointLight>(light_position1, light_intensity1);

    // =======================================================
    // define some constants to avoid duplication
    // =======================================================
    mn::Material white_material;
    white_material.color(mn::make_color(1.0, 1.0, 1.0));
    white_material.diffuse(0.7);
    white_material.ambient(0.1);
    white_material.specular(0.0);
    white_material.reflective(0.1);

    mn::Material blue_material;
    blue_material.color(mn::make_color(0.537, 0.831, 0.914));
    blue_material.diffuse(0.7);
    blue_material.ambient(0.1);
    blue_material.specular(0.0);
    blue_material.reflective(0.1);

    mn::Material red_material;
    red_material.color(mn::make_color(0.941, 0.322, 0.388));
    red_material.diffuse(0.7);
    red_material.ambient(0.1);
    red_material.specular(0.0);
    red_material.reflective(0.1);

    mn::Material purple_material;
    purple_material.color(mn::make_color(0.373, 0.404, 0.550));
    purple_material.diffuse(0.7);
    purple_material.ambient(0.1);
    purple_material.specular(0.0);
    purple_material.reflective(0.1);

    mn::Matrix4x4 standard_transform = mn::scaling(0.5, 0.5, 0.5) * mn::translation(1.0, -1.0, 1.0);
    mn::Matrix4x4 large_object = mn::scaling(3.5, 3.5, 3.5) * standard_transform;
    mn::Matrix4x4 medium_object = mn::scaling(3.0, 3.0, 3.0) * standard_transform;
    mn::Matrix4x4 small_object = mn::scaling(2.0, 2.0, 2.0) * standard_transform;

    // =======================================================
    // white backdrop for the scene
    // =======================================================
    auto plane = mn::make_plane();
    plane->material().color(mn::make_color(1.0, 1.0, 1.0));
    plane->material().ambient(1.0);
    plane->material().diffuse(0.0);
    plane->material().specular(0.0);
    plane->transform(mn::translation(0.0, 0.0, 500) * mn::rotation_x(mn::kPiOver2));

    // =======================================================
    // describe the elements of the scene
    // =======================================================
    auto sphere = mn::make_sphere();
    sphere->material().color(mn::make_color(0.373, 0.404, 0.550));
    sphere->material().diffuse(0.2);
    sphere->material().ambient(0.0);
    sphere->material().specular(1.0);
    sphere->material().shininess(200.0);
    sphere->material().reflective(0.7);
    sphere->material().transparency(0.7);
    sphere->material().refractive_index(1.5);
    sphere->transform(large_object);

    auto cube01 = mn::make_cube();
    cube01->material(white_material);
    cube01->transform(mn::translation(4.0, 0.0, 0.0) * medium_object);

    auto cube02 = mn::make_cube();
    cube02->material(blue_material);
    cube02->transform(mn::translation(8.5, 1.5, -0.5) * large_object);

    auto cube03 = mn::make_cube();
    cube03->material(red_material);
    cube03->transform(mn::translation(0.0, 0.0, 4.0) * large_object);

    auto cube04 = mn::make_cube();
    cube04->material(white_material);
    cube04->transform(mn::translation(4.0, 0.0, 4.0) * small_object);

    auto cube05 = mn::make_cube();
    cube05->material(purple_material);
    cube05->transform(mn::translation(7.5, 0.5, 4.0) * medium_object);

    auto cube06 = mn::make_cube();
    cube06->material(white_material);
    cube06->transform(mn::translation(-0.25, 0.25, 8.0) * medium_object);

    auto cube07 = mn::make_cube();
    cube07->material(blue_material);
    cube07->transform(mn::translation(4.0, 1.0, 7.5) * large_object);

    auto cube08 = mn::make_cube();
    cube08->material(red_material);
    cube08->transform(mn::translation(10.0, 2.0, 7.5) * medium_object);

    auto cube09 = mn::make_cube();
    cube09->material(white_material);
    cube09->transform(mn::translation(8.0, 2.0, 12.0) * small_object);

    auto cube10 = mn::make_cube();
    cube10->material(white_material);
    cube10->transform(mn::translation(20.0, 1.0, 9.0) * small_object);

    auto cube11 = mn::make_cube();
    cube11->material(blue_material);
    cube11->transform(mn::translation(-0.5, -5.0, 0.25) * large_object);

    auto cube12 = mn::make_cube();
    cube12->material(red_material);
    cube12->transform(mn::translation(4.0, -4.0, 0.0) * large_object);

    auto cube13 = mn::make_cube();
    cube13->material(white_material);
    cube13->transform(mn::translation(8.5, -4.0, 0.0) * large_object);

    auto cube14 = mn::make_cube();
    cube14->material(white_material);
    cube14->transform(mn::translation(0.0, -4.0, 4.0) * large_object);

    auto cube15 = mn::make_cube();
    cube15->material(purple_material);
    cube15->transform(mn::translation(-0.5, -4.5, 8.0) * large_object);

    auto cube16 = mn::make_cube();
    cube16->material(white_material);
    cube16->transform(mn::translation(0.0, -8.0, 4.0) * large_object);

    auto cube17 = mn::make_cube();
    cube17->material(white_material);
    cube17->transform(mn::translation(-0.5, -8.5, 8.0) * large_object);

    // =======================================================
    // add objects to world
    // =======================================================
    mn::World world;
    world.set_light(p_light);
    world.add_object(plane);
    world.add_object(sphere);
    world.add_object(cube01);
    world.add_object(cube02);
    world.add_object(cube03);
    world.add_object(cube04);
    world.add_object(cube05);
    world.add_object(cube06);
    world.add_object(cube07);
    world.add_object(cube08);
    world.add_object(cube09);
    world.add_object(cube10);
    world.add_object(cube11);
    world.add_object(cube12);
    world.add_object(cube13);
    world.add_object(cube14);
    world.add_object(cube15);
    world.add_object(cube16);
    world.add_object(cube17);

    mn::Canvas canvas(camera.horizontal_size(), camera.vertical_size());
    mn::render(camera, world, canvas);

    mn::PPM ppm;
    ppm.canvas_to_ppm(canvas, "cover_page.ppm");

    return 0;
}
