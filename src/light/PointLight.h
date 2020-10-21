//
// Created by ivan on 18.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_POINTLIGHT_H
#define THE_RAY_TRACER_CHALLENGE_POINTLIGHT_H

#include "../Tuple.h"

namespace mn {

    class PointLight {
    public:
        PointLight() = default;

        PointLight(Point p, Color i) : _position(p), _intensity(i) {}

        [[nodiscard]] const Point &position() const { return _position; }

        void position(const Point &p) { _position = p; }

        [[nodiscard]] Color intensity() const { return _intensity; }

        void intensity(const Color &c) { _intensity = c; }

        bool operator==(const PointLight &l) const {
            return _position == l._position && _intensity == l._intensity;
        }

    private:
        Point _position;
        Color _intensity;

    };

}

#endif //THE_RAY_TRACER_CHALLENGE_POINTLIGHT_H
