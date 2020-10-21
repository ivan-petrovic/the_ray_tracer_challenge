//
// Created by ivan on 15.10.2020..
//
#include "Tuple.h"
#include "Matrix4x4.h"
#include "Canvas.h"
#include "canvas_to_file/PPM.h"

int main() {
    int w = 100;     // canvas width and height
    int radius = 40; // clock radius
    mn::Color white = mn::make_color(1.0, 1.0, 1.0);

    mn::Canvas canvas(w, w);

    mn::Point twelve = mn::make_point(0.0, 1.0, 0.0);

    for (int i = 0; i <= 11; i += 1) {
        mn::Matrix4x4 R = mn::rotation_z(mn::deg_to_rad(i * (-30.0)));
        mn::Point p = R * twelve;
        canvas.write_pixel(
                static_cast<int>(p.x * radius) + w / 2,
                static_cast<int>(p.y * radius) + w / 2,
                white
        );
    }

    mn::PPM ppm;
    ppm.canvas_to_ppm(canvas, "clock_face_background.ppm");

    return 0;
}
