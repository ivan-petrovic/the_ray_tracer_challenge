//
// Created by ivan on 28.10.2020..
//

#include "TestPattern.h"
#include "Matrix4x4.h"

bool the_default_transformation();
bool assigning_a_transformation();

int main() {
    if (the_default_transformation() && assigning_a_transformation()) return 0;
    return 1;
}

bool the_default_transformation() {
    mn::TestPattern pattern;

    return pattern.transform() == mn::identity();
}

bool assigning_a_transformation() {
    mn::TestPattern pattern;
    mn::Matrix4x4 T = mn::translation(2.0, 3.0, 4.0);
    pattern.transform(T);

    return pattern.transform() == T;
}
