//
// Created by ivan on 5.12.2020..
//

#include "model/Cylinder.h"

bool the_default_min_and_max_for_a_cylinder();

bool the_default_closed_value_for_a_cylinder();

int main() {
    if (!the_default_min_and_max_for_a_cylinder()) return 1;
    if (!the_default_closed_value_for_a_cylinder()) return 1;

    return 0;
}

bool the_default_min_and_max_for_a_cylinder() {
    mn::Cylinder cylinder;
    return cylinder.minimum() == -mn::kInfinity && cylinder.maximum() == mn::kInfinity;
}

bool the_default_closed_value_for_a_cylinder() {
    mn::Cylinder cylinder;
    return !cylinder.closed();
}
