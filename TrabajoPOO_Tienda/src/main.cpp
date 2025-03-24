#include <iostream>
#include <vector>
#include <limits>  // Para limpiar el buffer de entrada
#include "Producto.h"

using namespace std;

int main() {
    vector<Producto*> inventario;
    string comando, nombre, codigo;
    int stock;
    float precio;

    while (true) {
        cout << "Ingrese comando (AGREGAR, QUITAR, MOSTRAR, SALIR): ";
        cin >> comando;
        cin.ignore(); // Limpia el buffer antes de leer líneas completas

        if (comando == "AGREGAR") {
            cout << "Ingrese nombre: ";
            getline(cin, nombre);

            cout << "Ingrese codigo: ";
            cin >> codigo;
            cin.ignore();

            cout << "Ingrese precio: ";
            cin >> precio;

            cout << "Ingrese stock: ";
            cin >> stock;

            // Validar entrada
            if (cin.fail()) {
                cin.clear();  // Restablecer cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Limpiar buffer
                cout << "Error: Entrada inválida. Intente nuevamente.\n";
                continue; // Volver al inicio del bucle
            }

            // Agregar producto al inventario
            inventario.push_back(new Producto(codigo, nombre, precio, stock));
            cout << "Producto agregado!" << endl;
        }

        else if (comando == "QUITAR") {
            cout << "Ingrese codigo del producto a quitar: ";
            cin >> codigo;

            bool encontrado = false;
            for (auto it = inventario.begin(); it != inventario.end(); ++it) {
                if ((*it)->getCodigo() == codigo) {
                    delete *it;  // Liberar memoria
                    inventario.erase(it);
                    cout << "Producto eliminado!" << endl;
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                cout << "Producto no encontrado!" << endl;
            }
        }

        else if (comando == "MOSTRAR") {
            if (inventario.empty()) {
                cout << "El inventario está vacío." << endl;
            } else {
                cout << "Inventario:\n";
                for (const auto& producto : inventario) {
                    cout << "Nombre: " << producto->getNombre()
                         << ", Codigo: " << producto->getCodigo()
                         << ", Precio: " << producto->getPrecio()
                         << ", Stock: " << producto->getStock() << endl;
                }
            }
        }

        else if (comando == "SALIR") {
            break;
        }

        else {
            cout << "Comando no reconocido! Intente de nuevo." << endl;
        }
    }

    // Liberar memoria antes de salir
    for (auto producto : inventario) {
        delete producto;
    }
    inventario.clear();

    cout << "Programa finalizado!" << endl;
    return 0;
}

