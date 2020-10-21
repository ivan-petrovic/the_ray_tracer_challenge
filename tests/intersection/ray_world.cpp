//
// Created by ivan on 20.10.2020..
//
#include "Ray.h"
#include "World.h"
#include "intersection/Intersections.h"

bool intersects_a_world_with_a_ray();

int main() {
    if (intersects_a_world_with_a_ray()) return 0;
    return 1;
}

bool intersects_a_world_with_a_ray() {
    mn::World world;
    mn::make_default_world(world);

    mn::Ray ray(mn::make_point(0.0, 0.0, -5.0), mn::make_vector(0.0, 0.0, 1.0));

    mn::Intersections result;
    mn::intersect(ray, world, result);

    if (result.count() != 4) return false;
    if (result[0].t != 4.0) return false;
    if (result[1].t != 4.5) return false;
    if (result[2].t != 5.5) return false;
    if (result[3].t != 6.0) return false;

    return true;
}

