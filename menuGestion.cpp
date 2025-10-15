#include <iostream>
#include "clsPersona.h"
#include "clsActividad.h"
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
#include "menuInscripciones.h"
#include "menuModificarCliente.h"
#include "menuModificarActividad.h"
#include "tunearMenu.h"
#include "rlutil.h"

using namespace std;

int menuGestion(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 35);
    bordesMenu(24, 6, 35);
    separarMenues(24, 7, 35);
    for (int i = 0; i < 11; i ++) bordesMenu(24, 8 + i, 35);
    parteAbajoMenu(24, 19, 35);


    resaltarMenu("M E N U  D E  G E S T I O N", 29, 6, false);
    resaltarMenu("GESTIONAR    LOS   CLIENTES", 30, 9, y == 0);
    resaltarMenu("GESTIONAR  LAS  ACTIVIDADES", 30, 11, y == 1);
    resaltarMenu("GESTIONAR LAS INSCRIPCIONES", 30, 13, y == 2);
    resaltarMenu("  REPORTES  DEL  PROGRAMA  ", 30, 15, y == 3);
    resaltarMenu("  VOLVER AL MENU PRICIPAL  ", 30, 17, y == 4);


    mostrarCursor(28, 58, 9, y);
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
            opcionMenu = 3; /// MANEJO DE DATOS
            break;
        }case 3:
        {
            opcionMenu = 4; /// MANEJO DE DATOS
            break;
        }
        case 4:
        {
            opcionMenu = 0;
            break; /// SALIDA DEL PROGRAMA
        }
        }
    }
    else if(tecla > 13) y = accionarCursor(y, tecla, 4);

    return opcionMenu;

}


/*void mostrarMenuGestion()
{
    cout << "===============================" << endl;
    cout << "        MENU PRINCIPAL" << endl;
    cout << "===============================" << endl;
    cout << "1. Gestion de Clientes" << endl;
    cout << "2. Gestion de Actividades" << endl;
    cout << "3. Gestion de Inscripciones" << endl;
    cout << "4. Reportes (PROXIMAMENTE SOLO EN CINES Y EN 3D)" << endl;
    cout << "-------------------------------" << endl;
    cout << "0. SALIR DEL PROGRAMA" << endl;
    cout << "===============================" << endl;
    cout << "Ingrese opcion: ";
}
    */

void darDeBajaCliente() {
    ArchivoCliente arch("clientes.dat");
    int dni, pos;
    char confirmacion;

    cout << "Ingrese el DNI del cliente a dar de baja: ";
    cin >> dni;

    pos = arch.buscarCliente(dni);
    if (pos == -1) {
        cout << "ERROR: No se encontro un cliente con ese DNI." << endl;
        system("pause");
        return;
    }

    Persona per = arch.leerArchivo(pos);
    cout << "Se encontro el siguiente cliente:" << endl;
    per.mostrar();

    if (per.getEstado() == false) {
        cout << "\nEste cliente ya se encuentra inactivo." << endl;
        system("pause");
        return;
    }

    cout << "\nEsta seguro de que desea dar de baja a este cliente? (S/N): ";
    cin >> confirmacion;

    if (confirmacion == 'S' || confirmacion == 's') {
        per.setEstado(false);
        if (arch.modificarCliente(per, pos)) {
            cout << "Cliente dado de baja con exito." << endl;
        } else {
            cout << "ERROR: No se pudo modificar el registro." << endl;
        }
    } else {
        cout << "La operacion ha sido cancelada." << endl;
    }
    system("pause");
}

void menuClientes() {
    ArchivoCliente arch("clientes.dat");
    Persona per;
    int opcion;

    do {
        system("cls");
        cout << "--- GESTION DE CLIENTES ---" << endl;
        cout << "1. Nuevo Cliente" << endl;
        cout << "2. Modificar Cliente" << endl;
        cout << "3. Listar Clientes Activos" << endl;
        cout << "4. Buscar Cliente por DNI" << endl;
        cout << "5. Aniquilar cliente" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case 1: {
                per.cargar();
                int proximoNroSocio = arch.contarClientes() + 1;
                per.setNumeroSocio(proximoNroSocio);

                if (arch.inscribirCliente(per)) {
                    cout << "Cliente guardado con exito. Nro de Socio: " << proximoNroSocio << endl;
                } else {
                    cout << "Error al guardar el cliente." << endl;
                }
                system("pause");
                break;
            }
            case 2:
                menuModificarCliente();
                system("pause");
                break;
            case 3:
                arch.listar();
                system("pause");
                break;
            case 4: {
                int dni, pos;
                cout << "Ingrese el DNI a buscar: ";
                cin >> dni;
                pos = arch.buscarCliente(dni);
                if (pos != -1) {
                    cout << "Cliente encontrado:" << endl;
                    per = arch.leerArchivo(pos);
                    per.mostrar();
                } else {
                    cout << "No se encontro cliente con el DNI " << dni << endl;
                }
                system("pause");
                break;
            }
            case 5:
                system("cls");

                darDeBajaCliente();

                system("cls");
        }
    } while (opcion != 0);
}

void menuActividades() {
    ArchivoActividad arch("actividad.dat");
    Actividad act;
    int opcion;

    do {
        system("cls");
        cout << "--- GESTION DE ACTIVIDADES ---" << endl;
        cout << "1. Nueva Actividad" << endl;
        cout << "2. Modificar Actividad" << endl;
        cout << "3. Listar Actividades" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case 1: {
                int proximoID = arch.contarActividades() + 1;
                act.cargar(proximoID);

                if (arch.inscribirActividad(act)) {
                    cout << "Actividad guardada con exito." << endl;
                } else {
                    cout << "Error al guardar la actividad." << endl;
                }
                break;
            }
            case 2:
                menuModificarActividad();
                break;
            case 3:
                arch.listar();
                break;
        }
        if (opcion != 0) system("pause");
    } while (opcion != 0);
}


void accionarMenu()
{
    int opcionMenu = -1, y = 0;
    do
    {
        system("cls");
        menuGestion(opcionMenu, y);

        switch(opcionMenu)
        {
        case 1:
            menuClientes();
            break;
        case 2:
            menuActividades();
            break;
        case 3:
            system("cls");

            menuInscripciones();

            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Modulo de reportes en construccion." << endl;
            system("pause");
            break;
        }
        if(opcionMenu != 0) opcionMenu = -1;
    }
    while(opcionMenu != 0);
}
