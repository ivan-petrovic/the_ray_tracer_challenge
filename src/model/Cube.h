//
// Created by ivan on 22.11.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_CUBE_H
#define THE_RAY_TRACER_CHALLENGE_CUBE_H

#include <memory>
#include "Object.h"
#include "../Ray.h"

namespace mn {

    class Cube : public Object {
    public:
        Cube() : Object() {}

        void local_intersect(const Ray &object_ray, Intersections &intersections) const override {
            double xt_min, xt_max, yt_min, yt_max, zt_min, zt_max;

            check_axis(object_ray.origin().x, object_ray.direction().x, xt_min, xt_max);
            check_axis(object_ray.origin().y, object_ray.direction().y, yt_min, yt_max);
            check_axis(object_ray.origin().z, object_ray.direction().z, zt_min, zt_max);

            double t_min = std::max(std::max(xt_min, yt_min), zt_min);
            double t_max = std::min(std::min(xt_max, yt_max), zt_max);

            if (t_min > t_max) return;

            intersections.add(t_min, this);
            intersections.add(t_max, this);
        }

        // We assume object_point is on the cube.
        // For example it is ray-cube intersection point.
        [[nodiscard]] Vector local_normal_at(const Point &object_point) const override {
            double abs_x = std::abs(object_point.x);
            double abs_y = std::abs(object_point.y);
            double abs_z = std::abs(object_point.z);

            double max_c = std::max(std::max(abs_x, abs_y), abs_z);

            if (max_c == abs_x)
                return make_vector(object_point.x, 0.0, 0.0);
            else if (max_c == abs_y)
                return make_vector(0.0, object_point.y, 0.0);

            return make_vector(0.0, 0.0, object_point.z);
        }

    private:
        static void check_axis(double origin, double direction, double &t_min, double &t_max) {
            double t_min_numerator = -1.0 - origin;
            double t_max_numerator = 1.0 - origin;

            if (!mn::epsilon_equal(direction, 0.0)) {
                t_min = t_min_numerator / direction;
                t_max = t_max_numerator / direction;
            } else {
                t_min = t_min_numerator * kInfinity;
                t_max = t_max_numerator * kInfinity;
            }

            if (t_min > t_max) std::swap(t_min, t_max);
        }

    };

    inline std::unique_ptr<Object> make_cube() {
        return std::make_unique<Cube>();
    }

}
#endif //THE_RAY_TRACER_CHALLENGE_CUBE_H
