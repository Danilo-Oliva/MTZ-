#include <iostream>
#include "rlutil.h"


using namespace std;

void resaltarMenu(const char* texto, int posX, int posY, bool seleccionado)
{
    if(seleccionado)
    {
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        rlutil::setColor(rlutil::BLACK);
    }
    else
    {
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::LIGHTRED);
    }
    rlutil::locate(posX,posY);
    cout << texto << endl;
}

void parteArribaMenu(int posX, int posY)
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(posX, posY);
    cout << (char)201;
    for (int i = 0; i < 29; i++) cout << (char)205;
    cout << (char)187 << endl;
}

void separarMenues(int posX, int posY)
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(posX, posY);
    cout << (char)204;
    for (int i = 0; i < 29; i++) cout << (char)205;
    cout << (char)185 << endl;
}

void bordesMenu(int posX, int posY)
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(posX, posY);
    cout << (char)186 << "                             " << (char)186 << endl;
}

void parteAbajoMenu(int posX, int posY)
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(posX, posY);
    cout << (char)200;
    for (int i = 0; i < 29; i++) cout << (char)205;
    cout << (char)188 << endl;
}

void mostrarCursor(int posX1, int posX2, int posY, int y)
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTRED); ///SE ESTABLECE FONDO DE VUELTA PARA EVITAR QUE SE RESALTE TODO EL RESTO

    rlutil::locate(posX1, posY + y * 2); ///y CONTROLA LA POSICION DEL CURSOR (arriba y abajo)
    cout << (char)175 << endl;
    rlutil::locate(posX2, posY + y * 2); ///y CONTROLA LA POSICION DEL CURSOR (arriba y abajo)
    cout << (char)174 << endl;
}

int accionarCursor(int y, int tecla)
{
    switch(tecla) /// VALORES EN ASCII
    {
    case 14: /// ARRIBA
    {
        rlutil::locate(28, 9 + y);
        cout << " " << endl;
        y--;
        if (y < 0) y = 0; ///IMPIDE IR A OPCIONES POR ENCIMA DEL MENU
        break;
    }
    case 15: /// ABAJO
    {
        rlutil::locate(28, 9 + y);
        cout << " " << endl;
        y++;
        if(y > 2) y = 2; ///IMPIDE IR A OPCIONES POR DEBAJO DEL MENU
        break;
    }
    default:
        cout << "Esto no tendria que estar aca" << endl;
        return -1;
    } /// FIN SWITCH
    return y;
}
