#include <iostream>
#include "../Matrix3x3.h"
#include "../Vector4.h"


bool test_set_and_get();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Test Matrix3x3 class\n";
    std::cout << "--------------------\n";

    if(!test_set_and_get()) { cnt_failed += 1; std::cout << "test_set_and_get failed\n"; }
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
