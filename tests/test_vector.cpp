// g++ test_vector.cpp
#include <iostream>
#include "../Vector4.h"

bool check_vector4_point_creation();
bool check_point_creation();
bool check_vector_creation();
bool check_vector4_vector_creation();
bool adding_two_vectors();
bool subtracting_two_points();
bool subtracting_vector_from_a_point();
bool subtracting_two_vectors();
bool subtracting_a_vector_from_the_zero_vector();
bool negating_a_vector();
bool multiplying_a_vector_by_a_scalar();
bool multiplying_a_vector_by_a_fraction();
bool dividing_a_vector_by_a_fraction();
bool computing_the_magnitude_of_vector();
bool normalizing_vector();
bool dot_product();
bool cross_product();

int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Test vector class\n";
    std::cout << "--------------------\n";

    if(!check_vector4_point_creation()) { cnt_failed += 1; std::cout << "check_vector4_point_creation() failed\n"; }
    else { cnt_passed += 1; }

    if(!check_point_creation()) { cnt_failed += 1; std::cout << "check_point_creation() failed\n"; }
    else { cnt_passed += 1; }

    if(!check_vector4_vector_creation()) { cnt_failed += 1; std::cout << "check_vector4_vector_creation() failed\n"; }
    else { cnt_passed += 1; }

    if(!check_vector_creation()) { cnt_failed += 1; std::cout << "check_vector_creation() failed\n"; }
    else { cnt_passed += 1; }

    if(!adding_two_vectors()) { cnt_failed += 1; std::cout << "adding_two_vectors() failed\n"; }
    else { cnt_passed += 1; }

    if(!subtracting_two_points()) { cnt_failed += 1; std::cout << "subtracting_two_points() failed\n"; }
    else { cnt_passed += 1; }

    if(!subtracting_vector_from_a_point()) { cnt_failed += 1; std::cout << "subtracting_vector_from_a_point() failed\n"; }
    else { cnt_passed += 1; }

    if(!subtracting_two_vectors()) { cnt_failed += 1; std::cout << "subtracting_two_vectors() failed\n"; }
    else { cnt_passed += 1; }

    if(!subtracting_a_vector_from_the_zero_vector()) { cnt_failed += 1; std::cout << "subtracting_a_vector_from_the_zero_vector() failed\n"; }
    else { cnt_passed += 1; }

    if(!negating_a_vector()) { cnt_failed += 1; std::cout << "negating_a_vector() failed\n"; }
    else { cnt_passed += 1; }

    if(!multiplying_a_vector_by_a_scalar()) { cnt_failed += 1; std::cout << "multiplying_a_vector_by_a_scalar() failed\n"; }
    else { cnt_passed += 1; }

    if(!multiplying_a_vector_by_a_fraction()) { cnt_failed += 1; std::cout << "multiplying_a_vector_by_a_fraction() failed\n"; }
    else { cnt_passed += 1; }

    if(!dividing_a_vector_by_a_fraction()) { cnt_failed += 1; std::cout << "dividing_a_vector_by_a_fraction() failed\n"; }
    else { cnt_passed += 1; }

    if(!computing_the_magnitude_of_vector()) { cnt_failed += 1; std::cout << "computing_the_magnitude_of_vector() failed\n"; }
    else { cnt_passed += 1; }

    if(!normalizing_vector()) { cnt_failed += 1; std::cout << "normalizing_vector() failed\n"; }
    else { cnt_passed += 1; }

    if(!dot_product()) { cnt_failed += 1; std::cout << "dot_product() failed\n"; }
    else { cnt_passed += 1; }
    
    if(!cross_product()) { cnt_failed += 1; std::cout << "cross_product() failed\n"; }
    else { cnt_passed += 1; }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool check_point_creation() {
    Vector4 p = make_point(4.3f, -4.2f, 3.1f);

    if (p.x != 4.3f) { std::cout << "p.x != 4.3: " << p.x << "\n"; return false; }
    if (p.y != -4.2f) { std::cout << "p.y != -4.2: " << p.y << "\n"; return false; }
    if (p.z != 3.1f) { std::cout << "p.z != 3.1: " << p.z << "\n"; return false; }
    if (p.w != 1.0f) { std::cout << "p.w != 1.0: " << p.w << "\n"; return false; }
    if (p.is_vector()) { std::cout << "p.is_vector(): and should be point\n"; return false; }

    return true; 
}

