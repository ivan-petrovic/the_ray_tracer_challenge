//
// Created by ivan on 18.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_MATERIAL_H
#define THE_RAY_TRACER_CHALLENGE_MATERIAL_H

#include "Tuple.h"
#include "pattern/StripedPattern.h"

namespace mn {

    class Material {
    public:
        Material() = default;

        Material(const Color &c, double a, double d, double s, double sh) :
                _color(c), _ambient(a), _diffuse(d), _specular(s), _shininess(sh), _pattern_is_set(false) {}

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

        [[nodiscard]] bool has_pattern() const { return _pattern_is_set; }

        void pattern(const StripedPattern &pattern) { _pattern = pattern; _pattern_is_set = true; }

        [[nodiscard]] const StripedPattern &pattern() const { return _pattern; }

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
        StripedPattern _pattern;
        bool _pattern_is_set;

    };

    inline void make_default_material(Material &material) {
        material.color(mn::make_color(1.0, 1.0, 1.0));
        material.ambient(0.1);
        material.diffuse(0.9);
        material.specular(0.9);
        material.shininess(200.0);
    }

}

#endif //THE_RAY_TRACER_CHALLENGE_MATERIAL_H
