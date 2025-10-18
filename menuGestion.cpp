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

int mostrarMenuGestion(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 37);
    bordesMenu(24, 6, 37);
    separarMenues(24, 7, 37);
    for (int i = 0; i < 11; i ++) bordesMenu(24, 8 + i, 37);
    parteAbajoMenu(24, 19, 37);


    resaltarMenu("M E N U  D E  G E S T I O N", 30, 6, false);
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

int mostrarMenuClientes(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 33);
    bordesMenu(24, 6, 33);
    separarMenues(24, 7, 33);
    for (int i = 0; i < 14; i ++) bordesMenu(24, 8 + i, 33);
    parteAbajoMenu(24, 22, 33);


    resaltarMenu("M E N U  D E  C L I E N T E S", 27, 6, false);
    resaltarMenu("INGRESAR NUEVO CLIENTE ", 30, 9, y == 0);
    resaltarMenu("  MODIFICAR  CLIENTES  ", 30, 11, y == 1);
    resaltarMenu("    LISTAR   CLIENTES   ", 30, 13, y == 2);
    resaltarMenu("BUSCAR CLIENTES POR DNI", 30, 15, y == 3);
    resaltarMenu("   ESTADO   CLIENTES   ", 30, 17, y == 4);
    resaltarMenu("  BORRAR  UN  CLIENTE  ",30, 19, y == 5 );
    resaltarMenu("VOLVER AL  MENU GESTION", 30, 21, y == 6);


    mostrarCursor(28, 54, 9, y);
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
            opcionMenu = 5;
            break;
        }
        case 5:
        {
            opcionMenu = 6;
            break;
        }
        case 6:
        {
            opcionMenu = 0;
            break;
        }
        }
    }
    else if(tecla > 13) y = accionarCursor(y, tecla, 6);

    return opcionMenu;

}


int mostrarMenuActividades(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 31);
    bordesMenu(24, 6, 31);
    separarMenues(24, 7, 31);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 31);
    parteAbajoMenu(24, 17, 31);


    resaltarMenu("M E N U   A C T I V I D A D E S", 25, 6, false);
    resaltarMenu("CREAR NUEVA ACTIVIDAD", 30, 9, y == 0);
    resaltarMenu("MODIFICAR   ACTIVIDAD", 30, 11, y == 1);
    resaltarMenu(" LISTAR  ACTIVIDADES ", 30, 13, y == 2);
    resaltarMenu("VOLVER A MENU GESTION", 30, 15, y == 3);


    mostrarCursor(28, 52, 9, y);
    int tecla = rlutil::getkey();
    if(tecla == 1)
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
            opcionMenu = 3;
            break;
        }
        case 3:
            {
                opcionMenu = 0; /// SALIDA DEL PROGRAMA
                break;
            }
        }
    }
    else if(tecla > 13) y = accionarCursor(y, tecla, 3);

    return opcionMenu;

}

