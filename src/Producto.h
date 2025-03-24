//
// Created by alfonso vega villadiego on 22/03/25.
//



#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>

using namespace std;


class Producto {
private:
    string codigo;
    string nombre;
    float precio;
    int stock;

public:
    // Constructor
    Producto(string codigo, string nombre, float precio, int stock);

    // Métodos de acceso (getters)
    string getCodigo();
    string getNombre();
    float getPrecio();
    int getStock();

    // Métodos de modificación (setters)
    void setPrecio(float nuevoPrecio);
    void setStock(int stockActual);

    // Métodos de negocio
    void descontarStock(int cantidad);
    void agregarStock(int cantidad);

};

#endif
