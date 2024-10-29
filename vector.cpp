#include "vector.hpp"

// Constructor por defecto
Vector::Vector() : n_elems(0), data(nullptr) {}

// Constructor personalizado
Vector::Vector(int size) : n_elems(size), data(new double[size]) {
    for (int i = 0; i < n_elems; ++i) {
        data[i] = 0.0;
    }
}

// Constructor copia (deep copy)
Vector::Vector(const Vector& other) : n_elems(other.n_elems), data(new double[other.n_elems]) {
    for (int i = 0; i < n_elems; ++i) {
        data[i] = other.data[i];
    }
}

// Operador de asignación (deep copy)
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data;
        n_elems = other.n_elems;
        data = new double[n_elems];
        for (int i = 0; i < n_elems; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// Destructor
Vector::~Vector() {
    delete[] data;
}

// Métodos de acceso
int Vector::size() const {
    return n_elems;
}

double Vector::get(int index) const {
    if (index < 0 || index >= n_elems) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return data[index];
}

void Vector::set(int index, double value) {
    if (index < 0 || index >= n_elems) {
        throw std::out_of_range("Índice fuera de rango");
    }
    data[index] = value;
}

// Método para imprimir el vector
void Vector::print() const {
    std::cout << "[";
    for (int i = 0; i < n_elems; ++i) {
        std::cout << data[i];
        if (i < n_elems - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// Sobrecarga del operador de adición
Vector Vector::operator+(const Vector& other) const {
    if (n_elems != other.n_elems) {
        throw std::invalid_argument("Los vectores deben tener el mismo tamaño");
    }
    Vector result(n_elems);
    for (int i = 0; i < n_elems; ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

// Sobrecarga del operador de sustracción
Vector Vector::operator-(const Vector& other) const {
    if (n_elems != other.n_elems) {
        throw std::invalid_argument("Los vectores deben tener el mismo tamaño");
    }
    Vector result(n_elems);
    for (int i = 0; i < n_elems; ++i) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

// Sobrecarga del operador de multiplicación por escalar
Vector Vector::operator*(double scalar) const {
    Vector result(n_elems);
    for (int i = 0; i < n_elems; ++i) {
        result.data[i] = data[i] * scalar;
    }
    return result;
}

// Sobrecarga del operador de flujo de salida
std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "[";
    for (int i = 0; i < vec.n_elems; ++i) {
        os << vec.data[i];
        if (i < vec.n_elems - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}