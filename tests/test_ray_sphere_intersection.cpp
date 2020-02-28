// g++ test_ray_sphere_intersection.cpp ../Intersection.cpp
#include <iostream>
#include "../Ray.h"
#include "../Sphere.h"
#include "../Intersection.h"

bool ray_intersects_sphere_at_two_points();
bool ray_intersects_sphere_at_a_tangent();
bool ray_misses_a_sphere();
bool ray_originates_inside_a_sphere();
bool sphere_is_behind_a_ray();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Testing Ray Sphere intersection\n";

    if(!ray_intersects_sphere_at_two_points()) {
        cnt_failed += 1;
        std::cout << "ray_intersects_sphere_at_two_points failed\n";
    } else { cnt_passed += 1; }

    if(!ray_intersects_sphere_at_a_tangent()) {
        cnt_failed += 1;
        std::cout << "ray_intersects_sphere_at_a_tangent failed\n";
    } else { cnt_passed += 1; }

    if(!ray_misses_a_sphere()) {
        cnt_failed += 1;
        std::cout << "ray_misses_a_sphere failed\n";
    } else { cnt_passed += 1; }

    if(!ray_originates_inside_a_sphere()) {
        cnt_failed += 1;
        std::cout << "ray_originates_inside_a_sphere failed\n";
    } else { cnt_passed += 1; }

    if(!sphere_is_behind_a_ray()) {
        cnt_failed += 1;
        std::cout << "sphere_is_behind_a_ray failed\n";
    } else { cnt_passed += 1; }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool ray_intersects_sphere_at_two_points() {
    Ray ray(make_point(0.0f, 0.0f, -5.0f), make_vector(0.0f, 0.0f, 1.0f));
    Sphere sphere;

    std::vector<float> result = intersect(&sphere, ray);
    
    if (result.size() != 2) return false;
    if (result[0] != 4.0f) return false;
    if (result[1] != 6.0f) return false;

    return true; 
}

bool ray_intersects_sphere_at_a_tangent() {
    Ray ray(make_point(0.0f, 1.0f, -5.0f), make_vector(0.0f, 0.0f, 1.0f));
    Sphere sphere;

    std::vector<float> result = intersect(&sphere, ray);
    
    if (result.size() != 2) return false;
    if (result[0] != 5.0f) return false;
    if (result[1] != 5.0f) return false;

    return true; 
}

bool ray_misses_a_sphere() {
    Ray ray(make_point(0.0f, 2.0f, -5.0f), make_vector(0.0f, 0.0f, 1.0f));
    Sphere sphere;

    std::vector<float> result = intersect(&sphere, ray);
    
    if (result.size() != 0) return false;

    return true; 
}

bool ray_originates_inside_a_sphere() {
    Ray ray(make_point(0.0f, 0.0f, 0.0f), make_vector(0.0f, 0.0f, 1.0f));
    Sphere sphere;

    std::vector<float> result = intersect(&sphere, ray);
    
    if (result.size() != 2) return false;
    if (result[0] != -1.0f) return false;
    if (result[1] != 1.0f) return false;

    return true; 
}

bool sphere_is_behind_a_ray() {
    Ray ray(make_point(0.0f, 0.0f, 5.0f), make_vector(0.0f, 0.0f, 1.0f));
    Sphere sphere;

    std::vector<float> result = intersect(&sphere, ray);
    
    if (result.size() != 2) return false;
    if (result[0] != -6.0f) return false;
    if (result[1] != -4.0f) return false;

    return true; 
}
