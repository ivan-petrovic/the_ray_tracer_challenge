//
// Created by ivan on 28.2.2021..
//
#include "obj_parser/OBJ_Parser.h"
#include <iostream>

bool ignoring_unrecognized_lines();

bool vertex_records();

bool vertex_normal_records();

bool parsing_triangle_faces();

bool triangulating_polygons();

bool faces_with_normals();

bool triangles_in_groups();

bool reading_from_file();

bool converting_an_obj_file_to_a_group();

int main() {
    if (
            ignoring_unrecognized_lines() &&
            vertex_records() &&
            vertex_normal_records() &&
            parsing_triangle_faces() &&
            triangulating_polygons() &&
            faces_with_normals() &&
            triangles_in_groups() &&
            reading_from_file() &&
            converting_an_obj_file_to_a_group()
            )
        return 0;
    return 1;
}

bool ignoring_unrecognized_lines() {
    // arrange
    std::vector<std::string> lines{
            "There was a young lady named Bright",
            "who traveled much faster than light.",
            "She set out one day",
            "in a relative way,",
            "and came back the previous night.",
    };
    mn::OBJ_Parser parser;

    // act
    parser.parse_lines(lines);

    // assert
    return lines.size() == parser.ignored_lines_count();
}

bool vertex_records() {
    // arrange
    std::vector<std::string> lines{
            "v -1 1 0",
            "v -1.0000 0.5000 0.0000",
            "v 1 0 0",
            "v 1 1 0",
    };
    mn::OBJ_Parser parser;

    // act
    parser.parse_lines(lines);

    // assert
    return (parser.vertices()[1] == mn::make_point(-1.0, 1.0, 0.0) &&
            parser.vertices()[2] == mn::make_point(-1.0, 0.5, 0.0) &&
            parser.vertices()[3] == mn::make_point(1.0, 0.0, 0.0) &&
            parser.vertices()[4] == mn::make_point(1.0, 1.0, 0.0) &&
            parser.ignored_lines_count() == 0
    );
}

bool vertex_normal_records() {
    // arrange
    std::vector<std::string> lines{
            "vn 0 0 1",
            "vn 0.707 0 -0.707",
            "vn 1 2 3"
    };
    mn::OBJ_Parser parser;

    // act
    parser.parse_lines(lines);

    // assert
    return (parser.normals()[1] == mn::make_vector(0.0, 0.0, 1.0) &&
            parser.normals()[2] == mn::make_vector(0.707, 0.0, -0.707) &&
            parser.normals()[3] == mn::make_vector(1.0, 2.0, 3.0) &&
            parser.ignored_lines_count() == 0
    );
}

bool parsing_triangle_faces() {
    // arrange
    std::vector<std::string> lines{
            "v -1 1 0",
            "v -1 0 0",
            "v 1 0 0",
            "v 1 1 0",
            "f 1 2 3",
            "f 1 3 4",
    };
    mn::OBJ_Parser parser;

    // act
    parser.parse_lines(lines);

    // assert
    bool triangle_data = parser.triangles()[0].p1() == parser.vertices()[1] &&
                         parser.triangles()[0].p2() == parser.vertices()[2] &&
                         parser.triangles()[0].p3() == parser.vertices()[3] &&
                         parser.triangles()[1].p1() == parser.vertices()[1] &&
                         parser.triangles()[1].p2() == parser.vertices()[3] &&
                         parser.triangles()[1].p3() == parser.vertices()[4];

    const mn::Group &group = parser.default_group();
    bool group_data = group.objects()[0] == &parser.triangles()[0] &&
                      group.objects()[1] == &parser.triangles()[1];

    return triangle_data; // && group_data;
}

bool triangulating_polygons() {
    // arrange
    std::vector<std::string> lines{
            "v -1 1 0",
            "v -1 0 0",
            "v 1 0 0",
            "v 1 1 0",
            "f 1 2 3 4 5"
    };
    mn::OBJ_Parser parser;

    // act
    parser.parse_lines(lines);

    // assert
    bool triangle_data = parser.triangles()[0].p1() == parser.vertices()[1] &&
                         parser.triangles()[0].p2() == parser.vertices()[2] &&
                         parser.triangles()[0].p3() == parser.vertices()[3] &&
                         parser.triangles()[1].p1() == parser.vertices()[1] &&
                         parser.triangles()[1].p2() == parser.vertices()[3] &&
                         parser.triangles()[1].p3() == parser.vertices()[4] &&
                         parser.triangles()[2].p1() == parser.vertices()[1] &&
                         parser.triangles()[2].p2() == parser.vertices()[4] &&
                         parser.triangles()[2].p3() == parser.vertices()[5];

    const mn::Group &group = parser.default_group();
    bool group_data = group.objects()[0] == &parser.triangles()[0] &&
                      group.objects()[1] == &parser.triangles()[1] &&
                      group.objects()[2] == &parser.triangles()[2];

    return triangle_data && group_data;
}

