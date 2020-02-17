#include <iostream>
#include "../Matrix4x4.h"
#include "../Vector4.h"


bool test_set_and_get();
bool test_equality();
bool test_inequality();
bool test_matrix4x4_multiply();
bool test_vector4_multiply();
bool test_multiply_a_matrix_by_identity_matrix();
bool test_multiply_a_identity_matrix_by_a_tuple();
bool test_transposing_a_matrix();
bool test_transposing_the_identity_matrix();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Test Matrix4x4 class\n";
    std::cout << "--------------------\n";

    if(!test_set_and_get()) { cnt_failed += 1; std::cout << "test_set_and_get failed\n"; }
    else cnt_passed += 1;

    if(!test_equality()) { cnt_failed += 1; std::cout << "test_equality failed\n"; }
    else cnt_passed += 1;

    if(!test_inequality()) { cnt_failed += 1; std::cout << "test_inequality failed\n"; }
    else cnt_passed += 1;

    if(!test_matrix4x4_multiply()) { cnt_failed += 1; std::cout << "test_matrix4x4_multiply failed\n"; }
    else cnt_passed += 1;

    if(!test_vector4_multiply()) { cnt_failed += 1; std::cout << "test_vector4_multiply failed\n"; }
    else cnt_passed += 1;

    if(!test_multiply_a_matrix_by_identity_matrix()) { cnt_failed += 1; std::cout << "test_multiply_a_matrix_by_identity_matrix failed\n"; }
    else cnt_passed += 1;

    if(!test_multiply_a_identity_matrix_by_a_tuple()) { cnt_failed += 1; std::cout << "test_multiply_a_identity_matrix_by_a_tuple failed\n"; }
    else cnt_passed += 1;

    if(!test_transposing_a_matrix()) { cnt_failed += 1; std::cout << "test_transposing_a_matrix failed\n"; }
    else cnt_passed += 1;
    
    if(!test_transposing_the_identity_matrix()) { cnt_failed += 1; std::cout << "test_transposing_the_identity_matrix failed\n"; }
    else cnt_passed += 1;

    std::cout << "\nTotal:  " << (cnt_passed + cnt_failed) << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool test_set_and_get() {
    Matrix4x4 m;
    m.set_row_by_row(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.5f, 6.5f, 7.5f, 8.5f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.5f, 14.5f, 15.5f, 16.5f
    );

    if (m.m00 != 1.0f) return false;
    if (m.m03 != 4.0f) return false;
    if (m.m10 != 5.5f) return false;
    if (m.m12 != 7.5f) return false;
    if (m.m22 != 11.0f) return false;
    if (m.m30 != 13.5f) return false;
    if (m.m32 != 15.5f) return false;

    return true;
}

bool test_equality() {
    Matrix4x4 m1, m2;
    m1.set_row_by_row(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.5f, 6.5f, 7.5f, 8.5f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.5f, 14.5f, 15.5f, 16.5f
    );
    m2.set_row_by_row(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.5f, 6.5f, 7.5f, 8.5f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.5f, 14.5f, 15.5f, 16.5f
    );

    return m1==m2;
}

bool test_inequality() {
    Matrix4x4 m1, m2;
    m1.set_row_by_row(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.5f, 6.5f, 7.5f, 8.5f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.5f, 14.5f, 15.5f, 16.5f
    );
    m2.set_row_by_row(
        2.0f, 2.0f, 3.0f, 4.0f, // m00 changed
        5.5f, 6.5f, 7.5f, 8.5f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.5f, 14.5f, 15.5f, 16.5f
    );

    return m1!=m2;
}

bool test_matrix4x4_multiply() {
    Matrix4x4 m1, m2, expected_result;
    m1.set_row_by_row(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.0f, 6.0f, 7.0f, 8.0f,
        9.0f, 8.0f, 7.0f, 6.0f,
        5.0f, 4.0f, 3.0f, 2.0f
    );
    m2.set_row_by_row(
        -2.0f, 1.0f, 2.0f, 3.0f,
        3.0f, 2.0f, 1.0f, -1.0f,
        4.0f, 3.0f, 6.0f, 5.0f,
        1.0f, 2.0f, 7.0f, 8.0f
    );
    expected_result.set_row_by_row(
        20.0f, 22.0f, 50.0f, 48.0f,
        44.0f, 54.0f, 114.0f, 108.0f,
        40.0f, 58.0f, 110.0f, 102.0f,
        16.0f, 26.0f, 46.0f, 42.0f
    );

    Matrix4x4 computed_result = m1 * m2;

    return computed_result == expected_result;
}

bool test_vector4_multiply() {
    Matrix4x4 A;
    A.set_row_by_row(
        1.0f, 2.0f, 3.0f, 4.0f,
        2.0f, 4.0f, 4.0f, 2.0f,
        8.0f, 6.0f, 4.0f, 1.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );
    Vector4 b(1.0f, 2.0f, 3.0f, 1.0f);
    Vector4 expected_result(18.0f, 24.0f, 33.0f, 1.0f);
    
    Vector4 computed_result = A * b;

    return
        expected_result.x == computed_result.x &&
        expected_result.y == computed_result.y &&
        expected_result.z == computed_result.z &&
        expected_result.w == computed_result.w;
}

bool test_multiply_a_matrix_by_identity_matrix() {
    Matrix4x4 A, I;
    A.set_row_by_row(
        0.0f, 1.0f, 2.0f, 4.0f,
        1.0f, 2.0f, 4.0f, 8.0f,
        2.0f, 4.0f, 8.0f, 16.0f,
        4.0f, 8.0f, 16.0f, 32.0f
    );
    I.identity();
    
    return (A * I) == A;
}

bool test_multiply_a_identity_matrix_by_a_tuple() {
    Vector4 p;
    Matrix4x4 I;
    I.identity();
    
    return (I * p) == p;
}

bool test_transposing_a_matrix() {
    Matrix4x4 A, expected_result;
    A.set_row_by_row(
        0.0f, 9.0f, 3.0f, 0.0f,
        9.0f, 8.0f, 0.0f, 8.0f,
        1.0f, 8.0f, 5.0f, 3.0f,
        0.0f, 0.0f, 5.0f, 8.0f
    );
    expected_result.set_row_by_row(
        0.0f, 9.0f, 1.0f, 0.0f,
        9.0f, 8.0f, 8.0f, 0.0f,
        3.0f, 0.0f, 5.0f, 5.0f,
        0.0f, 8.0f, 3.0f, 8.0f
    );

    return transpose(A) == expected_result;
}

bool test_transposing_the_identity_matrix() {
    Matrix4x4 I;
    I.identity();

    return transpose(I) == I;
}
