//
// Created by ivan on 31.1.2021..
//

#include "model/Group.h"
#include "TestObject.h"

bool create_group();

bool adding_a_child_to_a_group();

bool converting_a_point_from_world_to_object_space();

bool converting_a_normal_from_object_to_world_space();

bool finding_a_normal_on_a_child_object();

int main() {
    if (create_group() &&
        adding_a_child_to_a_group() &&
        converting_a_point_from_world_to_object_space() &&
        converting_a_normal_from_object_to_world_space() &&
        finding_a_normal_on_a_child_object())
        return 0;
    return 1;
}

bool create_group() {
    mn::Group group;

    if (group.transform() != mn::identity()) return false;
    if (!group.empty()) return false;

    return true;
}

bool adding_a_child_to_a_group() {
    mn::Group group;
    mn::TestObject test_object;

    group.add_child(&test_object);

    if (group.empty()) return false;
    if (!test_object.has_parent()) return false;
    if (test_object.parent() != &group) return false;
    if (group.objects()[0] != &test_object) return false;

    return true;
}

bool converting_a_point_from_world_to_object_space() {
    mn::Group group1;
    group1.transform(mn::rotation_y(mn::kPiOver2));
    mn::Group group2;
    group2.transform(mn::scaling(2.0, 2.0, 2.0));
    group1.add_child(&group2);

    mn::Sphere sphere;
    sphere.transform(mn::translation(5.0, 0.0, 0.0));
    group2.add_child(&sphere);

    mn::Point p = sphere.world_to_object(mn::make_point(-2.0, 0.0, -10.0));

    return mn::epsilon_equal(p, mn::make_point(0.0, 0.0, -1.0));
}

bool converting_a_normal_from_object_to_world_space() {
    mn::Group group1;
    group1.transform(mn::rotation_y(mn::kPiOver2));
    mn::Group group2;
    group2.transform(mn::scaling(1.0, 2.0, 3.0));
    group1.add_child(&group2);

    mn::Sphere sphere;
    sphere.transform(mn::translation(5.0, 0.0, 0.0));
    group2.add_child(&sphere);

    double sqrt_of_3_over_3 = std::sqrt(3) / 3;
    mn::Vector n = sphere.normal_to_world(mn::make_vector(sqrt_of_3_over_3, sqrt_of_3_over_3, sqrt_of_3_over_3));

    return mn::epsilon_equal(n, mn::make_vector(0.2857, 0.4286, -0.8571), 0.0001);
}

bool finding_a_normal_on_a_child_object() {
    mn::Group group1;
    group1.transform(mn::rotation_y(mn::kPiOver2));
    mn::Group group2;
    group2.transform(mn::scaling(1.0, 2.0, 3.0));
    group1.add_child(&group2);

    mn::Sphere sphere;
    sphere.transform(mn::translation(5.0, 0.0, 0.0));
    group2.add_child(&sphere);

    mn::Vector n = sphere.normal_at(mn::make_point(1.7321, 1.1547, -5.5774));

    return mn::epsilon_equal(n, mn::make_vector(0.2857, 0.4286, -0.8571), 0.0001);
}
