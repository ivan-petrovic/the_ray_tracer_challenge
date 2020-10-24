//
// Created by ivan on 12.10.2020..
//
#include "Matrix4x4.h"

namespace mn {

    // m00 m01 m02 m03
    // m10 m11 m12 m13
    // m20 m21 m22 m23
    // m30 m31 m32 m33
    void Matrix4x4::set_row_by_row(
            double m00_, double m01_, double m02_, double m03_,
            double m10_, double m11_, double m12_, double m13_,
            double m20_, double m21_, double m22_, double m23_,
            double m30_, double m31_, double m32_, double m33_
    ) {
        m00 = m00_;
        m01 = m01_;
        m02 = m02_;
        m03 = m03_;
        m10 = m10_;
        m11 = m11_;
        m12 = m12_;
        m13 = m13_;
        m20 = m20_;
        m21 = m21_;
        m22 = m22_;
        m23 = m23_;
        m30 = m30_;
        m31 = m31_;
        m32 = m32_;
        m33 = m33_;
    }

    // Check equality
    bool Matrix4x4::operator==(const Matrix4x4 &a) const {
        return m00 == a.m00 && m01 == a.m01 && m02 == a.m02 && m03 == a.m03 &&
               m10 == a.m10 && m11 == a.m11 && m12 == a.m12 && m13 == a.m13 &&
               m20 == a.m20 && m21 == a.m21 && m22 == a.m22 && m23 == a.m23 &&
               m30 == a.m30 && m31 == a.m31 && m32 == a.m32 && m33 == a.m33;
    }

    bool Matrix4x4::operator!=(const Matrix4x4 &a) const {
        return m00 != a.m00 || m01 != a.m01 || m02 != a.m02 || m03 != a.m03 ||
               m10 != a.m10 || m11 != a.m11 || m12 != a.m12 || m13 != a.m13 ||
               m20 != a.m20 || m21 != a.m21 || m22 != a.m22 || m23 != a.m23 ||
               m30 != a.m30 || m31 != a.m31 || m32 != a.m32 || m33 != a.m33;
    }

    // 1 0 0 0
    // 0 1 0 0
    // 0 0 1 0
    // 0 0 0 1
    void Matrix4x4::identity() {
        m00 = 1.0;
        m01 = 0.0;
        m02 = 0.0;
        m03 = 0.0;

        m10 = 0.0;
        m11 = 1.0;
        m12 = 0.0;
        m13 = 0.0;

        m20 = 0.0;
        m21 = 0.0;
        m22 = 1.0;
        m23 = 0.0;

        m30 = 0.0;
        m31 = 0.0;
        m32 = 0.0;
        m33 = 1.0;
    }

    // a b c | a b
    // d e f | d e
    // g h i | g h
    // on the "to right" diagonals multiply and add
    // on the "to left" diagonals multiply and subtract
    double Matrix4x4::minor(
            double a, double b, double c,
            double d, double e, double f,
            double g, double h, double i
    ) {
        return a * e * i + b * f * g + c * d * h - b * d * i - a * f * h - c * e * g;
    }

    double Matrix4x4::determinant() const {
        return
                m00 * minor(m11, m12, m13, m21, m22, m23, m31, m32, m33) -
                m01 * minor(m10, m12, m13, m20, m22, m23, m30, m32, m33) +
                m02 * minor(m10, m11, m13, m20, m21, m23, m30, m31, m33) -
                m03 * minor(m10, m11, m12, m20, m21, m22, m30, m31, m32);
    }

    Matrix4x4 operator*(const Matrix4x4 &a, const Matrix4x4 &b) {
        Matrix4x4 r{};

        r.m00 = a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20 + a.m03 * b.m30;
        r.m01 = a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21 + a.m03 * b.m31;
        r.m02 = a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22 + a.m03 * b.m32;
        r.m03 = a.m00 * b.m03 + a.m01 * b.m13 + a.m02 * b.m23 + a.m03 * b.m33;

        r.m10 = a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20 + a.m13 * b.m30;
        r.m11 = a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31;
        r.m12 = a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32;
        r.m13 = a.m10 * b.m03 + a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33;

        r.m20 = a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20 + a.m23 * b.m30;
        r.m21 = a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31;
        r.m22 = a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32;
        r.m23 = a.m20 * b.m03 + a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33;

        r.m30 = a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + a.m33 * b.m30;
        r.m31 = a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31;
        r.m32 = a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32;
        r.m33 = a.m30 * b.m03 + a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33;

        return r;
    }

