//
// Created by ivan on 27.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_STRIPED_PATTERN_H
#define THE_RAY_TRACER_CHALLENGE_STRIPED_PATTERN_H

#include <memory>
#include "../Tuple.h"
#include "../Matrix4x4.h"
#include "Pattern.h"

namespace mn {

    class StripedPattern : public Pattern {
    public:
        StripedPattern(const Color &c1, const Color &c2) : Pattern(c1, c2) {}

        [[nodiscard]] Color pattern_at(const Point &pattern_point) const override {
            if (static_cast<int>(std::floor(pattern_point.x)) % 2 == 0) return _a;
            return _b;
        }

    };

    inline std::unique_ptr<Pattern> make_striped_pattern(const Color &c1, const Color &c2) {
        return std::make_unique<StripedPattern>(c1, c2);
    }

}

#endif //THE_RAY_TRACER_CHALLENGE_STRIPED_PATTERN_H
