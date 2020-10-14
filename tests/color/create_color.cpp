//
// Created by ivan on 5.10.2020..
//
#include "Tuple.h"

// Colors are red, green, blue tuples
int main() {
    double red = -0.5, green = 0.4, blue = 1.7;
    mn::Tuple color = mn::color(red, green, blue);

    if (color.r() == red && color.g() == green && color.b() == blue) return 0;
    return 1;
}
