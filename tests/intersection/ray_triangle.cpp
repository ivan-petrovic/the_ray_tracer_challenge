//
// Created by ivan on 21.2.2021..
//

#include "Ray.h"
#include "model/Triangle.h"

bool intersecting_a_ray_parallel_to_the_triangle();

bool a_ray_misses_the_p1_p3_edge();

bool a_ray_misses_the_p1_p2_edge();

bool a_ray_misses_the_p2_p3_edge();

bool a_ray_strikes_a_triangle();

int main() {
    if (
            intersecting_a_ray_parallel_to_the_triangle() &&
            a_ray_misses_the_p1_p3_edge() &&
            a_ray_misses_the_p1_p2_edge() &&
            a_ray_misses_the_p2_p3_edge() &&
            a_ray_strikes_a_triangle()
            )
        return 0;
    return 1;
}

bool intersecting_a_ray_parallel_to_the_triangle() {
    mn::Point p1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Point p2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Point p3 = mn::make_point(1.0, 0.0, 0.0);
    mn::Triangle triangle(p1, p2, p3);

    mn::Ray ray(
            mn::make_point(0.0, -1.0, -2.0),
            mn::make_vector(0.0, 1.0, 0.0)
    );

    mn::Intersections result;
    triangle.local_intersect(ray, result);

    return result.count() == 0;
}

bool a_ray_misses_the_p1_p3_edge() {
    mn::Point p1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Point p2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Point p3 = mn::make_point(1.0, 0.0, 0.0);
    mn::Triangle triangle(p1, p2, p3);

    mn::Ray ray(
            mn::make_point(1.0, 1.0, -2.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );

    mn::Intersections result;
    triangle.local_intersect(ray, result);

    return result.count() == 0;
}

bool a_ray_misses_the_p1_p2_edge() {
    mn::Point p1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Point p2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Point p3 = mn::make_point(1.0, 0.0, 0.0);
    mn::Triangle triangle(p1, p2, p3);

    mn::Ray ray(
            mn::make_point(1.0, -1.0, -2.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );

    mn::Intersections result;
    triangle.local_intersect(ray, result);

    return result.count() == 0;
}

bool a_ray_misses_the_p2_p3_edge() {
    mn::Point p1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Point p2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Point p3 = mn::make_point(1.0, 0.0, 0.0);
    mn::Triangle triangle(p1, p2, p3);

    mn::Ray ray(
            mn::make_point(0.0, -1.0, -2.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );

    mn::Intersections result;
    triangle.local_intersect(ray, result);

    return result.count() == 0;
}

bool a_ray_strikes_a_triangle() {
    mn::Point p1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Point p2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Point p3 = mn::make_point(1.0, 0.0, 0.0);
    mn::Triangle triangle(p1, p2, p3);

    mn::Ray ray(
            mn::make_point(0.0, 0.5, -2.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );

    mn::Intersections result;
    triangle.local_intersect(ray, result);

    return result.count() == 1 && result[0].t == 2.0;
}
