//
// Created by ivan on 28.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_PATTERN_H
#define THE_RAY_TRACER_CHALLENGE_PATTERN_H

#include <memory>
#include "../Tuple.h"
#include "../Matrix4x4.h"

namespace mn {

    class Pattern {
    public:
        Pattern(const Color &c1, const Color &c2) : _a(c1), _b(c2), _transform{} {
            _transform.identity();
        }

        [[nodiscard]] const Color &a() const { return _a; }

        [[nodiscard]] Color &a() { return _a; }

        void a(const Color &c) { _a = c; }

        [[nodiscard]] const Color &b() const { return _b; }

        [[nodiscard]] Color &b() { return _b; }

        void b(const Color &c) { _b = c; }

        [[nodiscard]] const Matrix4x4 &transform() const { return _transform; }

        void transform(const Matrix4x4 &m) { _transform = m; }

        bool operator==(const Pattern &pattern) const {
            return _a == pattern._a && _b == pattern._b && _transform == pattern._transform;
        }

        bool operator!=(const Pattern &pattern) const {
            return _a != pattern._a || _b != pattern._b || _transform != pattern._transform;
        }

        [[nodiscard]] virtual Color pattern_at(const Point &pattern_point) const = 0;

    protected:
        Color _a, _b;
        Matrix4x4 _transform;

    };

}

#endif //THE_RAY_TRACER_CHALLENGE_STRIPED_PATTERN_H
