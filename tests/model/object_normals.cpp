//
// Created by ivan on 18.10.2020..
//
#include "TestObject.h"

bool computing_the_normal_on_a_translated_object();

bool computing_the_normal_on_a_transformed_object();

int main() {
    if (
            computing_the_normal_on_a_translated_object() &&
                    computing_the_normal_on_a_transformed_object())
        return 0;
    return 1;
}

bool computing_the_normal_on_a_translated_object() {
    mn::TestObject object;
    object.transform(mn::translation(0.0, 1.0, 0.0));

    const double half_sqrt_of_2 = std::sqrt(2.0) / 2;
    mn::Vector n = object.normal_at(mn::make_point(0.0, 1.0 + half_sqrt_of_2, -half_sqrt_of_2));

    return mn::epsilon_equal(n, mn::make_vector(0.0, half_sqrt_of_2, -half_sqrt_of_2));
}

bool computing_the_normal_on_a_transformed_object() {
    mn::TestObject object;
    object.transform(mn::scaling(1.0, 0.5, 1.0) * mn::rotation_z(mn::kPi/5));

    const double half_sqrt_of_2 = std::sqrt(2.0) / 2;
    mn::Vector n = object.normal_at(mn::make_point(0.0, half_sqrt_of_2, -half_sqrt_of_2));

    return mn::epsilon_equal(n, mn::make_vector(0.0, 0.97014, -0.24254), 0.00001);
}