bool check_vector4_point_creation() {
    Vector4 p(4.3f, -4.2f, 3.1f, 1.0f);

    if (p.x != 4.3f) { std::cout << "p.x != 4.3: " << p.x << "\n"; return false; }
    if (p.y != -4.2f) { std::cout << "p.y != -4.2: " << p.y << "\n"; return false; }
    if (p.z != 3.1f) { std::cout << "p.z != 3.1: " << p.z << "\n"; return false; }
    if (p.w != 1.0f) { std::cout << "p.w != 1.0: " << p.w << "\n"; return false; }
    if (p.is_vector()) { std::cout << "p.is_vector(): and should be point\n"; return false; }

    return true; 
}

bool check_vector_creation() {
    Vector4 p = make_vector(4.3f, -4.2f, 3.1f);

    if (p.x != 4.3f) { std::cout << "p.x != 4.3: " << p.x << "\n"; return false; }
    if (p.y != -4.2f) { std::cout << "p.y != -4.2: " << p.y << "\n"; return false; }
    if (p.z != 3.1f) { std::cout << "p.z != 3.1: " << p.z << "\n"; return false; }
    if (p.w != 0.0f) { std::cout << "p.w != 0.0: " << p.w << "\n"; return false; }
    if (p.is_point()) { std::cout << "p.is_point(): and should be vector\n"; return false; }

    return true; 
}

bool check_vector4_vector_creation() {
    Vector4 p(4.3f, -4.2f, 3.1f, 0.0f);

    if (p.x != 4.3f) { std::cout << "p.x != 4.3: " << p.x << "\n"; return false; }
    if (p.y != -4.2f) { std::cout << "p.y != -4.2: " << p.y << "\n"; return false; }
    if (p.z != 3.1f) { std::cout << "p.z != 3.1: " << p.z << "\n"; return false; }
    if (p.w != 0.0f) { std::cout << "p.w != 0.0: " << p.w << "\n"; return false; }
    if (p.is_point()) { std::cout << "p.is_point(): and should be vector\n"; return false; }

    return true; 
}

bool adding_two_vectors() {
    Vector4 a = make_point(3.0f, -2.0f, 5.0f);
    Vector4 b = make_vector(-2.0f, 3.0f, 1.0f);
    Vector4 expected_result(1.0f, 1.0f, 6.0f, 1.0);

    Vector4 c = a + b;

    if (c.x != expected_result.x) { std::cout << "c.x != 1.0: " << c.x << "\n"; return false; }
    if (c.y != expected_result.y) { std::cout << "c.y != 1.0: " << c.y << "\n"; return false; }
    if (c.z != expected_result.z) { std::cout << "c.z != 6.0: " << c.z << "\n"; return false; }
    if (c.w != expected_result.w) { std::cout << "c.w != 1.0: " << c.w << "\n"; return false; }

    return true;
}

bool subtracting_two_points() {
    Vector4 a = make_point(3.0f, 2.0f, 1.0f);
    Vector4 b = make_point(5.0f, 6.0f, 7.0f);
    Vector4 expected_result = make_vector(-2.0f, -4.0f, -6.0f);

    Vector4 c = a - b;

    if (c.x != expected_result.x) { std::cout << "c.x != -2.0: " << c.x << "\n"; return false; }
    if (c.y != expected_result.y) { std::cout << "c.y != -4.0: " << c.y << "\n"; return false; }
    if (c.z != expected_result.z) { std::cout << "c.z != -6.0: " << c.z << "\n"; return false; }
    if (c.w != expected_result.w) { std::cout << "c.w != 1.0: " << c.w << "\n"; return false; }

    return true;
}

