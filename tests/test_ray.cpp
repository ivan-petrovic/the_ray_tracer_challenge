// g++ test_ray.cpp
#include <iostream>
#include "../Ray.h"

bool ray_creation();
bool computing_a_point_from_a_distance();

int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Testing Ray class\n";

    if(!ray_creation()) {
        cnt_failed += 1;
        std::cout << "ray_creation failed\n";
    } else { cnt_passed += 1; }

    if(!computing_a_point_from_a_distance()) {
        cnt_failed += 1;
        std::cout << "computing_a_point_from_a_distance failed\n";
    } else { cnt_passed += 1; }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool ray_creation() {
    Vector4 origin = make_point(1.0f, 2.0f, 3.0f);
    Vector4 direction = make_vector(4.0f, 5.0f, 6.0f);
    Ray r(origin, direction);

    if (r.origin != origin) return false;
    if (r.direction != direction) return false;

    return true; 
}

bool computing_a_point_from_a_distance() {
    Ray r(make_point(2.0f, 3.0f, 4.0f), make_vector(1.0f, 0.0f, 0.0f));

    if (r.position(0.0f) != make_point(2.0f, 3.0f, 4.0f)) return false;
    if (r.position(1.0f) != make_point(3.0f, 3.0f, 4.0f)) return false;
    if (r.position(-1.0f) != make_point(1.0f, 3.0f, 4.0f)) return false;
    if (r.position(2.5f) != make_point(4.5f, 3.0f, 4.0f)) return false;

    return true;
}
