#include<iostream>
#include "clsFecha.h"
#include "rlutil.h"
#include "cargarCadena.h"

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
void Fecha::cargar(int x, int y, int x2, int x3)
{
    while (true)
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

        if (!esValida())
        {
            rlutil::locate(x, y + 3);
            cout << "Fecha invalida. Reingrese (presione una tecla)...";
            rlutil::anykey();
        }
        else
        {
            break;
        }
    }
}
void Fecha::mostrar()
{
    cout << dia << "/" << mes << "/" << anio;
}
bool Fecha::esBisiesto()
{
    int y = anio;
    return ( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) );
}

bool Fecha::esValida()
{
    if (anio < 1900 || anio > 2025) return false;
    if (mes < 1 || mes > 12) return false;

    int diasPorMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int maxDia = diasPorMes[mes];
    if (mes == 2 && esBisiesto()) maxDia = 29;

    if (dia < 1 || dia > maxDia) return false;
    return true;
}
bool Fecha::cargarCompacta(int xPos, int yPos)
{
    rlutil::showcursor();
    int d, m, a;

    while (true)
    {
        rlutil::locate(xPos, yPos);
        cout << "                ";
        rlutil::locate(xPos, yPos);
        cin >> d;
        rlutil::locate(xPos + 2, yPos);
        cout << "/";
        cin >> m;


        rlutil::locate(xPos + 5, yPos);;
        cout << "/";
        cin >> a;


        dia = d;
        mes = m;
        anio = a;

        if (esValida())
        {
            rlutil::hidecursor();
            return true;
        }
        else
        {
            rlutil::locate(xPos, yPos);
            rlutil::setColor(rlutil::YELLOW);
            cout << "Fecha invalida";
            rlutil::anykey();

            rlutil::locate(xPos, yPos);
            cout << "              ";
            rlutil::setColor(rlutil::LIGHTRED);

        }
        cin.clear();
        cin.ignore(1000, '\n');
    }
    rlutil::hidecursor();
    return false;
}
