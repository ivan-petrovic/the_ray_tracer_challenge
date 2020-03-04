#include <iostream>
#include "Intersection.h"

Intersections intersect(Sphere * s, const Ray& r) {
    Intersections result;
    Ray r2 = r.transform(inverse(s->transform));

    // the vector from the sphere's center, to the ray origin​
    // remember: the sphere is centered at the world origin​
    Vector4 sphere_to_ray = r2.origin - make_point(0.0f, 0.0f, 0.0f);

    float a = r2.direction * r2.direction;
    float b = 2.0f * r2.direction * sphere_to_ray;
    float c = sphere_to_ray * sphere_to_ray - 1;

    float discriminant = b * b - 4.0f * a * c;

    // no intersection
    if (discriminant < 0.0f) {
        return result;
    }

    float sqrt_discriminant = sqrt(discriminant);
    float one_over_2a = 0.5f / a;
    
    float t1 = (-b - sqrt_discriminant) * one_over_2a;
    float t2 = (-b + sqrt_discriminant) * one_over_2a;

    result.add(Intersection(t1, s));
    result.add(Intersection(t2, s));

    return result;
}

Intersection hit(Intersections & xs) {
    // no intersection
    if (xs.count() == 0) {
        return Intersection(0.0f, nullptr);    
    }
    
    const float REALLY_BIG_NUMBER = 1000000000.0f;
    int min_index = 0;
    float min_t = REALLY_BIG_NUMBER;

    for (int i = 0; i < xs.count(); i += 1) {
        if (xs[i].t < 0.0f) continue;
        if (xs[i].t < min_t) {
            min_t = xs[i].t;
            min_index = i;
        }
    }

    Intersection result = xs[min_index];

    // no nonnegative t value
    if (min_t == 1000000.0f) {
        result.object = nullptr;
    };

    return result;
}
