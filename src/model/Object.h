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
                _material{},
                _parent{nullptr} {
            _transform.identity();
            _material = make_default_material();
        }

        virtual ~Object() = default;

        [[nodiscard]] const Point &origin() const { return _origin; }

        void origin(const Point &p) { _origin = p; }

        [[nodiscard]] const Matrix4x4 &transform() const { return _transform; }

        [[nodiscard]] Matrix4x4 chained_transform() const {
            if (_parent == nullptr)
                return _transform;

            return _parent->transform() * _transform;
        }

        [[nodiscard]] Point world_to_object(Point point) const {
            if (_parent != nullptr)
                point = _parent->world_to_object(point);

            return inverse(_transform) * point;
        }

        [[nodiscard]] Point normal_to_world(Vector n) const {
            n = transpose(inverse(_transform)) * n;
            n.w = 0.0;
            n.normalize();

            if (_parent != nullptr)
                n = _parent->normal_to_world(n);

            return n;
        }

        void transform(const Matrix4x4 &m) { _transform = m; }

        [[nodiscard]] const Material &material() const { return _material; }

        [[nodiscard]] Material &material() { return _material; }

        void material(const Material &m) { _material = m; }

        bool has_parent() { return _parent != nullptr; }

        void set_parent(Object *parent) { _parent = parent; }

        Object *parent() { return _parent; }

        virtual void local_intersect(const Ray &ray, Intersections &intersections) const = 0;

        [[nodiscard]] virtual Vector local_normal_at(const Point &object_point) const = 0;

        [[nodiscard]] Vector normal_at(const Point &world_point) const {
            Point object_point = world_to_object(world_point);
            Vector object_normal = local_normal_at(object_point);
            return normal_to_world(object_normal);
        }

    protected:
        Point _origin;
        Matrix4x4 _transform;
        Material _material;
        Object *_parent;

    };

}

#endif //THE_RAY_TRACER_CHALLENGE_OBJECT_H
