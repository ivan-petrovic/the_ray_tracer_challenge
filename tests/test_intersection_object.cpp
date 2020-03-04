// g++ test_intersection_object.cpp ../Intersection.cpp
#include <iostream>
#include "../Sphere.h"
#include "../Intersection.h"

bool intersection_encapsulates_t_and_object();
bool aggregating_intersections();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Testing Ray Sphere intersection\n";

    if(!intersection_encapsulates_t_and_object()) {
        cnt_failed += 1;
        std::cout << "intersection_encapsulates_t_and_object failed\n";
    } else { cnt_passed += 1; }

    if(!aggregating_intersections()) {
        cnt_failed += 1;
        std::cout << "aggregating_intersections failed\n";
    } else { cnt_passed += 1; }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool intersection_encapsulates_t_and_object() {
    Sphere sphere;

    Intersection i(3.5f, &sphere);
    
    if (i.t != 3.5f) return false;
    if (i.object != &sphere) return false;

    return true; 
}

bool aggregating_intersections() {
    Sphere sphere;

    Intersection i1(1.0f, &sphere);
    Intersection i2(2.0f, &sphere);

    Intersections xs;
    xs.add(i1);
    xs.add(i2);
    
    if (xs.count() != 2) return false;
    if (xs[0].t != 1.0f) return false;
    if (xs[1].t != 2.0f) return false;

    return true; 
}
