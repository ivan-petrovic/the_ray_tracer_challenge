// g++ e03_gradient.cpp
#include <iostream>
#include "../first_version/Vector4.h"
#include "../first_version/Color.h"
#include "../first_version/Canvas.h"


int main() {
    int w = 100;        // canvas width and height
    Color white(1.0f, 1.0f, 1.0f);
    Color red(1.0f, 0.0f, 0.0f);
    Color blue(0.0f, 0.0f, 1.0f);

    Canvas canvas(w, w);

    for (int row = 0; row < w; row += 1) {
        Color c;
        float k = row / float(w - 1);
        
        if (row < w/2) {
            k *= 2.0f;              // k [0, 1/2] -> [0, 1]
            c = white * (1.0f - k) + red * k;
        } else {
            k = 2.0f * k - 1.0f;    // k [1/2, 1] -> [0, 1]
            c = red * (1.0f - k) + blue * k;
        }
         
        for (int col = 0; col < w; col += 1) {
            canvas.write_pixel(col, row, c);
        }
    }

    save_to_ppm_file(canvas, "temp.ppm");

    return 0;
}
