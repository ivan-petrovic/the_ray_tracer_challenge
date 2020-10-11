//
// Created by ivan on 11.10.2020..
//
#include <fstream>
#include "PPM.h"
#include "../rtc.h"

namespace mn {

    void PPM::canvas_to_ppm(const Canvas &canvas, const std::string& filename) {
        _header(canvas.width(), canvas.height());
        _pixel_data(canvas.buffer());

        if (!filename.empty()) {
            _save(filename);
        }
    }

    int PPM::test() {
        if (!test_convert_to_0_255_range()) return 1;

        if (!test_case_1()) return 1;

        // prepare clean state for test case 2
        _ppm.clear();
        if (!test_case_2()) return 1;

        return 0;
    }

    // PPM file header
    void PPM::_header(int width, int height) {
        _ppm.emplace_back("P3\n"); // ppm file version: plain ppm in this case
        _ppm.emplace_back(std::to_string(width) + ' ' + std::to_string(height) + '\n');
        _ppm.emplace_back("255\n"); // maximum color value
    }

    // PPM file data
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

    void PPM::_save(const std::string& filename) const {
        std::ofstream output_file(filename);

        if (!output_file.is_open()) return;

        for (const std::string& line : _ppm) output_file << line;
        output_file.close();
    }

    // Testing functions
    bool PPM::test_case_1() {
        // arrange
        const int width = 5;
        const int height = 3;
        mn::Canvas canvas(5, 3);

        Color c1 = color(1.5, 0.0, 0.0);
        Color c2 = color(0.0, 0.5, 0.0);
        Color c3 = color(-0.5, 0.0, 1.0);

        canvas.write_pixel(0, 0, c1);
        canvas.write_pixel(2, 1, c2);
        canvas.write_pixel(4, 2, c3);

        // act
        canvas_to_ppm(canvas);

        // assert
        if (_ppm[0] != "P3\n") return false;
        if (_ppm[1] != (std::to_string(width) + ' ' + std::to_string(height) + '\n')) return false;
        if (_ppm[2] != "255\n") return false;

        if (_ppm[3] != "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n") return false;
        if (_ppm[4] != "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n") return false;
        if (_ppm[5] != "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n") return false;

        return true;
    }

    bool PPM::test_case_2() {
        // arrange
        const int width = 10;
        const int height = 2;
        Canvas canvas(width, height);

        Color c = mn::color(1.0, 0.8, 0.6);
        for(int x = 0; x < width; ++x)
            for(int y = 0; y < height; ++y) {
                canvas.write_pixel(x, y, c);
            }

        // act
        canvas_to_ppm(canvas);

        if (_ppm[0] != "P3\n") return false;
        if (_ppm[1] != (std::to_string(width) + ' ' + std::to_string(height) + '\n')) return false;
        if (_ppm[2] != "255\n") return false;

        if (_ppm[3] != "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n") return false;
        if (_ppm[4] != "153 255 204 153 255 204 153 255 204 153 255 204 153\n") return false;
        if (_ppm[5] != "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n") return false;
        if (_ppm[6] != "153 255 204 153 255 204 153 255 204 153 255 204 153\n") return false;

        return true;
    }

    bool PPM::test_convert_to_0_255_range() {
        if (_convert_to_0_255_range(1.5) != 255) return false;
        if (_convert_to_0_255_range(-0.5) != 0) return false;
        if (_convert_to_0_255_range(0.5) != 128) return false;

        return true;
    }

}
