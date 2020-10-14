#include <iostream>
#include "Tuple.h"
#include "canvas_to_file/PPM.h"

class Projectile {
public:
    Projectile(mn::Tuple position_, mn::Tuple velocity_)
            : position(position_), velocity(velocity_) {}

    mn::Tuple position;   // point
    mn::Tuple velocity;   // vector
};

class Environment {
public:
    Environment(mn::Tuple gravity_, mn::Tuple wind_)
            : gravity(gravity_), wind(wind_) {}

    mn::Tuple gravity;    // vector
    mn::Tuple wind;       // vector
};

void tick(Environment &e, Projectile &p) {
    p.position = p.position + p.velocity;
    p.velocity = p.velocity + e.gravity + e.wind;
}

int main() {
    // projectile starts one unit above origin.
    // velocity is normalized to 1 unit/tick
    Projectile projectile(
            mn::point(0.0, 1.0, 0.0),
            mn::normalize(mn::vector(1.0, 1.8, 0.0)) * 11.25
    );

    // gravity -0.1 unit/tick, and wind is -0.01 unit/tick
    Environment environment(
            mn::vector(0.0, -0.1, 0.0),
            mn::vector(-0.01, 0.0, 0.0)
    );

    const int width = 900;
    const int height = 550;
    mn::Canvas canvas(width, height);

    mn::Color red = mn::color(1.0, 0.0, 0.0);
    while (projectile.position.y > 0.0f) {
        int x = static_cast<int>(projectile.position.x);
        int y = static_cast<int>(projectile.position.y);

        if ((x >= 0 && x <= width) && (y >= 0 && y <= height)) {
            canvas.write_pixel(x, y, red);
        }

        tick(environment, projectile);
    }

    mn::PPM ppm;
    ppm.canvas_to_ppm(canvas, "trajectory.ppm");

    return 0;
}
