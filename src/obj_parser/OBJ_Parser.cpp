//
// Created by ivan on 21.2.2021..
//

#include "OBJ_Parser.h"
#include <fstream>
#include <iostream>

namespace mn {

    void OBJ_Parser::parse_file(const std::string &filename) {
        std::ifstream input_file(filename);

        if (!input_file.is_open()) return;

        std::string line;
        while (std::getline(input_file, line)) {
            _lines.push_back(line);
        }
        input_file.close();

        parse_lines(_lines);
    }

    void OBJ_Parser::parse_lines(const std::vector<std::string> &lines) {
        _ignored_lines = 0;
        for (const std::string &line : lines) {
            if (!line.empty()) {
                process_statement(line);
            }
        };

        _current_triangle_index = 0;
        for (const std::string &line : lines) {
            if (!line.empty()) {
                process_statement_second_pass(line);
            }
        };
    };

    void OBJ_Parser::process_statement(const std::string &line) {
        char c;
        std::istringstream in(line);
        in >> c;

        switch (c) {
            case 'v':
                if (!process_vertex_statement(in)) {
                    ++_ignored_lines;
                };
                break;
            case 'f':
                if (!process_face_statement(in)) {
                    ++_ignored_lines;
                };
                break;
            case 'g':
                if (!process_group_statement(in)) {
                    ++_ignored_lines;
                };
                break;
            default:
                ++_ignored_lines;
                break;
        }
    }

    void OBJ_Parser::process_statement_second_pass(const std::string &line) {
        char c;
        std::istringstream in(line);
        in >> c;

        switch (c) {
            case 'f':
                process_face_statement_second_pass(in);
                break;
            case 'g':
                process_group_statement_second_pass(in);
                break;
            default:
                break;
        }
    }

    bool OBJ_Parser::process_vertex_statement(std::istringstream &in) {
        double n1, n2, n3;

        if (!(in >> n1)) {
            return false;
        }
        if (!(in >> n2)) {
            return false;
        }
        if (!(in >> n3)) {
            return false;
        }

        _vertices.push_back(mn::make_point(n1, n2, n3));
        return true;
    }

    bool OBJ_Parser::process_face_statement(std::istringstream &in) {
        std::vector<int> indices;

        int n;
        while (in >> n) {
            indices.push_back(n);
        }

        if (indices.size() < 3) {
            return false;
        }

        fan_triangulation(indices);
        return true;
    }

    void OBJ_Parser::process_face_statement_second_pass(std::istringstream &in) {
        int cnt = 0;
        int n;
        while (in >> n) {
            ++cnt;
        }

        if (cnt < 3) {
            return;
        }

        mn::Group &current_group = *_groups[_current_group];
        for (int i = 0; i < cnt - 2; ++i) {
            current_group.add_child(&_triangles[_current_triangle_index + i]);
        }
        _current_triangle_index += cnt - 2;
    }

    bool OBJ_Parser::process_group_statement(std::istringstream &in) {
        std::string name;

        if (!(in >> name)) {
            return false;
        }

        _groups[name] = std::make_unique<Group>();
        return true;
    }

    void OBJ_Parser::process_group_statement_second_pass(std::istringstream &in) {
        std::string name;

        if (!(in >> name)) {
            return;
        }

        _current_group = name;
    }

    void OBJ_Parser::fan_triangulation(const std::vector<int> &v) {
        for (int i = 1; i < v.size() - 1; ++i) {
            _triangles.emplace_back(Triangle(_vertices[v[0]], _vertices[v[i]], _vertices[v[i + 1]]));
        }
    }

    [[nodiscard]] const Group &OBJ_Parser::obj_to_group() {
        if (_obj_to_group == nullptr) {
            _obj_to_group = std::make_unique<Group>();
            for (auto &group : _groups) {
                // std::cout << group.first << "\t" << (group.second->empty() ? "empty" : "not empty") << "\n";
                if (!group.second->empty()) {
                    _obj_to_group->add_child(group.second.get());
                    // std::cout << group.first << "\t" << (long long)(group.second.get()) << "\n";
                }
            }
        }

        return *_obj_to_group;
    }

}
