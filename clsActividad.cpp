#include<iostream>
#include "clsActividad.h"
using namespace std;

Actividad::Actividad(float _Cuota, bool _Libre, int _opcion_act){
    CuotaBase = _Cuota;
    Libre = _Libre;
}

void Actividad::setCuotaBase(float _Cuota){
    CuotaBase = _Cuota;
}
void Actividad::setLibre(bool _Libre){
    Libre = _Libre;
}
void Actividad::setOpcion_act(int _opcion_act){
    opcion_act = _opcion_act;
}
float Actividad::getCuotaBase(){
    return CuotaBase;
}
bool Actividad::getLibre(){
    return Libre;
}
int Actividad::getOpcion_act(){
    return opcion_act;
}

float Actividad::calcularCuota(){
    if(Libre){
        return CuotaBase;
    }else{
        return CuotaBase * 0.75;
    }
}
void Actividad::cargar(){
    int opcion_mod;
    cout << "Elegir actividad: " << endl;
    cout << "1 - Funcional" << endl;
    cout << "2 - Musculacion" << endl;
    cout << "3 - Boxeo" << endl;
    cout << "opcion: ";
    cin >> opcion_act;

    cout << "Ingrese cuota base: ";
    cin >> CuotaBase;
    cout << "Modalidad (1 si es libre, 2 si es 3 veces por semana): ";
    cin >> opcion_mod;
    Libre = (opcion_mod == 1);
}
void Actividad::mostrar(){
    switch(getOpcion_act())
    {
    case 1:
        cout << "Actividad: Funcional" << endl;
        break;
    case 2:
        cout << "Actividad: Musculacion" << endl;
        break;
    case 3:
        cout << "Actividad: Boxeo" << endl;
        break;
    default:
        cout << "No se ha registrado la actividad" << endl;
        break;
    }
    cout << "Couta base: $" << CuotaBase << endl;
    cout << "Modalidad: " << (Libre ? "Libre" : "3 veces por semana") << endl;
    cout << "Cuota Final: $" << calcularCuota() << endl;
}
Funcional::Funcional(bool Libre){
    CuotaBase = 28000.0f;
    Libre = Libre;
}
Musculacion::Musculacion(bool Libre){
    CuotaBase = 32000.0f;
    Libre = Libre;
}
Boxeo::Boxeo(bool Libre){
    CuotaBase = 25000.0f;
    Libre = Libre;
}
