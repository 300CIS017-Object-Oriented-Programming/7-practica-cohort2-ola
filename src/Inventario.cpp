//
// Created by alfonso vega villadiego on 22/03/25.
//
#include "Inventario.h"


using namespace std;

void Inventario :: agregarProducto(string codigo, string nombre, float precio, int stock){
    Producto* producto = new Producto(codigo, nombre, precio, stock);
    productos.push_back(producto);
}

void Inventario :: eliminarProducto(string codigo){
    Producto* encontrado;
    for(auto it = productos.begin(); it != productos.end(); ++it){
        if ((*it)->getCodigo() == codigo){
            productos.erase(it);
            break;
        }
    }
}
void Inventario :: agregarCliente(int idCliente, string nombre){
    Cliente* cliente = new Cliente(idCliente, nombre);
    clientes.push_back(cliente);
}

void Inventario :: reabastecerProducto(string codigoProducto, int cantidad){
    Producto* producto = buscarProducto(codigoProducto);
    if(producto != nullptr){

        int stockActual = producto->getStock();
        producto->setStock(stockActual + cantidad);
    }
    else{
        cout << "No tenemos más de ese producto o no fue encontrado" << endl;
    }
}

Producto* Inventario :: buscarProducto(string codigo){
    Producto* encontrado = nullptr;
    for(auto it = productos.begin(); it != productos.end() && encontrado == nullptr; ++it){
        if ((*it)->getCodigo() == codigo){
            encontrado = *it;
        }
    }
    return encontrado;
}

Cliente* Inventario::buscarCliente(int idBuscado){
    Cliente* encontrado = nullptr;
    for(auto it = clientes.begin(); it != clientes.end() && encontrado == nullptr; ++it){
        if ((*it)->getId() == idBuscado){
            encontrado = *it;
        }
    }
    return encontrado;
}

void Inventario::listarProductos() const{
    cout << "Lista de Productos" << endl;
    for(auto it = productos.begin(); it != productos.end(); ++it){
        cout << "Código: " << (*it)->getCodigo()
             << " Nombre: " << (*it)->getNombre()
             << " Precio: $" << (*it)->getPrecio()
             << " Stock: " << (*it)->getStock() << endl;
    }

}

void Inventario::mostrarVentas() const {
    cout << "Registro de Ventas" << endl;
    for(auto it = clientes.begin(); it != clientes.end(); ++it){
        cout << "Cliente: " << (*it)->getNombre() << endl << "Historial de compras:" << endl;
        (*it)->mostrarHistorialCompras();
    }

}

float Inventario::calcularValorInventario() const{
    float valorTotal = 0.0;
    for(auto it = productos.begin(); it != productos.end(); ++it){
        valorTotal += (*it)->getPrecio() * (*it)->getStock();
    }
    return valorTotal;
}