    Tuple operator*(const Matrix4x4 &m, const Tuple &p) {
        return Tuple(
                m.m00 * p.x + m.m01 * p.y + m.m02 * p.z + m.m03 * p.w,
                m.m10 * p.x + m.m11 * p.y + m.m12 * p.z + m.m13 * p.w,
                m.m20 * p.x + m.m21 * p.y + m.m22 * p.z + m.m23 * p.w,
                m.m30 * p.x + m.m31 * p.y + m.m32 * p.z + m.m33 * p.w
        );
    }

    Matrix4x4 identity() {
        Matrix4x4 I{};
        I.identity();
        return I;
    }

    // Compute the transpose of a matrix: turn its rows into columns
    // m00 m01 m02 m03     m00 m10 m20 m30
    // m10 m11 m12 m13 ==> m01 m11 m21 m31
    // m20 m21 m22 m23     m02 m12 m22 m32
    // m30 m31 m32 m33     m03 m13 m23 m33
    Matrix4x4 transpose(const Matrix4x4 &m) {
        Matrix4x4 r{};

        r.m00 = m.m00;
        r.m01 = m.m10;
        r.m02 = m.m20;
        r.m03 = m.m30;

        r.m10 = m.m01;
        r.m11 = m.m11;
        r.m12 = m.m21;
        r.m13 = m.m31;

        r.m20 = m.m02;
        r.m21 = m.m12;
        r.m22 = m.m22;
        r.m23 = m.m32;

        r.m30 = m.m03;
        r.m31 = m.m13;
        r.m32 = m.m23;
        r.m33 = m.m33;

        return r;
    }

    double determinant(const Matrix4x4 &m) {
        return m.determinant();
    }

    // A * inverse(A) = I
    Matrix4x4 inverse(const Matrix4x4 &m) {
        Matrix4x4 r{};
        double det = determinant(m);

        // Fail silently by returning default constructed matrix
        if (epsilon_equal(det, 0.0)) return r;

        // transpose while calculating
        r.m00 = Matrix4x4::minor(m.m11, m.m12, m.m13, m.m21, m.m22, m.m23, m.m31, m.m32, m.m33) / det;
        r.m10 = -Matrix4x4::minor(m.m10, m.m12, m.m13, m.m20, m.m22, m.m23, m.m30, m.m32, m.m33) / det;
        r.m20 = Matrix4x4::minor(m.m10, m.m11, m.m13, m.m20, m.m21, m.m23, m.m30, m.m31, m.m33) / det;
        r.m30 = -Matrix4x4::minor(m.m10, m.m11, m.m12, m.m20, m.m21, m.m22, m.m30, m.m31, m.m32) / det;

        r.m01 = -Matrix4x4::minor(m.m01, m.m02, m.m03, m.m21, m.m22, m.m23, m.m31, m.m32, m.m33) / det;
        r.m11 = Matrix4x4::minor(m.m00, m.m02, m.m03, m.m20, m.m22, m.m23, m.m30, m.m32, m.m33) / det;
        r.m21 = -Matrix4x4::minor(m.m00, m.m01, m.m03, m.m20, m.m21, m.m23, m.m30, m.m31, m.m33) / det;
        r.m31 = Matrix4x4::minor(m.m00, m.m01, m.m02, m.m20, m.m21, m.m22, m.m30, m.m31, m.m32) / det;

        r.m02 = Matrix4x4::minor(m.m01, m.m02, m.m03, m.m11, m.m12, m.m13, m.m31, m.m32, m.m33) / det;
        r.m12 = -Matrix4x4::minor(m.m00, m.m02, m.m03, m.m10, m.m12, m.m13, m.m30, m.m32, m.m33) / det;
        r.m22 = Matrix4x4::minor(m.m00, m.m01, m.m03, m.m10, m.m11, m.m13, m.m30, m.m31, m.m33) / det;
        r.m32 = -Matrix4x4::minor(m.m00, m.m01, m.m02, m.m10, m.m11, m.m12, m.m30, m.m31, m.m32) / det;

        r.m03 = -Matrix4x4::minor(m.m01, m.m02, m.m03, m.m11, m.m12, m.m13, m.m21, m.m22, m.m23) / det;
        r.m13 = Matrix4x4::minor(m.m00, m.m02, m.m03, m.m10, m.m12, m.m13, m.m20, m.m22, m.m23) / det;
        r.m23 = -Matrix4x4::minor(m.m00, m.m01, m.m03, m.m10, m.m11, m.m13, m.m20, m.m21, m.m23) / det;
        r.m33 = Matrix4x4::minor(m.m00, m.m01, m.m02, m.m10, m.m11, m.m12, m.m20, m.m21, m.m22) / det;

        return r;
    }

