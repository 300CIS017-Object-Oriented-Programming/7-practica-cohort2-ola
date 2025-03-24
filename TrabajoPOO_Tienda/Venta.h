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

class Cliente;
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
    float calcularTotal();
    void mostrarDetalleVenta();
    Cliente* getCliente();
};

#endif
