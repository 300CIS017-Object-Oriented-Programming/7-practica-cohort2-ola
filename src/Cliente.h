//
// Created by alfonso vega villadiego on 22/03/25.
//

#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <vector>

class Venta;

using namespace std;


class Cliente {
private:
    int idCliente;
    string nombre;
    vector<Venta> compras;

public:
    // Constructor
    Cliente(int idCliente, string nombre);

    // Métodos de acceso (getters)
    int getId();
    string getNombre();

    // Métodos de negocio
    void agregarCompra(Venta venta);
    void mostrarHistorialCompras();

    void setNombre(string nombre);
    void setId(int idCliente);
};

#endif