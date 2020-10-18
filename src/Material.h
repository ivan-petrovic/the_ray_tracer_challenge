//
// Created by ivan on 18.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_MATERIAL_H
#define THE_RAY_TRACER_CHALLENGE_MATERIAL_H

#include "Tuple.h"

namespace mn {


    class Material {
    public:
        // constructor with default values
        explicit Material(
                const Color &c = mn::color(1.0, 1.0, 1.0),
                double a = 0.1, double d = 0.9, double s = 0.9, double sh = 200.0) :
                _color(c), _ambient(a), _diffuse(d), _specular(s), _shininess(sh) {}

        [[nodiscard]] const Color &color() const { return _color; }

        void color(const Color &c) { _color = c; }

        [[nodiscard]] double ambient() const { return _ambient; }

        void ambient(double a) { _ambient = a; }

        [[nodiscard]] double diffuse() const { return _diffuse; }

        void diffuse(double d) { _diffuse = d; }

        [[nodiscard]] double specular() const { return _specular; }

        void specular(double s) { _specular = s; }

        [[nodiscard]] double shininess() const { return _shininess; }

        void shininess(double sh) { _shininess = sh; }

    private:
        Color _color;
        double _ambient, _diffuse, _specular, _shininess;

    };

}

#endif //THE_RAY_TRACER_CHALLENGE_MATERIAL_H
