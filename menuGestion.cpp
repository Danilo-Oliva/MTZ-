#include <iostream>
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
#include "clsArchivoInscripcion.h"
#include "clsPersona.h"
#include "clsActividad.h"
#include "clsInscripcionActividad.h"
#include "menuModificarActividad.h"
#include "menuModificarCliente.h"
#include "menuGestionCliente.h"
#include "menuGestionActividades.h"
#include "rlutil.h"
#include "menusVisual.h"
#include "menuGestionCliente.h"
#include "menuGestionActividades.h"
#include "menuGestionInscripciones.h"
#include "tunearMenu.h"

using namespace std;


///ACTIVIDAD
void menuActividades()
{
    ArchivoActividad arch("actividad.dat");
    Actividad act;
    int opcion, y = 0;
    system("cls");

    parteArribaMenu(24, 5, 31);
    bordesMenu(24, 6, 31);
    separarMenues(24, 7, 31);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 31);
    parteAbajoMenu(24, 17, 31);


    escribirTexto("M E N U   A C T I V I D A D E S", 25, 6);
    escribirTexto("CREAR NUEVA ACTIVIDAD", 30, 9);
    escribirTexto("MODIFICAR   ACTIVIDAD", 30, 11);
    escribirTexto(" LISTAR  ACTIVIDADES ", 30, 13);
    escribirTexto("VOLVER A MENU GESTION", 30, 15);

    do
    {
        opcion = -1;

        mostrarMenuActividades(opcion, y);

        switch (opcion)
        {
        case 1:
            ingresarNuevaActividad();
            break;

        case 2:
            menuModificarActividad();
            break;

        case 3:
            menuListarActividades();
            break;
        }
    }
    while (opcion != 0);
        system("cls");
}
///MENU INSCRIPCIONES
void menuInscripciones() {
    int opcion, y = 0;
        system("cls");
    parteArribaMenu(24, 5, 38);
    bordesMenu(24, 6, 38);
    separarMenues(24, 7, 38);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 38);
    parteAbajoMenu(24, 17, 38);


    escribirTexto("M E N U    I N S C R I P C I O N E S", 26, 6);
    escribirTexto(" INGRESAR NUEVA INSCRIPCION ", 30, 9);
    escribirTexto("CAMBIAR  ESTADO  INSCRIPCION", 30, 11);
    escribirTexto(" LISTAR  LAS  INSCRIPCIONES ", 30, 13);
    escribirTexto("VOLVER   AL   MENU   GESTION", 30, 15);

    do {
        opcion = -1;

        mostrarMenuInscripciones(opcion, y);


        switch (opcion) {
            case 1:
                system("cls");

                nuevaInscripcion();

                rlutil::anykey();
                system("cls");
                break;
            case 2:
                system("cls");

                gestionarEstadoInscripcion();

                rlutil::anykey();
                system("cls");
                break;
            case 3:
                system("cls");

                menuListarInscripciones();

                system("cls");
                break;
        }

    } while (opcion != 0);
}





///MENU PRINCIPAL
void accionarMenu()
{
    int opcionMenu = -1, y = 0;
    system("cls");

    parteArribaMenu(24, 5, 37);
    bordesMenu(24, 6, 37);
    separarMenues(24, 7, 37);
    for (int i = 0; i < 11; i ++) bordesMenu(24, 8 + i, 37);
    parteAbajoMenu(24, 19, 37);

    escribirTexto("M E N U  D E  G E S T I O N", 30, 6);
    escribirTexto("GESTIONAR    LOS   CLIENTES", 30, 9);
    escribirTexto("GESTIONAR  LAS  ACTIVIDADES", 30, 11);
    escribirTexto("GESTIONAR LAS INSCRIPCIONES", 30, 13);
    escribirTexto("  REPORTES  DEL  PROGRAMA  ", 30, 15);
    escribirTexto("  VOLVER AL MENU PRICIPAL  ", 30, 17);

    do
    {

        mostrarMenuGestion(opcionMenu, y);

        switch(opcionMenu)
        {
        case 1:
            menuClientes();
            break;
        case 2:
            menuActividades();
            break;
        case 3:
            menuInscripciones();
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "Bob el constructor está trabajando en esta opcion." << endl;
            rlutil::anykey();
            system("cls");
            break;
        }
        if(opcionMenu != 0) opcionMenu = -1;
    }
    while(opcionMenu != 0);
    system("cls");
}
