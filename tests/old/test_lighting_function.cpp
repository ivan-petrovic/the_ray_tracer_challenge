// g++ test_lighting_function.cpp ../Lighting.cpp
#include <iostream>
#include "../first_version/Vector4.h"
#include "../first_version/Material.h"
#include "../first_version/PointLight.h"
#include "../first_version/Lighting.h"

Material m;
Vector4 position;

void setup();
bool lighting_with_the_eye_between_the_light_and_the_surface();
bool lighting_with_the_eye_between_the_light_and_the_surface_with_eye_offset_45();
bool lighting_with_the_eye_between_the_light_and_the_surface_with_light_offset_45();
bool lighting_with_the_eye_in_the_path_of_the_reflection_vector();
bool lighting_with_the_light_behind_the_surface();


int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Testing Lightning calculation (The Phong Reflection Model)\n";
    setup();

    if(!lighting_with_the_eye_between_the_light_and_the_surface()) {
        cnt_failed += 1;
        std::cout << "lighting_with_the_eye_between_the_light_and_the_surface failed\n";
    } else { cnt_passed += 1; }

    if(!lighting_with_the_eye_between_the_light_and_the_surface_with_eye_offset_45()) {
        cnt_failed += 1;
        std::cout << "lighting_with_the_eye_between_the_light_and_the_surface_with_eye_offset_45 failed\n";
    } else { cnt_passed += 1; }

    if(!lighting_with_the_eye_between_the_light_and_the_surface_with_light_offset_45()) {
        cnt_failed += 1;
        std::cout << "lighting_with_the_eye_between_the_light_and_the_surface_with_light_offset_45 failed\n";
    } else { cnt_passed += 1; }

    if(!lighting_with_the_eye_in_the_path_of_the_reflection_vector()) {
        cnt_failed += 1;
        std::cout << "lighting_with_the_eye_in_the_path_of_the_reflection_vector failed\n";
    } else { cnt_passed += 1; }

    if(!lighting_with_the_light_behind_the_surface()) {
        cnt_failed += 1;
        std::cout << "lighting_with_the_light_behind_the_surface failed\n";
    } else { cnt_passed += 1; }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

void setup() {
    m = Material();
    position = make_point(0.0f, 0.0f, 0.0f);
}

bool lighting_with_the_eye_between_the_light_and_the_surface() {
    Vector4 eyev = make_vector(0.0f, 0.0f, -1.0f);
    Vector4 normalv = make_vector(0.0f, 0.0f, -1.0f);
    PointLight light(make_point(0.0f, 0.0f, -10.0f), Color(1.0f, 1.0f, 1.0f));
    
    Color result = lighting(m, light, position, eyev, normalv);

    Color expected_result(1.9f, 1.9f, 1.9f);

    if (result != expected_result) return false;

    return true; 
}

bool lighting_with_the_eye_between_the_light_and_the_surface_with_eye_offset_45() {
    float sqrt_of_2 = 1.41421356;
    const float EPSILON = 0.00001f;
    Vector4 eyev = make_vector(0.0f, sqrt_of_2/2, -sqrt_of_2/2);
    Vector4 normalv = make_vector(0.0f, 0.0f, -1.0f);
    PointLight light(make_point(0.0f, 0.0f, -10.0f), Color(1.0f, 1.0f, 1.0f));
    
    Color result = lighting(m, light, position, eyev, normalv);

    Color expected_result(1.0f, 1.0f, 1.0f);

    if (abs(result.r - expected_result.r) > EPSILON) return false;
    if (abs(result.g - expected_result.g) > EPSILON) return false;
    if (abs(result.b - expected_result.b) > EPSILON) return false;

    return true; 
}

bool lighting_with_the_eye_between_the_light_and_the_surface_with_light_offset_45() {
    float sqrt_of_2 = 1.41421356;
    Vector4 eyev = make_vector(0.0f, 0.0f, -1.0f);
    Vector4 normalv = make_vector(0.0f, 0.0f, -1.0f);
    PointLight light(make_point(0.0f, 10.0f, -10.0f), Color(1.0f, 1.0f, 1.0f));
    
    Color result = lighting(m, light, position, eyev, normalv);

    Color expected_result(0.7364f, 0.7364f, 0.7364f);

    const float EPSILON = 0.00001f;
    if (abs(result.r - expected_result.r) > EPSILON) return false;
    if (abs(result.g - expected_result.g) > EPSILON) return false;
    if (abs(result.b - expected_result.b) > EPSILON) return false;

    return true; 
}

bool lighting_with_the_eye_in_the_path_of_the_reflection_vector() {
    float sqrt_of_2 = 1.41421356;
    Vector4 eyev = make_vector(0.0f, -sqrt_of_2/2, -sqrt_of_2/2);
    Vector4 normalv = make_vector(0.0f, 0.0f, -1.0f);
    PointLight light(make_point(0.0f, 10.0f, -10.0f), Color(1.0f, 1.0f, 1.0f));
    
    Color result = lighting(m, light, position, eyev, normalv);

    Color expected_result(1.6364f, 1.6364f, 1.6364f);

    const float EPSILON = 0.0001f;
    if (abs(result.r - expected_result.r) > EPSILON) return false;
    if (abs(result.g - expected_result.g) > EPSILON) return false;
    if (abs(result.b - expected_result.b) > EPSILON) return false;

    return true; 
}

bool lighting_with_the_light_behind_the_surface() {
    float sqrt_of_2 = 1.41421;
    Vector4 eyev = make_vector(0.0f, 0.0f, -1.0f);
    Vector4 normalv = make_vector(0.0f, 0.0f, -1.0f);
    PointLight light(make_point(0.0f, 10.0f, 10.0f), Color(1.0f, 1.0f, 1.0f));
    
    Color result = lighting(m, light, position, eyev, normalv);

    Color expected_result(0.1f, 0.1f, 0.1f);

    if (result != expected_result) return false;

    return true; 
}
