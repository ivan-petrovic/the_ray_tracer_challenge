//
// Created by ivan on 20.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_WORLD_H
#define THE_RAY_TRACER_CHALLENGE_WORLD_H

#include <vector>
#include <memory>
#include "model/Object.h"
#include "model/Sphere.h"
#include "light/PointLight.h"

namespace mn {

    class World {
    public:
        World() = default;

        [[nodiscard]] const std::vector<std::unique_ptr<Object>> &objects() const { return _objects; }

        void add_object(std::unique_ptr<Object> &p_object) { _objects.push_back(std::move(p_object)); }

        void set_light(std::unique_ptr<PointLight> &p_light) { _light = std::move(p_light); }

        // [[nodiscard]] const std::unique_ptr<PointLight> &light() const { return _light; }
        [[nodiscard]] const PointLight &light() const { return *_light; }

        [[nodiscard]] PointLight &light() { return *_light; }

        void light(const PointLight &l) { *_light = l; }

        [[nodiscard]] bool has_light() const { return _light != nullptr; }

        [[nodiscard]] bool is_empty() const { return _objects.empty(); }

    private:
        std::unique_ptr<PointLight> _light;
        std::vector<std::unique_ptr<Object>> _objects;
    };

    void make_default_world(World &world);

}
#endif //THE_RAY_TRACER_CHALLENGE_WORLD_H
