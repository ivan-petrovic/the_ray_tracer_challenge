#include <iostream>
#include "../Matrix2x2.h"
#include "../Vector4.h"


bool test_set_and_get();
bool test_calculating_the_determinant();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Test Matrix2x2 class\n";
    std::cout << "--------------------\n";

    if(!test_set_and_get()) { cnt_failed += 1; std::cout << "test_set_and_get failed\n"; }
    else cnt_passed += 1;

    if(!test_calculating_the_determinant()) { cnt_failed += 1; std::cout << "test_calculating_the_determinant failed\n"; }
    else cnt_passed += 1;

    std::cout << "\nTotal:  " << (cnt_passed + cnt_failed) << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool test_set_and_get() {
    Matrix2x2 m;
    m.set_row_by_row(
        -3.0f, 5.0f,
        1.0f, -2.0f
    );

    if (m.m00 != -3.0f) return false;
    if (m.m01 != 5.0f) return false;
    if (m.m10 != 1.0f) return false;
    if (m.m11 != -2.0f) return false;

    return true;
}

bool test_calculating_the_determinant() {
    Matrix2x2 A;
    A.set_row_by_row(
        1.0f, 5.0f,
        -3.0f, 2.0f
    );

    return determinant(A) == 17.0f;
}
