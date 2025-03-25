//
// Created by alfonso vega villadiego on 22/03/25.
//

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
    vector<pair<Producto, int>> productosVendidos;

public:
    // Constructor
    Venta(int idVenta);

    // Métodos de negocio
    void agregarProductoVendido(Producto producto, int cantidad);
    float calcularTotal();
    void mostrarDetalleVenta();
};

#endif
