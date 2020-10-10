/////////////////////////////////////////////////////////////////////////////
//
// From: 3D Math Primer for Games and Graphics Development
// Changed a little bit: added w coordinate
//
// Vector4.h - Declarations for 3D vector class
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __VECTOR4_H_INCLUDED__
#define __VECTOR4_H_INCLUDED__

#include <math.h>

/////////////////////////////////////////////////////////////////////////////
//
// class Vector4 - a simple 3D vector class
//
/////////////////////////////////////////////////////////////////////////////

class Vector4 {
public:

// Public representation:  Not many options here.

	float x, y, z, w;

// Constructors

	// Default constructor leaves vector in
	// an indeterminate state

	Vector4() {}

	// Copy constructor

	Vector4(const Vector4 &a) : x(a.x), y(a.y), z(a.z), w(a.w) {}

	// Construct given three values

	Vector4(float nx, float ny, float nz, float wz) : x(nx), y(ny), z(nz), w(wz) {}

// Standard object maintenance

	// Assignment.  We adhere to C convention and
	// return reference to the lvalue

	Vector4 &operator =(const Vector4 &a) {
		x = a.x; y = a.y; z = a.z; w = a.w;
		return *this;
	}

	// Check for equality

	// bool operator ==(const Vector4 &a) const {
	// 	return x==a.x && y==a.y && z==a.z;
	// }

	bool operator ==(const Vector4 &a) const {
		const float EPSILON = 0.0001f;
    	return (abs(x - a.x) < EPSILON) && (abs(y - a.y) < EPSILON) && (abs(z - a.z) < EPSILON);
	}

	// bool operator !=(const Vector4 &a) const {
	// 	return x!=a.x || y!=a.y || z!=a.z;
	// }

	bool operator !=(const Vector4 &a) const {
		const float EPSILON = 0.0001f;
    	return (abs(x - a.x) > EPSILON) || (abs(y - a.y) > EPSILON) || (abs(z - a.z) > EPSILON);
	}

// Vector operations

	// Set the vector to zero

	void zero() { x = y = z = w = 0.0f; }

	// Unary minus returns the negative of the vector

	Vector4 operator -() const { return Vector4(-x,-y,-z, w); }

	// Binary + and - add and subtract vectors

	Vector4 operator +(const Vector4 &a) const {
		return Vector4(x + a.x, y + a.y, z + a.z, w + a.w);
	}

	Vector4 operator -(const Vector4 &a) const {
		return Vector4(x - a.x, y - a.y, z - a.z, w - a.w);
	}

	// Multiplication and division by scalar

	Vector4 operator *(float a) const {
		return Vector4(x*a, y*a, z*a, a*w);
	}

	Vector4 operator /(float a) const {
		float	oneOverA = 1.0f / a; // NOTE: no check for divide by zero here
		return Vector4(x*oneOverA, y*oneOverA, z*oneOverA, w*oneOverA);
	}

	// Combined assignment operators to conform to
	// C notation convention

	Vector4 &operator +=(const Vector4 &a) {
		x += a.x; y += a.y; z += a.z; w += a.w;
		return *this;
	}

	Vector4 &operator -=(const Vector4 &a) {
		x -= a.x; y -= a.y; z -= a.z; w -= a.w;
		return *this;
	}

	Vector4 &operator *=(float a) {
		x *= a; y *= a; z *= a; w *= a;
		return *this;
	}

	Vector4 &operator /=(float a) {
		float	oneOverA = 1.0f / a;
		x *= oneOverA; y *= oneOverA; z *= oneOverA; w *= oneOverA;
		return *this;
	}

	// Normalize the vector

	void normalize() {
		float magSq = x*x + y*y + z*z;
		if (magSq > 0.0f) { // check for divide-by-zero
			float oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}

	// Vector dot product.  We overload the standard
	// multiplication symbol to do this

	float operator *(const Vector4 &a) const {
		return x*a.x + y*a.y + z*a.z;
	}

    bool is_vector() const {
        return w == 0.0f;
    }

    bool is_point() const {
        return w == 1.0f;
    }
};

/////////////////////////////////////////////////////////////////////////////
//
// Nonmember functions
//
/////////////////////////////////////////////////////////////////////////////

// Compute the magnitude of a vector

inline float vectorMag(const Vector4 &a) {
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

// Compute normalized vector, but don't change the original vector
inline Vector4 normalize(const Vector4 &a) {
	Vector4 r = a;
	r.normalize();
	return r;
}

// Compute the cross product of two vectors (left-hand)

inline Vector4 crossProduct(const Vector4 &a, const Vector4 &b) {
	return Vector4(
		a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.x*b.y - a.y*b.x,
        0.0f
	);
}

// Scalar on the left multiplication, for symmetry

inline Vector4 operator *(float k, const Vector4 &v) {
	return Vector4(k*v.x, k*v.y, k*v.z, k*v.w);
}

// Compute the distance between two points

inline float distance(const Vector4 &a, const Vector4 &b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

// Compute the distance between two points, squared.  Often useful
// when comparing distances, since the square root is slow

inline float distanceSquared(const Vector4 &a, const Vector4 &b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return dx*dx + dy*dy + dz*dz;
}

// Compute the reflection vector

inline Vector4 reflect(const Vector4 &in, const Vector4 &normal) {
	return in - 2.0f * (in * normal) * normal;
	//                  ^^^^^^^^^^^
	//                  dot product
}

/////////////////////////////////////////////////////////////////////////////
//
// Global variables
//
/////////////////////////////////////////////////////////////////////////////

// We provide a global zero vector constant

// extern const Vector4 kZeroVector;
inline Vector4 make_point(float nx, float ny, float nz) {
    return Vector4(nx, ny, nz, 1.0f);
}

inline Vector4 make_vector(float nx, float ny, float nz) {
    return Vector4(nx, ny, nz, 0.0f);
}

/////////////////////////////////////////////////////////////////////////////
#endif // #ifndef __VECTOR4_H_INCLUDED__
