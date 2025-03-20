#include "Inventario.h"


using namespace std;

void Inventario :: agregarProducto(string codigo, string nombre, float precio, int stock){
    Producto* producto = new Producto(codigo, nombre, precio, stock);
    productos.push_back(producto);

}

void Inventario :: registrarVenta(int idCliente){
    Cliente* cliente = buscarCliente(idCliente);

    if(cliente != nullptr){
        Venta* nuevaVenta = new Venta(cliente);
        ventas.push_back(nuevaVenta);
        cliente->agregarCompra(nuevaVenta);

    }
    else{
        cout << "El cliente no se pudo encontrar" << endl;
    }
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
    for(auto it = ventas.begin(); it != ventas.end(); ++it){
        cout << "Cliente: " << (*it)->getCliente()->getNombre()
             << " Total: $" << (*it)->calcularTotal() << endl;
        (*it)->mostrarDetalleVenta();
    }

}

float Inventario::calcularValorInventario() const{
    float valorTotal = 0.0;
    for(auto it = productos.begin(); it != productos.end(); ++it){
        valorTotal += (*it)->getPrecio() * (*it)->getStock();
    }
    return valorTotal;
}








