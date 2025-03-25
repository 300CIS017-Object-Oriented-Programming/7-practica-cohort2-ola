#include <iostream>
#include <vector>
#include <limits>  // Para limpiar el buffer de entrada
#include "Producto.h"
#include "Inventario.h"
#include "Venta.h"
#include "Cliente.h"

using namespace std;

int main() {
    Inventario inventario;
    string comando, comando2, comando3, nombre, codigo;
    int stock, cedula, idVenta = 0, cantidad;
    float precio;

    while (true) {
        cout << "Ingrese comando (AGREGAR, QUITAR, MOSTRAR, INGRESAR, VENTAS, TOTAL, SALIR): ";
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
            inventario.agregarProducto(codigo, nombre, precio, stock);
            cout << "Producto agregado!" << endl;
        }

        else if (comando == "QUITAR") {
            cout << "Ingrese codigo del producto a quitar: ";
            cin >> codigo;

            inventario.eliminarProducto(codigo);

            cout << "Producto correctamente eliminado" << endl;
        }

        else if (comando == "MOSTRAR") {
            inventario.listarProductos();
        }

        else if (comando == "INGRESAR") {
            cout << "Bienvenido al sistema de compras!\n Ingrese su cedula: ";
            cin >> cedula;
            cout << "Ahora ingrese su nombre: ";
            cin >> nombre;
            inventario.agregarCliente(cedula, nombre);
            Cliente * cliente = inventario.buscarCliente(cedula);
            string comando2;
            while(comando2 != "SALIR"){
                cout << "Senior/a " << nombre << ", Que desea realizar? (COMPRAR, VER, SALIR): ";
                cin >> comando2;
                if (comando2 == "COMPRAR"){
                    Venta nuevaVenta = Venta(idVenta++);
                    string comando3;
                    while(comando3 != "SALIR"){
                        inventario.listarProductos();
                        cout << "Digite el codigo del producto que desea agregar a la compra (o digite SALIR si desea acabar la compra): " << endl;
                        cin >> comando3;
                        if(comando3 != "SALIR"){
                            cout << "Digite la cantidad de este producto que desea comprar: ";
                            cin >> cantidad;
                            Producto * productoRef = inventario.buscarProducto(comando3);
                            productoRef->descontarStock(cantidad);
                            if(productoRef->getStock() <= 0){
                                inventario.eliminarProducto(comando3);
                            }
                            Producto nuevoProducto = Producto(productoRef->getCodigo(), productoRef->getNombre(), productoRef->getPrecio(), productoRef->getStock());
                            nuevaVenta.agregarProductoVendido(nuevoProducto, cantidad);
                        }
                    }
                    cliente->agregarCompra(nuevaVenta);
                } else if(comando2 == "VER"){
                    cliente->mostrarHistorialCompras();
                }
            }
        }

        else if (comando == "VENTAS") {
            inventario.mostrarVentas();
        }

        else if (comando == "TOTAL") {
            cout << "Valor total del inventario: " << inventario.calcularValorInventario() << endl;
        }

        else if (comando == "SALIR") {
            break;
        }

        else {
            cout << "Comando no reconocido! Intente de nuevo." << endl;
        }
    }

    cout << "Programa finalizado!" << endl;
    return 0;
}

