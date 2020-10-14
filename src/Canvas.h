//
// Created by ivan on 10.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_CANVAS_H
#define THE_RAY_TRACER_CHALLENGE_CANVAS_H

#include <vector>
#include "Tuple.h"

namespace mn {

    class Canvas {
    public:
        // width x height pixels initialized to black
        Canvas(int width, int height) : _width{width}, _height{height}, _canvas(height, std::vector<Tuple>(width)) {}

        [[nodiscard]] int width() const { return _width; }

        [[nodiscard]] int height() const { return _height; }

        [[nodiscard]] const std::vector<std::vector<Color>> &buffer() const { return _canvas; }

        void write_pixel(int x, int y, Color color) { _canvas[y][x] = color; }

        [[nodiscard]] Color pixel_at(int x, int y) const { return _canvas[y][x]; }

    private:
        int _width, _height;
        std::vector<std::vector<Color>> _canvas;
    };

}


#endif //THE_RAY_TRACER_CHALLENGE_CANVAS_H
