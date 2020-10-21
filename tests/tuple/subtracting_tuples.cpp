//
// Created by ivan on 6.10.2020..
//
#include "Tuple.h"

bool subtracting_two_points();

bool subtracting_vector_from_a_point();

bool subtracting_two_vectors();

// Subtracting tuples
int main() {
    if (subtracting_two_points() && subtracting_vector_from_a_point() && subtracting_two_vectors()) return 0;
    return 1;
}

bool subtracting_two_points() {
    mn::Tuple a = mn::make_point(3.0, 2.0, 1.0);
    mn::Tuple b = mn::make_point(5.0, 6.0, 7.0);
    mn::Tuple expected = mn::make_vector(-2.0, -4.0, -6.0);

    mn::Tuple actual = a - b;

    if (actual == expected) return true;
    return false;
}

bool subtracting_vector_from_a_point() {
    mn::Tuple p = mn::make_point(3.0, 2.0, 1.0);
    mn::Tuple v = mn::make_vector(5.0, 6.0, 7.0);
    mn::Tuple expected = mn::make_point(-2.0, -4.0, -6.0);

    mn::Tuple actual = p - v;

    if (actual == expected) return true;
    return false;
}

bool subtracting_two_vectors() {
    mn::Tuple p = mn::make_vector(3.0, 2.0, 1.0);
    mn::Tuple v = mn::make_vector(5.0, 6.0, 7.0);
    mn::Tuple expected = mn::make_vector(-2.0, -4.0, -6.0);

    mn::Tuple actual = p - v;

    if (actual == expected) return true;
    return false;
}
