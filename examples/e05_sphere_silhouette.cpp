// g++ e05_sphere_silhouette.cpp ../Matrix4x4.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp ../Intersection.cpp
#include <iostream>
#include "../first_version/Vector4.h"
#include "../first_version/Matrix4x4.h"
#include "../first_version/Ray.h"
#include "../first_version/Sphere.h"
#include "../first_version/Intersection.h"
#include "../first_version/Color.h"
#include "../first_version/Canvas.h"


int main() {
    const int W = 200;
    Color red(0.9f, 0.1f, 0.0f);

    Sphere sphere;
    sphere.transform = shearing(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) * scaling(0.5f, 1.0f, 1.0f);

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
        
            if (hit(xs)) {
                canvas.write_pixel(x, y, red);
            }
        }
    }

    save_to_ppm_file(canvas, "temp.ppm");
    return 0;
}
