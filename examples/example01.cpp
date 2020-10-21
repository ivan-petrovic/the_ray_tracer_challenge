#include <iostream>
#include "Tuple.h"

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
            mn::make_point(0.0, 1.0, 0.0),
            mn::normalize(mn::make_vector(1.0, 1.0, 0.0))
    );

    // gravity -0.1 unit/tick, and wind is -0.01 unit/tick
    Environment environment(
            mn::make_vector(0.0, -0.1, 0.0),
            mn::make_vector(-0.01, 0.0, 0.0)
    );

    while (projectile.position.y > 0.0) {
        std::cout << "(" << projectile.position.x << ", " << projectile.position.y << ")\n";
        tick(environment, projectile);
    }

    return 0;
}
