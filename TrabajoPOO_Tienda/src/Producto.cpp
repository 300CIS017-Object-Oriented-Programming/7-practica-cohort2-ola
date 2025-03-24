//
// Created by alfonso vega villadiego on 22/03/25.
//

#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

Producto:: Producto(string codigo, string nombre, float precio, int stock)
{
	this->codigo = codigo;
    this->nombre = nombre;
    this->precio = precio;
    this->stock = stock;
}


// Creamos los getters de Producto
string Producto::getCodigo()
{return codigo;}
string Producto::getNombre()
{return nombre;}
float Producto::getPrecio()
{return precio;}
int Producto::getStock()
{return stock;}

// Creamos los setters de Producto
void Producto::setPrecio(float nuevoPrecio)
{this->precio = nuevoPrecio;}
void Producto::setStock(int stockActual)
{this->stock = stockActual;}
void Producto::descontarStock(int cantidad)
{this->stock -= cantidad;}
void Producto::agregarStock(int cantidad)
{this->stock += cantidad;}
