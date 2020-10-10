// g++ test_reflection.cpp
#include <iostream>
#include "../../first_version/Vector4.h"

bool reflecting_a_vector_approaching_at_45();
bool reflecting_a_vector_of_a_slanted_surface();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Testing Ray class\n";

    if(!reflecting_a_vector_approaching_at_45()) {
        cnt_failed += 1;
        std::cout << "reflecting_a_vector_approaching_at_45 failed\n";
    } else { cnt_passed += 1; }

    if(!reflecting_a_vector_of_a_slanted_surface()) {
        cnt_failed += 1;
        std::cout << "reflecting_a_vector_of_a_slanted_surface failed\n";
    } else { cnt_passed += 1; }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool reflecting_a_vector_approaching_at_45() {
    Vector4 v = make_vector(1.0f, -1.0f, 0.0f);
    Vector4 n = make_vector(0.0f, 1.0f, 0.0f);
    Vector4 result = reflect(v, n);
    Vector4 expected_result = make_vector(1.0f, 1.0f, 0.0f);

    if (result != expected_result) return false;

    return true; 
}

bool reflecting_a_vector_of_a_slanted_surface() {
    Vector4 v = make_vector(0.0f, -1.0f, 0.0f);
    float sqrt_of_2 = 1.41421;
    Vector4 n = make_vector(sqrt_of_2/2, sqrt_of_2/2, 0.0f);
    Vector4 result = reflect(v, n);
    Vector4 expected_result = make_vector(1.0f, 0.0f, 0.0f);

    if (result != expected_result) return false;

    return true; 
}
