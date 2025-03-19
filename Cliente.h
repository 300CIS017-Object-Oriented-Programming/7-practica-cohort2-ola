//
// Created by alanm on 18/03/2025.
//

#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Venta.h"

class Cliente {
private:
    int idCliente;
    std::string nombre;
    std::vector<Venta*> compras;

public:
    // Constructor
    Cliente(int id, std::string nombre);

    // Métodos de acceso (getters)
    int getId() const;
    std::string getNombre() const;

    // Métodos de negocio
    void agregarCompra(Venta* venta);
    void mostrarHistorialCompras() const;
};

#endif
