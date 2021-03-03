//
// Created by ivan on 21.2.2021..
//

#include "Ray.h"
#include "model/CSG.h"
#include "model/Sphere.h"
#include "model/Cube.h"

bool a_ray_misses_csg_object();

bool a_ray_hits_csg_object();

bool a_ray_misses_the_p2_p3_edge();

bool a_ray_strikes_a_triangle();

int main() {
    if (
            a_ray_misses_csg_object() &&
            a_ray_hits_csg_object()
            )
        return 0;
    return 1;
}

bool a_ray_misses_csg_object() {
    mn::Sphere sphere;
    mn::Cube cube;
    mn::CSG csg(mn::CSG::UNION, &sphere, &cube);

    mn::Ray ray(
            mn::make_point(0.0, 2.0, -5.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );

    mn::Intersections result;
    csg.local_intersect(ray, result);

    return result.count() == 0;
}

bool a_ray_hits_csg_object() {
    mn::Sphere sphere1;
    mn::Sphere sphere2;
    sphere2.transform(mn::translation(0.0, 0.0, 0.5));

    mn::CSG csg(mn::CSG::UNION, &sphere1, &sphere2);

    mn::Ray ray(
            mn::make_point(0.0, 0.0, -5.0),
            mn::make_vector(0.0, 0.0, 1.0)
    );

    mn::Intersections result;
    csg.local_intersect(ray, result);

    if (result.count() != 2) return false;
    if (result[0].t != 4) return false;
    if (result[0].object != &sphere1) return false;
    if (result[1].t != 6.5) return false;
    if (result[1].object != &sphere2) return false;
    return true;
}
