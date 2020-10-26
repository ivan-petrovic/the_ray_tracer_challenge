//
// Created by ivan on 26.10.2020..
//

#include "TestObject.h"
#include "Matrix4x4.h"

bool the_default_transformation();
bool assigning_a_transformation();

int main() {
    if (the_default_transformation() && assigning_a_transformation()) return 0;
    return 1;
}

bool the_default_transformation() {
    mn::TestObject object;

    return object.transform() == mn::identity();
}

bool assigning_a_transformation() {
    mn::TestObject object;
    mn::Matrix4x4 T = mn::translation(2.0, 3.0, 4.0);
    object.transform(T);

    return object.transform() == T;
}
