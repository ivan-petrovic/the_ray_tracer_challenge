//
// Created by ivan on 29.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_CHECKER_3D_PATTERN_H
#define THE_RAY_TRACER_CHALLENGE_CHECKER_3D_PATTERN_H

#include <memory>
#include "../Tuple.h"
#include "../Matrix4x4.h"
#include "Pattern.h"

namespace mn {

    class Checker3DPattern : public Pattern {
    public:
        Checker3DPattern(const Color &c1, const Color &c2) : Pattern(c1, c2) {}

        [[nodiscard]] Color pattern_at(const Point &pattern_point) const override {
            int f = static_cast<int>(std::floor(pattern_point.x) +std::floor(pattern_point.y) + std::floor(pattern_point.z)) % 2;
            if (f == 0) return _a;
            return _b;
        }

    };

    inline std::unique_ptr<Pattern> make_checker3d_pattern(const Color &c1, const Color &c2) {
        return std::make_unique<Checker3DPattern>(c1, c2);
    }

}

#endif //THE_RAY_TRACER_CHALLENGE_CHECKER_3D_PATTERN_H
