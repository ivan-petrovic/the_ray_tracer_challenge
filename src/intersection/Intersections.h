//
// Created by ivan on 15.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_INTERSECTIONS_H
#define THE_RAY_TRACER_CHALLENGE_INTERSECTIONS_H

#include <vector>
#include "../Tuple.h"
//#include "../Ray.h"
// #include "../model/Object.h"
//#include "../model/Sphere.h"
// #include "../World.h"

namespace mn {

    class Object;

    struct Intersection {
        double t;
        const Object *object;
        double u, v;
    };

    struct Hit {
        double t;
        const Object *object;
        Point point;
        Point over_point;
        Point under_point;
        Vector eye;
        Vector normal;
        Vector reflect_v;
        bool inside;
        double n1, n2;
    };

    class Intersections {
    public:
        Intersections() = default;

        [[nodiscard]] int count() const { return _intersections.size(); }

        void add(double t, const Object *o) { _intersections.push_back(Intersection{t, o}); }
        void add(double t, const Object *o, double u, double v) {
            _intersections.push_back(Intersection{t, o, u, v});
        }

        const Intersection &operator[](int i) const { return _intersections[i]; } // no bound checking

        void sort();

    private:
        std::vector<Intersection> _intersections;
    };

//    void intersect(const Ray &ray, const Object &object, Intersections &intersections);
//
//    void intersect(const Ray &ray, const World &world, Intersections &intersections);
//
//    Intersection find_hit(Intersections &intersections);
//
//    Hit prepare_computations(const Intersection &intersection, const Ray &ray);

}
#endif //THE_RAY_TRACER_CHALLENGE_INTERSECTIONS_H
