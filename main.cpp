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

int main()
{
    rlutil::hidecursor();
    int opcion_menu = -1, y = 0;
    while(true)
    {

        resaltarMenu("MENU DE INICIO", 33, 6, false);
        resaltarMenu("INGRESO DE USUARIOS", 30, 9, y == 0);        resaltarMenu("GESTIONAR CLIENTES ", 30, 10, y == 1);        resaltarMenu("SALIR DEL PROGRAMA ", 30, 11, y == 2);

        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::LIGHTRED); ///SE ESTABLECE FONDO DE VUELTA PARA EVITAR QUE SE RESALTE TODO EL RESTO

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
                break;
    }
    ///FIN SWITCH MENU

        if (opcion_menu != -1)
        {
            switch(opcion_menu)
            {
                case 1:
                    system("cls");
                    cout << "Por ahora nada :v" << endl;
                    break;
                case 2:
                    accionarMenu();
                    break;
                case 0:
                    return 0;
            }
                    system("pause");
                    system("cls");
            opcion_menu = -1; // reset para esperar nueva tecla
        } /// CIERRA IF
    } ///FIN WHILE TRUE
}
