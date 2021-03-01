//
// Created by ivan on 5.12.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_CYLINDER_H
#define THE_RAY_TRACER_CHALLENGE_CYLINDER_H

#include <memory>
#include "Object.h"
#include "../Ray.h"

namespace mn {

    class Cylinder : public Object {
    public:
        Cylinder() : Object(), _minimum(-kInfinity), _maximum(kInfinity), _closed(false) {}

        void local_intersect(const Ray &object_ray, Intersections &intersections) const override {
            const double a = object_ray.direction().x * object_ray.direction().x +
                             object_ray.direction().z * object_ray.direction().z;
            // ray is parallel to the y axis
            if (!epsilon_equal(a, 0.0)) {
                const double b = 2.0 * object_ray.origin().x * object_ray.direction().x +
                                 2.0 * object_ray.origin().z * object_ray.direction().z;
                const double c = object_ray.origin().x * object_ray.origin().x +
                                 object_ray.origin().z * object_ray.origin().z - 1.0;

                const double disc = b * b - 4 * a * c;

                // ray does not intersect the cylinder
                if (disc < 0.0) return;

                const double sqrt_disc = std::sqrt(disc);
                double t0 = (-b - sqrt_disc) / (2 * a);
                double t1 = (-b + sqrt_disc) / (2 * a);

                if (t0 > t1) {
                    const double t_temp = t0;
                    t0 = t1;
                    t1 = t_temp;
                }

                const double y0 = object_ray.origin().y + t0 * object_ray.direction().y;
                if (_minimum < y0 && y0 < _maximum) {
                    intersections.add(t0, this);
                }

                const double y1 = object_ray.origin().y + t1 * object_ray.direction().y;
                if (_minimum < y1 && y1 < _maximum) {
                    intersections.add(t1, this);
                }
            }

            intersect_caps(object_ray, intersections);
        }

        // We assume object_point is on the cylinder.
        // For example it is ray-cylinder intersection point.
        [[nodiscard]] Vector local_normal_at(const Point &object_point, Intersection intersection) const override {
            // compute the square of the distance from the y axis
            const double dist = object_point.x * object_point.x + object_point.z * object_point.z;

            if (dist < 1.0 && object_point.y >= _maximum - mn::kEpsilon)
                return make_vector(0.0, 1.0, 0.0);
            else if (dist < 1.0 && object_point.y <= _minimum + mn::kEpsilon)
                return make_vector(0.0, -1.0, 0.0);
            else
                return make_vector(object_point.x, 0.0, object_point.z);
        }

        [[nodiscard]] double minimum() const { return _minimum; }

        void minimum(double m) { _minimum = m; }

        [[nodiscard]] double maximum() const { return _maximum; }

        void maximum(double m) { _maximum = m; }

        [[nodiscard]] bool closed() const { return _closed; }

        void closed(bool flag) { _closed = flag; }

    private:
        double _minimum, _maximum;
        bool _closed;

        // a helper function to reduce duplication.
        // checks to see if the intersection at 't' is within a radius
        // of 1 (the radius of your cylinders) from the y axis.
        [[nodiscard]] static bool check_cap(const Ray &object_ray, double t) {
            const double x = object_ray.origin().x + t * object_ray.direction().x;
            const double z = object_ray.origin().z + t * object_ray.direction().z;

            return (x * x + z * z) <= 1.0;
        }

        void intersect_caps(const Ray &object_ray, Intersections &intersections) const {
            // caps only matter if the cylinder is closed, and might possibly be
            // intersected by the ray
            if (!_closed || epsilon_equal(object_ray.direction().y, 0.0))
                return;

            // check for an intersection with the lower end cap by intersecting
            // the ray with the plane at y = _minimum
            double t = (_minimum - object_ray.origin().y) / object_ray.direction().y;
            if (check_cap(object_ray, t)) {
                intersections.add(t, this);
            }

            // check for an intersection with the upper end cap by intersecting
            // the ray with the plane at y = _maximum
            t = (_maximum - object_ray.origin().y) / object_ray.direction().y;
            if (check_cap(object_ray, t)) {
                intersections.add(t, this);
            }
        }

    };

    inline std::unique_ptr<Object> make_cylinder() {
        return std::make_unique<Cylinder>();
    }

}
#endif //THE_RAY_TRACER_CHALLENGE_CYLINDER_H
