//
// Created by alanm on 18/03/2025.
//

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
private:
    int codigo;
    std::string nombre;
    double precio;
    int stock;

public:
    // Constructor
    Producto(int codigo, std::string nombre, double precio, int stock);

    // Métodos de acceso (getters)
    int getCodigo() const;
    std::string getNombre() const;
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
