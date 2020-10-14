//
// Created by ivan on 11.10.2020..
//
#include "Canvas.h"

// Colors are red, green, blue tuples
int main() {
    int width = 10, height = 20;
    mn::Canvas canvas(width, height);

    if (canvas.width() != width) return 1;
    if (canvas.height() != height) return 1;
    if (canvas.buffer().size() != height) return 1;
    if (canvas.buffer()[0].size() != width) return 1;

    mn::Color black = mn::color(0.0, 0.0, 0.0);
    for (int x = 0; x < width; ++x)
        for (int y = 0; y < height; ++y)
            if (canvas.pixel_at(x, y) != black) return 1;

    return 0;
}
