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

    rlutil::resetColor();
}

void parteArribaMenu(int posX, int posY, int espacios)
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(posX, posY);
    cout << (char)201;
    for (int i = 0; i < espacios; i++) cout << (char)205;
    cout << (char)187 << endl;
}

void separarMenues(int posX, int posY, int espacios)
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(posX, posY);
    cout << (char)204;
    for (int i = 0; i < espacios; i++) cout << (char)205;
    cout << (char)185 << endl;
}

void bordesMenu(int posX, int posY, int espacios)
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(posX, posY);
    cout << (char)186;
    for (int i = 0; i < espacios; i++) cout << " ";
    cout << (char)186 << endl;
}

void parteAbajoMenu(int posX, int posY, int espacios)
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(posX, posY);
    cout << (char)200;
    for (int i = 0; i < espacios; i++) cout << (char)205;
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
int accionarCursor(int y, int tecla, int limiteCursor)
{
    switch(tecla) /// VALORES EN ASCII
    {
    case rlutil::KEY_UP: /// ARRIBA
    {
        rlutil::locate(28, 9 + y);
        cout << " " << endl;
        y--;
        if (y < 0) y = limiteCursor;
        break;
    }
    case rlutil::KEY_DOWN: /// ABAJO
    {
        rlutil::locate(28, 9 + y);
        cout << " " << endl;
        y++;
        if(y > limiteCursor) y = 0;
        break;
    }
    } /// FIN SWITCH
    return y;
}

void mostrarCursorConfirmacion(int posX1, int posX2, int posY, int x)
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTRED); ///SE ESTABLECE FONDO DE VUELTA PARA EVITAR QUE SE RESALTE TODO EL RESTO

    rlutil::locate(posX1 + x * 22, posY); ///x CONTROLA LA POSICION DEL CURSOR (izquierda y derecha)
    cout << (char)175 << endl;
    rlutil::locate(posX2 + x * 22, posY); ///x CONTROLA LA POSICION DEL CURSOR (izquierda y derecha)
    cout << (char)174 << endl;
}

int accionarCursorConfirmacion(int x, int tecla, int limiteCursor)
{
    switch(tecla) /// VALORES EN ASCII
    {
    case rlutil::KEY_LEFT: /// IZQUIERDA
    {
        rlutil::locate(28 + x * 22, 9);
        cout << " " << endl;
        x--;
        if (x < 0) x = limiteCursor;
        break;
    }
    case rlutil::KEY_RIGHT: /// DERECHA
    {
        rlutil::locate(28 + x * 22, 9);
        cout << " " << endl;
        x++;
        if(x > limiteCursor) x = 0;
        break;
    }
    } /// FIN SWITCH
    return x;
}

int mostrarMenuPrincipal(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 29);
    bordesMenu(24, 6, 29);
    separarMenues(24, 7, 29);
    for (int i = 0; i < 7; i ++) bordesMenu(24, 8 + i, 29);
    parteAbajoMenu(24, 15, 29);


    resaltarMenu("M E N U   P R I N C I P A L", 26, 6, false);
    resaltarMenu("INGRESO DE USUARIOS", 30, 9, y == 0);
    resaltarMenu("MENUES  DE  GESTION", 30, 11, y == 1);
    resaltarMenu("SALIR  DEL PROGRAMA", 30, 13, y == 2);


    mostrarCursor(28, 50, 9, y);
    int tecla = rlutil::getkey();
    if(tecla == 1) /// NO SE PASA A LA FUNCION PORQUE TIRA ERROR
    {
        switch(y)
        {
        case 0:
        {
            opcionMenu = 1; /// INGRESA CLIENTE AL GIMNASIO
            break;
        }
        case 1:
        {
            opcionMenu = 2; /// MANEJO DE DATOS
            break;
        }
        case 2:
        {
            opcionMenu = 0;
            break; /// SALIDA DEL PROGRAMA
        }
        }
    }
    else if(tecla > 13) y = accionarCursor(y, tecla, 2);

    return opcionMenu;

}
