//
// Created by ivan on 11.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_PPM_H
#define THE_RAY_TRACER_CHALLENGE_PPM_H

#include <vector>
#include <string>
#include "../Tuple.h"
#include "../Canvas.h"

namespace mn {

    class PPM {
    public:
        PPM() = default;

        void canvas_to_ppm(const Canvas &canvas, const std::string& filename = "");

        int test();

    private:
        const int MAX_LINE_LENGTH = 70;

        std::vector<std::string> _ppm;

        void _header(int width, int height);

        static int _convert_to_0_255_range(double a);

        void _add_color_component_to_line(std::string &line, double rgb_component, bool space_before);

        void _pixel_data(const std::vector<std::vector<Color>> &buffer);

        void _save(const std::string& filename) const;

        // Testing functions
        bool test_case_1();

        bool test_case_2();

        static bool test_convert_to_0_255_range();
    };

}


#endif //THE_RAY_TRACER_CHALLENGE_PPM_H
