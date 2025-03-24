#include <iostream>
#include "src/Cliente.h"
#include <vector>
#include "src/Producto.h"
#include "src/Venta.h"
#include "src/Inventario.h"

using namespace std;


int main() {
    string idCliente, nombre;

    cout << "Bienvenido al sistema." ;
    cout << "Por favor, ingrese su cédula (ID): ";
    cin >> idCliente;

    cout << "Ingrese su nombre: ";
    cin >> nombre;

    cout << "Gracias, " << nombre << ". Su cédula es " << idCliente << "." << endl;

    return 0;
}