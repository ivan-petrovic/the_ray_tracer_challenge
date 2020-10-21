//
// Created by ivan on 20.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_WORLD_H
#define THE_RAY_TRACER_CHALLENGE_WORLD_H

#include <vector>
#include "model/Object.h"
#include "model/Sphere.h"
#include "light/PointLight.h"

namespace mn {

    class World {
    public:
        World() : _light{} {};

        [[nodiscard]] const std::vector<Sphere> &objects() const { return _objects; }

        void add(const Sphere &object) { _objects.push_back(object); }

        [[nodiscard]] const PointLight &light() const { return _light; }

        void light(const PointLight &l) { _light = l; }

    private:
        PointLight _light;
        std::vector<Sphere> _objects;
    };

    void make_default_world(World &world);

}
#endif //THE_RAY_TRACER_CHALLENGE_WORLD_H
