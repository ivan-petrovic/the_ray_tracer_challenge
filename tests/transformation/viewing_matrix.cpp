//
// Created by ivan on 22.10.2020..
//

#include "math_util.h"
#include "Tuple.h"
#include "Matrix4x4.h"

bool test_default_orientation();

bool test_looking_in_positive_z_direction();

bool test_view_transformation_moves_the_world();

bool test_arbitrary_view_transformation();

int main() {
    if (
            test_default_orientation() &&
            test_looking_in_positive_z_direction() &&
            test_view_transformation_moves_the_world() &&
            test_arbitrary_view_transformation()
            )
        return 0;

    return 1;
}

bool test_default_orientation() {
    return mn::view_transform(
            mn::make_point(0.0, 0.0, 0.0),
            mn::make_point(0.0, 0.0, -1.0),
            mn::make_vector(0.0, 1.0, 0.0)
    ) == mn::identity();
}

bool test_looking_in_positive_z_direction() {
    return mn::view_transform(
            mn::make_point(0.0, 0.0, 0.0),
            mn::make_point(0.0, 0.0, 1.0),
            mn::make_vector(0.0, 1.0, 0.0)
    ) == mn::scaling(-1.0, 1.0, -1.0);
}

bool test_view_transformation_moves_the_world() {
    return mn::view_transform(
            mn::make_point(0.0, 0.0, 8.0),
            mn::make_point(0.0, 0.0, 0.0),
            mn::make_vector(0.0, 1.0, 0.0)
    ) == mn::translation(0.0, 0.0, -8.0);
}

bool test_arbitrary_view_transformation() {
    mn::Matrix4x4 M{
            -0.50709, 0.50709, 0.67612, -2.36643,
            0.76772, 0.60609, 0.12122, -2.82843,
            -0.35857, 0.59761, -0.71714, 0.0,
            0.0, 0.0, 0.0, 1.0
    };

    mn::Matrix4x4 T = mn::view_transform(
            mn::make_point(1.0, 3.0, 2.0),
            mn::make_point(4.0, -2.0, 8.0),
            mn::make_vector(1.0, 1.0, 0.0)
    );

    return mn::epsilon_equal(T, M, 0.00001);
}
