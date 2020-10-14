//
// Created by ivan on 11.10.2020..
//
#include "Canvas.h"
#include "Tuple.h"

// Colors are red, green, blue tuples
int main() {
    mn::Canvas canvas(10, 20);
    mn::Color red = mn::color(1.0, 0.0, 0.0);

    int x = 2, y = 3;
    canvas.write_pixel(x, y, red);

    if (canvas.pixel_at(x, y) == red) return 0;
    return 1;
}
