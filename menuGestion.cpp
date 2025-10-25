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

    rlutil::cls();
    imprimirMenuActividades();

    do
    {
        opcion = -1;

        interactuarMenuActividades(opcion, y);

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
    rlutil::cls();
    imprimirMenuGestion();
}
///MENU INSCRIPCIONES
void menuInscripciones() {
    int opcion, y = 0;
    system("cls");

    imprimirMenuInscripciones();

    do {
        opcion = -1;

        interactuarMenuInscripciones(opcion, y);

        switch (opcion) {
            case 1:
                system("cls");

                nuevaInscripcion();

                rlutil::anykey();
                system("cls");
                imprimirMenuInscripciones();

                break;
            case 2:
                system("cls");

                gestionarEstadoInscripcion();

                rlutil::anykey();
                system("cls");
                imprimirMenuInscripciones();

                break;
            case 3:
                menuListarInscripciones();

                rlutil::anykey();
                system("cls");
                imprimirMenuInscripciones();

                break;
        }

    } while (opcion != 0);
}

///MENU PRINCIPAL
void accionarMenu()
{
    int opcionMenu = -1, y = 0;
    system("cls");

    imprimirMenuGestion();

    do
    {

        interactuarMenuGestion(opcionMenu, y);

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
            imprimirMenuGestion();
            break;
        case 4:
            system("cls");
            cout << "Bob el constructor está trabajando en esta opcion." << endl;

            rlutil::anykey();
            system("cls");
            imprimirMenuGestion();

            break;
        }
        if(opcionMenu != 0) opcionMenu = -1;
    }
    while(opcionMenu != 0);
    system("cls");
}
