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

    const int kRemaining = 5;

    Color shade_hit(const World &world, const Hit &hit, int remaining = kRemaining);

    Color color_at(const World &world, const Ray &ray, int remaining = kRemaining);

    void render(const Camera &camera, const World &world, Canvas &canvas);

    bool is_shadowed(const World &world, const Point &point);

    Color pattern_at_object(const Pattern &pattern, const Object &object, const Point &world_point);

    Color reflected_color(const World &world, const Hit &hit, int remaining = kRemaining);

    Color refracted_color(const World &world, const Hit &hit, int remaining = kRemaining);

    double schlick(const Hit &hit);
}

#endif //THE_RAY_TRACER_CHALLENGE_RENDER_H
