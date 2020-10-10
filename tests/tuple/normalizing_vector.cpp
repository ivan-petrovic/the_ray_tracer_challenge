//
// Created by ivan on 8.10.2020..
//

#include "Tuple.h"
#include "rtc.h"

bool magnitude_example_case_1();

bool magnitude_example_case_2();

bool magnitude_example_case_3();

int main() {
    if (
            magnitude_example_case_1() &&
            magnitude_example_case_2() &&
            magnitude_example_case_3()) {
        return 0;
    }
    return 1;
}

bool magnitude_example_case_1() {
    mn::Tuple v = mn::vector(4.0f, 0.0f, 0.0f);
    mn::Tuple expected = mn::vector(1.0f, 0.0f, 0.0f);

    v.normalize();
    if (v == expected) return true;
    return false;
}

bool magnitude_example_case_2() {
    mn::Tuple v = mn::vector(1.0f, 2.0f, 3.0f);
    double t = std::sqrt(14.0);
    mn::Tuple expected = mn::vector(1.0 / t, 2.0 / t, 3.0 / t);

    if (mn::normalize(v) == expected) return true;
    return false;
}

// The magnitude of a normalized vector
bool magnitude_example_case_3() {
    mn::Tuple v = mn::vector(1.0, 2.0, 3.0);
    mn::Tuple norm = mn::normalize(v);

    if (mn::magnitude(norm) == 1.0) return true;
    return false;
}
