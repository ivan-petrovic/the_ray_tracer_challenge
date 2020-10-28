//
// Created by ivan on 28.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_TEST_PATTERN_H
#define THE_RAY_TRACER_CHALLENGE_TEST_PATTERN_H

#include <memory>
#include "pattern/Pattern.h"

namespace mn {

    class TestPattern : public Pattern {
    public:
        TestPattern() : Pattern(
                make_color(0.0, 0.0, 0.0),
                make_color(1.0, 1.0, 1.0)
                ), c{} {}

        [[nodiscard]] const Color &pattern_at(const Point &pattern_point) const override {
            c = make_color(pattern_point.x, pattern_point.y, pattern_point.z);
            return c;
        };

        mutable Color c;
    };

}

#endif //THE_RAY_TRACER_CHALLENGE_TEST_PATTERN_H
