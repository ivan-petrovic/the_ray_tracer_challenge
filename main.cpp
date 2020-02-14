#include <iostream>
#include "m4x4.h"
#include "m3x3.h"
#include "m2x2.h"
#include "Vector4.h"

bool check_default_m4x4() {
    M4x4 m;

    for (int row = 0; row < 4; row += 1) {
        for (int col = 0; col < 4; col += 1) {
            if (m.get(row, col) != 0) {
                std::cout << "Error: M4x4.get(" << row << ", " << col << ") != 0 -> " << m.get(row, col) << "\n";
                return false;
            }
        }
    }
    
    return true;
}

bool check_m4x4_set_and_get() {
    M4x4 m;
    m.set_by_row(
        1, 2, 3, 4,
        5.5, 6.5, 7.5, 8.5,
        9, 10, 11, 12,
        13.5, 14.5, 15.5, 16.5
    );
    bool success = true;
    if (m.get(0, 0) != 1) { std::cout << "Error: M4x4.get(0, 0) != 1"; success = false; }
    if (m.get(0, 3) != 4) { std::cout << "Error: M4x4.get(0, 3) != 4"; success = false; }
    if (m.get(1, 0) != 5.5) { std::cout << "Error: M4x4.get(1, 0) != 5.5"; success = false; }
    if (m.get(1, 2) != 7.5) { std::cout << "Error: M4x4.get(1, 2) != 7.5"; success = false; }
    if (m.get(2, 2) != 11) { std::cout << "Error: M4x4.get(2, 2) != 11"; success = false; }
    if (m.get(3, 0) != 13.5) { std::cout << "Error: M4x4.get(3, 0) != 13.5"; success = false; }
    if (m.get(3, 2) != 15.5) { std::cout << "Error: M4x4.get(3, 2) != 15.5"; success = false; }

    try {
        m.get(4, 2);
        success = false;
        std::cout << "M4x4.get() Exception not thrown, and it should be.\n";
    } catch (const std::invalid_argument& e) {
        // std::cout << e.what() << '\n';
    }
    try {
        m.get(0, 4);
        success = false;
        std::cout << "M4x4.get() Exception not thrown, and it should be.\n";
    } catch (const std::invalid_argument& e) {
        // std::cout << e.what() << '\n';
    }
    
    return success;
}

bool check_m4x4_equality() {
    M4x4 m1, m2;
    m1.set_by_row(
        1, 2, 3, 4,
        5.5, 6.5, 7.5, 8.5,
        9, 10, 11, 12,
        13.5, 14.5, 15.5, 16.5
    );
    m2.set_by_row(
        1, 2, 3, 4,
        5.5, 6.5, 7.5, 8.5,
        9, 10, 11, 12,
        13.5, 14.5, 15.5, 16.5
    );

    return m1.equal(m2);
}

bool check_m4x4_inequality() {
    M4x4 m1, m2;
    m1.set_by_row(
        1, 2, 3, 4,
        5.5, 6.5, 7.5, 8.5,
        9, 10, 11, 12,
        13.5, 14.5, 15.5, 16.5
    );

    return !m1.equal(m2);
}

bool check_m4x4_multiply() {
    M4x4 m1, m2, m1xm2;
    m1.set_by_row(
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 8, 7, 6,
        5, 4, 3, 2
    );
    m2.set_by_row(
        -2, 1, 2, 3,
        3, 2, 1, -1,
        4, 3, 6, 5,
        1, 2, 7, 8
    );
    m1xm2.set_by_row(
        20, 22, 50, 48,
        44, 54, 114, 108,
        40, 58, 110, 102,
        16, 26, 46, 42
    );

    return m1.multiply(m2).equal(m1xm2);
}

bool check_m4x4_Vector4_multiply() {
    M4x4 A;
    A.set_by_row(
        1, 2, 3, 4,
        2, 4, 4, 2,
        8, 6, 4, 1,
        0, 0, 0, 1
    );
    Vector4 b(1, 2, 3, 1);
    Vector4 expected_result(18, 24, 33, 1);
    
    Vector4 computed_result = A.multiply(b);

    return
        expected_result.x == computed_result.x &&
        expected_result.y == computed_result.y &&
        expected_result.z == computed_result.z &&
        expected_result.w == computed_result.w;
}

bool check_default_m3x3() {
    M3x3 m;

    for (int row = 0; row < 3; row += 1) {
        for (int col = 0; col < 3; col += 1) {
            if (m.get(row, col) != 0) {
                std::cout << "Error: M3x3.get(" << row << ", " << col << ") != 0 -> " << m.get(row, col) << "\n";
                return false;
            }
        }
    }
    
    return true;
}

