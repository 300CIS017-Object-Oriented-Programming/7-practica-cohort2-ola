#include <iostream>
#include "Cliente.h"

using namespace std;

// Constructor
Cliente::Cliente(int id, const string& nombre) : id(id), nombre(nombre) {}

// Agregar una compra al historial
void Cliente::agregarCompra(const string& compra) {
    historialCompras.push_back(compra);
}

// Mostrar el historial de compras
void Cliente::mostrarHistorial() const {
    cout << "Historial de compras de " << nombre << " (ID: " << id << "):\n";
    for (const auto& compra : historialCompras) {
        cout << "- " << compra << endl;
    }
}

// Obtener ID
int Cliente::getId() const {
    return id;
}

// Obtener nombre
string Cliente::getNombre() const {
    return nombre;
}
