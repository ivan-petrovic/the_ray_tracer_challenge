//
// Created by ivan on 5.10.2020..
// Used: 3D Math Primer for Games and Graphics Development
// Changed a little bit: added w coordinate
//

#ifndef THE_RAY_TRACER_CHALLENGE_TUPLE_H
#define THE_RAY_TRACER_CHALLENGE_TUPLE_H

#include "math_util.h"

namespace mn {

    class Tuple {
    public:
        double x, y, z, w;

        // Default constructor leaves tuple in an indeterminate state
        Tuple() = default;

        // Copy constructor
        Tuple(const Tuple &a) = default;

        // Construct given four values
        Tuple(double nx, double ny, double nz, double wz) : x(nx), y(ny), z(nz), w(wz) {}

        // Check for equality
        bool operator==(const Tuple &a) const {
            return x == a.x && y == a.y && z == a.z && w == a.w;
        }

        bool operator!=(const Tuple &a) const {
            return x != a.x || y != a.y || z != a.z || w != a.w;
        }

        // Assignment. We adhere to C convention and
        // return reference to the lvalue
        Tuple &operator =(const Tuple &a) = default;

        // Operations

//        // Set the vector to zero
//        void zero() { x = y = z = w = 0.0f; }

        // Unary minus returns the negative of the tuple
        // Makes sense only if tuple is a vector
        Tuple operator-() const { return Tuple(-x, -y, -z, -w); }

        // Binary + and - add and subtract tuples
        // Makes sense only if tuples are vectors, or a point and a vector
        Tuple operator+(const Tuple &a) const {
            return Tuple(x + a.x, y + a.y, z + a.z, w + a.w);
        }

        // Makes sense also if tuples are points;
        // Then we get displacement vector between them
        Tuple operator-(const Tuple &a) const {
            return Tuple(x - a.x, y - a.y, z - a.z, w - a.w);
        }

        // Multiplication and division by scalar
        // Makes sense only if tuples are vectors
        Tuple operator*(double a) const {
            return Tuple(x * a, y * a, z * a, a * w);
        }

        Tuple operator/(double a) const {
            double one_over_a = 1.0 / a; // NOTE: no check for divide by zero here
            return Tuple(x * one_over_a, y * one_over_a, z * one_over_a, w * one_over_a);
        }

//        // Combined assignment operators to conform to
//        // C notation convention
//        Vector4 &operator +=(const Vector4 &a) {
//            x += a.x; y += a.y; z += a.z; w += a.w;
//            return *this;
//        }
//
//        Vector4 &operator -=(const Vector4 &a) {
//            x -= a.x; y -= a.y; z -= a.z; w -= a.w;
//            return *this;
//        }
//
//        Vector4 &operator *=(float a) {
//            x *= a; y *= a; z *= a; w *= a;
//            return *this;
//        }
//
//        Vector4 &operator /=(float a) {
//            float	oneOverA = 1.0f / a;
//            x *= oneOverA; y *= oneOverA; z *= oneOverA; w *= oneOverA;
//            return *this;
//        }

        // Hadamard product (for color multiplication). We overload the standard
        // multiplication symbol to do this
        Tuple operator*(const Tuple &a) const {
            return Tuple(x * a.x, y * a.y, z * a.z, w * a.w);
        }

        [[nodiscard]] double magnitude() const {
            return std::sqrt(x * x + y * y + z * z + w * w);
        }

        // Normalize the vector
        void normalize() {
            double magnitude_squared = x * x + y * y + z * z + w * w;
            if (magnitude_squared > 0.0) { // check for divide-by-zero
                double one_over_magnitude = 1.0 / std::sqrt(magnitude_squared);
                x *= one_over_magnitude;
                y *= one_over_magnitude;
                z *= one_over_magnitude;
            }
        }

        // Tuple as a Color
        [[nodiscard]] double r() const { return x; }

        [[nodiscard]] double g() const { return y; }

        [[nodiscard]] double b() const { return z; }

    };

    // Scalar on the left multiplication, for symmetry
    inline Tuple operator*(double k, const Tuple &v) {
        return Tuple(k * v.x, k * v.y, k * v.z, k * v.w);
    }

    // Compute the magnitude of a vector
    inline double magnitude(const Tuple &a) {
        return a.magnitude();
    }

    // Compute normalized vector, but don't change the original vector
    inline Tuple normalize(const Tuple &a) {
        Tuple r = a;
        r.normalize();
        return r;
    }

//    // Compute the distance between two points
//    inline float distance(const Vector4 &a, const Vector4 &b) {
//        float dx = a.x - b.x;
//        float dy = a.y - b.y;
//        float dz = a.z - b.z;
//        return sqrt(dx*dx + dy*dy + dz*dz);
//    }
// Compute the distance between two points, squared.  Often useful
// when comparing distances, since the square root is slow
//
//    inline float distanceSquared(const Vector4 &a, const Vector4 &b) {
//        float dx = a.x - b.x;
//        float dy = a.y - b.y;
//        float dz = a.z - b.z;
//        return dx*dx + dy*dy + dz*dz;
//    }


    // Vector dot product.
    inline double dot(const Tuple &a, const Tuple &b) {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }

    // Compute the cross product of two vectors
    inline Tuple cross(const Tuple &a, const Tuple &b) {
        return Tuple(
                a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x,
                0.0
        );
    }

    inline Tuple hadamard(const Tuple &a, const Tuple &b) {
        return a * b;
    }

    typedef Tuple Point;
    typedef Tuple Vector;
    typedef Tuple Color;

    inline bool is_point(const Tuple &t) { return t.w == 1.0; }

    inline bool is_not_point(const Tuple &t) { return t.w != 1.0; }

    inline bool is_vector(const Tuple &t) { return t.w == 0.0; }

    inline bool is_not_vector(Tuple &t) { return t.w != 0.0; }

    // Factory method for making points
    inline Point make_point(double x, double y, double z) { return Tuple(x, y, z, 1.0); }

    // Factory method for making vectors
    inline Vector make_vector(double x, double y, double z) { return Tuple(x, y, z, 0.0); }

    // Zero vector
    inline Vector zero() { return Tuple(0.0, 0.0, 0.0, 0.0); }

    // Factory method for making colors
    inline Color make_color(double red, double green, double blue, double alpha = 0.0) {
        return Tuple(red, green, blue, alpha);
    }

    inline bool epsilon_equal(const Tuple &a, const Tuple &b, double e = kEpsilon) {
        return
                epsilon_equal(a.x, b.x, e) &&
                epsilon_equal(a.y, b.y, e) &&
                epsilon_equal(a.z, b.z, e) &&
                epsilon_equal(a.w, b.w, e);
    }

    // Compute the reflection vector
    // vector: in starts in P ends in L
    // vector: n starts in P ends in N
    // vector: r starts in P ends in R
    // We reflect in vector in relation to n vector
    // and result is r (reflection) vector
    // R   N   L
    //  \  |  /
    //   \ | /
    //    \|/
    //     P
    inline Vector reflect(const Vector &in, const Vector &normal) {
        // if vector in starts in L ends in P, then the formula would be:
        // return in - 2.0 * dot(in, normal) * normal;

        // if vector in starts in P ends in L, then the formula is:
        return 2.0 * dot(in, normal) * normal - in;
    }

}

#endif //THE_RAY_TRACER_CHALLENGE_TUPLE_H
