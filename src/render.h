//
// Created by ivan on 24.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_RENDER_H
#define THE_RAY_TRACER_CHALLENGE_RENDER_H

#include "Tuple.h"
#include "model/Object.h"
#include "Material.h"
#include "light/PointLight.h"
#include "intersection/intersect.h"
#include "World.h"
#include "Camera.h"
#include "Canvas.h"

namespace mn {

    Color lighting(
            const Material &material,
            const Object &object,
            const PointLight &light,
            const Point &position,
            const Vector &eye,
            const Vector &normal,
            bool in_shadow = false
    );

    Color shade_hit(const World &world, const Hit &hit);

    Color color_at(const World &world, const Ray &ray);

    void render(const Camera &camera, const World &world, Canvas &canvas);

    bool is_shadowed(const World &world, const Point &point);

    const Color &pattern_at_object(const Pattern &pattern, const Object &object, const Point &world_point);

}

#endif //THE_RAY_TRACER_CHALLENGE_RENDER_H
