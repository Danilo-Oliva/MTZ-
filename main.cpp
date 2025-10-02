#include <iostream>
#include "cargarCadena.h"
#include "clsActividad.h"
#include "clsDomicilio.h"
#include "clsFecha.h"
#include "clsPersona.h"
#include "cargarDatos.h"
#include "clsFichaMedica.h"
#include "clsArchivoCliente.h"
#include "menuGestion.h"
#include "rlutil.h"

using namespace std;


int main()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTRED);
    int opcion_menu;
    while(true)
    {
        cout << "========== MENU DE INICIO ===========" << endl;
        cout << "1. Ingreso de Usuarios." << endl;
        cout << "2. Gestionar clientes." << endl;
        cout << "0. Salir del programa." << endl;
        cout << "Opcion: ";
        cin >> opcion_menu;
        system("cls");

        switch(opcion_menu)
        {
        case 1:
            cout << "Por ahora nada :v" << endl;
            break;
        case 2:
            {
            accionarMenu();
            }
            break;
        case 0:
            return 0;
        default:
            cout << "Opcion invalida." << endl;
            break;
        }
        system("pause");
        system("cls");
    } /// FINAL WHILE TRUE

    return 0;
}
