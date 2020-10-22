//
// Created by ivan on 18.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_LIGHTING_H
#define THE_RAY_TRACER_CHALLENGE_LIGHTING_H

#include "../Tuple.h"
#include "../Material.h"
#include "PointLight.h"
#include "../World.h"
#include "../intersection/Intersections.h"

namespace mn {

    Color lighting(
            const Material &material,
            const PointLight &light,
            const Point &position,
            const Vector &eye,
            const Vector &normal
    );

    Color shade_hit(const World &world, const Hit &hit);

    Color color_at(const World &world, const Ray &ray);

}

#endif //THE_RAY_TRACER_CHALLENGE_LIGHTING_H
