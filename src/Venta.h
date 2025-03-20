#ifndef VENTA_H
#define VENTA_H

#include "Cliente.h"
#include "Producto.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Venta {
private:
    int idVenta;
    Cliente* cliente;
    vector<pair<Producto*, int>> productosVendidos;

public:
    // Constructor
    Venta(Cliente* cliente);

    // Métodos de negocio
    void agregarProductoVendido(Producto* producto, int cantidad);
    float calcularTotal() const;
    void mostrarDetalleVenta() const;
    Cliente* getCliente() const;
};

#endif