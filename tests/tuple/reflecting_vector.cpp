//
// Created by ivan on 18.10.2020..
//
#include "Tuple.h"

bool reflecting_a_vector_approaching_at_45();

bool reflecting_a_vector_of_a_slanted_surface();

int main() {
    if (
            reflecting_a_vector_approaching_at_45() &&
            reflecting_a_vector_of_a_slanted_surface()
            )
        return 0;
    return 1;
}

bool reflecting_a_vector_approaching_at_45() {
    mn::Vector v = mn::vector(1.0, -1.0, 0.0);
    mn::Vector n = mn::vector(0.0, 1.0, 0.0);

    mn::Vector result = reflect(v, n);

    return result == mn::vector(1.0, 1.0, 0.0);
}

bool reflecting_a_vector_of_a_slanted_surface() {
    mn::Vector v = mn::vector(0.0, -1.0, 0.0);
    const double sqrt_of_2 = std::sqrt(2.0);
    mn::Vector n = mn::vector(sqrt_of_2 / 2, sqrt_of_2 / 2, 0.0);

    mn::Vector result = reflect(v, n);

    return mn::epsilon_equal(result, mn::vector(1.0, 0.0, 0.0));
}
