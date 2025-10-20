#include<iostream>
#include "clsFecha.h"
#include "rlutil.h"

using namespace std;

Fecha::Fecha(int d, int m, int a)
{
    dia = d;
    mes = m;
    anio = a;
}
void Fecha::setDia(int d)
{
    dia = d;
}
void Fecha::setMes(int m)
{
    mes = m;
}
void Fecha::setAnio(int a)
{
    anio = a;
}
int Fecha::getDia()
{
    return dia;
}
int Fecha::getMes()
{
    return mes;
}
int Fecha::getAnio()
{
    return anio;
}
void Fecha::cargar(int x, int y)
{
    rlutil::locate(x, y);
    cout << "Dia: ";
    cin >> dia;
    rlutil::locate(x, y + 1);
    cout << "Mes: ";
    cin >> mes;
    rlutil::locate(x, y + 2);
    cout << "Anio: ";
    cin >> anio;
}

void Fecha::mostrar()
{
    cout << dia << "/" << mes << "/" << anio << endl;
}