void GestionarEstadoCliente() {
    ArchivoCliente arch("clientes.dat");
    int dni, pos;
    char confirmacion;

    cout << "Ingrese el DNI del cliente para gestionar su estado: ";
    cin >> dni;

    pos = arch.buscarCliente(dni);
    if (pos == -1) {
        cout << "ERROR: No se encontro un cliente con ese DNI." << endl;
        system("pause");
        return;
    }

    Persona per = arch.leerArchivo(pos);
    system("cls");
    cout << "--- CLIENTE ENCONTRADO ---" << endl;
    per.mostrar();
    cout << "--------------------------" << endl << endl;


    if (per.getEstado() == false) {

        cout << "Este cliente se encuentra INACTIVO en el sistema." << endl;
        cout << "Desea reactivarlo en este momento? (S/N): ";
        cin >> confirmacion;

        if (confirmacion == 'S' || confirmacion == 's') {
            per.setEstado(true);
            if (arch.modificarCliente(per, pos)) {
                cout << "\nCliente reactivado con exito!" << endl;
            } else {
                cout << "\nERROR: No se pudo modificar el registro." << endl;
            }
        } else {
            cout << "\nOperacion cancelada. El cliente permanece inactivo." << endl;
        }
    } else {
        cout << "\nEste cliente se encuentra ACTIVO." << endl;
        cout << "Esta seguro de que desea dar de baja a este cliente? (S/N): ";
        cin >> confirmacion;

        if (confirmacion == 'S' || confirmacion == 's') {
            per.setEstado(false);
            if (arch.modificarCliente(per, pos)) {
                cout << "\nCliente dado de baja con exito." << endl;
            } else {
                cout << "\nERROR: No se pudo modificar el registro." << endl;
            }
        } else {
            cout << "\nLa operacion ha sido cancelada." << endl;
        }
    }
    system("pause");
}
void EliminarClientePermanente() {
    ArchivoCliente arch("clientes.dat");
    int dni;
    char confirmacion;

    cout << "--- ELIMINACION PERMANENTE DE CLIENTE ---" << endl;
    cout << "Ingrese el DNI del cliente a ELIMINAR: ";
    cin >> dni;

    int pos = arch.buscarCliente(dni);
    if (pos == -1) {
        cout << "\nERROR: No se encontro un cliente con ese DNI." << endl;
        system("pause");
        return;
    }

    Persona per = arch.leerArchivo(pos);
    cout << "\nSe encontro el siguiente cliente:" << endl;
    per.mostrar();

    cout << "\n\nADVERTENCIA: Esta accion es IRREVERSIBLE y eliminara al cliente del sistema para siempre." << endl;
    cout << "Esta absolutamente seguro de que desea continuar? (S/N): ";
    cin >> confirmacion;

    if (confirmacion == 'S' || confirmacion == 's') {
        if (arch.eliminarCliente(dni)) {
            cout << "\nCliente eliminado permanentemente del sistema." << endl;
        } else {
            cout << "\nERROR: No se pudo eliminar el registro." << endl;
        }
    } else {
        cout << "\nOperacion cancelada." << endl;
    }
    system("pause");
}
void menuListarClientes() {
    ArchivoCliente arch("clientes.dat");
    int opcion;

    do {
        system("cls");
        cout << "--- OPCIONES DE LISTADO DE CLIENTES ---" << endl;
        cout << "1. Listar Clientes Activos" << endl;
        cout << "2. Listar Clientes Inactivos" << endl;
        cout << "3. Listar Todos" << endl;
        cout << "---------------------------------------" << endl;
        cout << "0. Volver al menu anterior" << endl;
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;
        system("cls");

        if (opcion > 0 && opcion < 4) {
            // Si el usuario elige 1 -> modo 1 (activos)
            // Si el usuario elige 2 -> modo 2 (inactivos)
            // Si el usuario elige 3 -> modo 0 (todos)
            arch.listar(opcion % 3);
            system("pause");
        } else if (opcion != 0) {
            cout << "Opcion incorrecta." << endl;
            system("pause");
        }
    } while (opcion != 0);
}

void menuClientes() {
    ArchivoCliente arch("clientes.dat");
    Persona per;
    int opcion, y = 0;

    do {
        opcion = -1;


        rlutil::cls();
        opcion = mostrarMenuClientes(opcion, y);
        rlutil::cls();


        switch (opcion) {
            case 1: {
                int dni, pos;
                cout << "--- NUEVO CLIENTE ---" << endl;
                cout << "Ingrese el DNI del nuevo cliente: ";
                cin >> dni;

                pos = arch.buscarCliente(dni);
                if (pos != -1) {
                    cout << "\nERROR: Ya existe un cliente registrado con el DNI " << dni << "." << endl;
                } else {
                    Persona per;
                    per.setDNI(dni);
                    per.cargar();
                    if (arch.inscribirCliente(per)) {
                        cout << "\nCliente guardado con exito." << endl;
                    } else {
                        cout << "\nError al guardar el cliente." << endl;
                    }
                }

                system("pause");
                break;
            }
            case 2:
                menuModificarCliente();

                system("pause");
                break;
            case 3:
                menuListarClientes();

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

                GestionarEstadoCliente();
                system("cls");
                break;
            case 6:
                EliminarClientePermanente();
                break;
        }
        system("cls");
    } while (opcion != 0);
}

void menuActividades() {
    ArchivoActividad arch("actividad.dat");
    Actividad act;
    int opcion, y = 0;

    do {
        opcion = -1;

        system("cls");
        mostrarMenuActividades(opcion, y);
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
                system("pause");
                break;
        }
    } while (opcion != 0);
}


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
            system("cls");

            menuInscripciones();
            break;
        case 4:
            system("cls");
            cout << "Bob el constructor esta chambeando en esta opcion." << endl;
            system("pause");

            break;
        }
        if(opcionMenu != 0) opcionMenu = -1;
    }
    while(opcionMenu != 0);
}
