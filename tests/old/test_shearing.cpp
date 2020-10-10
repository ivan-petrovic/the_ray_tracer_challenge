// g++ test_shearing.cpp ../Matrix4x4.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp
#include <iostream>
#include "../../first_version/Matrix4x4.h"
#include "../../first_version/Vector4.h"


bool test_shearing_moves_x_in_proportions_to_y();
bool test_shearing_moves_x_in_proportions_to_z();
bool test_shearing_moves_y_in_proportions_to_x();
bool test_shearing_moves_y_in_proportions_to_z();
bool test_shearing_moves_z_in_proportions_to_x();
bool test_shearing_moves_z_in_proportions_to_y();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Test shearing\n";
    std::cout << "--------------------\n";

    if(!test_shearing_moves_x_in_proportions_to_y()) {
        cnt_failed += 1;
        std::cout << "test_shearing_moves_x_in_proportions_to_y failed\n";
    } else cnt_passed += 1;

    if(!test_shearing_moves_x_in_proportions_to_z()) {
        cnt_failed += 1;
        std::cout << "test_shearing_moves_x_in_proportions_to_z failed\n";
    } else cnt_passed += 1;

    if(!test_shearing_moves_y_in_proportions_to_x()) {
        cnt_failed += 1;
        std::cout << "test_shearing_moves_y_in_proportions_to_x failed\n";
    } else cnt_passed += 1;

    if(!test_shearing_moves_y_in_proportions_to_z()) {
        cnt_failed += 1;
        std::cout << "test_shearing_moves_y_in_proportions_to_z failed\n";
    } else cnt_passed += 1;

    if(!test_shearing_moves_z_in_proportions_to_x()) {
        cnt_failed += 1;
        std::cout << "test_shearing_moves_z_in_proportions_to_x failed\n";
    } else cnt_passed += 1;

    if(!test_shearing_moves_z_in_proportions_to_y()) {
        cnt_failed += 1;
        std::cout << "test_shearing_moves_z_in_proportions_to_y failed\n";
    } else cnt_passed += 1;

    std::cout << "\nTotal:  " << (cnt_passed + cnt_failed) << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool test_shearing_moves_x_in_proportions_to_y() {
    Vector4 p = make_point(2.0f, 3.0f, 4.0f);
    Matrix4x4 transform = shearing(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    if (transform * p != make_point(5.0f, 3.0f, 4.0f)) return false;
    return true;
}

bool test_shearing_moves_x_in_proportions_to_z() {
    Vector4 p = make_point(2.0f, 3.0f, 4.0f);
    Matrix4x4 transform = shearing(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);

    if (transform * p != make_point(6.0f, 3.0f, 4.0f)) return false;
    return true;
}

bool test_shearing_moves_y_in_proportions_to_x() {
    Vector4 p = make_point(2.0f, 3.0f, 4.0f);
    Matrix4x4 transform = shearing(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);

    if (transform * p != make_point(2.0f, 5.0f, 4.0f)) return false;
    return true;
}

bool test_shearing_moves_y_in_proportions_to_z() {
    Vector4 p = make_point(2.0f, 3.0f, 4.0f);
    Matrix4x4 transform = shearing(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);

    if (transform * p != make_point(2.0f, 7.0f, 4.0f)) return false;
    return true;
}

bool test_shearing_moves_z_in_proportions_to_x() {
    Vector4 p = make_point(2.0f, 3.0f, 4.0f);
    Matrix4x4 transform = shearing(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    if (transform * p != make_point(2.0f, 3.0f, 6.0f)) return false;
    return true;
}

bool test_shearing_moves_z_in_proportions_to_y() {
    Vector4 p = make_point(2.0f, 3.0f, 4.0f);
    Matrix4x4 transform = shearing(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);

    if (transform * p != make_point(2.0f, 3.0f, 7.0f)) return false;
    return true;
}
