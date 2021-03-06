//
// Created by ivan on 21.2.2021..
//

#ifndef THE_RAY_TRACER_CHALLENGE_OBJ_PARSER_H
#define THE_RAY_TRACER_CHALLENGE_OBJ_PARSER_H

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include "../Tuple.h"
#include "../model/Triangle.h"
#include "../model/SmoothTriangle.h"
#include "../model/Group.h"

namespace mn {

    class OBJ_Parser {
    public:
        OBJ_Parser() : _ignored_lines(0), _current_face_index(0),
        _current_group("default"), _faces_normals_data_present(false) {
            // because we want array to be 1-based
            _vertices.push_back(mn::make_point(0.0, 0.0, 0.0));
            // because we want array to be 1-based
            _normals.push_back(mn::make_vector(0.0, 0.0, 0.0));
            _groups["default"] = std::make_unique<Group>();
            _obj_to_group = nullptr;
        };

        void parse_file(const std::string &filename = "");

        void parse_lines(const std::vector<std::string> &lines);

        [[nodiscard]] int lines_count() const { return _lines.size(); }

        [[nodiscard]] int ignored_lines_count() const { return _ignored_lines; }

        [[nodiscard]] const std::vector<Point> &vertices() const { return _vertices; }

        [[nodiscard]] const std::vector<Vector> &normals() const { return _normals; }

        [[nodiscard]] const std::vector<Triangle> &triangles() const { return _triangles; }

        [[nodiscard]] const std::vector<SmoothTriangle> &smooth_triangles() const {
            return _smooth_triangles;
        }

        [[nodiscard]] const Group &default_group() { return *(_groups["default"]); }

        // void create_group(const std::string &name) { _groups[name] = std::make_unique<Group>(); }

        [[nodiscard]] const Group &group(const std::string &name) { return *_groups[name]; }

        [[nodiscard]] bool group_exists(const std::string &name) {
            if (_groups.find(name) == _groups.end())
                return false;

            return true;
        }

        [[nodiscard]] const Group &obj_to_group();

    private:
        std::vector<std::string> _lines;
        std::vector<Point> _vertices;
        std::vector<Vector> _normals;
        std::vector<Triangle> _triangles;
        std::vector<SmoothTriangle> _smooth_triangles;
        std::unordered_map<std::string, std::unique_ptr<Group>> _groups;
        std::string _current_group;
        int _ignored_lines;
        unsigned long long _current_face_index;
        std::unique_ptr<Group> _obj_to_group;
        bool _faces_normals_data_present;

        void process_statement(const std::vector<std::string> &tokens);

        void process_statement_second_pass(const std::vector<std::string> &tokens);

        bool process_vertex_statement(const std::vector<std::string> &tokens);

        bool process_vertex_normal_statement(const std::vector<std::string> &tokens);

        bool process_face_statement(const std::vector<std::string> &tokens);

        void process_face_statement_second_pass(const std::vector<std::string> &tokens);

        static void tokenize_face_statement(
                std::string const &str,
                char delim,
                std::vector<std::string> &out
        );

        bool process_group_statement(const std::vector<std::string> &tokens);

        void process_group_statement_second_pass(const std::vector<std::string> &tokens);

        void fan_triangulation(const std::vector<int> &v, const std::vector<int> &n);
    };

};

#endif //THE_RAY_TRACER_CHALLENGE_OBJ_PARSER_H
