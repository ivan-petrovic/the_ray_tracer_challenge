// g++ test_material.cpp
#include <iostream>
#include "../first_version/Material.h"


bool the_default_material();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Testing Ray class\n";

    if(!the_default_material()) {
        cnt_failed += 1;
        std::cout << "the_default_material failed\n";
    } else { cnt_passed += 1; }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool the_default_material() {
    Material m;

    if (m.color != Color(1.0f, 1.0f, 1.0f)) return false;
    if (m.ambient != 0.1f) return false;
    if (m.diffuse != 0.9f) return false;
    if (m.specular != 0.9f) return false;
    if (m.shininess != 200.0f) return false;

    return true; 
}
