//
// Created by ivan on 15.10.2020..
//
#include "World.h"

int main() {
    mn::World world;

    // World contains no objects and has no light source
    if (world.is_empty() && !world.has_light()) return 0;
    return 1;
}
