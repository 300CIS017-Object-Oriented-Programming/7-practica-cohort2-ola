#ifndef INVENTARIO_H
#define INVENTARIO_H



#include <iostream>
#include <vector>
#include <string>
#include "Producto.h"
#include "Cliente.h"
#include "Venta.h"


using namespace std;

class Inventario {
private:
    vector<Producto*> productos;
    vector<Cliente*> clientes;
    vector<Venta*> ventas;
    vector<Producto*> stock;

public:
    // Métodos de negocio
    void agregarProducto(string codigo, string nombre, float precio, int stock);
    void registrarVenta(int idCliente);
    void reabastecerProducto(string codigoProducto, int cantidad);
    Producto* buscarProducto(string codigo);
    Cliente* buscarCliente(int idCliente);
    void listarProductos() const;
    void mostrarVentas() const;
    float calcularValorInventario() const;
};

#endif