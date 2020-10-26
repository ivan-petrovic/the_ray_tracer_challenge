//
// Created by ivan on 15.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_RAY_H
#define THE_RAY_TRACER_CHALLENGE_RAY_H

#include "Tuple.h"
#include "Matrix4x4.h"

namespace mn {

    class Ray {
    public:
        Ray() : _origin{}, _direction{} {}

        Ray(Point origin_, Vector direction_) : _origin(origin_), _direction(direction_) {}

        [[nodiscard]] Point origin() const { return _origin; }

        void origin(const Point &p) { _origin = p; }

        [[nodiscard]] Vector direction() const { return _direction; }

        void direction(const Vector &v) { _direction = v; }

        [[nodiscard]] Point position(double t) const { return _origin + t * _direction; }

        [[nodiscard]] Ray transform(const Matrix4x4 &m) const { return Ray(m * _origin, m * _direction); }

    private:
        Point _origin;
        Vector _direction;
    };

    inline Ray transform(const Ray &ray, const Matrix4x4 &m) { return ray.transform(m); }

}

#endif //THE_RAY_TRACER_CHALLENGE_RAY_H
