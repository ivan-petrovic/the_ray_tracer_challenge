//
// Created by ivan on 28.10.2020..
//
#include "Tuple.h"
#include "Material.h"
#include "model/Sphere.h"
#include "render.h"

bool stripes_with_an_object_transformation();

bool stripes_with_an_pattern_transformation();

bool stripes_with_both_an_object_and_a_pattern_transformation();

int main() {
    if (
            stripes_with_an_object_transformation() &&
            stripes_with_an_pattern_transformation() &&
            stripes_with_both_an_object_and_a_pattern_transformation()
            )
        return 0;
    return 1;
}

bool stripes_with_an_object_transformation() {
    mn::Sphere object;
    object.transform(mn::scaling(2.0, 2.0, 2.0));

    mn::Color black = mn::make_color(0.0, 0.0, 0.0);
    mn::Color white = mn::make_color(1.0, 1.0, 1.0);
    mn::StripedPattern pattern(white, black);

    return mn::stripe_at_object(pattern, object, mn::make_point(1.5, 0.0, 0.0)) == white;
}

bool stripes_with_an_pattern_transformation() {
    mn::Sphere object;

    mn::Color black = mn::make_color(0.0, 0.0, 0.0);
    mn::Color white = mn::make_color(1.0, 1.0, 1.0);
    mn::StripedPattern pattern(white, black);
    pattern.transform(mn::scaling(2.0, 2.0, 2.0));

    return mn::stripe_at_object(pattern, object, mn::make_point(1.5, 0.0, 0.0)) == white;
}

bool stripes_with_both_an_object_and_a_pattern_transformation() {
    mn::Sphere object;
    object.transform(mn::scaling(2.0, 2.0, 2.0));

    mn::Color black = mn::make_color(0.0, 0.0, 0.0);
    mn::Color white = mn::make_color(1.0, 1.0, 1.0);
    mn::StripedPattern pattern(white, black);
    pattern.transform(mn::translation(0.5, 0.0, 0.0));

    return mn::stripe_at_object(pattern, object, mn::make_point(2.5, 0.0, 0.0)) == white;
}
