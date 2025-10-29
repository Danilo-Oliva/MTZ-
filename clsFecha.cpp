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
    while (true)
    {
        rlutil::locate(x, y);
        std::cout << "Dia: ";
        std::cin >> dia;
        rlutil::locate(x, y + 1);
        std::cout << "Mes: ";
        std::cin >> mes;
        rlutil::locate(x, y + 2);
        std::cout << "Anio: ";
        std::cin >> anio;

        if (!esValida())
        {
            rlutil::locate(x, y + 3);
            std::cout << "Fecha invalida. Reingrese (presione una tecla)...";
            rlutil::anykey();
            //rlutil::cls();
        }
        else
        {
            break;
        }
    }
}
void Fecha::mostrar()
{
    cout << dia << "/" << mes << "/" << anio << endl;
}
bool Fecha::esBisiesto()
{
    int y = anio;
    return ( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) );
}

bool Fecha::esValida()
{
    if (anio < 1900 || anio > 2100) return false;
    if (mes < 1 || mes > 12) return false;

    int diasPorMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int maxDia = diasPorMes[mes];
    if (mes == 2 && esBisiesto()) maxDia = 29;

    if (dia < 1 || dia > maxDia) return false;
    return true;
}
