// g++ test_scaling.cpp ../Matrix4x4.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp
#include <iostream>
#include "../Matrix4x4.h"
#include "../Vector4.h"


bool test_scaling_applied_to_a_point();
bool test_scaling_applied_to_a_vector();
bool test_multiplying_by_the_inverse_of_a_scaling_matrix();
bool test_reflection_is_scaling_by_a_negative_value();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Test scaling\n";
    std::cout << "--------------------\n";

    if(!test_scaling_applied_to_a_point()) {
        cnt_failed += 1;
        std::cout << "test_scaling_applied_to_a_point failed\n";
    } else cnt_passed += 1;

    if(!test_scaling_applied_to_a_vector()) {
        cnt_failed += 1;
        std::cout << "test_scaling_applied_to_a_vector failed\n";
    } else cnt_passed += 1;

    if(!test_multiplying_by_the_inverse_of_a_scaling_matrix()) {
        cnt_failed += 1;
        std::cout << "test_multiplying_by_the_inverse_of_a_scaling_matrix failed\n";
    } else cnt_passed += 1;

    if(!test_reflection_is_scaling_by_a_negative_value()) {
        cnt_failed += 1;
        std::cout << "test_reflection_is_scaling_by_a_negative_value failed\n";
    } else cnt_passed += 1;

    std::cout << "\nTotal:  " << (cnt_passed + cnt_failed) << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool test_scaling_applied_to_a_point() {
    Matrix4x4 t = scaling(2.0f, 3.0f, 4.0f);
    Vector4 p = make_point(-4.0f, 6.0f, 8.0f);
    Vector4 expected_result = make_point(-8.0f, 18.0f, 32.0f);

    return t * p == expected_result;
}

bool test_scaling_applied_to_a_vector() {
    Matrix4x4 t = scaling(2.0f, 3.0f, 4.0f);
    Vector4 p = make_vector(-4.0f, 6.0f, 8.0f);
    Vector4 expected_result = make_vector(-8.0f, 18.0f, 32.0f);

    return t * p == expected_result;
}

bool test_multiplying_by_the_inverse_of_a_scaling_matrix() {
    Matrix4x4 t = scaling(2.0f, 3.0f, 4.0f);
    Matrix4x4 inv = inverse(t);
    Vector4 p = make_vector(-4.0f, 6.0f, 8.0f);
    Vector4 expected_result = make_point(-2.0f, 2.0f, 2.0f);

    return inv * p == expected_result;
}

bool test_reflection_is_scaling_by_a_negative_value() {
    Matrix4x4 t = scaling(-1.0f, 1.0f, 1.0f);
    Vector4 p = make_point(2.0f, 3.0f, 4.0f);
    Vector4 expected_result = make_vector(-2.0f, 3.0f, 4.0f);

    return t * p == expected_result;
}
