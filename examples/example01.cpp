#include <iostream>
#include "Tuple.h"
#include "rtc.h"

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
            mn::point(0.0f, 1.0f, 0.0f),
            mn::normalize(mn::vector(1.0f, 1.0f, 0.0f))
    );

    // gravity -0.1 unit/tick, and wind is -0.01 unit/tick
    Environment environment(
            mn::vector(0.0f, -0.1f, 0.0f),
            mn::vector(-0.01f, 0.0f, 0.0f)
    );

    while (projectile.position.y > 0.0f) {
        std::cout << "(" << projectile.position.x << ", " << projectile.position.y << ")\n";
        tick(environment, projectile);
    }

    return 0;
}