bool subtracting_vector_from_a_point() {
    Vector4 p = make_point(3.0f, 2.0f, 1.0f);
    Vector4 v = make_vector(5.0f, 6.0f, 7.0f);
    Vector4 expected_result = make_point(-2.0f, -4.0f, -6.0f);

    Vector4 c = p - v;

    if (c.x != expected_result.x) { std::cout << "c.x != -2.0: " << c.x << "\n"; return false; }
    if (c.y != expected_result.y) { std::cout << "c.y != -4.0: " << c.y << "\n"; return false; }
    if (c.z != expected_result.z) { std::cout << "c.z != -6.0: " << c.z << "\n"; return false; }
    if (!c.is_point()) { std::cout << "c.is_vector(): and should be point\n"; return false; }

    return true;
}

bool subtracting_two_vectors() {
    Vector4 p = make_vector(3.0f, 2.0f, 1.0f);
    Vector4 v = make_vector(5.0f, 6.0f, 7.0f);
    Vector4 expected_result = make_vector(-2.0f, -4.0f, -6.0f);

    Vector4 c = p - v;

    if (c.x != expected_result.x) { std::cout << "c.x != -2.0: " << c.x << "\n"; return false; }
    if (c.y != expected_result.y) { std::cout << "c.y != -4.0: " << c.y << "\n"; return false; }
    if (c.z != expected_result.z) { std::cout << "c.z != -6.0: " << c.z << "\n"; return false; }
    if (!c.is_vector()) { std::cout << "c.is_point(): and should be vector\n"; return false; }

    return true;
}

bool subtracting_a_vector_from_the_zero_vector() {
    Vector4 zero = make_vector(0.0f, 0.0f, 0.0f);
    Vector4 v = make_vector(1.0f, -2.0f, 3.0f);
    Vector4 expected_result = make_vector(-1.0f, 2.0f, -3.0f);

    Vector4 c = zero - v;

    if (c.x != expected_result.x) { std::cout << c.x << " != " << expected_result.x << "\n"; return false; }
    if (c.y != expected_result.y) { std::cout << c.y << " != " << expected_result.y << "\n"; return false; }
    if (c.z != expected_result.z) { std::cout << c.z << " != " << expected_result.z << "\n"; return false; }
    if (!c.is_vector()) { std::cout << "result is point and should be vector\n"; return false; }

    return true;
}

bool negating_a_vector() {
    Vector4 v = make_vector(1.0f, -2.0f, 3.0f);
    Vector4 expected_result = make_vector(-1.0f, 2.0f, -3.0f);

    Vector4 c = -v;

    if (c.x != expected_result.x) { std::cout << c.x << " != " << expected_result.x << "\n"; return false; }
    if (c.y != expected_result.y) { std::cout << c.y << " != " << expected_result.y << "\n"; return false; }
    if (c.z != expected_result.z) { std::cout << c.z << " != " << expected_result.z << "\n"; return false; }
    if (!c.is_vector()) { std::cout << "result is point and should be vector\n"; return false; }

    return true;
}

bool multiplying_a_vector_by_a_scalar() {
    Vector4 v(1.0f, -2.0f, 3.0f, -4.0f);
    Vector4 expected_result(3.5f, -7.0f, 10.5f, -14.0f);

    Vector4 actual_result = 3.5f * v;

    if (actual_result.x != expected_result.x) { std::cout << actual_result.x << " != " << expected_result.x << "\n"; return false; }
    if (actual_result.y != expected_result.y) { std::cout << actual_result.y << " != " << expected_result.y << "\n"; return false; }
    if (actual_result.z != expected_result.z) { std::cout << actual_result.z << " != " << expected_result.z << "\n"; return false; }
    if (actual_result.w != expected_result.w) { std::cout << actual_result.w << " != " << expected_result.w << "\n"; return false; }

    return true;
}

