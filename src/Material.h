//
// Created by ivan on 18.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_MATERIAL_H
#define THE_RAY_TRACER_CHALLENGE_MATERIAL_H

#include <memory>
#include "Tuple.h"
#include "pattern/StripedPattern.h"

namespace mn {

    class Material {
    public:
        Material() :
                _color{}, _ambient(0.0), _diffuse(0.0), _specular(0.0), _shininess(0.0), _pattern(nullptr) {}

        Material(const Color &c, double a, double d, double s, double sh) :
                _color(c), _ambient(a), _diffuse(d), _specular(s), _shininess(sh), _pattern(nullptr) {}

        [[nodiscard]] const Color &color() const { return _color; }

        [[nodiscard]] Color &color() { return _color; }

        void color(const Color &c) { _color = c; }

        [[nodiscard]] double ambient() const { return _ambient; }

        void ambient(double a) { _ambient = a; }

        [[nodiscard]] double diffuse() const { return _diffuse; }

        void diffuse(double d) { _diffuse = d; }

        [[nodiscard]] double specular() const { return _specular; }

        void specular(double s) { _specular = s; }

        [[nodiscard]] double shininess() const { return _shininess; }

        void shininess(double sh) { _shininess = sh; }

        [[nodiscard]] bool has_pattern() const { return _pattern != nullptr; }

        // void pattern(const Pattern &pattern) { *_pattern = pattern; }
        void set_pattern(const std::shared_ptr<Pattern> &pattern) { _pattern = pattern; }

        [[nodiscard]] const Pattern &pattern() const { return *_pattern; }

        [[nodiscard]] Pattern &pattern() { return *_pattern; }

        bool operator==(const Material &m) const {
            return
                    _color == m._color &&
                    _ambient == m._ambient &&
                    _diffuse == m._diffuse &&
                    _specular == m._specular &&
                    _shininess == m._shininess;
        }

        bool operator!=(const Material &m) const {
            return
                    _color != m._color ||
                    _ambient != m._ambient ||
                    _diffuse != m._diffuse ||
                    _specular != m._specular ||
                    _shininess != m._shininess;
        }

    private:
        Color _color;
        double _ambient, _diffuse, _specular, _shininess;
        std::shared_ptr<Pattern> _pattern;

    };

    inline Material make_default_material() {
        Material material(
                mn::make_color(1.0, 1.0, 1.0),
                0.1, 0.9, 0.9, 200.0
        );

        return material;
    }

}

#endif //THE_RAY_TRACER_CHALLENGE_MATERIAL_H
