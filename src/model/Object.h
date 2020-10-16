//
// Created by ivan on 16.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_OBJECT_H
#define THE_RAY_TRACER_CHALLENGE_OBJECT_H

#include "../Tuple.h"
#include "../Matrix4x4.h"
// #include "../Material.h"

namespace mn {

    class Object {
    public:
        explicit Object() : _origin(point(0.0, 0.0, 0.0)), _transform() { _transform.identity(); }

        [[nodiscard]] Point origin() const { return _origin; }

        void origin(const Point &p) { _origin = p; }

        [[nodiscard]] const Matrix4x4 &transform() const { return _transform; }

        void transform(const Matrix4x4 &m) { _transform = m; }

    private:
        Point _origin;
        Matrix4x4 _transform;
//        Material material;

    };

}

#endif //THE_RAY_TRACER_CHALLENGE_OBJECT_H
