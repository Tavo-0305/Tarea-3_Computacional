#include "vector.hpp"
#include <iostream>

int main() {
    Vector v1(3);
    v1.set(0, 1.0);
    v1.set(1, 2.0);
    v1.set(2, 3.0);

    Vector v2 = v1; // Constructor copia

    Vector v3 = v1 + v2; // Suma
    Vector v4 = v1 - v2; // Resta
    Vector v5 = v1 * 2.0; // Multiplicación por escalar

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3 = (v1 + v2): " << v3 << std::endl;
    std::cout << "v4 = (v1 - v2): " << v4 << std::endl;
    std::cout << "v5 = (v1 * 2): " << v5 << std::endl;

    return 0;
}
