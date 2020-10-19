// g++ e04_mandelbrot.cpp
#include <iostream>
#include "../first_version/Vector4.h"
#include "../first_version/Color.h"
#include "../first_version/Canvas.h"


int main() {
    const int W = 1200;
    int H = 500;

    Color white(1.0f, 1.0f, 1.0f);
    Color red(1.0f, 0.0f, 0.0f);
    Color blue(0.0f, 0.0f, 1.0f);

    Canvas canvas(W, H);

    for (int x = 0; x < W; x += 1) {
        for (int y = 0; y < H; y += 1) {

            // x [0, W-1], y [0, H-1] -> x [-1, 1], y [-1, 1]
            float one_over, aspect_ratio;
            float mx, my;
            if (W >= H) {
                one_over = 1.0f / H;
                aspect_ratio = W * one_over;
                mx = 2.0f * x * one_over - aspect_ratio;
                my = 2.0f * y * one_over - 1.0f;
            } else {
                one_over = 1.0f / W;
                aspect_ratio = H * one_over;
                mx = 2.0f * x * one_over - 1.0f;
                my = 2.0f * y * one_over - aspect_ratio;
            }
            // float scale = 1.5f;
            // mx *= scale;
            // my *= scale;

            // Mandelbrot
            float cx = 0.0f;
            float cy = 0.0f;
            const int NUM_STEPS = 50;

            Color c = blue;
            for (int i = 0; i < NUM_STEPS; i += 1) {
                float xtemp = cx*cx - cy*cy + mx;
                cy = 2.0*cx*cy + my;
                cx = xtemp;
    
                if ( (cx*cx + cy*cy) >= 8.0) {
                    float d = float(i) / float(NUM_STEPS);
                    // c = Color(d,d,d); // gray scale
                    c = white * (1.0f - d) + red * d;
                    break;
                }
            }

            canvas.write_pixel(x, y, c);
        }
    }

    save_to_ppm_file(canvas, "temp.ppm");
    return 0;
}
