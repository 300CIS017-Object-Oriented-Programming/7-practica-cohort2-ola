//
// Created by alfonso vega villadiego on 22/03/25.
//
#include "Cliente.h"
#include "Venta.h"

Cliente::Cliente(int idCliente, string nombre)
{
    this->idCliente = idCliente;
    this->nombre = nombre;
}

//GETTERS
int Cliente::getId()
    {return this->idCliente;}

string Cliente::getNombre()
    {return this->nombre;}

//SETTERS
void Cliente::setNombre(string nombreC)
    {this->nombre = nombre;}

void Cliente::setId(int idCliente)
{
    this->idCliente = idCliente;
}

void Cliente::agregarCompra(Venta venta)
{
    this->compras.push_back(venta);
}

void Cliente::mostrarHistorialCompras()
{
    for (int i = 0; i < this->compras.size(); i++)
    {
        compras[i].mostrarDetalleVenta();
    }
}