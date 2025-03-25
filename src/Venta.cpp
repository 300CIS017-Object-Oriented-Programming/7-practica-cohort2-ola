//
// Created by alfonso vega villadiego on 22/03/25.
//

#include "Venta.h"

Venta::Venta(int idVenta)
{
    this->idVenta = idVenta;
}

void Venta::agregarProductoVendido(Producto producto, int cantidad)
{
    pair<Producto, int> agregarProducto = make_pair(producto, cantidad);
    productosVendidos.push_back(agregarProducto);
}

float Venta::calcularTotal()
{
    float total = 0;

    for (int i = 0; i < productosVendidos.size(); i++)
    {
        total += productosVendidos[i].first.getPrecio()*productosVendidos[i].second;
    }

    return total;
}

void Venta::mostrarDetalleVenta()
{
    for (int i = 0; i < productosVendidos.size(); i++)
    {
        cout << productosVendidos[i].first.getNombre() << " " << productosVendidos[i].first.getPrecio() << " " << productosVendidos[i].second << endl;
    }
}
//GETTERS
