//
// Created by ivan on 11.10.2020..
//
#include "canvas_to_file/PPM.h"
#include "Tuple.h"

bool test_case_1();
bool test_case_2();

// Canvas to ppm file
int main() {
    if (test_case_1() && test_case_2()) return 0;
    return 1;
}

bool test_case_1() {
    // arrange
    const int width = 5;
    const int height = 3;
    mn::Canvas canvas(5, 3);

    mn::Color c1 = mn::color(1.5, 0.0, 0.0);
    mn::Color c2 = mn::color(0.0, 0.5, 0.0);
    mn::Color c3 = mn::color(-0.5, 0.0, 1.0);

    canvas.write_pixel(0, 0, c1);
    canvas.write_pixel(2, 1, c2);
    canvas.write_pixel(4, 2, c3);

    // act
    mn::PPM ppm;
    ppm.canvas_to_ppm(canvas);

    // assert
    auto data = ppm.data();

    if (data[0] != "P3\n") return false;
    if (data[1] != (std::to_string(width) + ' ' + std::to_string(height) + '\n')) return false;
    if (data[2] != "255\n") return false;

    if (data[3] != "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n") return false;
    if (data[4] != "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n") return false;
    if (data[5] != "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n") return false;

    return true;
}

bool test_case_2() {
    // arrange
    const int width = 10;
    const int height = 2;
    mn::Canvas canvas(width, height);

    mn::Color c = mn::color(1.0, 0.8, 0.6);
    for(int x = 0; x < width; ++x)
        for(int y = 0; y < height; ++y) {
            canvas.write_pixel(x, y, c);
        }

    // act
    mn::PPM ppm;
    ppm.canvas_to_ppm(canvas);

    // assert
    auto data = ppm.data();

    if (data[0] != "P3\n") return false;
    if (data[1] != (std::to_string(width) + ' ' + std::to_string(height) + '\n')) return false;
    if (data[2] != "255\n") return false;

    if (data[3] != "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n") return false;
    if (data[4] != "153 255 204 153 255 204 153 255 204 153 255 204 153\n") return false;
    if (data[5] != "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n") return false;
    if (data[6] != "153 255 204 153 255 204 153 255 204 153 255 204 153\n") return false;

    return true;
}
