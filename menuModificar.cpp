#include <iostream>
#include "menuModificar.h"

using namespace std;

int imprimirModificar()
{
    int opcModificar;
    cout << "Que archivo desea modificar?" << endl;
    cout << "1. Clientes" << endl;
    cout << "2. Actividades" << endl;
    cout << "0. Salir" << endl;
    cout << "Elegir opcion: ";
    cin >> opcModificar;
    return opcModificar;
}

void menuModificar()
{
    int opcModificar;
    do{
        opcModificar = imprimirModificar();
        switch(opcModificar)
        {
        case 1:
            cout << "Elegiste Cliente" << endl;
            break;
        case 2:
            cout << "Elegiste Actividad" << endl;
            break;
        case 0:
            cout << "Saliendo...." << endl;
            break;
        default:
            system("cls");

            cout << "Opcion incorrecta" << endl;

            system("pause");
            system("cls");
            break;
        }
    }while(opcModificar != 0);
}
