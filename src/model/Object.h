//
// Created by ivan on 16.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_OBJECT_H
#define THE_RAY_TRACER_CHALLENGE_OBJECT_H

#include "../Tuple.h"
#include "../Matrix4x4.h"
#include "../Ray.h"
// #include "../pattern/StripedPattern.h"
#include "../Material.h"
#include "../intersection/Intersections.h"

namespace mn {

    class Object {
    public:
        Object() :
                _origin(make_point(0.0, 0.0, 0.0)),
                _transform{},
                _material{} {
            _transform.identity();
            _material = make_default_material();
        }

        virtual ~Object() = default;

        [[nodiscard]] const Point &origin() const { return _origin; }

        void origin(const Point &p) { _origin = p; }

        [[nodiscard]] const Matrix4x4 &transform() const { return _transform; }

        void transform(const Matrix4x4 &m) { _transform = m; }

        [[nodiscard]] const Material &material() const { return _material; }

        [[nodiscard]] Material &material() { return _material; }

        void material(const Material &m) { _material = m; }

        virtual void local_intersect(const Ray &ray, Intersections &intersections) const = 0;

        [[nodiscard]] virtual Vector local_normal_at(const Point &object_point) const = 0;

        [[nodiscard]] Vector normal_at(const Point &world_point) const {
            Point object_point = inverse(_transform) * world_point;

            Vector object_normal = local_normal_at(object_point);

            // In normal_matrix method last row are all zeros,
            // so after multiplication world_normal.w is 0.0
            Vector world_normal = normal_matrix(_transform) * object_normal;
            world_normal.normalize();

            return world_normal;
        }

    protected:
        Point _origin;
        Matrix4x4 _transform;
        Material _material;

    };

}

#endif //THE_RAY_TRACER_CHALLENGE_OBJECT_H
