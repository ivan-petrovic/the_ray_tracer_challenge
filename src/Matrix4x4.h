//
// Created by ivan on 12.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_MATRIX4X4_H
#define THE_RAY_TRACER_CHALLENGE_MATRIX4X4_H

#include "Tuple.h"

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

    // Operator *= for conformace to C++ standards
    // Matrix4x4 &operator*=(Matrix4x4 &a, const Matrix4x4 &b);
    // Vector &operator*=(const Matrix4x4 &m, Vector &p);

    // Identity matrix factory
    Matrix4x4 identity();

    // Compute the transpose of a matrix
    Matrix4x4 transpose(const Matrix4x4 &m);

    // Compute the determinant of the 4x4 matrix
    double determinant(const Matrix4x4 &m);

    // Compute the inverse of the 4x4 matrix
    Matrix4x4 inverse(const Matrix4x4 &m);

    // Compute the normal matrix of the 4x4 matrix
    // Normal matrix is used to transform normal vector
    // from object to world space
    Matrix4x4 normal_matrix(const Matrix4x4 &m);

    bool epsilon_equal(const Matrix4x4 &a, const Matrix4x4 &b, double e = kEpsilon);

    // Transformations

    Matrix4x4 translation(double dx, double dy, double dz);

    Matrix4x4 scaling(double sx, double sy, double sz);

    Matrix4x4 rotation_x(double rad);

    Matrix4x4 rotation_y(double rad);

    Matrix4x4 rotation_z(double rad);

    Matrix4x4 shearing(double xy, double xz, double yx, double yz, double zx, double zy);

    Matrix4x4 view_transform(Point from, Point to, Vector up);
}

#endif //THE_RAY_TRACER_CHALLENGE_MATRIX4X4_H
