//
// Created by ivan on 16.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_OBJECT_H
#define THE_RAY_TRACER_CHALLENGE_OBJECT_H

#include "../Tuple.h"
#include "../Matrix4x4.h"
#include "../Material.h"

namespace mn {

    class Object {
    public:
        Object() :
                _origin(make_point(0.0, 0.0, 0.0)),
                _transform{},
                _material{} {
            _transform.identity();
            make_default_material(_material);
        }

        virtual ~Object() = default;

        [[nodiscard]] const Point &origin() const { return _origin; }

        void origin(const Point &p) { _origin = p; }

        [[nodiscard]] const Matrix4x4 &transform() const { return _transform; }

        void transform(const Matrix4x4 &m) { _transform = m; }

        [[nodiscard]] const Material &material() const { return _material; }

        [[nodiscard]] Material &material() { return _material; }

        void material(const Material &m) { _material = m; }

        [[nodiscard]] virtual Vector normal_at(const Point &world_point) const = 0;

    protected:
        Point _origin;
        Matrix4x4 _transform;
        Material _material;

    };

}

#endif //THE_RAY_TRACER_CHALLENGE_OBJECT_H
