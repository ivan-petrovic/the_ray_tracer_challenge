//
// Created by ivan on 26.10.2020..
//
#include "intersect.h"

namespace mn {

    void intersect(const Ray &ray, const Object &object, Intersections &intersections) {
        // convert the ray into object space
        Ray object_ray = ray.transform(inverse(object.transform()));

        object.local_intersect(object_ray, intersections);
    }

    Intersection find_hit(Intersections &intersections) {
        // no intersection
        if (intersections.count() == 0) return Intersection{0.0, nullptr};

        intersections.sort();

        for (int i = 0; i < intersections.count(); i += 1) {
            if (intersections[i].t < 0.0) continue;
            return intersections[i];
        }

        // no non-negative t value, so no intersection
        return Intersection{0.0, nullptr};
    }

    void intersect(const Ray &ray, const World &world, Intersections &intersections) {
        for (auto &&object : world.objects()) {
            intersect(ray, *object, intersections);
        }
        intersections.sort();
    }

    Hit prepare_computations(const Intersection &intersection, const Ray &ray) {
        Hit hit_data{};

        // copy the intersection's properties, for convenience
        hit_data.t = intersection.t;
        hit_data.object = intersection.object;

        // precompute some useful values
        hit_data.point = ray.position(hit_data.t);
        hit_data.eye = -ray.direction();
        hit_data.normal = intersection.object->normal_at(hit_data.point);

        if (dot(hit_data.normal, hit_data.eye) < 0) {
            hit_data.inside = true;
            hit_data.normal = -hit_data.normal;
        } else {
            hit_data.inside = false;
        }

        hit_data.reflect_v = mn::reflect(-ray.direction(), hit_data.normal);

        hit_data.over_point = hit_data.point + hit_data.normal * kEpsilon;

        return hit_data;
    }

}