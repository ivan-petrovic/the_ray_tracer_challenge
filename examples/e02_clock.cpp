// g++ e02_clock.cpp ../Matrix4x4.cpp ../Matrix3x3.cpp ../Matrix2x2.cpp
#include <iostream>
#include "../first_version/Vector4.h"
#include "../first_version/Matrix4x4.h"
#include "../first_version/Color.h"
#include "../first_version/Canvas.h"


int main() {
    int w = 100;        // canvas width and height
    int radius = 40;    // clock radius
    Color white(1.0f, 1.0f, 1.0f);

    Canvas canvas(w, w);

    Vector4 twelve = make_point(0.0f, 1.0f, 0.0f);

    for (int i = 0; i <=11; i += 1) {
        Matrix4x4 R = rotation_z(radians(i * (-30.0f)));
        Vector4 p = R * twelve;
        canvas.write_pixel(int(p.x * radius + w/2), int(p.y * radius + w/2), white);
    }

    save_to_ppm_file(canvas, "temp.ppm");

    return 0;
}
