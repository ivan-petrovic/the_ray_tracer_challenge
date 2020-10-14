//
// Created by ivan on 12.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_MATRIX4X4_H
#define THE_RAY_TRACER_CHALLENGE_MATRIX4X4_H

#include "Tuple.h"
#include "math_util.h"

namespace mn {

    class Matrix4x4 {
    public:
        double m00, m01, m02, m03;
        double m10, m11, m12, m13;
        double m20, m21, m22, m23;
        double m30, m31, m32, m33;

        Matrix4x4() = default;

        void set_row_by_row(
                double m00_, double m01_, double m02_, double m03_,
                double m10_, double m11_, double m12_, double m13_,
                double m20_, double m21_, double m22_, double m23_,
                double m30_, double m31_, double m32_, double m33_
        );

        // Check equality
        bool operator==(const Matrix4x4 &a) const;

        bool operator!=(const Matrix4x4 &a) const;

        void identity();

        // Compute the determinant of the 4x4 matrix
        [[nodiscard]] double determinant() const;

        static double minor(
                double a, double b, double c,
                double d, double e, double f,
                double g, double h, double i
        );

    };

    // Operator* is used to concatenate (multiply) matrices
    Matrix4x4 operator*(const Matrix4x4 &a, const Matrix4x4 &b);

    // And to transform points
    Tuple operator*(const Matrix4x4 &m, const Tuple &p);

    // Identity matrix factory
    Matrix4x4 identity();

    // Compute the transpose of a matrix
    Matrix4x4 transpose(const Matrix4x4 &m);

    // Compute the determinant of the 4x4 matrix
    double determinant(const Matrix4x4 &m);

    // Compute the inverse of the 4x4 matrix
    Matrix4x4 inverse(const Matrix4x4 &m);

    bool epsilon_equal(const Matrix4x4 &a, const Matrix4x4 &b, double e = epsilon);

}

#endif //THE_RAY_TRACER_CHALLENGE_MATRIX4X4_H
