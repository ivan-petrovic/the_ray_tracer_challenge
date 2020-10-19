//
// Created by ivan on 19.10.2020..
// Chapter 6: Light and Shading
//
#include "Tuple.h"
#include "Matrix4x4.h"
#include "Ray.h"
#include "model/Sphere.h"
#include "intersection/Intersections.h"
#include "light/PointLight.h"
#include "light/lighting.h"
#include "Canvas.h"
#include "canvas_to_file/PPM.h"

int main() {
    const int width = 400;

    mn::Sphere sphere;
    mn::Material mat(mn::color(1.0, 0.2, 1.0));
    sphere.material(mat);
    // sphere.transform(mn::shearing(1.0, 0.0, 0.0, 0.0, 0.0, 0.0) * mn::scaling(0.5, 1.0, 1.0));

    mn::Point light_position = mn::point(-10.0, 10.0, -10.0);
    mn::Color light_color = mn::color(1.0, 1.0, 1.0);
    mn::PointLight light(light_position, light_color);

    mn::Point ray_origin = mn::point(0.0, 0.0, -5.0);

    double wall_z = 10.0;
    double wall_size = 7.0;
    double half_wall_size = wall_size / 2.0;

    double pixel_size = wall_size / width;

    mn::Canvas canvas(width, width);

    for (int y = 0; y < width; y += 1) {
        double world_y = -half_wall_size + pixel_size * y;

        for (int x = 0; x < width; x += 1) {
            double world_x = -half_wall_size + pixel_size * x;

            // point on the wall that the ray will target
            mn::Point position = mn::point(world_x, world_y, wall_z);
            mn::Vector direction = mn::normalize(position - ray_origin);

            mn::Ray ray(ray_origin, direction);
            mn::Intersections xs;
            mn::intersect(ray, sphere, xs);

            mn::Intersection intersection = mn::hit(xs);
            if (intersection.object != nullptr) {
                mn::Point point = ray.position(intersection.t);
                mn::Vector normal = intersection.object->normal_at(point);
                mn::Vector eye = -ray.direction();

                mn::Color c = mn::lighting(intersection.object->material(), light, point, eye, normal);
                canvas.write_pixel(x, y, c);
            }
        }
    }

    mn::PPM ppm;
    ppm.canvas_to_ppm(canvas, "sphere3D.ppm");

    return 0;
}
