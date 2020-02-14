#ifndef __Canvas_H_INCLUDED__
#define __Canvas_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>
#include "Color.h"

/////////////////////////////////////////////////////////////////////////////
//
// class Canvas - a simple class for represinting canvas
//
/////////////////////////////////////////////////////////////////////////////

class Canvas {
public:
    Canvas(int w, int h) : width(w), height(h) {
        /* std::cout << "Allocating: " << width * height << " color slots\n" */;
        array = new Color[width * height];
    }
    ~Canvas() { /* std::cout << "Destructor\n" */; delete[] array; }

    void write_pixel(int x, int y, Color c) {
        array[y * width + x] = c;
    }

    Color pixel_at(int x, int y) const {
        return array[y * width + x];
    }

    int width, height;

private:
    Color * array;
};

int convert_to_0_255_range(float a) {
    if (a < 0.0f) return 0;
    if (a >= 1.0f) return 255;
    return std::round(255 * a);
}

std::vector<std::string> canvas_to_ppm(const Canvas & canvas) {
    const int MAX_LINE_LENGTH = 70;
    const int MAX_COLOR_STRING_LENGTH = 12; // 255 235 128 + \n
    std::vector<std::string> result;

    // PPM file header
    std::stringstream header;
    // header << "P3\n" << canvas.width << ' ' << canvas.height << '\n' << "255\n";
    header << canvas.width << ' ' << canvas.height << '\n';
    result.push_back("P3\n");
    result.push_back(header.str());
    result.push_back("255\n");
    // result.push_back(header.str());

    // PPM file data
    std::string current_line;

    for(int row = canvas.height - 1; row >= 0; row -= 1) {
        for(int col = 0; col < canvas.width; col += 1) {
            // std::cout << "row: " << row << ", col: " << col << "\n";
            Color c = canvas.pixel_at(col, row);
            std::stringstream ss;

            // std::cout << c.r << " " << c.g << " " << c.b << "\n";

            // std::cout << convert_to_0_255_range(c.r) << " "
            //     << convert_to_0_255_range(c.g) << " "
            //     << convert_to_0_255_range(c.b) << "\n";

            ss << convert_to_0_255_range(c.r) << " "
                << convert_to_0_255_range(c.g) << " "
                << convert_to_0_255_range(c.b); // << (col == canvas.width - 1 ? "" : " ");
            
            current_line += ss.str();

            if (current_line.length() > MAX_LINE_LENGTH - MAX_COLOR_STRING_LENGTH) {
                current_line += '\n';
                result.push_back(current_line);
                current_line.erase();
            } else {
                if (col == canvas.width - 1) {
                    current_line += '\n';
                    result.push_back(current_line);
                    current_line.erase();
                } else {
                    current_line += ' ';
                }
            }
        }
    }
    
    return result;
}

bool save_ppm_file(std::vector<std::string> data, std::string fname) {
    std::ofstream output_file(fname);
    
    if (output_file.is_open()) {
        for(int count = 0; count < data.size(); count += 1) {
            output_file << data[count];
        }
        output_file.close();
    } else {
        // std::cout << "Unable to open file";
        return false;
    } 
    
    return true;
}

#endif // __Canvas_H_INCLUDED__