    // Vector world_normal = transpose(inverse(_transform)) * object_normal;
    Matrix4x4 normal_matrix(const Matrix4x4 &m) {
        Matrix4x4 r{};
        // determinant of 3x3 portion of matrix m
        double det3x3 = Matrix4x4::minor(m.m00, m.m01, m.m02, m.m10, m.m11, m.m12, m.m20, m.m21, m.m22);

        r.m00 = (m.m11 * m.m22 - m.m12 * m.m21) / det3x3;
        r.m01 = (m.m12 * m.m20 - m.m10 * m.m22) / det3x3;
        r.m02 = (m.m10 * m.m21 - m.m11 * m.m20) / det3x3;
        r.m03 = 0.0;

        r.m10 = (m.m02 * m.m21 - m.m01 * m.m22) / det3x3;
        r.m11 = (m.m00 * m.m22 - m.m02 * m.m20) / det3x3;
        r.m12 = (m.m01 * m.m20 - m.m00 * m.m21) / det3x3;
        r.m13 = 0.0;

        r.m20 = (m.m01 * m.m12 - m.m02 * m.m11) / det3x3;
        r.m21 = (m.m02 * m.m10 - m.m00 * m.m12) / det3x3;
        r.m22 = (m.m00 * m.m11 - m.m01 * m.m10) / det3x3;
        r.m23 = 0.0;

        r.m30 = 0.0;
        r.m31 = 0.0;
        r.m32 = 0.0;
        r.m33 = 0.0;

        return r;
    }

    bool epsilon_equal(const Matrix4x4 &a, const Matrix4x4 &b, double e) {
        return
                epsilon_equal(a.m00, b.m00, e) &&
                epsilon_equal(a.m01, b.m01, e) &&
                epsilon_equal(a.m02, b.m02, e) &&
                epsilon_equal(a.m03, b.m03, e) &&
                epsilon_equal(a.m10, b.m10, e) &&
                epsilon_equal(a.m11, b.m11, e) &&
                epsilon_equal(a.m12, b.m12, e) &&
                epsilon_equal(a.m13, b.m13, e) &&
                epsilon_equal(a.m20, b.m20, e) &&
                epsilon_equal(a.m21, b.m21, e) &&
                epsilon_equal(a.m22, b.m22, e) &&
                epsilon_equal(a.m23, b.m23, e) &&
                epsilon_equal(a.m30, b.m30, e) &&
                epsilon_equal(a.m31, b.m31, e) &&
                epsilon_equal(a.m32, b.m32, e) &&
                epsilon_equal(a.m33, b.m33, e);
    }

    // 1 0 0 dx
    // 0 1 0 dy
    // 0 0 1 dz
    // 0 0 0 1
    Matrix4x4 translation(double dx, double dy, double dz) {
        Matrix4x4 r{};

        r.m00 = 1.0;
        r.m01 = 0.0;
        r.m02 = 0.0;
        r.m03 = dx;

        r.m10 = 0.0;
        r.m11 = 1.0;
        r.m12 = 0.0;
        r.m13 = dy;

        r.m20 = 0.0;
        r.m21 = 0.0;
        r.m22 = 1.0;
        r.m23 = dz;

        r.m30 = 0.0;
        r.m31 = 0.0;
        r.m32 = 0.0;
        r.m33 = 1.0;

        return r;
    }

    // sx  0  0  0
    //  0 sy  0  0
    //  0  0 sz  0
    //  0  0  0  1
    Matrix4x4 scaling(double sx, double sy, double sz) {
        Matrix4x4 r{};

        r.m00 = sx;
        r.m01 = 0.0;
        r.m02 = 0.0;
        r.m03 = 0.0;

        r.m10 = 0.0;
        r.m11 = sy;
        r.m12 = 0.0;
        r.m13 = 0.0;

        r.m20 = 0.0;
        r.m21 = 0.0;
        r.m22 = sz;
        r.m23 = 0.0;

        r.m30 = 0.0;
        r.m31 = 0.0;
        r.m32 = 0.0;
        r.m33 = 1.0;

        return r;
    }

