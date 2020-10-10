// g++ test_chained_transformations.cpp ../Matrix4x4.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp
#include <iostream>
#include "../first_version/Matrix4x4.h"
#include "../first_version/Vector4.h"


bool test_individual_transformations_applied_in_sequence();
bool test_chained_transformations_must_be_applied_in_reverse_order();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Test chaining transformations\n";
    std::cout << "--------------------\n";

    if(!test_individual_transformations_applied_in_sequence()) {
        cnt_failed += 1;
        std::cout << "test_individual_transformations_applied_in_sequence failed\n";
    } else cnt_passed += 1;

    if(!test_chained_transformations_must_be_applied_in_reverse_order()) {
        cnt_failed += 1;
        std::cout << "test_chained_transformations_must_be_applied_in_reverse_order failed\n";
    } else cnt_passed += 1;

    std::cout << "\nTotal:  " << (cnt_passed + cnt_failed) << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool test_individual_transformations_applied_in_sequence() {
    Vector4 p = make_point(1.0f, 0.0f, 1.0f);
    
    Matrix4x4 R = rotation_x(radians(90.0f));
    Matrix4x4 S = scaling(5.0f, 5.0f, 5.0f);
    Matrix4x4 T = translation(10.0f, 5.0f, 7.0f);

    // Apply rotation first
    Vector4 p2 = R * p;
    if (p2 != make_point(1.0f, -1.0f, 0.0f)) return false;

    // Then apply scaling
    Vector4 p3 = S * p2;
    if (p3 != make_point(5.0f, -5.0f, 0.0f)) return false;

    // Then apply translation
    Vector4 p4 = T * p3;
    if (p4 != make_point(15.0f, 0.0f, 7.0f)) return false;

    return true;
}

bool test_chained_transformations_must_be_applied_in_reverse_order() {
    Vector4 p = make_point(1.0f, 0.0f, 1.0f);
    
    Matrix4x4 R = rotation_x(radians(90.0f));
    Matrix4x4 S = scaling(5.0f, 5.0f, 5.0f);
    Matrix4x4 T = translation(10.0f, 5.0f, 7.0f);

    Matrix4x4 M = T * S * R;

    if (M * p != make_point(15.0f, 0.0f, 7.0f)) return false;

    return true;
}
