//
// Created by ivan on 15.10.2020..
//
#include "World.h"

int main() {
    mn::World world;

    // World contains no objects and has no light source
    if (world.objects().empty()) return 0;
    return 1;
}
