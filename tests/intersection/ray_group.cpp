//
// Created by ivan on 31.01.2021..
//
#include "Ray.h"
#include "model/Group.h"
#include "model/Sphere.h"

bool intersecting_a_ray_with_an_empty_group();

bool intersecting_a_ray_with_an_non_empty_group();

bool intersecting_a_transformed_group();

int main() {
    if (
            intersecting_a_ray_with_an_empty_group() &&
            intersecting_a_ray_with_an_non_empty_group() &&
            intersecting_a_transformed_group()
            )
        return 0;
    return 1;
}

bool intersecting_a_ray_with_an_empty_group() {
    mn::Group group;
    mn::Ray ray(
            mn::make_point(0.0, 0.0, 0.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );

    mn::Intersections result;
    group.local_intersect(ray, result);

    return result.count() == 0;
}

bool intersecting_a_ray_with_an_non_empty_group() {
    mn::Group group;

    mn::Sphere sphere1;
    mn::Sphere sphere2;
    sphere2.transform(mn::translation(0.0, 0.0, -3.0));
    mn::Sphere sphere3;
    sphere3.transform(mn::translation(5.0, 0.0, 0.0));

    group.add_child(&sphere1);
    group.add_child(&sphere2);
    group.add_child(&sphere3);

    mn::Ray ray(
            mn::make_point(0.0, 0.0, -5.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );

    mn::Intersections result;
    group.local_intersect(ray, result);

    if (result.count() != 4) return false;
    if (result[0].object != &sphere2) return false;
    if (result[1].object != &sphere2) return false;
    if (result[2].object != &sphere1) return false;
    if (result[3].object != &sphere1) return false;
    return true;
}

bool intersecting_a_transformed_group() {
    mn::Group group;
    group.transform(mn::scaling(2.0, 2.0, 2.0));

    mn::Sphere sphere;
    sphere.transform(mn::translation(5.0, 0.0, 0.0));

    group.add_child(&sphere);

    mn::Ray ray(
            mn::make_point(10.0, 0.0, -10.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );

    mn::Intersections result;
    group.local_intersect(ray, result);

    if (result.count() != 2) return false;
    return true;
}
