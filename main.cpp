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
#include "tunearMenu.h"

using namespace std;


int main()
{
    rlutil::hidecursor();
    int opcion_menu = -1, y = 0;
    while(true)
    {
        parteArribaMenu(24, 5);
        bordesMenu(24, 6);
        separarMenues(24, 7);
        for (int i = 0; i < 7; i ++) bordesMenu(24, 8 + i);
        parteAbajoMenu(24, 15);


        resaltarMenu("M E N U  G E S T O R", 30, 6, false);
        resaltarMenu("INGRESO DE USUARIOS", 30, 9, y == 0);
        resaltarMenu("GESTIONAR CLIENTES ", 30, 11, y == 1);
        resaltarMenu("SALIR DEL PROGRAMA ", 30, 13, y == 2);


        mostrarCursor(28, 50, 9, y);
        int tecla = rlutil::getkey();
        if(tecla == 1) /// NO SE PASA A LA FUNCION PORQUE TIRA ERROR
        {
            switch(y)
            {
                case 0:
                {
                    return 1; /// INGRESA CLIENTE AL GIMNASIO
                }
                case 1:
                {
                    return 2; /// MANEJO DE DATOS
                }
                case 2:
                {
                    return 0; /// SALIDA DEL PROGRAMA
                }
            }
        }
        else if(tecla > 13) y = accionarCursor(y, tecla);



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
