// g++ test_translation.cpp ../Matrix4x4.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp
#include <iostream>
#include "../Matrix4x4.h"
#include "../Vector4.h"


bool test_multiplying_by_a_translation_matrix();
bool test_multiplying_by_the_inverse_of_a_translation_matrix();
bool test_translation_does_not_affect_vectors();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Test translation\n";
    std::cout << "--------------------\n";

    if(!test_multiplying_by_a_translation_matrix()) {
        cnt_failed += 1;
        std::cout << "test_multiplying_by_a_translation_matrix failed\n";
    } else cnt_passed += 1;

    if(!test_multiplying_by_the_inverse_of_a_translation_matrix()) {
        cnt_failed += 1;
        std::cout << "test_multiplying_by_the_inverse_of_a_translation_matrix failed\n";
    } else cnt_passed += 1;

    if(!test_translation_does_not_affect_vectors()) {
        cnt_failed += 1;
        std::cout << "test_translation_does_not_affect_vectors failed\n";
    } else cnt_passed += 1;

    std::cout << "\nTotal:  " << (cnt_passed + cnt_failed) << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool test_multiplying_by_a_translation_matrix() {
    Matrix4x4 t = translation(5.0f, -3.0f, 2.0f);
    Vector4 p = make_point(-3.0f, 4.0f, 5.0f);
    Vector4 expected_result = make_point(2.0f, 1.0f, 7.0f);

    // Vector4 actual_result = t * p;
    // std::cout << actual_result.x << " = " << expected_result.x << '\n';
    // std::cout << actual_result.y << " = " << expected_result.y << '\n';
    // std::cout << actual_result.z << " = " << expected_result.z << '\n';
    return t * p == expected_result;
}

bool test_multiplying_by_the_inverse_of_a_translation_matrix() {
    Matrix4x4 t = translation(5.0f, -3.0f, 2.0f);
    Matrix4x4 inv = inverse(t);
    Vector4 p = make_point(-3.0f, 4.0f, 5.0f);
    Vector4 expected_result = make_point(-8.0f, 7.0f, 3.0f);

    return (inv * p) == expected_result;
}

bool test_translation_does_not_affect_vectors() {
    Matrix4x4 t = translation(5.0f, -3.0f, 2.0f);
    Vector4 v = make_vector(-3.0f, 4.0f, 5.0f);

    return (t * v) == v;
}
