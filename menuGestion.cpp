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

using namespace std;

///CLIENTES
/*
void menuClientes()
{
    int opcion, y = 0;

    do
    {
        opcion = -1;


        rlutil::cls();
        opcion = mostrarMenuClientes(opcion, y);
        rlutil::cls();


        switch (opcion)
        {
        case 1:
            ingresarNuevoCliente();
            system("pause");
            break;
        case 2:
            menuModificarCliente();
            system("pause");
            break;
        case 3:
            menuListarClientes();
            break;

        case 4:
            buscarCliente();
            system("pause");
            break;
        case 5:
            system("cls");
            GestionarEstadoCliente();
            system("cls");
            break;
        case 6:
            EliminarClientePermanente();
            break;
        }
        system("cls");
    }
    while (opcion != 0);
}*/
///ACTIVIDAD
void menuActividades()
{
    ArchivoActividad arch("actividad.dat");
    Actividad act;
    int opcion, y = 0;

    do
    {
        opcion = -1;

        system("cls");
        mostrarMenuActividades(opcion, y);
        system("cls");

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
}
///MENU INSCRIPCIONES
void menuInscripciones() {
    int opcion, y = 0;
    do {
        system("cls");
        opcion = -1;

        mostrarMenuInscripciones(opcion, y);

        system("cls");

        switch (opcion) {
            case 1:
                system("cls");

                nuevaInscripcion();

                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");

                gestionarEstadoInscripcion();

                system("pause");
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
    do
    {
        system("cls");
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
            break;
        case 4:
            system("cls");
            cout << "Bob el constructor está trabajando en esta opcion." << endl;
            system("pause");
            break;
        }
        if(opcionMenu != 0) opcionMenu = -1;
    }
    while(opcionMenu != 0);
}
