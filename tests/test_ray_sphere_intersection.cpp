// g++ test_ray_sphere_intersection.cpp ../Intersection.cpp ../Matrix4x4.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp
#include <iostream>
#include "../Ray.h"
#include "../Sphere.h"
#include "../Intersection.h"

bool ray_intersects_sphere_at_two_points();
bool ray_intersects_sphere_at_a_tangent();
bool ray_misses_a_sphere();
bool ray_originates_inside_a_sphere();
bool sphere_is_behind_a_ray();
bool intersect_sets_the_object_on_the_intersection();
bool intersecting_a_scaled_sphere_with_a_ray();
bool intersecting_a_translated_sphere_with_a_ray();


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

    if(!intersect_sets_the_object_on_the_intersection()) {
        cnt_failed += 1;
        std::cout << "intersect_sets_the_object_on_the_intersection failed\n";
    } else { cnt_passed += 1; }

    if(!intersecting_a_scaled_sphere_with_a_ray()) {
        cnt_failed += 1;
        std::cout << "intersecting_a_scaled_sphere_with_a_ray failed\n";
    } else { cnt_passed += 1; }

    if(!intersecting_a_translated_sphere_with_a_ray()) {
        cnt_failed += 1;
        std::cout << "intersecting_a_translated_sphere_with_a_ray failed\n";
    } else { cnt_passed += 1; }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool ray_intersects_sphere_at_two_points() {
    Ray ray(make_point(0.0f, 0.0f, -5.0f), make_vector(0.0f, 0.0f, 1.0f));
    Sphere sphere;

    Intersections result = intersect(&sphere, ray);
    
    if (result.count() != 2) return false;
    if (result[0].t != 4.0f) return false;
    if (result[1].t != 6.0f) return false;

    return true; 
}

bool ray_intersects_sphere_at_a_tangent() {
    Ray ray(make_point(0.0f, 1.0f, -5.0f), make_vector(0.0f, 0.0f, 1.0f));
    Sphere sphere;

    Intersections result = intersect(&sphere, ray);
    
    if (result.count() != 2) return false;
    if (result[0].t != 5.0f) return false;
    if (result[1].t != 5.0f) return false;

    return true; 
}

bool ray_misses_a_sphere() {
    Ray ray(make_point(0.0f, 2.0f, -5.0f), make_vector(0.0f, 0.0f, 1.0f));
    Sphere sphere;

    Intersections result = intersect(&sphere, ray);
    
    if (result.count() != 0) return false;

    return true; 
}

bool ray_originates_inside_a_sphere() {
    Ray ray(make_point(0.0f, 0.0f, 0.0f), make_vector(0.0f, 0.0f, 1.0f));
    Sphere sphere;

    Intersections result = intersect(&sphere, ray);
    
    if (result.count() != 2) return false;
    if (result[0].t != -1.0f) return false;
    if (result[1].t != 1.0f) return false;

    return true; 
}

bool sphere_is_behind_a_ray() {
    Ray ray(make_point(0.0f, 0.0f, 5.0f), make_vector(0.0f, 0.0f, 1.0f));
    Sphere sphere;

    Intersections result = intersect(&sphere, ray);
    
    if (result.count() != 2) return false;
    if (result[0].t != -6.0f) return false;
    if (result[1].t != -4.0f) return false;

    return true; 
}

bool intersect_sets_the_object_on_the_intersection() {
    Ray ray(make_point(0.0f, 0.0f, -5.0f), make_vector(0.0f, 0.0f, 1.0f));
    Sphere sphere;

    Intersections result = intersect(&sphere, ray);
    
    if (result.count() != 2) return false;
    if (result[0].object != &sphere) return false;
    if (result[1].object != &sphere) return false;

    return true; 
    return true;
}

bool intersecting_a_scaled_sphere_with_a_ray() {
    Ray ray(make_point(0.0f, 0.0f, -5.0f), make_vector(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    sphere.transform = scaling(2.0f, 2.0f, 2.0f);

    Intersections result = intersect(&sphere, ray);
    
    if (result.count() != 2) return false;
    if (result[0].t != 3.0f) return false;
    if (result[1].t != 7.0f) return false;

    return true; 
}

bool intersecting_a_translated_sphere_with_a_ray() {
    Ray ray(make_point(0.0f, 0.0f, -5.0f), make_vector(0.0f, 0.0f, 1.0f));
    Sphere sphere;
    sphere.transform = translation(5.0f, 0.0f, 0.0f);

    Intersections result = intersect(&sphere, ray);
    
    if (result.count() != 0) return false;

    return true; 
}
