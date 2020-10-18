//
// Created by ivan on 18.10.2020..
//
#include "light/PointLight.h"

int main() {
    mn::Point position = mn::point(0.0, 0.0, 0.0);
    mn::Color intensity = mn::color(1.0, 1.0, 1.0);

    mn::PointLight light(position, intensity);

    if (light.position() == position && light.intensity() == intensity) return 0;
    return 1;
}
