//
// Created by ivan on 5.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_TUPLE_H
#define THE_RAY_TRACER_CHALLENGE_TUPLE_H

#include <cmath>

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

        // Operations

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

        // Hadamard product (for color multiplication). We overload the standard
        // multiplication symbol to do this
        Tuple operator *(const Tuple &a) const {
            return Tuple(x * a.x, y * a.y, z * a.z, w * a.w);
        }

        [[nodiscard]] double magnitude() const {
            return std::sqrt(x * x + y * y + z * z + w * w);
        }

        // Normalize the vector
        void normalize() {
            double magnitude_squared = x * x + y * y + z * z + w * w;
            if (magnitude_squared > 0.0) { // check for divide-by-zero
                double one_over_magnitude = 1.0 / sqrt(magnitude_squared);
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
}

#endif //THE_RAY_TRACER_CHALLENGE_TUPLE_H
