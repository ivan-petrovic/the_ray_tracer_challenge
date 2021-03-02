//
// Created by ivan on 21.2.2021..
//

#include "OBJ_Parser.h"
#include <fstream>
#include <algorithm>
#include <iterator>
#include <stdexcept>      // std::invalid_argument

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
                std::istringstream iss(line);
                std::vector<std::string> tokens{
                        std::istream_iterator<std::string>{iss},
                        std::istream_iterator<std::string>{}
                };
                process_statement(tokens);
            }
        };

        _current_face_index = 0;
        for (const std::string &line : lines) {
            if (!line.empty()) {
                std::istringstream iss(line);
                std::vector<std::string> tokens{
                        std::istream_iterator<std::string>{iss},
                        std::istream_iterator<std::string>{}
                };
                process_statement_second_pass(tokens);
            }
        };
    };

    void OBJ_Parser::process_statement(const std::vector<std::string> &tokens) {
        std::string statement = tokens[0];

        if (statement == "v") {
            if (!process_vertex_statement(tokens)) {
                ++_ignored_lines;
            };
        } else if (statement == "vn") {
            if (!process_vertex_normal_statement(tokens)) {
                ++_ignored_lines;
            };
        } else if (statement == "f") {
            if (!process_face_statement(tokens)) {
                ++_ignored_lines;
            };
        } else if (statement == "g") {
            if (!process_group_statement(tokens)) {
                ++_ignored_lines;
            };
        } else {
            ++_ignored_lines;
        }
    }

    void OBJ_Parser::process_statement_second_pass(const std::vector<std::string> &tokens) {
        std::string statement = tokens[0];

        if (statement == "f") {
            process_face_statement_second_pass(tokens);
        } else if (statement == "g") {
            process_group_statement_second_pass(tokens);
        }
    }

    // Vertex statement has the following form:
    // v -1 1 0
    bool OBJ_Parser::process_vertex_statement(const std::vector<std::string> &tokens) {
        double x, y, z;

        if (tokens.size() != 4) return false;

        try {
            x = std::stod(tokens[1]);
        } catch (const std::invalid_argument &ia) {
            return false;
        }
        try {
            y = std::stod(tokens[2]);
        } catch (const std::invalid_argument &ia) {
            return false;
        }
        try {
            z = std::stod(tokens[3]);
        } catch (const std::invalid_argument &ia) {
            return false;
        }

        _vertices.push_back(mn::make_point(x, y, z));
        return true;
    }

    // Vertex normal statement has the following form:
    // vn -1 1 0
    bool OBJ_Parser::process_vertex_normal_statement(const std::vector<std::string> &tokens) {
        double x, y, z;

        if (tokens.size() != 4) return false;

        try {
            x = std::stod(tokens[1]);
        } catch (const std::invalid_argument &ia) {
            return false;
        }
        try {
            y = std::stod(tokens[2]);
        } catch (const std::invalid_argument &ia) {
            return false;
        }
        try {
            z = std::stod(tokens[3]);
        } catch (const std::invalid_argument &ia) {
            return false;
        }

        _normals.push_back(mn::make_vector(x, y, z));
        return true;
    }

    // Faces statement has the following forms:
    // f 1 2 3
    // f 1 2 3 4 5
    // f 1//3 2//1 3//2
    // f 1/0/3 2/102/1 3/14/2
    // but in one file can be either form with 3 values 1//3 or 1/2/3
    // either form with 1 value, not both (that is assumption, code does not check for that)
    bool OBJ_Parser::process_face_statement(const std::vector<std::string> &tokens) {
        std::vector<int> indices_face;
        std::vector<int> indices_normal;

        for (int i = 1; i < tokens.size(); ++i) {
            try {
                std::vector<std::string> out;
                tokenize_face_statement(tokens[i], '/', out);
                if (out.size() == 1) {
                    int f = std::stoi(out[0]);
                    indices_face.push_back(f);
                } else if (out.size() == 3) {
                    int f = std::stoi(out[0]);
                    // out[1] (if not empty) contains texture coord; no support for that - for now :)
                    int n = std::stoi(out[2]);
                    indices_face.push_back(f);
                    indices_normal.push_back(n);
                } else {
                    return false;
                }

            } catch (const std::invalid_argument &ia) {
                return false;
            }
        }

        if (indices_face.size() < 3) return false;
        if (!indices_normal.empty()) _faces_normals_data_present = true;

        fan_triangulation(indices_face, indices_normal);
        return true;
    }

    void OBJ_Parser::tokenize_face_statement(
            std::string const &str,
            char delim,
            std::vector<std::string> &out
    ) {
        // construct a stream from the string
        std::stringstream ss(str);

        std::string s;
        while (std::getline(ss, s, delim)) {
            out.push_back(s);
        }
    }

    void OBJ_Parser::process_face_statement_second_pass(const std::vector<std::string> &tokens) {
        auto cnt = tokens.size() - 1; // - first token 'f'
        if (cnt < 3) return;

        mn::Group &current_group = *_groups[_current_group];
        if (!_faces_normals_data_present) {
            for (int i = 0; i < cnt - 2; ++i) {
                current_group.add_child(&_triangles[_current_face_index + i]);
            }
        } else {
            for (int i = 0; i < cnt - 2; ++i) {
                current_group.add_child(&_smooth_triangles[_current_face_index + i]);
            }
        }
        _current_face_index += cnt - 2;
    }

    // Group statement has the following form:
    // g <group name>
    bool OBJ_Parser::process_group_statement(const std::vector<std::string> &tokens) {
        if (tokens.size() != 2) return false;

        _groups[tokens[1]] = std::make_unique<Group>();
        return true;
    }

    void OBJ_Parser::process_group_statement_second_pass(const std::vector<std::string> &tokens) {
        _current_group = tokens[1];
    }

    void OBJ_Parser::fan_triangulation(const std::vector<int> &v, const std::vector<int> &n) {
        // there is no data about normals for face
        if (!_faces_normals_data_present) {
            for (int i = 1; i < v.size() - 1; ++i) {
                _triangles.emplace_back(Triangle(_vertices[v[0]], _vertices[v[i]], _vertices[v[i + 1]]));
            }
        } else {
            for (int i = 1; i < v.size() - 1; ++i) {
                _smooth_triangles.emplace_back(
                        SmoothTriangle(
                                _vertices[v[0]], _vertices[v[i]], _vertices[v[i + 1]],
                                _normals[n[0]], _normals[n[i]], _normals[n[i + 1]]
                        )
                );
            }
        }
    }

    [[nodiscard]] const Group &OBJ_Parser::obj_to_group() {
        if (_obj_to_group == nullptr) {
            _obj_to_group = std::make_unique<Group>();
            for (auto &group : _groups) {
                if (!group.second->empty()) {
                    _obj_to_group->add_child(group.second.get());
                }
            }
        }

        return *_obj_to_group;
    }

}
