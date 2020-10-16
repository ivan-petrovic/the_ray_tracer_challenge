//
// Created by ivan on 15.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_INTERSECTIONS_H
#define THE_RAY_TRACER_CHALLENGE_INTERSECTIONS_H

#include <vector>
#include "../Ray.h"
#include "../model/Object.h"
#include "../model/Sphere.h"

namespace mn {

    struct Intersection {
        double t;
        const Object *object;
    };

    class Intersections {
    public:
        Intersections() = default;

        [[nodiscard]] int count() const { return _intersections.size(); }

        void add(double t, const Object *o) { _intersections.push_back(Intersection{t, o}); }

        const Intersection &operator[](int i) { return _intersections[i]; } // no bound checking

        void sort();

    private:
        std::vector<Intersection> _intersections;
    };

    void intersect(const Ray &ray, const Sphere &sphere, Intersections &intersections);

    Intersection hit(Intersections &intersections);

}
#endif //THE_RAY_TRACER_CHALLENGE_INTERSECTIONS_H
