#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Producto {
private:
    string codigo;
    string nombre;
    double precio;
    int stock;

public:
    // Constructor
    Producto(string codigo, string nombre, double precio, int stock);

    // Métodos de acceso (getters)
    string getCodigo() const;
    string getNombre() const;
    double getPrecio() const;
    int getStock() const;

    // Métodos de modificación (setters)
    void setPrecio(double nuevoPrecio);
    void setStock(int nuevoStock);

    // Métodos de negocio
    bool descontarStock(int cantidad);
    void agregarStock(int cantidad);
};

#endif