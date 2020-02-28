#ifndef __INTERSECTION_H_INCLUDED__
#define __INTERSECTION_H_INCLUDED__

#include <vector>
#include "Ray.h"
#include "Sphere.h"

std::vector<float> intersect(const Sphere * s, const Ray& r);

#endif // __INTERSECTION_H_INCLUDED__
