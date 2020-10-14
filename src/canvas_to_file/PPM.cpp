//
// Created by ivan on 11.10.2020..
//
#include <fstream>
#include "PPM.h"

namespace mn {

    void PPM::canvas_to_ppm(const Canvas &canvas, const std::string &filename) {
        _header(canvas.width(), canvas.height());
        _pixel_data(canvas.buffer());

        if (!filename.empty()) {
            _save(filename);
        }
    }

    const std::vector<std::string> &PPM::data() const { return _ppm; }

    // PPM file header
    void PPM::_header(int width, int height) {
        _ppm.emplace_back("P3\n"); // ppm file version: plain ppm in this case
        _ppm.emplace_back(std::to_string(width) + ' ' + std::to_string(height) + '\n');
        _ppm.emplace_back("255\n"); // maximum color value
    }

    // PPM file data
    // Canvas coordinates go from bottom to top; for example for 5x3 canvas:
    // (0,4) (1,4) (2,4) (3,4) (4,4)
    // (0,3) (1,3) (2,3) (3,3) (4,3)
    // (0,2) (1,2) (2,2) (3,2) (4,2)
    // (0,1) (1,1) (2,1) (3,1) (4,1)
    // (0,0) (1,0) (2,0) (3,0) (4,0)
    // PPM file format saves image from top to bottom.
    // That is why we go from height - 1 to 0 for y coordinate.
    void PPM::_pixel_data(const std::vector<std::vector<Color>> &buffer) {
        int height = buffer.size();
        for (int y = height - 1; y >= 0; --y) {
            const std::vector<Color> &row = buffer[y];

            std::string current_line;
            int width = row.size();
            for (int x = 0; x < width; ++x) {
                const Color &c = row[x];

                _add_color_component_to_line(current_line, c.r(), current_line.length() != 0);
                _add_color_component_to_line(current_line, c.g(), current_line.length() != 0);
                _add_color_component_to_line(current_line, c.b(), current_line.length() != 0);
            }
            current_line += '\n';
            _ppm.push_back(current_line);
        }
    }

    void PPM::_add_color_component_to_line(std::string &line, double rgb_component, bool space_before) {
        std::string component_to_add = std::to_string(_convert_to_0_255_range(rgb_component));
        auto added_width = (space_before ? 1 : 0) + component_to_add.length() + 1; // +1 for \n

        if (line.length() + added_width <= MAX_LINE_LENGTH) {
            line += (space_before ? " " : "") + component_to_add;
        } else {
            line += '\n';
            _ppm.push_back(line);
            line.erase();
            line += component_to_add;
        }
    }

    int PPM::_convert_to_0_255_range(double a) {
        if (a < 0.0) return 0;
        if (a >= 1.0) return 255;
        return static_cast <int>(std::round(255 * a));
    }

    void PPM::_save(const std::string &filename) const {
        std::ofstream output_file(filename);

        if (!output_file.is_open()) return;

        for (const std::string &line : _ppm) output_file << line;
        output_file.close();
    }

}
