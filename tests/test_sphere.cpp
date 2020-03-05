// g++ test_sphere.cpp ../Matrix4x4.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp
#include <iostream>
#include "../Sphere.h"
#include "../Matrix4x4.h"

bool spheres_default_transformation();
bool changing_a_spheres_transformation();
bool normal_on_a_sphere_at_a_point_on_the_x_axis();
bool normal_on_a_sphere_at_a_point_on_the_y_axis();
bool normal_on_a_sphere_at_a_point_on_the_z_axis();
bool the_normal_is_a_normalized_vector();
bool computing_the_normal_on_a_translated_sphere();
bool computing_the_normal_on_a_transformad_sphere();
bool sphere_has_a_default_material();
bool sphere_can_be_assigned_a_material();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Testing Ray class\n";

    if(!spheres_default_transformation()) {
        cnt_failed += 1;
        std::cout << "spheres_default_transformation failed\n";
    } else { cnt_passed += 1; }

    if(!changing_a_spheres_transformation()) {
        cnt_failed += 1;
        std::cout << "changing_a_spheres_transformation failed\n";
    } else { cnt_passed += 1; }

    if(!normal_on_a_sphere_at_a_point_on_the_x_axis()) {
        cnt_failed += 1;
        std::cout << "normal_on_a_sphere_at_a_point_on_the_x_axis failed\n";
    } else { cnt_passed += 1; }
    
    if(!normal_on_a_sphere_at_a_point_on_the_y_axis()) {
        cnt_failed += 1;
        std::cout << "normal_on_a_sphere_at_a_point_on_the_y_axis failed\n";
    } else { cnt_passed += 1; }
    
    if(!normal_on_a_sphere_at_a_point_on_the_z_axis()) {
        cnt_failed += 1;
        std::cout << "normal_on_a_sphere_at_a_point_on_the_z_axis failed\n";
    } else { cnt_passed += 1; }

    if(!the_normal_is_a_normalized_vector()) {
        cnt_failed += 1;
        std::cout << "the_normal_is_a_normalized_vector failed\n";
    } else { cnt_passed += 1; }

    if(!computing_the_normal_on_a_translated_sphere()) {
        cnt_failed += 1;
        std::cout << "computing_the_normal_on_a_translated_sphere failed\n";
    } else { cnt_passed += 1; }

    if(!computing_the_normal_on_a_transformad_sphere()) {
        cnt_failed += 1;
        std::cout << "computing_the_normal_on_a_transformad_sphere failed\n";
    } else { cnt_passed += 1; }

    if(!sphere_has_a_default_material()) {
        cnt_failed += 1;
        std::cout << "sphere_has_a_default_material failed\n";
    } else { cnt_passed += 1; }

    if(!sphere_can_be_assigned_a_material()) {
        cnt_failed += 1;
        std::cout << "sphere_can_be_assigned_a_material failed\n";
    } else { cnt_passed += 1; }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool spheres_default_transformation() {
    Sphere sphere;
    Matrix4x4 I; I.identity();

    if (sphere.transform != I) return false;

    return true; 
}

bool changing_a_spheres_transformation() {
    Sphere sphere;
    Matrix4x4 T = translation(2.0f, 3.0f, 4.0f);
    sphere.transform = T;

    if (sphere.transform != T) return false;

    return true; 
}

bool normal_on_a_sphere_at_a_point_on_the_x_axis() {
    Sphere sphere;
    Vector4 point_on_surface = make_point(1.0f, 0.0f, 0.0f);
    Vector4 n = sphere.normal_at(point_on_surface);
    
    if (n != point_on_surface) return false;

    return true; 
}

bool normal_on_a_sphere_at_a_point_on_the_y_axis() {
    Sphere sphere;
    Vector4 point_on_surface = make_point(0.0f, 1.0f, 0.0f);
    Vector4 n = sphere.normal_at(point_on_surface);
    
    if (n != point_on_surface) return false;

    return true; 
}

bool normal_on_a_sphere_at_a_point_on_the_z_axis() {
    Sphere sphere;
    Vector4 point_on_surface = make_point(0.0f, 0.0f, 1.0f);
    Vector4 n = sphere.normal_at(point_on_surface);
    
    if (n != point_on_surface) return false;

    return true; 
}

bool normal_on_a_sphere_at_a_nonaxial_point() {
    Sphere sphere;
    float sqrt_of_3 = 1.732051;
    Vector4 point_on_surface = make_point(sqrt_of_3/3, sqrt_of_3/3, sqrt_of_3/3);
    Vector4 n = sphere.normal_at(point_on_surface);
    
    if (n != point_on_surface) return false;

    return true; 
}

bool the_normal_is_a_normalized_vector() {
    const float EPSILON = 0.00001f;
    Sphere sphere;
    float sqrt_of_3 = 1.732051;
    Vector4 point_on_surface = make_point(sqrt_of_3/3, sqrt_of_3/3, sqrt_of_3/3);
    Vector4 n = sphere.normal_at(point_on_surface);
    
    if (abs(vectorMag(n) - 1.0f) > EPSILON) return false;

    return true; 
}

bool computing_the_normal_on_a_translated_sphere() {
    Sphere sphere;
    sphere.transform = translation(0.0f, 1.0f, 0.0f);

    Vector4 point_on_surface = make_point(0.0f, 1.70711f, -0.70711f);
    Vector4 n = sphere.normal_at(point_on_surface);
    
    if (n != make_point(0.0f, 0.70711f, -0.70711f)) return false;

    return true; 
}

bool computing_the_normal_on_a_transformad_sphere() {
    const float EPSILON = 0.00001f;
    Sphere sphere;
    sphere.transform = scaling(1.0f, 0.5f, 1.0f) * rotation_z(3.14159f/5);

    float sqrt_of_2 = 1.41421;
    Vector4 point_on_surface = make_point(0.0f, sqrt_of_2/2, -sqrt_of_2/2);
    Vector4 n = sphere.normal_at(point_on_surface);
    
    if (n != make_vector(0.0f, 0.97014f, -0.24254f)) return false;

    return true; 
}

bool sphere_has_a_default_material() {
    Sphere sphere;
    Material m;

    if (sphere.material.color != m.color) return false;
    if (sphere.material.ambient != m.ambient) return false;
    if (sphere.material.diffuse != m.diffuse) return false;
    if (sphere.material.specular != m.specular) return false;
    if (sphere.material.shininess != m.shininess) return false;

    return true; 
}

bool sphere_can_be_assigned_a_material() {
    Sphere sphere;
    Material m;
    m.ambient = 1.0f;

    sphere.material = m;

    if (sphere.material.color != m.color) return false;
    if (sphere.material.ambient != m.ambient) return false;
    if (sphere.material.diffuse != m.diffuse) return false;
    if (sphere.material.specular != m.specular) return false;
    if (sphere.material.shininess != m.shininess) return false;

    return true; 
}
