//
// Created by ivan on 1.3.2021..
//

#include "model/SmoothTriangle.h"

bool create_smooth_triangle();

bool a_smooth_triangle_uses_uv_to_interpolate_the_normal();

int main() {
    if (create_smooth_triangle() && a_smooth_triangle_uses_uv_to_interpolate_the_normal())
        return 0;
    return 1;
}

bool create_smooth_triangle() {
    mn::Point p1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Point p2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Point p3 = mn::make_point(1.0, 0.0, 0.0);
    mn::Vector n1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Vector n2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Vector n3 = mn::make_point(1.0, 0.0, 0.0);

    mn::SmoothTriangle triangle(p1, p2, p3, n1, n2, n3);

    if (triangle.p1() != p1) return false;
    if (triangle.p2() != p2) return false;
    if (triangle.p3() != p3) return false;
    if (triangle.normal1() != n1) return false;
    if (triangle.normal2() != n2) return false;
    if (triangle.normal3() != n3) return false;

    return true;
}

bool a_smooth_triangle_uses_uv_to_interpolate_the_normal() {
    mn::Point p1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Point p2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Point p3 = mn::make_point(1.0, 0.0, 0.0);
    mn::Vector n1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Vector n2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Vector n3 = mn::make_point(1.0, 0.0, 0.0);

    mn::SmoothTriangle triangle(p1, p2, p3, n1, n2, n3);
    mn::Intersection intersection{1.0, &triangle, 0.45, 0.25};

    mn::Vector n = triangle.normal_at(mn::make_point(0.0, 0.0, 0.0), intersection);

    return mn::epsilon_equal(n, mn::make_vector(-0.55470, 0.83205, 0.0));
}
