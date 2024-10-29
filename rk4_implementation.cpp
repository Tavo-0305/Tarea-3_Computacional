#include <iostream>
#include <fstream>
#include <cmath>
#include "vector.hpp" 

// primero creamos una función para evaluar dy/dx
double dydx(double x, double y) {
    return 2 * (1 - y) - std::exp(-4 * x);
}

// Implementamos el método RK4 usando la clase Vector
void rungeKutta(double x0, double y0, double h, int steps, const std::string &filename) {
    Vector x_vals(steps + 1); // Vector para almacenar valores de x
    Vector y_vals(steps + 1); // Vector para almacenar valores de y

    // Condiciones iniciales
    x_vals.set(0, x0);
    y_vals.set(0, y0);

    double x = x0;
    double y = y0;

    // Ciclo para calcular cada paso del método RK4
    for (int i = 1; i <= steps; ++i) {
        double k1 = h * dydx(x, y);
        double k2 = h * dydx(x + h / 2, y + k1 / 2);
        double k3 = h * dydx(x + h / 2, y + k2 / 2);
        double k4 = h * dydx(x + h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x += h;

        // Guardamos los valores en los vectores
        x_vals.set(i, x);
        y_vals.set(i, y);
    }

    // Creación del archivo con los datos:
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo " << filename << std::endl;
        return;
    }

    // Encabezado:
    file << "x y\n";

    // Para el guardado de los valores en el archivo definimos:
    for (int i = 0; i <= steps; ++i) {
        file << x_vals.get(i) << " " << y_vals.get(i) << "\n";
    }

    file.close();
    std::cout << "Los resultados se han guardado en el archivo: " << filename << std::endl;
}

int main() {
    double x0 = 0.0;
    double y0 = 1.0;  // Condición inicial y(0) = 1
    double h = 0.1;   // Tamaño del paso
    int steps = 100;  // Número de pasos

    std::string filename = "rk4_results.txt";
    rungeKutta(x0, y0, h, steps, filename);

    return 0;
 }