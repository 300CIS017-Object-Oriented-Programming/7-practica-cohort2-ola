#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <vector>
#include "Venta.h"

using namespace std;


class Cliente {
private:
    int idCliente;
    string nombre;
    vector<Venta*> compras;

public:
    // Constructor
    Cliente(int idCliente, string nombre);

    // Métodos de acceso (getters)
    int getId() const;
    string getNombre() const;

    // Métodos de negocio
    void agregarCompra(Venta* venta);
    void mostrarHistorialCompras() const;
};

#endif