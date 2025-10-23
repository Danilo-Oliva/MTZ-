#include <iostream>
#include <cstring>
#include "clsActividad.h"
#include "cargarCadena.h"

using namespace std;

Actividad::Actividad(const char* nombre, float cuota, bool estado)
{
    idAct = 0;
    strcpy(Nombre, nombre);
    Nombre[49] = '\0';
    CuotaBase = cuota;
    Estado = estado;
}


// Setters
void Actividad::setIdAct(int id)
{
    idAct = id;
}
void Actividad::setNombre(const char* n)
{
    strcpy(Nombre, n);
}
void Actividad::setCuotaBase(float c)
{
    CuotaBase = c;
}

void Actividad::setEstado(bool e)
{
    Estado = e;
}

// Getters
int Actividad::getIdAct()
{
    return idAct;
}
const char* Actividad::getNombre()
{
    return Nombre;
}
float Actividad::getCuotaBase() const
{
    return CuotaBase;
}

bool Actividad::getEstado()
{
    return Estado;
}

float Actividad::calcularCuota()
{
    return CuotaBase;
}


void Actividad::cargar(int proximoId)
{
    idAct = proximoId;
    cout << "ID DE LA NUEVA ACTIVIDAD: " << idAct << endl;
    cout << "Ingrese el nombre de la actividad: ";
    cargarCadena(Nombre, 49);
    cout << "Ingrese la cuota base: $";
    cin >> CuotaBase;


    Estado = true;
}

void Actividad::mostrar()
{
    cout << "======= DATOS DE LA ACTIVIDAD =======" << endl;
    cout << "ID: " << idAct << endl;
    cout << "Actividad: " << Nombre << endl;
    cout << "Couta base: $" << CuotaBase << endl;
    cout << "Estado: " << (Estado ? "Activa" : "Inactiva") << endl;
}
