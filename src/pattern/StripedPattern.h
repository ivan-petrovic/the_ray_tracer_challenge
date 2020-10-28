//
// Created by ivan on 27.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_STRIPED_PATTERN_H
#define THE_RAY_TRACER_CHALLENGE_STRIPED_PATTERN_H

#include <memory>
#include "../Tuple.h"
#include "../Matrix4x4.h"

namespace mn {

    class StripedPattern {
    public:
        StripedPattern() = default;

        StripedPattern(const Color &c1, const Color &c2) : _a(c1), _b(c2), _transform{} {
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

        bool operator==(const StripedPattern &pattern) const {
            return _a == pattern._a && _b == pattern._b;
        }

        bool operator!=(const StripedPattern &pattern) const {
            return _a != pattern._a || _b != pattern._b;
        }

        [[nodiscard]] const Color &stripe_at(const Point &point) const {
            if (static_cast<int>(std::floor(point.x)) % 2 == 0) return _a;
            return _b;
        }

    private:
        Color _a, _b;
        Matrix4x4 _transform;

    };

    inline std::unique_ptr<StripedPattern> make_striped_pattern(const Color &c1, const Color &c2) {
        return std::make_unique<StripedPattern>(c1, c2);
    }

}

#endif //THE_RAY_TRACER_CHALLENGE_STRIPED_PATTERN_H
