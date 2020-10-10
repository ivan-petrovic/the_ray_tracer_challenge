// g++ test_ray.cpp ../Matrix4x4.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp
#include <iostream>
#include "../../first_version/Ray.h"
#include "../../first_version/Matrix4x4.h"

bool ray_creation();
bool computing_a_point_from_a_distance();
bool translating_a_ray();
bool scaling_a_ray();

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

    if(!translating_a_ray()) {
        cnt_failed += 1;
        std::cout << "translating_a_ray failed\n";
    } else { cnt_passed += 1; }

    if(!scaling_a_ray()) {
        cnt_failed += 1;
        std::cout << "scaling_a_ray failed\n";
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

bool translating_a_ray() {
    Ray r(make_point(1.0f, 2.0f, 3.0f), make_vector(0.0f, 1.0f, 0.0f));
    Matrix4x4 T = translation(3.0f, 4.0f, 5.0f);

    Ray result = r.transform(T);

    if (result.origin != make_point(4.0f, 6.0f, 8.0f)) return false;
    if (result.direction != make_vector(0.0f, 1.0f, 0.0f)) return false;

    return true;
}

bool scaling_a_ray() {
    Ray r(make_point(1.0f, 2.0f, 3.0f), make_vector(0.0f, 1.0f, 0.0f));
    Matrix4x4 S = scaling(2.0f, 3.0f, 4.0f);

    Ray result = r.transform(S);

    if (result.origin != make_point(2.0f, 6.0f, 12.0f)) return false;
    if (result.direction != make_vector(0.0f, 3.0f, 0.0f)) return false;

    return true;
}
