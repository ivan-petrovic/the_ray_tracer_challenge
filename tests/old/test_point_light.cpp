// g++ test_point_light.cpp
#include <iostream>
#include "../../first_version/PointLight.h"


bool point_light_has_a_position_and_intensity();

int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Testing Ray class\n";

    if(!point_light_has_a_position_and_intensity()) {
        cnt_failed += 1;
        std::cout << "point_light_has_a_position_and_intensity failed\n";
    } else { cnt_passed += 1; }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool point_light_has_a_position_and_intensity() {
    Vector4 position = make_point(0.0f, 0.0f, 0.0f);
    Color intensity(1.0f, 1.0f, 1.0f);

    PointLight l(position, intensity);

    if (l.position != position) return false;
    if (l.intensity != intensity) return false;

    return true; 
}