bool check_m3x3_set_and_get() {
    M3x3 m;
    m.set_by_row(
        -3, 5, 0,
        1, -2, -7,
        0, 1, 1
    );
    bool success = true;
    if (m.get(0, 0) != -3) { std::cout << "Error: M3x3.get(0, 0) != -3"; success = false; }
    if (m.get(1, 1) != -2) { std::cout << "Error: M3x3.get(1, 1) != -2"; success = false; }
    if (m.get(2, 2) != 1) { std::cout << "Error: M3x3.get(2, 2) != 1"; success = false; }

    try {
        m.get(4, 2);
        success = false;
        std::cout << "M3x3.get() Exception not thrown, and it should be.\n";
    } catch (const std::invalid_argument& e) {
        // std::cout << e.what() << '\n';
    }
    try {
        m.get(0, 4);
        success = false;
        std::cout << "M3x3.get() Exception not thrown, and it should be.\n";
    } catch (const std::invalid_argument& e) {
        // std::cout << e.what() << '\n';
    }
    
    return success;
}
bool check_default_m2x2() {
    M2x2 m;

    for (int row = 0; row < 2; row += 1) {
        for (int col = 0; col < 2; col += 1) {
            if (m.get(row, col) != 0) {
                std::cout << "Error: M2x2.get(" << row << ", " << col << ") != 0 -> " << m.get(row, col) << "\n";
                return false;
            }
        }
    }
    
    return true;
}

bool check_m2x2_set_and_get() {
    M2x2 m;
    m.set_by_row(
        -3, 5,
        1, -2
    );
    bool success = true;
    if (m.get(0, 0) != -3) { std::cout << "Error: M2x2.get(0, 0) != -3"; success = false; }
    if (m.get(0, 1) != 5) { std::cout << "Error: M2x2.get(0, 1) != 5"; success = false; }
    if (m.get(1, 0) != 1) { std::cout << "Error: M2x2.get(1, 0) != 1"; success = false; }
    if (m.get(1, 1) != -2) { std::cout << "Error: M2x2.get(1, 1) != -2"; success = false; }

    try {
        m.get(4, 2);
        success = false;
        std::cout << "M2x2.get() Exception not thrown, and it should be.\n";
    } catch (const std::invalid_argument& e) {
        // std::cout << e.what() << '\n';
    }
    try {
        m.get(0, 4);
        success = false;
        std::cout << "M2x2.get() Exception not thrown, and it should be.\n";
    } catch (const std::invalid_argument& e) {
        // std::cout << e.what() << '\n';
    }
    
    return success;
}

int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    if(!check_default_m4x4()) {
        cnt_failed += 1;
        std::cout << "check_default_m4x4() failed\n";
    } else {
        cnt_passed += 1;
    }
    
    if(!check_m4x4_set_and_get()) {
        cnt_failed += 1;
        std::cout << "check_m4x4_set_and_get() failed\n";
    } else {
        cnt_passed += 1;
    }

    if(!check_m4x4_equality()) {
        cnt_failed += 1;
        std::cout << "check_m4x4_equality() failed\n";
    } else {
        cnt_passed += 1;
    }

    if(!check_m4x4_inequality()) {
        cnt_failed += 1;
        std::cout << "check_m4x4_inequality() failed\n";
    } else {
        cnt_passed += 1;
    }

    if(!check_m4x4_multiply()) {
        cnt_failed += 1;
        std::cout << "check_m4x4_multiply() failed\n";
    } else {
        cnt_passed += 1;
    }

    if(!check_m4x4_Vector4_multiply()) {
        cnt_failed += 1;
        std::cout << "check_m4x4_Vector4_multiply() failed\n";
    } else {
        cnt_passed += 1;
    }

    if(!check_default_m3x3()) {
        cnt_failed += 1;
        std::cout << "check_default_m3x3() failed\n";
    } else {
        cnt_passed += 1;
    }
    
    if(!check_m3x3_set_and_get()) {
        cnt_failed += 1;
        std::cout << "check_m3x3_set_and_get() failed\n";
    } else {
       cnt_passed += 1;
    }

    if(!check_default_m2x2()) {
        cnt_failed += 1;
        std::cout << "check_default_m2x2() failed\n";
    } else {
        cnt_passed += 1;
    }
    
    if(!check_m2x2_set_and_get()) {
        cnt_failed += 1;
        std::cout << "check_m2x2_set_and_get() failed\n";
    } else {
        cnt_passed += 1;
    }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}
