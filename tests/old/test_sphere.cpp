// g++ test_sphere.cpp ../Matrix4x4.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp
#include <iostream>
#include "../../first_version/Sphere.h"
#include "../../first_version/Matrix4x4.h"

bool sphere_has_a_default_material();
bool sphere_can_be_assigned_a_material();

int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    if(!sphere_has_a_default_material()) {
        cnt_failed += 1;
        std::cout << "sphere_has_a_default_material failed\n";
    } else { cnt_passed += 1; }

    if(!sphere_can_be_assigned_a_material()) {
        cnt_failed += 1;
        std::cout << "sphere_can_be_assigned_a_material failed\n";
    } else { cnt_passed += 1; }

    return 0;
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
