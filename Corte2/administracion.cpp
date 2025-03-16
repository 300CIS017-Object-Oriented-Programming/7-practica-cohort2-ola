#include <iostream>
#include <vector>
using namespace std;

class CuartoUtil {
public:
    string numeracion;
    int piso;
    string estado;
    
    CuartoUtil(string num, int p, string est) : numeracion(num), piso(p), estado(est) {}
};

class Propiedad {
public:
    int numero_piso;
    string numero_identificacion;
    float area;
    bool parqueadero;
    CuartoUtil* cuarto_util;
    
    Propiedad(int piso, string id, float ar, bool parque, CuartoUtil* cuarto=nullptr)
        : numero_piso(piso), numero_identificacion(id), area(ar), parqueadero(parque), cuarto_util(cuarto) {}
    
    float calcular_cobro() {
        float cobro_ascensor = 15000 * numero_piso;
        float valor_base = 150000;
        if (area > 150) valor_base *= 1.05;
        float descuento = (cuarto_util && cuarto_util->estado == "obra gris") ? valor_base * 0.01 : 0;
        return cobro_ascensor + valor_base - descuento;
    }
};

class Propietario {
public:
    string nombre;
    string identificacion;
    Propiedad* propiedad;
    
    Propietario(string nom, string id, Propiedad* prop) : nombre(nom), identificacion(id), propiedad(prop) {}
};

class Administracion {
public:
    vector<Propietario*> propietarios;
    
    void agregar_propietario(Propietario* p) {
        propietarios.push_back(p);
    }
    
    float calcular_recaudo_total() {
        float total = 0;
        for (auto p : propietarios) {
            total += p->propiedad->calcular_cobro();
        }
        return total;
    }
    
    void imprimir_propietarios_con_parqueadero() {
        for (auto p : propietarios) {
            if (p->propiedad->parqueadero) {
                cout << p->nombre << " tiene parqueadero.\n";
            }
        }
    }
    
    void generarReportePropiedades() {
        cout << "\n--- Reporte de Propiedades ---\n";
        for (auto p : propietarios) {
            cout << "Propietario: " << p->nombre << "\n";
            cout << "ID: " << p->identificacion << "\n";
            cout << "Número de piso: " << p->propiedad->numero_piso << "\n";
            cout << "Área: " << p->propiedad->area << " m2\n";
            cout << "Parqueadero: " << (p->propiedad->parqueadero ? "Sí" : "No") << "\n";
            cout << "Cuarto Útil: " << (p->propiedad->cuarto_util ? p->propiedad->cuarto_util->numeracion : "No tiene") << "\n";
            cout << "-----------------------------\n";
        }
    }
};

int main() {
    CuartoUtil cu1("A201", 2, "obra gris");
    CuartoUtil cu2("A202", 2, "terminado");
    
    Propiedad prop1(10, "101", 160, true, &cu1);
    Propiedad prop2(9, "901", 30, false, &cu2);
    
    Propietario prop1_obj("Debora Vilar", "20202492", &prop1);
    Propietario prop2_obj("Ignacio Rodriguez", "30458452", &prop2);
    
    Administracion admin;
    admin.agregar_propietario(&prop1_obj);
    admin.agregar_propietario(&prop2_obj);
    
    cout << "Recaudo total: " << admin.calcular_recaudo_total() << "\n";
    admin.imprimir_propietarios_con_parqueadero();
    
    // Prueba de la nueva función
    admin.generarReportePropiedades();
    
    return 0;
}
