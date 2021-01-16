//
// Created by ivan on 16.1.2020..
//

#include "model/Cone.h"

bool the_normal_vector_on_a_cone(mn::Point point, mn::Vector normal);

bool the_normal_vector_on_end_caps_of_a_cone(mn::Point point, mn::Vector normal);

int main() {
    if (!the_normal_vector_on_a_cone(
            mn::make_point(0.0, 0.0, 0.0),
            mn::make_vector(0.0, 0.0, 0.0))
            )
        return 1;
    if (!the_normal_vector_on_a_cone(
            mn::make_point(1.0, 1.0, 1.0),
            mn::make_vector(1.0, -std::sqrt(2.0), 1.0))
            )
        return 1;
    if (!the_normal_vector_on_a_cone(
            mn::make_point(-1.0, -1.0, 0.0),
            mn::make_vector(-1.0, 1.0, 0.0))
            )
        return 1;

    if (!the_normal_vector_on_end_caps_of_a_cone(
            mn::make_point(0.0, -1.0, 0.5),
            mn::make_vector(0.0, -1.0, 0.0))
            )
        return 1;
    if (!the_normal_vector_on_end_caps_of_a_cone(
            mn::make_point(0.0, 2.0, 0.5),
            mn::make_vector(0.0, 1.0, 0.0))
            )
        return 1;

    return 0;
}

bool the_normal_vector_on_a_cone(mn::Point point, mn::Vector normal) {
    mn::Cone cone;

    mn::Vector n = cone.local_normal_at(point);

    return n == normal;
}

bool the_normal_vector_on_end_caps_of_a_cone(mn::Point point, mn::Vector normal) {
    mn::Cone cone;
    cone.minimum(-1.0);
    cone.maximum(2.0);
    cone.closed(true);

    mn::Vector n = cone.local_normal_at(point);

    return n == normal;
}
