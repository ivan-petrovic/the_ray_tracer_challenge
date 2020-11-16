//
// Created by ivan on 26.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_INTERSECT_H
#define THE_RAY_TRACER_CHALLENGE_INTERSECT_H

#include "Intersections.h"
#include "../Ray.h"
#include "../model/Object.h"
#include "../World.h"

namespace mn {

    class Object;

    void intersect(const Ray &ray, const Object &object, Intersections &intersections);

    void intersect(const Ray &ray, const World &world, Intersections &intersections);

    Intersection find_hit(Intersections &intersections);

    Hit prepare_computations(const Intersection &intersection, const Ray &ray, const Intersections &intersections);

}

#endif //THE_RAY_TRACER_CHALLENGE_INTERSECT_H
