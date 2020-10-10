#ifndef __INTERSECTION_H_INCLUDED__
#define __INTERSECTION_H_INCLUDED__

#include <vector>
#include "Ray.h"
#include "Sphere.h"

class Intersection {
public:
    float t;
    Sphere * object;

    Intersection(float t_, Sphere * object_) : t(t_), object(object_) {}
    bool operator!=(const Intersection other) { return t != other.t || object != other.object; }
    bool no_intersection() const { return object == nullptr; }
    operator bool() { return object != nullptr; }
};

class Intersections {
public:
    void add(Intersection i) { intersections.push_back(i); }
    int count() const { return intersections.size(); }
    Intersection &operator[](int i) {
        // no bound checking
        return intersections[i];
    }

private:
    std::vector<Intersection> intersections;
};

Intersections intersect(Sphere * s, const Ray& r);

Intersection hit(Intersections & xs);

#endif // __INTERSECTION_H_INCLUDED__
