//
// Created by ivan on 18.10.2020..
//
#include "Tuple.h"
#include "Material.h"
#include "light/PointLight.h"
#include "light/lighting.h"

bool lighting_with_the_eye_between_the_light_and_the_surface();

bool lighting_with_the_eye_between_the_light_and_the_surface_with_eye_offset_45();

bool lighting_with_the_eye_between_the_light_and_the_surface_with_light_offset_45();

bool lighting_with_the_eye_in_the_path_of_the_reflection_vector();

bool lighting_with_the_light_behind_the_surface();


int main() {
    if (
            lighting_with_the_eye_between_the_light_and_the_surface() &&
            lighting_with_the_eye_between_the_light_and_the_surface_with_eye_offset_45() &&
            lighting_with_the_eye_between_the_light_and_the_surface_with_light_offset_45() &&
            lighting_with_the_eye_in_the_path_of_the_reflection_vector() &&
            lighting_with_the_light_behind_the_surface()
            )
        return 0;
    return 1;
}

bool lighting_with_the_eye_between_the_light_and_the_surface() {
    mn::Material material{};
    mn::make_default_material(material);
    mn::Point position = mn::make_point(0.0, 0.0, 0.0);

    mn::Vector eye = mn::make_vector(0.0, 0.0, -1.0);
    mn::Vector normal = mn::make_vector(0.0, 0.0, -1.0);
    mn::PointLight light(mn::make_point(0.0, 0.0, -10.0), mn::make_color(1.0, 1.0, 1.0));

    mn::Color result = mn::lighting(material, light, position, eye, normal);

    return result == mn::make_color(1.9, 1.9, 1.9);
}

bool lighting_with_the_eye_between_the_light_and_the_surface_with_eye_offset_45() {
    mn::Material material{};
    mn::make_default_material(material);
    mn::Point position = mn::make_point(0.0, 0.0, 0.0);

    const double half_sqrt_of_2 = std::sqrt(2.0) / 2;
    mn::Vector eye = mn::make_vector(0.0, half_sqrt_of_2, -half_sqrt_of_2);
    mn::Vector normal = mn::make_vector(0.0, 0.0, -1.0);
    mn::PointLight light(mn::make_point(0.0, 0.0, -10.0), mn::make_color(1.0, 1.0, 1.0));

    mn::Color result = mn::lighting(material, light, position, eye, normal);

    return result == mn::make_color(1.0, 1.0, 1.0);
}

bool lighting_with_the_eye_between_the_light_and_the_surface_with_light_offset_45() {
    mn::Material material{};
    mn::make_default_material(material);
    mn::Point position = mn::make_point(0.0, 0.0, 0.0);

    mn::Vector eye = mn::make_vector(0.0, 0.0, -1.0);
    mn::Vector normal = mn::make_vector(0.0, 0.0, -1.0);
    mn::PointLight light(mn::make_point(0.0, 10.0, -10.0), mn::make_color(1.0, 1.0, 1.0));

    const double half_sqrt_of_2 = std::sqrt(2.0) / 2;
    mn::Color expected = mn::make_color(
            0.1 + 0.9 * half_sqrt_of_2,
            0.1 + 0.9 * half_sqrt_of_2,
            0.1 + 0.9 * half_sqrt_of_2
    );

    mn::Color result = mn::lighting(material, light, position, eye, normal);

    return mn::epsilon_equal(result, expected);
}

bool lighting_with_the_eye_in_the_path_of_the_reflection_vector() {
    mn::Material material{};
    mn::make_default_material(material);
    mn::Point position = mn::make_point(0.0, 0.0, 0.0);

    const double half_sqrt_of_2 = std::sqrt(2.0) / 2;
    mn::Vector eye = mn::make_vector(0.0, -half_sqrt_of_2, -half_sqrt_of_2);
    mn::Vector normal = mn::make_vector(0.0, 0.0, -1.0);
    mn::PointLight light(mn::make_point(0.0, 10.0, -10.0), mn::make_color(1.0, 1.0, 1.0));

    mn::Color expected = mn::make_color(
            0.1 + 0.9 * half_sqrt_of_2 + 0.9,
            0.1 + 0.9 * half_sqrt_of_2 + 0.9,
            0.1 + 0.9 * half_sqrt_of_2 + 0.9
    );

    mn::Color result = mn::lighting(material, light, position, eye, normal);

    return mn::epsilon_equal(result, expected);
}

bool lighting_with_the_light_behind_the_surface() {
    mn::Material material{};
    mn::make_default_material(material);
    mn::Point position = mn::make_point(0.0, 0.0, 0.0);

    float sqrt_of_2 = 1.41421;
    mn::Vector eye = mn::make_vector(0.0, 0.0, -1.0);
    mn::Vector normal = mn::make_vector(0.0, 0.0, -1.0);
    mn::PointLight light(mn::make_point(0.0, 10.0, 10.0), mn::make_color(1.0, 1.0, 1.0));

    mn::Color result = mn::lighting(material, light, position, eye, normal);

    return result == mn::make_color(0.1, 0.1, 0.1);
}
