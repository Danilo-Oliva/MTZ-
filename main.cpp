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
    rlutil::hidecursor();
    int opcion_menu, y = 0;
    while(true)
    {


        rlutil::locate(34,6);
        cout << "MENU DE INICIO" << endl;
        rlutil::locate(30,9);
        cout << "INGRESO DE USUARIOS" << endl;
        rlutil::locate(30,10);
        cout << " GESTIONAR CLIENTES" << endl;
        rlutil::locate(30,11);
        cout << "       SALIR       " << endl;
        rlutil::locate(30,12);

        /// CURSOR
        rlutil::locate(28,9 + y); ///y CONTROLA LA POSICION DEL CURSOR (arriba y abajo)
        cout << (char)175 << endl;


    switch(rlutil::getkey()) /// VALORES EN ASCII
    {
        case 14: /// ARRIBA
        {
            rlutil::locate(28,9 + y);
            cout << " " << endl;
            y--;
            if (y < 0) y = 0; ///IMPIDE IR A OPCIONES POR ENCIMA DEL MENU
            break;
        }
        case 15: /// ABAJO
        {
            rlutil::locate(28,9 + y);
            cout << " " << endl;
            y++;
            if(y > 2) y = 2; ///IMPIDE IR A OPCIONES POR DEBAJO DEL MENU
            break;
        }
        case 1: /// ENTER
        {
            switch(y)
            {
            case 0:
                {
                    opcion_menu = 1; /// INGRESA CLIENTE AL GIMNASIO
                    break;
                }
            case 1:
                {
                    opcion_menu = 2; /// MANEJO DE DATOS
                    break;
                }
            case 2:
                {
                    opcion_menu = 0; /// SALIDA DEL PROGRAMA
                    break;
                }
            }
            break;
        }
            default:
                cout << "Esto no tendria que estar aca" << endl;
    }

/*
        switch(opcion_menu)
        {
        case 1:
            system("cls");
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
*/
    } /// FINAL WHILE TRUE
    return 0;
}
