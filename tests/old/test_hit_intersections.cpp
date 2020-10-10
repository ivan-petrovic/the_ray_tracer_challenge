// g++ test_hit_intersections.cpp ../Intersection.cpp ../Matrix4x4.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp
#include <iostream>
#include "../first_version/Sphere.h"
#include "../first_version/Intersection.h"

bool the_hit_when_all_intersections_have_positive_t();
bool the_hit_when_some_intersections_have_negative_t();
bool the_hit_when_all_intersections_have_negative_t();
bool the_hit_is_always_the_lowest_nonnegative_intersection();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Testing hit intersection\n";

    if(!the_hit_when_all_intersections_have_positive_t()) {
        cnt_failed += 1;
        std::cout << "the_hit_when_all_intersections_have_positive_t failed\n";
    } else { cnt_passed += 1; }

    if(!the_hit_when_some_intersections_have_negative_t()) {
        cnt_failed += 1;
        std::cout << "the_hit_when_some_intersections_have_negative_t failed\n";
    } else { cnt_passed += 1; }

    if(!the_hit_when_all_intersections_have_negative_t()) {
        cnt_failed += 1;
        std::cout << "the_hit_when_all_intersections_have_negative_t failed\n";
    } else { cnt_passed += 1; }

    if(!the_hit_is_always_the_lowest_nonnegative_intersection()) {
        cnt_failed += 1;
        std::cout << "the_hit_is_always_the_lowest_nonnegative_intersection failed\n";
    } else { cnt_passed += 1; }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool the_hit_when_all_intersections_have_positive_t() {
    Sphere sphere;
    Intersection i1(1.0f, &sphere);
    Intersection i2(2.0f, &sphere);

    Intersections xs;
    xs.add(i1);
    xs.add(i2);
    
    Intersection i = hit(xs);

    if (i != i1) return false;

    return true; 
}

bool the_hit_when_some_intersections_have_negative_t() {
    Sphere sphere;
    Intersection i1(-1.0f, &sphere);
    Intersection i2(1.0f, &sphere);

    Intersections xs;
    xs.add(i1);
    xs.add(i2);
    
    Intersection i = hit(xs);

    if (i != i2) return false;

    return true; 
}

bool the_hit_when_all_intersections_have_negative_t() {
    Sphere sphere;
    Intersection i1(-2.0f, &sphere);
    Intersection i2(-1.0f, &sphere);

    Intersections xs;
    xs.add(i2);
    xs.add(i1);
    
    Intersection i = hit(xs);

    if (true != i) return false;

    return true; 
}

bool the_hit_is_always_the_lowest_nonnegative_intersection() {
    Sphere sphere;
    Intersection i1(5.0f, &sphere);
    Intersection i2(7.0f, &sphere);
    Intersection i3(-3.0f, &sphere);
    Intersection i4(2.0f, &sphere);

    Intersections xs;
    xs.add(i1); xs.add(i2); xs.add(i3); xs.add(i4);
    
    Intersection i = hit(xs);

    if (i != i4) return false;

    return true; 
}
