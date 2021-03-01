//
// Created by ivan on 1.3.2021..
//

#include "Ray.h"
#include "render.h"
#include "model/SmoothTriangle.h"

bool intersecting_a_ray_parallel_to_the_triangle();

bool a_ray_misses_the_p1_p3_edge();

bool a_ray_misses_the_p1_p2_edge();

bool a_ray_misses_the_p2_p3_edge();

bool a_ray_strikes_a_triangle_and_stores_uv();

bool intersection_with_uv();

bool preparing_the_normal_on_a_smooth_triangle();

int main() {
    if (
            intersecting_a_ray_parallel_to_the_triangle() &&
            a_ray_misses_the_p1_p3_edge() &&
            a_ray_misses_the_p1_p2_edge() &&
            a_ray_misses_the_p2_p3_edge() &&
            a_ray_strikes_a_triangle_and_stores_uv() &&
            intersection_with_uv() &&
            preparing_the_normal_on_a_smooth_triangle()
            )
        return 0;
    return 1;
}

bool intersecting_a_ray_parallel_to_the_triangle() {
    mn::Point p1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Point p2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Point p3 = mn::make_point(1.0, 0.0, 0.0);
    mn::Vector n1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Vector n2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Vector n3 = mn::make_point(1.0, 0.0, 0.0);

    mn::SmoothTriangle triangle(p1, p2, p3, n1, n2, n3);

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
    mn::Vector n1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Vector n2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Vector n3 = mn::make_point(1.0, 0.0, 0.0);

    mn::SmoothTriangle triangle(p1, p2, p3, n1, n2, n3);

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
    mn::Vector n1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Vector n2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Vector n3 = mn::make_point(1.0, 0.0, 0.0);

    mn::SmoothTriangle triangle(p1, p2, p3, n1, n2, n3);

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
    mn::Vector n1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Vector n2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Vector n3 = mn::make_point(1.0, 0.0, 0.0);

    mn::SmoothTriangle triangle(p1, p2, p3, n1, n2, n3);

    mn::Ray ray(
            mn::make_point(0.0, -1.0, -2.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );

    mn::Intersections result;
    triangle.local_intersect(ray, result);

    return result.count() == 0;
}

bool a_ray_strikes_a_triangle_and_stores_uv() {
    mn::Point p1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Point p2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Point p3 = mn::make_point(1.0, 0.0, 0.0);
    mn::Vector n1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Vector n2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Vector n3 = mn::make_point(1.0, 0.0, 0.0);

    mn::SmoothTriangle triangle(p1, p2, p3, n1, n2, n3);

    mn::Ray ray(
            mn::make_point(-0.2, 0.3, -2.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );

    mn::Intersections result;
    triangle.local_intersect(ray, result);

    return mn::epsilon_equal(result[0].u, 0.45) && mn::epsilon_equal(result[0].v, 0.25);
}

bool intersection_with_uv() {
    mn::Point p1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Point p2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Point p3 = mn::make_point(1.0, 0.0, 0.0);
    mn::Vector n1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Vector n2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Vector n3 = mn::make_point(1.0, 0.0, 0.0);

    mn::SmoothTriangle triangle(p1, p2, p3, n1, n2, n3);

    mn::Intersection i{3.5, &triangle, 0.2, 0.4};
    return i.u == 0.2 && i.v == 0.4;
}

bool preparing_the_normal_on_a_smooth_triangle() {
    mn::Point p1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Point p2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Point p3 = mn::make_point(1.0, 0.0, 0.0);
    mn::Vector n1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Vector n2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Vector n3 = mn::make_point(1.0, 0.0, 0.0);

    mn::SmoothTriangle triangle(p1, p2, p3, n1, n2, n3);

    mn::Ray ray(
            mn::make_point(-0.2, 0.3, -2.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );

    mn::Intersections intersections;
    intersections.add(1.0, &triangle, 0.45, 0.25);

    mn::Hit hit = mn::prepare_computations(intersections[0], ray, intersections);

    return mn::epsilon_equal(hit.normal, mn::make_vector(-0.55470, 0.83205, 0.0));
}
