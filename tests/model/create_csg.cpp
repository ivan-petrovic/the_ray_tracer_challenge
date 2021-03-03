//
// Created by ivan on 3.3.2021..
//

#include "model/CSG.h"
#include "model/Cube.h"
#include "model/Sphere.h"

bool create_csg();

bool filtering_a_list_of_intersections(int op, int l, int r);

int main() {
    if (
            create_csg() &&
            filtering_a_list_of_intersections(mn::CSG::UNION, 0, 3) &&
            filtering_a_list_of_intersections(mn::CSG::INTERSECTION, 1, 2) &&
            filtering_a_list_of_intersections(mn::CSG::DIFFERENCE, 0, 1)
            )
        return 0;
    return 1;
}

bool create_csg() {
    mn::Sphere sphere;
    mn::Cube cube;
    mn::CSG csg(mn::CSG::UNION, &sphere, &cube);

    if (csg.operation() != mn::CSG::UNION) return false;
    if (csg.left() != &sphere) return false;
    if (csg.right() != &cube) return false;
    if (sphere.parent() != &csg) return false;
    if (cube.parent() != &csg) return false;

    return true;
}

bool filtering_a_list_of_intersections(int op, int l, int r) {
    mn::Sphere sphere;
    mn::Cube cube;
    mn::CSG csg(op, &sphere, &cube);

    mn::Intersections xs;
    xs.add(1.0, &sphere);
    xs.add(2.0, &cube);
    xs.add(3.0, &sphere);
    xs.add(4.0, &cube);

    mn::Intersections fxs;
    csg.filter_intersections(xs, fxs);
    if (fxs.count() != 2) return false;
    if (fxs[0].t != xs[l].t) return false;
    if (fxs[0].object != xs[l].object) return false;
    if (fxs[1].t != xs[r].t) return false;
    if (fxs[1].object != xs[r].object) return false;

    return true;
}
