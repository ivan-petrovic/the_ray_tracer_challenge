//
// Created by ivan on 28.10.2020..
//
#include "Tuple.h"
#include "Material.h"
#include "model/Sphere.h"
#include "../pattern/TestPattern.h"
#include "render.h"

bool a_pattern_with_an_object_transformation();

bool a_pattern_with_an_pattern_transformation();

bool a_pattern_with_both_an_object_and_a_pattern_transformation();

int main() {
    if (
            a_pattern_with_an_object_transformation() &&
            a_pattern_with_an_pattern_transformation() &&
            a_pattern_with_both_an_object_and_a_pattern_transformation()
            )
        return 0;
    return 1;
}

bool a_pattern_with_an_object_transformation() {
    mn::Sphere object;
    object.transform(mn::scaling(2.0, 2.0, 2.0));

    mn::TestPattern pattern;

    mn::Color expected = mn::make_color(1.0, 1.5, 2.0);
    return mn::pattern_at_object(pattern, object, mn::make_point(2.0, 3.0, 4.0)) == expected;
}

bool a_pattern_with_an_pattern_transformation() {
    mn::Sphere object;

    mn::TestPattern pattern;
    pattern.transform(mn::scaling(2.0, 2.0, 2.0));

    mn::Color expected = mn::make_color(1.0, 1.5, 2.0);
    return mn::pattern_at_object(pattern, object, mn::make_point(2.0, 3.0, 4.0)) == expected;
}

bool a_pattern_with_both_an_object_and_a_pattern_transformation() {
    mn::Sphere object;
    object.transform(mn::scaling(2.0, 2.0, 2.0));

    mn::TestPattern pattern;
    pattern.transform(mn::translation(0.5, 1.0, 1.5));

    mn::Color expected = mn::make_color(0.75, 0.5, 0.25);
    return mn::pattern_at_object(pattern, object, mn::make_point(2.5, 3.0, 3.5)) == expected;
}
