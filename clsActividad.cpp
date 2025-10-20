#include <iostream>
#include <cstring>
#include "clsActividad.h"
#include "cargarCadena.h"

using namespace std;

Actividad::Actividad(const char* nombre, float cuota, bool libre, bool estado) {
    idAct = 0;
    strcpy(Nombre, nombre);
    Nombre[49] = '\0';
    CuotaBase = cuota;
    Libre = libre;
    Estado = estado;
}


// Setters
void Actividad::setIdAct(int id) { idAct = id; }
void Actividad::setNombre(const char* n) { strcpy(Nombre, n); }
void Actividad::setCuotaBase(float c) { CuotaBase = c; }
void Actividad::setLibre(bool l) { Libre = l; }
void Actividad::setEstado(bool e) { Estado = e; }

// Getters
int Actividad::getIdAct() { return idAct; }
const char* Actividad::getNombre() { return Nombre; }
float Actividad::getCuotaBase() { return CuotaBase; }
bool Actividad::getLibre() { return Libre; }
bool Actividad::getEstado() { return Estado; }


float Actividad::calcularCuota(){
    if(Libre){
        return CuotaBase;
    }else{
        return CuotaBase * 0.75;
    }
}

void Actividad::cargar(int proximoId){
    idAct = proximoId;
    cout << "ID DE LA NUEVA ACTIVIDAD: " << idAct << endl;
    cout << "Ingrese el nombre de la actividad: ";
    cargarCadena(Nombre, 49);
    cout << "Ingrese la cuota base: $";
    cin >> CuotaBase;
    int opcion_mod;
    cout << "Modalidad (1 para Pase Libre, 2 para 3 veces por semana): ";
    cin >> opcion_mod;
    Libre = (opcion_mod == 1);
    Estado = true;
}

void Actividad::mostrar(){
    cout << "======= DATOS DE LA ACTIVIDAD =======" << endl;
    cout << "ID: " << idAct << endl;
    cout << "Actividad: " << Nombre << endl;
    cout << "Couta base: $" << CuotaBase << endl;
    cout << "Modalidad: " << (Libre ? "Pase Libre" : "3 veces por semana") << endl;
    cout << "Cuota Final: $" << calcularCuota() << endl;
    cout << "Estado: " << (Estado ? "Activa" : "Inactiva") << endl;
}
