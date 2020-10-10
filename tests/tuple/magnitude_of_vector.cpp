//
// Created by ivan on 8.10.2020..
//
#include "Tuple.h"
#include "rtc.h"

bool magnitude_example_case_1();

bool magnitude_example_case_2();

bool magnitude_example_case_3();

bool magnitude_example_case_4();

bool magnitude_example_case_5();

int main() {
    if (
            magnitude_example_case_1() &&
            magnitude_example_case_2() &&
            magnitude_example_case_3() &&
            magnitude_example_case_4() &&
            magnitude_example_case_5()) {
        return 0;
    }
    return 1;
}

bool magnitude_example_case_1() {
    mn::Tuple v = mn::vector(1.0, 0.0, 0.0);
    double expected = 1.0;

    if (mn::magnitude(v) == expected) return true;
    return false;
}

bool magnitude_example_case_2() {
    mn::Tuple v = mn::vector(0.0, 1.0, 0.0);
    double expected = 1.0;

    if (mn::magnitude(v) == expected) return true;
    return false;
}

bool magnitude_example_case_3() {
    mn::Tuple v = mn::vector(0.0, 0.0, 1.0);
    double expected = 1.0;

    if (mn::magnitude(v) == expected) return true;
    return false;
}

bool magnitude_example_case_4() {
    mn::Tuple v = mn::vector(1.0f, 2.0f, 3.0f);
    double expected = std::sqrt(14.0);

    if (mn::magnitude(v) == expected) return true;
    return false;
}

bool magnitude_example_case_5() {
    mn::Tuple v = mn::vector(-1.0f, -2.0f, -3.0f);
    double expected = std::sqrt(14.0);

    if (v.magnitude() == expected) return true;
    return false;
}
