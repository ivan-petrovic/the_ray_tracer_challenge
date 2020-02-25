// g++ test_color.cpp
#include <iostream>
#include "../Color.h"

bool color_creation();
bool adding_colors();
bool subtracting_colors();
bool multiplying_color_by_a_scalar();
bool dividing_color_by_a_scalar();
bool multiplying_colors();

int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Testing color class\n";

    if(!color_creation()) { cnt_failed += 1; std::cout << "color_creation() failed\n"; }
    else { cnt_passed += 1; }

    if(!adding_colors()) { cnt_failed += 1; std::cout << "adding_colors() failed\n"; }
    else { cnt_passed += 1; }

    if(!subtracting_colors()) { cnt_failed += 1; std::cout << "subtracting_colors() failed\n"; }
    else { cnt_passed += 1; }
    
    if(!multiplying_color_by_a_scalar()) { cnt_failed += 1; std::cout << "multiplying_color_by_a_scalar() failed\n"; }
    else { cnt_passed += 1; }

    if(!dividing_color_by_a_scalar()) { cnt_failed += 1; std::cout << "dividing_color_by_a_scalar() failed\n"; }
    else { cnt_passed += 1; }

    if(!multiplying_colors()) { cnt_failed += 1; std::cout << "multiplying_colors() failed\n"; }
    else { cnt_passed += 1; }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool color_creation() {
    Color c(-0.5f, 0.4f, 1.7f);

    if (c.r != -0.5f) return false;
    if (c.g != 0.4f) return false;
    if (c.b != 1.7f) return false;

    return true; 
}

bool adding_colors() {
    const float EPSILON = 0.0001f;

    Color c1(0.9f, 0.6f, 0.75f);
    Color c2(0.7f, 0.1f, 0.25f);
    Color expected_result(1.6f, 0.7f, 1.0f);
    
    Color actual_result = c1 + c2;

    if (abs(expected_result.r - actual_result.r) > EPSILON) return false;
    if (abs(expected_result.g - actual_result.g) > EPSILON) return false;
    if (abs(expected_result.b - actual_result.b) > EPSILON) return false;

    return true; 
}

bool subtracting_colors() {
    const float EPSILON = 0.0001f;

    Color c1(0.9f, 0.6f, 0.75f);
    Color c2(0.7f, 0.1f, 0.25f);
    Color expected_result(0.2f, 0.5f, 0.5f);
    
    Color actual_result = c1 - c2;

    if (abs(expected_result.r - actual_result.r) > EPSILON) return false;
    if (abs(expected_result.g - actual_result.g) > EPSILON) return false;
    if (abs(expected_result.b - actual_result.b) > EPSILON) return false;

    return true; 
}

bool multiplying_color_by_a_scalar() {
    const float EPSILON = 0.0001f;

    Color c(0.2f, 0.3f, 0.4f);
    Color expected_result(0.4f, 0.6f, 0.8f);
    
    Color actual_result = c * 2.0f;

    if (abs(expected_result.r - actual_result.r) > EPSILON) return false;
    if (abs(expected_result.g - actual_result.g) > EPSILON) return false;
    if (abs(expected_result.b - actual_result.b) > EPSILON) return false;

    return true; 
}

bool dividing_color_by_a_scalar() {
    const float EPSILON = 0.0001f;

    Color c(0.2f, 0.3f, 0.4f);
    Color expected_result(0.1f, 0.15f, 0.2f);
    
    Color actual_result = c / 2.0f;

    if (abs(expected_result.r - actual_result.r) > EPSILON) return false;
    if (abs(expected_result.g - actual_result.g) > EPSILON) return false;
    if (abs(expected_result.b - actual_result.b) > EPSILON) return false;

    return true; 
}

bool multiplying_colors() {
    const float EPSILON = 0.0001f;

    Color c1(1.0f, 0.2f, 0.4f);
    Color c2(0.9f, 1.0f, 0.1f);
    Color expected_result(0.9f, 0.2f, 0.04f);
    
    Color actual_result = c1 * c2;

    if (abs(expected_result.r - actual_result.r) > EPSILON) return false;
    if (abs(expected_result.g - actual_result.g) > EPSILON) return false;
    if (abs(expected_result.b - actual_result.b) > EPSILON) return false;

    return true; 
}
