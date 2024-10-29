#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stdexcept>

class Vector {
private:
    int n_elems;       
    double *data;      
    //n_elems y data manejarán recursos de memoria que no deberían ser modificados directamente fuera de la clase por esta razón se definen como atributos privados
public:
    // Constructor por defecto
    Vector();

    // Constructor personalizado
    Vector(int size);

    // Constructor copia
    Vector(const Vector& other);

    // Operador de asignación
    Vector& operator=(const Vector& other);

    // Destructor
    ~Vector();

    // Métodos de acceso
    int size() const;
    double get(int index) const;
    void set(int index, double value);

    // Método para imprimir el vector
    void print() const;

    // Sobrecarga de operadores
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(double scalar) const;

    // Sobrecarga de operador de flujo de salida
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
};

#endif 