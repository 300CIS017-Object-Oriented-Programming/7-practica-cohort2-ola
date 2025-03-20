//
// Created by alanm on 18/03/2025.
//

#ifndef VENTA_H
#define VENTA_H

#include <vector>
#include "Cliente.h"
#include "Producto.h"

class Venta {
private:
    int id;
    Cliente* cliente;
    std::vector<std::pair<Producto*, int>> productosVendidos;

public:
    // Constructor
    Venta(int id, Cliente* cliente);

    // Métodos de negocio
    void agregarProductoVendido(Producto* producto, int cantidad);
    float calcularTotal() const;
    void mostrarDetalleVenta() const;
};

#endif
