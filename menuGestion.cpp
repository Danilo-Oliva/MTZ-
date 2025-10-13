#include <iostream>
#include "clsPersona.h"
#include "clsActividad.h"
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
#include "menuModificarCliente.h"
#include "menuModificarActividad.h"
#include "rlutil.h"

using namespace std;

void mostrarMenuGestion()
{
    cout << "===============================" << endl;
    cout << "        MENU PRINCIPAL" << endl;
    cout << "===============================" << endl;
    cout << "1. Gestion de Clientes" << endl;
    cout << "2. Gestion de Actividades" << endl;
    cout << "3. Gestion de Inscripciones (PROXIMAMENTE SOLO EN CINES Y EN 3D)" << endl;
    cout << "4. Reportes (PROXIMAMENTE SOLO EN CINES Y EN 3D)" << endl;
    cout << "-------------------------------" << endl;
    cout << "0. SALIR DEL PROGRAMA" << endl;
    cout << "===============================" << endl;
    cout << "Ingrese opcion: ";
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
        cout << "3. Listar Clientes" << endl;
        cout << "4. Buscar Cliente por DNI" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case 1: {
                per.cargar(); // Carga los datos de la persona
                int proximoNroSocio = arch.contarClientes() + 1;
                per.setNumeroSocio(proximoNroSocio);

                if (arch.inscribirCliente(per)) {
                    cout << "Cliente guardado con exito. Nro de Socio: " << proximoNroSocio << endl;
                } else {
                    cout << "Error al guardar el cliente." << endl;
                }
                break;
            }
            case 2:
                menuModificarCliente();
                break;
            case 3:
                arch.listar();
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
                break;
            }
        }
        if (opcion != 0) system("pause");
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
                // 1. Calculamos cuál será el próximo ID
                int proximoID = arch.contarActividades() + 1;
                // 2. Se lo pasamos a la función cargar
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
    int opcion;
    do
    {
        system("cls");
        mostrarMenuGestion();
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            menuClientes();
            break;
        case 2:
            menuActividades();
            break;
        case 3:
            system("cls");
            cout << "Modulo de inscripciones en construccion." << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Modulo de reportes en construccion." << endl;
            system("pause");
            break;
        case 0:
            cout << "\nSaliendo del programa...\n";
            break;
        default:
            cout << "\nOpcion invalida.\n";
            system("pause");
        }
    }
    while(opcion != 0);
}
