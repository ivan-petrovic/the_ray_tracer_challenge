// g++ e06_sphere.cpp ../Matrix4x4.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp ../Intersection.cpp ../Lighting.cpp
#include <iostream>
#include "../Vector4.h"
#include "../Matrix4x4.h"
#include "../Ray.h"
#include "../Sphere.h"
#include "../PointLight.h"
#include "../Lighting.h"
#include "../Intersection.h"
#include "../Color.h"
#include "../Canvas.h"


int main() {
    const int W = 400;

    Sphere sphere;
    sphere.material.color = Color(1.0f, 0.2f, 1.0f);
    // sphere.transform = shearing(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) * scaling(0.5f, 1.0f, 1.0f);

    Vector4 light_position = make_point(-10.0f, 10.0f, 10.0f);
    Color light_color = Color(1.0f, 1.0f, 1.0f);
    PointLight light(light_position, light_color);

    Vector4 ray_origin = make_point(0.0f, 0.0f, -5.0f);

    float wall_z = 10.0f;
    float wall_size = 7.0f;
    float half = wall_size / 2.0f;

    float pixel_size = wall_size / (W - 1);

    Canvas canvas(W, W);

    for (int y = 0; y < W; y += 1) {
        float world_y = -half + pixel_size * y;

        for (int x = 0; x < W; x += 1) {
            float world_x = -half + pixel_size * x;

            // point on the wall that the ray will target
            Vector4 position = make_point(world_x, world_y, wall_z);
            Vector4 direction = position - ray_origin;
            direction.normalize();

            Ray r(ray_origin, direction);
            Intersections xs = intersect(&sphere, r);
        
            Intersection intersection = hit(xs);
            if (intersection) {
                Vector4 point = r.position(intersection.t);
                Vector4 normal = (*intersection.object).normal_at(point);
                Vector4 eye = -r.direction;

                Color c = lighting((*intersection.object).material, light, point, eye, normal);
                canvas.write_pixel(x, y, c);
            }
        }
    }

    save_to_ppm_file(canvas, "temp.ppm");
    return 0;
}
