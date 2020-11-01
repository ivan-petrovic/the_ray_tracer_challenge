//
// Created by ivan on 29.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_GRADIENT_PATTERN_H
#define THE_RAY_TRACER_CHALLENGE_GRADIENT_PATTERN_H

#include <memory>
#include "../Tuple.h"
#include "../Matrix4x4.h"
#include "Pattern.h"

namespace mn {

    class GradientPattern : public Pattern {
    public:
        GradientPattern(const Color &c1, const Color &c2) : Pattern(c1, c2) {}

        [[nodiscard]] Color pattern_at(const Point &pattern_point) const override {
            return _a + (_b - _a) * (pattern_point.x - std::floor(pattern_point.x));
        }

    };

    inline std::unique_ptr<Pattern> make_gradient_pattern(const Color &c1, const Color &c2) {
        return std::make_unique<GradientPattern>(c1, c2);
    }

}

#endif //THE_RAY_TRACER_CHALLENGE_GRADIENT_PATTERN_H
