// g++ test_canvas.cpp
#include <iostream>
#include <vector>
#include <string>
#include "../Canvas.h"
#include "../Color.h"

bool canvas_creation();
bool writing_pixels_to_canvas();
bool constructing_the_PPM_header();
bool constructing_the_PPM_pixel_data();
bool splitting_long_lines_in_PPM_data();

int main() {
    int cnt_failed = 0;
    int cnt_passed = 0;

    std::cout << "Testing canvas class\n";

    if(!canvas_creation()) { cnt_failed += 1; std::cout << "canvas_creation failed\n"; }
    else { cnt_passed += 1; }

    if(!writing_pixels_to_canvas()) { cnt_failed += 1; std::cout << "writing_pixels_to_canvas failed\n"; }
    else { cnt_passed += 1; }

    if(!constructing_the_PPM_header()) { cnt_failed += 1; std::cout << "constructing_the_PPM_header failed\n"; }
    else { cnt_passed += 1; }

    if(!constructing_the_PPM_pixel_data()) { cnt_failed += 1; std::cout << "constructing_the_PPM_pixel_data failed\n"; }
    else { cnt_passed += 1; }

    if(!splitting_long_lines_in_PPM_data()) { cnt_failed += 1; std::cout << "splitting_long_lines_in_PPM_data failed\n"; }
    else { cnt_passed += 1; }

    std::cout << "\nTotal:  " << cnt_passed + cnt_failed << " tests.\n";
    std::cout << "Passed: " << cnt_passed << "\n";
    std::cout << "Failed: " << cnt_failed << "\n";

    return 0;
}

bool canvas_creation() {
    Canvas canvas(10, 20);

    if (canvas.width != 10) return false;
    if (canvas.height != 20) return false;

    return true; 
}

bool writing_pixels_to_canvas() {
    Canvas canvas(10, 20);
    Color red(1.0f, 0.0f, 0.0f);

    canvas.write_pixel(2, 3, red);
    
    Color c = canvas.pixel_at(2, 3);
    
    if (c != red) return false;

    return true; 
}

bool constructing_the_PPM_header() {
    Canvas canvas(5, 3);

    std::vector<std::string> ppm = canvas_to_ppm(canvas);

    if (ppm[0] != "P3\n") return false;
    if (ppm[1] != "5 3\n") return false;
    if (ppm[2] != "255\n") return false;

    return true; 
}

bool constructing_the_PPM_pixel_data() {
    Canvas canvas(5, 3);
    Color c1(1.5f, 0.0f, 0.0f);
    Color c2(0.0f, 0.5f, 0.0f);
    Color c3(-0.5f, 0.0f, 1.0f);

    canvas.write_pixel(0, 0, c1);
    canvas.write_pixel(2, 1, c2);
    canvas.write_pixel(4, 2, c3);

    std::vector<std::string> ppm = canvas_to_ppm(canvas);

    // std::cout << "TEST: " << ppm[3] << "\n";
    if (ppm[3] != "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n") return false;
    if (ppm[4] != "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n") return false;
    if (ppm[5] != "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n") return false;

    // save_ppm_file(ppm, "temp.txt");

    return true; 
}

// PPM format demands that line be no more than 70 characters long
bool splitting_long_lines_in_PPM_data() {
    const int width = 10;
    const int height = 2;
    const int MAX_LINE_LENGTH = 70;

    Canvas canvas(width, height);
    Color c(1.0f, 0.8f, 0.6f);

    for(int x = 0; x < width; x += 1)
        for(int y = 0; y < height; y += 1)
            canvas.write_pixel(x, y, c);

    std::vector<std::string> ppm = canvas_to_ppm(canvas);

//255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204​
//153 255 204 153 255 204 153 255 204 153 255 204 153​
//255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204​
//153 255 204 153 255 204 153 255 204 153 255 204 153​
    
    // first 3 lines are header
    for (int i = 3; i < ppm.size(); i += 1) {
        if (ppm[i].length() > MAX_LINE_LENGTH) return false;
        // std::cout << "TEST[" << i << "]: " << ppm[i];
    }

    // save_ppm_file(ppm, "temp.ppm");

    return true; 
}