    //  1  0  0  0
    //  0  c -s  0
    //  0  s  c  0
    //  0  0  0  1
    Matrix4x4 rotation_x(double rad) {
        Matrix4x4 r{};

        double s = std::sin(rad);
        double c = std::cos(rad);

        r.m00 = 1.0;
        r.m01 = 0.0;
        r.m02 = 0.0;
        r.m03 = 0.0;

        r.m10 = 0.0;
        r.m11 = c;
        r.m12 = -s;
        r.m13 = 0.0;

        r.m20 = 0.0;
        r.m21 = s;
        r.m22 = c;
        r.m23 = 0.0;

        r.m30 = 0.0;
        r.m31 = 0.0;
        r.m32 = 0.0;
        r.m33 = 1.0;

        return r;
    }

    //  c  0  s  0
    //  0  1  0  0
    // -s  0  c  0
    //  0  0  0  1
    Matrix4x4 rotation_y(double rad) {
        Matrix4x4 r{};

        double s = std::sin(rad);
        double c = std::cos(rad);

        r.m00 = c;
        r.m01 = 0.0;
        r.m02 = s;
        r.m03 = 0.0;

        r.m10 = 0.0;
        r.m11 = 1.0;
        r.m12 = 0.0;
        r.m13 = 0.0;

        r.m20 = -s;
        r.m21 = 0.0;
        r.m22 = c;
        r.m23 = 0.0;

        r.m30 = 0.0;
        r.m31 = 0.0;
        r.m32 = 0.0;
        r.m33 = 1.0;

        return r;
    }

    //  c -s  0  0
    //  s  c  0  0
    //  0  0  1  0
    //  0  0  0  1
    Matrix4x4 rotation_z(double rad) {
        Matrix4x4 r{};

        double s = std::sin(rad);
        double c = std::cos(rad);

        r.m00 = c;
        r.m01 = -s;
        r.m02 = 0.0;
        r.m03 = 0.0;

        r.m10 = s;
        r.m11 = c;
        r.m12 = 0.0;
        r.m13 = 0.0;

        r.m20 = 0.0;
        r.m21 = 0.0;
        r.m22 = 1.0;
        r.m23 = 0.0;

        r.m30 = 0.0;
        r.m31 = 0.0;
        r.m32 = 0.0;
        r.m33 = 1.0;

        return r;
    }

    // xy means x moved in proportion to y, etc.
    //  1  xy  xz   0
    // yx   1  yz   0
    // zx  zy   1   0
    //  0   0   0   1
    Matrix4x4 shearing(double xy, double xz, double yx, double yz, double zx, double zy) {
        Matrix4x4 r{};

        r.m00 = 1.0;
        r.m01 = xy;
        r.m02 = xz;
        r.m03 = 0.0;

        r.m10 = yx;
        r.m11 = 1.0;
        r.m12 = yz;
        r.m13 = 0.0;

        r.m20 = zx;
        r.m21 = zy;
        r.m22 = 1.0;
        r.m23 = 0.0;

        r.m30 = 0.0;
        r.m31 = 0.0;
        r.m32 = 0.0;
        r.m33 = 1.0;

        return r;
    }

    // | left_x     left_y     left_z    0|   | 1 0 0 -from.x|
    // | true_up_x  true_up_y  true_up_z 0|   | 0 1 0 -from.y|
    // |-forward_x -forward_y -forward_z 0| * | 0 0 1 -from.z|
    // |   0          0          0       1|   | 0 0 0   1    |
    Matrix4x4 view_transform(Point from, Point to, Vector up) {
        Vector forward = normalize(to - from);
        Vector upn = normalize(up);
        Vector left = cross(forward, upn);
        Vector true_up = cross(left, forward);

        Matrix4x4 r{};

        r.m00 = left.x;
        r.m01 = left.y;
        r.m02 = left.z;
        r.m03 = 0.0;

        r.m10 = true_up.x;
        r.m11 = true_up.y;
        r.m12 = true_up.z;
        r.m13 = 0.0;

        r.m20 = -forward.x;
        r.m21 = -forward.y;
        r.m22 = -forward.z;
        r.m23 = 0.0;

        r.m30 = 0.0;
        r.m31 = 0.0;
        r.m32 = 0.0;
        r.m33 = 1.0;

        return r * translation(-from.x, -from.y, -from.z);
    }

}