bool faces_with_normals() {
    // arrange
    std::vector<std::string> lines{
            "v 0 1 0",
            "v -1 0 0",
            "v 1 0 0",
            "vn -1 0 0",
            "vn 1 0 0",
            "vn 0 1 0",
            "f 1//3 2//1 3//2",
            "f 1/0/3 2/102/1 3/14/2"
    };
    mn::OBJ_Parser parser;

    // act
    parser.parse_lines(lines);

//    std::cout << "parser: " << parser.smooth_triangles()[0].normal1().x << '\n';
//    std::cout << "parser: " << parser.smooth_triangles()[0].normal1().y << '\n';
//    std::cout << "parser: " << parser.smooth_triangles()[0].normal1().z << '\n';
//    std::cout << "vertices: " << parser.vertices()[1].x << '\n';
//    std::cout << "vertices: " << parser.vertices()[1].y << '\n';
//    std::cout << "vertices: " << parser.vertices()[1].z << '\n';

    // assert
    bool triangle_data = parser.smooth_triangles()[0].p1() == parser.vertices()[1] &&
                         parser.smooth_triangles()[0].p2() == parser.vertices()[2] &&
                         parser.smooth_triangles()[0].p3() == parser.vertices()[3] &&
                         parser.smooth_triangles()[0].normal1() == parser.normals()[3] &&
                         parser.smooth_triangles()[0].normal2() == parser.normals()[1] &&
                         parser.smooth_triangles()[0].normal3() == parser.normals()[2] &&
                         parser.smooth_triangles()[1].p1() == parser.vertices()[1] &&
                         parser.smooth_triangles()[1].p2() == parser.vertices()[2] &&
                         parser.smooth_triangles()[1].p3() == parser.vertices()[3] &&
                         parser.smooth_triangles()[1].normal1() == parser.normals()[3] &&
                         parser.smooth_triangles()[1].normal2() == parser.normals()[1] &&
                         parser.smooth_triangles()[1].normal3() == parser.normals()[2];

    const mn::Group &group = parser.default_group();
    bool group_data = group.objects()[0] == &parser.smooth_triangles()[0] &&
                      group.objects()[1] == &parser.smooth_triangles()[1];
    return triangle_data && group_data;
}

bool triangles_in_groups() {
    // arrange
    std::vector<std::string> lines{
            "v -1 1 0",
            "v -1 0 0",
            "v 1 0 0",
            "v 1 1 0",
            "g FirstGroup",
            "f 1 2 3",
            "g SecondGroup",
            "f 1 3 4"
    };
    mn::OBJ_Parser parser;

    // act
    parser.parse_lines(lines);

    // assert
    bool triangle_data = parser.triangles()[0].p1() == parser.vertices()[1] &&
                         parser.triangles()[0].p2() == parser.vertices()[2] &&
                         parser.triangles()[0].p3() == parser.vertices()[3] &&
                         parser.triangles()[1].p1() == parser.vertices()[1] &&
                         parser.triangles()[1].p2() == parser.vertices()[3] &&
                         parser.triangles()[1].p3() == parser.vertices()[4];

    const mn::Group &group1 = parser.group("FirstGroup");
    const mn::Group &group2 = parser.group("SecondGroup");
    bool group_data = group1.objects()[0] == &parser.triangles()[0] &&
                      group2.objects()[0] == &parser.triangles()[1];

    return triangle_data && group_data;
}

bool reading_from_file() {
    // arrange
    mn::OBJ_Parser parser;

    // act
    parser.parse_file("test_obj_file.txt");

    // assert
    bool triangle_data = parser.triangles()[0].p1() == parser.vertices()[1] &&
                         parser.triangles()[0].p2() == parser.vertices()[2] &&
                         parser.triangles()[0].p3() == parser.vertices()[3] &&
                         parser.triangles()[1].p1() == parser.vertices()[1] &&
                         parser.triangles()[1].p2() == parser.vertices()[3] &&
                         parser.triangles()[1].p3() == parser.vertices()[4];

    const mn::Group &group1 = parser.group("FirstGroup");
    const mn::Group &group2 = parser.group("SecondGroup");
    bool group_data = group1.objects()[0] == &parser.triangles()[0] &&
                      group2.objects()[0] == &parser.triangles()[1];

    return triangle_data && group_data;
}

bool converting_an_obj_file_to_a_group() {
    // arrange
    mn::OBJ_Parser parser;

    // act
    parser.parse_file("test_obj_file.txt");
    const mn::Group &group = parser.obj_to_group();

    // assert
    const mn::Group &group1 = parser.group("FirstGroup");
    const mn::Group &group2 = parser.group("SecondGroup");

//    std::cout << "group.objects[0]: " << (long long) group.objects()[0] << "\n";
//    std::cout << "group.objects[1]: " << (long long) group.objects()[1] << "\n";
//    std::cout << "FirstGroup:  " << (long long) &group1 << "\n";
//    std::cout << "SecondGroup: " << (long long) &group2 << "\n";

    return group.objects()[1] == &group1 && group.objects()[0] == &group2;
}
//    std::cout << "Test triangle 0: " << (long long) (&(parser.triangles()[0])) << "\n";
//    std::cout << "Test triangle 1: " << (long long) (&(parser.triangles()[1])) << "\n";
//
//    std::cout << "Test FirstGroup  0: " << (long long) group1.objects()[0] << "\n";
//    std::cout << "Test SecondGroup 1: " << (long long) group2.objects()[0] << "\n";
