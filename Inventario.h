//
// Created by alanm on 18/03/2025.
//

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <string>
#include "Producto.h"
#include "Cliente.h"
#include "Venta.h"

class Inventario {
private:
    std::vector<Producto*> productos;
    std::vector<Cliente*> clientes;
    std::vector<Venta*> ventas;

public:
    // Métodos de negocio
    void agregarProducto(std::string codigo, std::string nombre, float precio, int stock);
    void registrarVenta(int idCliente);
    void reabastecerProducto(std::string codigoProducto, int cantidad);
    Producto* buscarProducto(std::string codigo);
    Cliente* buscarCliente(int idCliente);
    void listarProductos() const;
    void mostrarVentas() const;
    float calcularValorInventario() const;
};

#endif
