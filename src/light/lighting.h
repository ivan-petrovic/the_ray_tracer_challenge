//
// Created by ivan on 18.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_LIGHTING_H
#define THE_RAY_TRACER_CHALLENGE_LIGHTING_H

#include "../Tuple.h"
#include "../Material.h"
#include "PointLight.h"

namespace mn {

    Color lighting(
            const Material &material,
            const PointLight &light,
            const Point &position,
            const Vector &eye,
            const Vector &normal
    );

}

#endif //THE_RAY_TRACER_CHALLENGE_LIGHTING_H