bool multiplying_a_vector_by_a_fraction() {
    Vector4 v(1.0f, -2.0f, 3.0f, -4.0f);
    Vector4 expected_result(0.5f, -1.0f, 1.5f, -2.0f);

    Vector4 actual_result = 0.5f * v;

    if (actual_result.x != expected_result.x) { std::cout << actual_result.x << " != " << expected_result.x << "\n"; return false; }
    if (actual_result.y != expected_result.y) { std::cout << actual_result.y << " != " << expected_result.y << "\n"; return false; }
    if (actual_result.z != expected_result.z) { std::cout << actual_result.z << " != " << expected_result.z << "\n"; return false; }
    if (actual_result.w != expected_result.w) { std::cout << actual_result.w << " != " << expected_result.w << "\n"; return false; }

    return true;
}

bool dividing_a_vector_by_a_fraction() {
    Vector4 v(1.0f, -2.0f, 3.0f, -4.0f);
    Vector4 expected_result(0.5f, -1.0f, 1.5f, -2.0f);

    Vector4 actual_result = v / 2.0f;

    if (actual_result.x != expected_result.x) { std::cout << actual_result.x << " != " << expected_result.x << "\n"; return false; }
    if (actual_result.y != expected_result.y) { std::cout << actual_result.y << " != " << expected_result.y << "\n"; return false; }
    if (actual_result.z != expected_result.z) { std::cout << actual_result.z << " != " << expected_result.z << "\n"; return false; }
    if (actual_result.w != expected_result.w) { std::cout << actual_result.w << " != " << expected_result.w << "\n"; return false; }

    return true;
}

bool computing_the_magnitude_of_vector() {
    Vector4 v1 = make_vector(1.0f, 0.0f, 0.0f);
    Vector4 v2 = make_vector(0.0f, 1.0f, 0.0f);
    Vector4 v3 = make_vector(0.0f, 0.0f, 1.0f);
    Vector4 v4 = make_vector(1.0f, 2.0f, 3.0f);
    Vector4 v5 = make_vector(-1.0f, -2.0f, -3.0f);
    
    if (1.0f != vectorMag(v1)) { std::cout << "Magnitude != 1\n"; return false; }
    if (1.0f != vectorMag(v2)) { std::cout << "Magnitude != 1\n"; return false; }
    if (1.0f != vectorMag(v3)) { std::cout << "Magnitude != 1\n"; return false; }
    if (sqrt(14.0f) != vectorMag(v4)) { std::cout << "Magnitude != sqrt(14)\n"; return false; }
    if (sqrt(14.0f) != vectorMag(v5)) { std::cout << "Magnitude != sqrt(14)\n"; return false; }

    return true;
}

bool normalizing_vector() {
    const float EPSILON = 0.0001f;
    
    Vector4 v1 = make_vector(4.0f, 0.0f, 0.0f);
    Vector4 expected1 = make_vector(1.0f, 0.0f, 0.0f);
    
    v1.normalize();
    if (v1 != expected1) { std::cout << "Normalization of v1 failed\n"; return false; }
    
    Vector4 v2 = make_vector(1.0f, 2.0f, 3.0f);
    Vector4 expected2 = make_vector(0.26726f, 0.53452f, 0.80178f);

    v2.normalize();
    if (abs(expected2.x - v2.x) > EPSILON) return false;
    if (abs(expected2.y - v2.y) > EPSILON) return false;
    if (abs(expected2.z - v2.z) > EPSILON) return false;
    float magnitude = vectorMag(v2);
    if (abs(1.0f - magnitude) > EPSILON) { std::cout << "Magnitude of normalized vector != 1\n"; return false; }

    return true;
}

bool dot_product() {
    Vector4 a = make_vector(1.0f, 2.0f, 3.0f);
    Vector4 b = make_vector(2.0f, 3.0f, 4.0f);

    if ((a * b) != 20.0f) return false;

    return true;
}

bool cross_product() {
    Vector4 a = make_vector(1.0f, 2.0f, 3.0f);
    Vector4 b = make_vector(2.0f, 3.0f, 4.0f);

    Vector4 expected_result1 = make_vector(-1.0f, 2.0f, -1.0);
    Vector4 expected_result2 = make_vector(1.0f, -2.0f, 1.0);
    
    if (crossProduct(a, b) != expected_result1) return false;
    if (crossProduct(b, a) != expected_result2) return false;

    return true;
}
