// g++ e01_projectile.cpp
#include <iostream>
#include "../Vector4.h"
#include "../Color.h"
#include "../Canvas.h"

class Projectile {
public:
    Projectile(Vector4 position_, Vector4 velocity_)
        : position(position_), velocity(velocity_) { }
    
    Vector4 position;   // point
    Vector4 velocity;   // vector
};

class Environment {
public:
    Environment(Vector4 gravity_, Vector4 wind_)
        : gravity(gravity_), wind(wind_) { }
    
    Vector4 gravity;    // vector
    Vector4 wind;       // vector
};

void tick(Environment & e, Projectile & p) {
    p.position = p.position + p.velocity;
    p.velocity = p.velocity + e.gravity + e.wind;
}

int main() {
    Vector4 position = make_point(0.0f, 1.0f, 0.0f);
    Vector4 velocity = make_vector(1.0f, 1.8f, 0.0f);
    velocity.normalize();
    velocity *= 11.25f;
    Projectile proj(position, velocity);

    Vector4 gravity = make_vector(0.0f, -0.1f, 0.0f);
    Vector4 wind = make_vector(-0.01f, 0.0f, 0.0f);
    Environment env(gravity, wind);

    Canvas canvas(900, 550);

    while(proj.position.y > 0.0f) {
        // std::cout << "(" << proj.position.x << ", " << proj.position.y << ")\n";
        canvas.write_pixel(int(proj.position.x), int(proj.position.y), Color(1.0f, 0.0f, 0.0f));
        tick(env, proj);
    }

    save_to_ppm_file(canvas, "temp.ppm");

    return 0;
}
