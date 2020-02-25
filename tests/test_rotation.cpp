// g++ test_rotation.cpp ../Matrix4x4.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp
#include <iostream>
#include "../Matrix4x4.h"
#include "../Vector4.h"


bool test_rotating_a_point_around_x_axis();
bool test_inverse_of_a_x_rotation_rotates_in_the_opposite_direction();
bool test_rotating_a_point_around_y_axis();
bool test_rotating_a_point_around_z_axis();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Test rotation\n";
    std::cout << "--------------------\n";

    if(!test_rotating_a_point_around_x_axis()) {
        cnt_failed += 1;
        std::cout << "test_rotating_a_point_around_x_axis failed\n";
    } else cnt_passed += 1;

    if(!test_inverse_of_a_x_rotation_rotates_in_the_opposite_direction()) {
        cnt_failed += 1;
        std::cout << "test_inverse_of_a_x_rotation_rotates_in_the_opposite_direction failed\n";
    } else cnt_passed += 1;

    if(!test_rotating_a_point_around_y_axis()) {
        cnt_failed += 1;
        std::cout << "test_rotating_a_point_around_y_axis failed\n";
    } else cnt_passed += 1;

    if(!test_rotating_a_point_around_z_axis()) {
        cnt_failed += 1;
        std::cout << "test_rotating_a_point_around_z_axis failed\n";
    } else cnt_passed += 1;

    std::cout << "\nTotal:  " << (cnt_passed + cnt_failed) << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool test_rotating_a_point_around_x_axis() {
    Vector4 p = make_point(0.0f, 1.0f, 0.0f);
    
    Matrix4x4 half_quarter = rotation_x(radians(45.0f));
    Matrix4x4 full_quarter = rotation_x(radians(90.0f));

    Vector4 result = half_quarter * p;
    
    if (half_quarter * p != make_point(0.0f, 0.70711f, 0.70711f)) return false;
    if (full_quarter * p != make_point(0.0f, 0.0f, 1.0f)) return false;

    return true;
}

bool test_inverse_of_a_x_rotation_rotates_in_the_opposite_direction() {
    Vector4 p = make_point(0.0f, 1.0f, 0.0f);
    
    Matrix4x4 half_quarter = rotation_x(radians(45.0f));
    Matrix4x4 inv = inverse(half_quarter);
    
    if (inv * p != make_point(0.0f, 0.70711f, -0.70711f)) return false;

    return true;
}

bool test_rotating_a_point_around_y_axis() {
    Vector4 p = make_point(0.0f, 0.0f, 1.0f);
    
    Matrix4x4 half_quarter = rotation_y(radians(45.0f));
    Matrix4x4 full_quarter = rotation_y(radians(90.0f));

    Vector4 result = half_quarter * p;
    
    if (half_quarter * p != make_point(0.70711f, 0.0f, 0.70711f)) return false;
    if (full_quarter * p != make_point(1.0f, 0.0f, 0.0f)) return false;

    return true;
}

bool test_rotating_a_point_around_z_axis() {
    Vector4 p = make_point(0.0f, 1.0f, 0.0f);
    
    Matrix4x4 half_quarter = rotation_z(radians(45.0f));
    Matrix4x4 full_quarter = rotation_z(radians(90.0f));

    Vector4 result = half_quarter * p;
    
    if (half_quarter * p != make_point(-0.70711f, 0.70711f, 0.0f)) return false;
    if (full_quarter * p != make_point(-1.0f, 0.0f, 0.0f)) return false;

    return true;
}
