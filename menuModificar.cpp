#include <iostream>
#include "menuModificar.h"

using namespace std;

int imprimirModificar()
{
    int opcModificar;
    cout << "¿Que archivo queres modificar?" << endl;
    cout << "1. Clientes" << endl;
    cout << "2. Actividades" << endl;
    cout << "3. Ficha Medica" << endl;
    cout << "0. Salir" << endl;
    cout << "Elegir opcion: ";
    cin >> opcModificar;
    return opcModificar;
}

void menuModificar()
{
    int opcModificar = imprimirModificar();

    switch(opcModificar)
    {
    case 1:
    {
        cout << "Elegiste Cliente" << endl;
        break;
    }
    case 2:
    {
        cout << "Elegiste Actividad" << endl;
        break;
    }
    case 3:
    {
        cout << "Elegiste Ficha Medica" << endl;
        break;
    }
    case 0:
    {
        cout << "Saliendo...." << endl;
        return;
    }
    }
}
