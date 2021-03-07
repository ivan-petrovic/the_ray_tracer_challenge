//
// Created by ivan on 21.2.2021..
//

#ifndef THE_RAY_TRACER_CHALLENGE_TRIANGLE_H
#define THE_RAY_TRACER_CHALLENGE_TRIANGLE_H

#include <memory>
#include "Object.h"
#include "../Ray.h"

namespace mn {

    class Triangle : public Object {
    public:
        Triangle(Point p1, Point p2, Point p3) : Object() {
            _p1 = p1;
            _p2 = p2;
            _p3 = p3;
            _e1 = p2 - p1;
            _e2 = p3 - p1;
            _n = normalize(cross(_e2, _e1));
        }

        [[nodiscard]] Point p1() const { return _p1; }

        [[nodiscard]] Point p2() const { return _p2; }

        [[nodiscard]] Point p3() const { return _p3; }

        [[nodiscard]] Vector normal() const { return _n; }

        [[nodiscard]] Vector e1() const { return _e1; }

        [[nodiscard]] Vector e2() const { return _e2; }

        // Fast, Minimum Storage Ray-Triangle Intersection
        // Tomas Moller & Ben Trumbore
        // https://www.tandfonline.com/doi/abs/10.1080/10867651.1997.10487468
        void local_intersect(const Ray &object_ray, Intersections &intersections) const override {
            Vector dir_cross_e2 = cross(object_ray.direction(), _e2);
            double det = dot(_e1, dir_cross_e2);

            if (epsilon_equal(det, 0.0)) return;

            double f = 1.0 / det;
            Vector p1_to_origin = object_ray.origin() - _p1;
            double u = f * dot(p1_to_origin, dir_cross_e2);

            if (u < 0.0 || u > 1.0) return;

            Vector origin_cross_e1 = cross(p1_to_origin, _e1);
            double v = f * dot(object_ray.direction(), origin_cross_e1);

            if (v < 0.0 || (u + v) > 1.0) return;

            double t = f * dot(_e2, origin_cross_e1);
            intersections.add(t, this);
        }

        // We assume object_point is in (and on) the triangle.
        // For example it is ray-triangle intersection point.
        [[nodiscard]] Vector local_normal_at(const Point &object_point, Intersection intersection) const override {
            return _n;
        }

    private:
        Point _p1, _p2, _p3;
        Vector _e1, _e2, _n;
    };

    inline std::unique_ptr<Object> make_triangle(Point p1, Point p2, Point p3) {
        return std::make_unique<Triangle>(p1, p2, p3);
    }

}

#endif //THE_RAY_TRACER_CHALLENGE_TRIANGLE_H
