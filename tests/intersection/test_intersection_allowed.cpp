//
// Created by ivan on 3.3.2021..
//
#include "model/CSG.h"
#include "intersection/intersect.h"

bool evaluating_the_rule_for_a_csg_operation(
        int op, bool left_hit, bool in_left, bool in_right, bool result
);

bool evaluating_the_rule_for_a_union_operation();

bool evaluating_the_rule_for_a_intersection_operation();

bool evaluating_the_rule_for_a_difference_operation();

int main() {
    if (
            evaluating_the_rule_for_a_union_operation() &&
            evaluating_the_rule_for_a_intersection_operation() &&
            evaluating_the_rule_for_a_difference_operation()
            )
        return 0;
    return 1;
}


bool evaluating_the_rule_for_a_union_operation() {
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::UNION, true, true, true, false)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::UNION, true, true, false, true)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::UNION, true, false, true, false)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::UNION, true, false, false, true)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::UNION, false, true, true, false)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::UNION, false, true, false, false)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::UNION, false, false, true, true)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::UNION, false, false, false, true)) return false;
    return true;
}

bool evaluating_the_rule_for_a_intersection_operation() {
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::INTERSECTION, true, true, true, true)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::INTERSECTION, true, true, false, false)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::INTERSECTION, true, false, true, true)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::INTERSECTION, true, false, false, false)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::INTERSECTION, false, true, true, true)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::INTERSECTION, false, true, true, true)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::INTERSECTION, false, false, true, false)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::INTERSECTION, false, false, true, false)) return false;
    return true;
}

bool evaluating_the_rule_for_a_difference_operation() {
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::DIFFERENCE, true, true, true, false)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::DIFFERENCE, true, true, false, true)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::DIFFERENCE, true, false, true, false)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::DIFFERENCE, true, false, false, true)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::DIFFERENCE, false, true, true, true)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::DIFFERENCE, false, true, true, true)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::DIFFERENCE, false, false, true, false)) return false;
    if (!evaluating_the_rule_for_a_csg_operation(mn::CSG::DIFFERENCE, false, false, true, false)) return false;
    return true;
}

bool evaluating_the_rule_for_a_csg_operation(
        int op, bool left_hit, bool in_left, bool in_right, bool result
) {
    bool r = mn::intersection_allowed(op, left_hit, in_left, in_right);
    return r == result;
}

