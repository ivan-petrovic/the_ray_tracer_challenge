#ifndef __Color_H_INCLUDED__
#define __Color_H_INCLUDED__

#include <math.h>

/////////////////////////////////////////////////////////////////////////////
//
// class Color - a simple class for represinting colors
//
/////////////////////////////////////////////////////////////////////////////

class Color {
public:

// Public representation:  Not many options here.

	float r, g, b;

// Constructors

	// Default constructor leaves color in
	// an indeterminate state

	Color() {}

	// Copy constructor

	Color(const Color &a) : r(a.r), g(a.g), b(a.b) {}

	// Construct given three values

	Color(float nr, float ng, float nb) : r(nr), g(ng), b(nb) {}

// Standard object maintenance

	// Assignment.  We adhere to C convention and
	// return reference to the lvalue

	Color &operator =(const Color &a) {
		r = a.r; g = a.g; b = a.b;
		return *this;
	}

	// Check for equality

	bool operator ==(const Color &a) const {
		return r==a.r && g==a.g && b==a.b;
	}

	bool operator !=(const Color &a) const {
		return r!=a.r || g!=a.g || b!=a.b;
	}

// // Vector operations

// 	// Set the vector to zero

// 	void zero() { x = y = z = w = 0.0f; }

// 	// Unary minus returns the negative of the vector

// 	Color operator -() const { return Color(-x,-y,-z, w); }

// 	// Binary + and - add and subtract vectors

	Color operator +(const Color &a) const {
		return Color(r + a.r, g + a.g, b + a.b);
	}

	Color operator -(const Color &a) const {
		return Color(r - a.r, g - a.g, b - a.b);
	}

// 	// Multiplication and division by scalar

	Color operator *(float a) const {
		return Color(r*a, g*a, b*a);
	}

// 	Color operator /(float a) const {
// 		float	oneOverA = 1.0f / a; // NOTE: no check for divide by zero here
// 		return Color(x*oneOverA, y*oneOverA, z*oneOverA, w*oneOverA);
// 	}

// 	// Combined assignment operators to conform to
// 	// C notation convention

	Color &operator +=(const Color &a) {
		r += a.r; g += a.g; b += a.b;
		return *this;
	}

	Color &operator -=(const Color &a) {
		r -= a.r; g -= a.g; b -= a.b;
		return *this;
	}

	Color &operator *=(float a) {
		r *= a; g *= a; b *= a;
		return *this;
	}

// 	Color &operator /=(float a) {
// 		float	oneOverA = 1.0f / a;
// 		x *= oneOverA; y *= oneOverA; z *= oneOverA; w *= oneOverA;
// 		return *this;
// 	}


	// Hadamard product.  We overload the standard
	// multiplication symbol to do this

	Color operator *(const Color &a) const {
		return Color(r*a.r, g*a.g, b*a.b);
	}
};

/////////////////////////////////////////////////////////////////////////////
//
// Nonmember functions
//
/////////////////////////////////////////////////////////////////////////////


// Scalar on the left multiplication, for symmetry

inline Color operator *(float k, const Color &v) {
	return Color(k*v.r, k*v.g, k*v.b);
}


// /////////////////////////////////////////////////////////////////////////////
// //
// // Global variables
// //
// /////////////////////////////////////////////////////////////////////////////

// // We provide a global zero vector constant

// // extern const Color kZeroVector;

/////////////////////////////////////////////////////////////////////////////
#endif // #ifndef __Color_H_INCLUDED__
