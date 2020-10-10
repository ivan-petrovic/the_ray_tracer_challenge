// g++ test_matrix3x3.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp
#include <iostream>
#include "../../first_version/Matrix3x3.h"
#include "../../first_version/Matrix2x2.h"
#include "../../first_version/Vector4.h"


bool test_set_and_get();
bool test_submatrix();
bool test_minor();
bool test_cofactor();
bool test_determinant();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Test Matrix3x3 class\n";
    std::cout << "--------------------\n";

    if(!test_set_and_get()) { cnt_failed += 1; std::cout << "test_set_and_get failed\n"; }
    else cnt_passed += 1;

    if(!test_submatrix()) { cnt_failed += 1; std::cout << "test_submatrix failed\n"; }
    else cnt_passed += 1;

    if(!test_minor()) { cnt_failed += 1; std::cout << "test_minor failed\n"; }
    else cnt_passed += 1;

    if(!test_cofactor()) { cnt_failed += 1; std::cout << "test_cofactor failed\n"; }
    else cnt_passed += 1;

    if(!test_determinant()) { cnt_failed += 1; std::cout << "test_determinant failed\n"; }
    else cnt_passed += 1;

    std::cout << "\nTotal:  " << (cnt_passed + cnt_failed) << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool test_set_and_get() {
    Matrix3x3 m;
    m.set_row_by_row(
        -3.0f, 5.0f, 0.0f,
        1.0f, -2.0f, -7.0f,
        0.0f, 1.0f, 1.0f
    );

    if (m.m00 != -3.0f) return false;
    if (m.m11 != -2.0f) return false;
    if (m.m22 != 1.0f) return false;

    return true;
}

bool test_submatrix() {
    Matrix3x3 m;
    m.set_row_by_row(
        1.0f, 5.0f, 0.0f,
        -3.0f, 2.0f, 7.0f,
        0.0f, 6.0f, -3.0f
    );
    Matrix2x2 expected_result;
    expected_result.set_row_by_row(
        -3.0f, 2.0f,
        0.0f, 6.0f
    );

    Matrix2x2 actual_result = submatrix(m, 0, 2);

    return actual_result == expected_result;
}

bool test_minor() {
    Matrix3x3 m;
    m.set_row_by_row(
        3.0f, 5.0f, 0.0f,
        2.0f, -1.0f, -7.0f,
        6.0f, -1.0f, 5.0f
    );
    float expected_result = 25.0f;

    return minor(m, 1, 0) == expected_result;
}

bool test_cofactor() {
    Matrix3x3 m;
    m.set_row_by_row(
        3.0f, 5.0f, 0.0f,
        2.0f, -1.0f, -7.0f,
        6.0f, -1.0f, 5.0f
    );
    
    if (minor(m, 0, 0) != -12.0f) return false;
    if (cofactor(m, 0, 0) != -12.0f) return false;
    if (minor(m, 1, 0) != 25.0f) return false;
    if (cofactor(m, 1, 0) != -25.0f) return false;

    return true;
}

bool test_determinant() {
    Matrix3x3 m;
    m.set_row_by_row(
        1.0f, 2.0f, 6.0f,
        -5.0f, 8.0f, -4.0f,
        2.0f, 6.0f, 4.0f
    );
    
    if (cofactor(m, 0, 0) != 56.0f) return false;
    if (cofactor(m, 0, 1) != 12.0f) return false;
    if (cofactor(m, 0, 2) != -46.0f) return false;
    if (determinant(m) != -196.0f) return false;

    return true;
}