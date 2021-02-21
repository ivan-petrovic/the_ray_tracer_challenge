//
// Created by ivan on 21.2.2021..
//

#include "model/Triangle.h"

bool create_triangle();

bool test_normal_on_triangle();

int main() {
    if (create_triangle() && test_normal_on_triangle())
        return 0;
    return 1;
}

bool create_triangle() {
    mn::Point p1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Point p2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Point p3 = mn::make_point(1.0, 0.0, 0.0);
    mn::Triangle triangle(p1, p2, p3);

    if (triangle.p1() != p1) return false;
    if (triangle.p2() != p2) return false;
    if (triangle.p3() != p3) return false;
    if (triangle.e1() != mn::make_vector(-1.0, -1.0, 0.0)) return false;
    if (triangle.e2() != mn::make_vector(1.0, -1.0, 0.0)) return false;
    if (triangle.normal() != mn::make_vector(0.0, 0.0, -1.0)) return false;

    return true;
}

bool test_normal_on_triangle() {
    mn::Point p1 = mn::make_point(0.0, 1.0, 0.0);
    mn::Point p2 = mn::make_point(-1.0, 0.0, 0.0);
    mn::Point p3 = mn::make_point(1.0, 0.0, 0.0);
    mn::Triangle triangle(p1, p2, p3);

    mn::Vector n1 = triangle.local_normal_at(mn::make_point(0.0,0.5, 0.0));
    mn::Vector n2 = triangle.local_normal_at(mn::make_point(-0.5,0.75, 0.0));
    mn::Vector n3 = triangle.local_normal_at(mn::make_point(0.5,0.25, 0.0));

    if (triangle.normal() != n1) return false;
    if (triangle.normal() != n2) return false;
    if (triangle.normal() != n3) return false;

    return true;
}
