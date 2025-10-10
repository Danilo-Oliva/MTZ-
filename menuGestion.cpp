#include <iostream>
#include "clsActividad.h"
#include "clsPersona.h"
#include "clsFichaMedica.h"
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
#include "mostrarMenu.h"
#include "menuModificar.h"
#include "rlutil.h"

using namespace std;

int menuGestion()
{
    int opcion;
    cout << "===== MENU GIMNASIO =====\n";
    cout << "1. Cargar cliente\n";
    cout << "2. Mostrar Clientes\n";
    cout << "3. Buscar cliente\n";
    cout << "4. Modificar cliente\n";
    cout << "5. Borrar cliente\n";
    cout << "0. Volver a Inicio\n";
    cout << "Ingrese opcion: ";
    cin >> opcion;
    return opcion;
}

void cargarCliente(Persona per, Actividad act, ArchivoCliente arc, ArchivoActividad arcAct)
{
    /// ---- Cargar cliente ----
    per.cargar();
    act.cargar();

    /// ---- Elegir actividad
    //GUARDAR EL CLIENTE EN EL .dat
    arc.inscribirCliente(per);
    arcAct.inscribirActividad(act);

    cout << "\nCliente cargado con exito.\n";
}

void accionarMenu()
{
    system("cls");
    //archivos
    ArchivoCliente arc;
    ArchivoActividad arcAct;

    //objetos (ya se que archivos son objetos, pero es para guiarnos)
    Persona per;
    Actividad act;

    int opcion;
    do
    {
        opcion = menuGestion();
        switch(opcion)
        {
        case 1:
        {
            system("cls");

            cargarCliente(per, act, arc, arcAct);

            system("pause");
            system("cls");
            break;
        }
        case 2:
            system("cls");

            accionarMenuMostrar();

            system("pause");
            system("cls");
            break;
        case 3:
        {
            system("cls");

            int dni;
            cout << "Ingrese DNI a buscar: ";
            cin >> dni;

            int pos = arc.buscarCliente(dni);
            if (pos >= 0)
            {
                Persona per = arc.leerArchivo(pos);
                Actividad act = arcAct.leerArchivo(pos);
                cout << "\n=== Cliente encontrado ===\n" << endl;;
                per.mostrar();
                act.mostrar();
            }
            else
            {
                cout << "No se encontro un cliente con DNI " << dni << endl;
            }

            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            system("cls");

            menuModificar();

            system("pause");
            system("cls");
            break;
        }
        case 5:
            break;
        case 0:
            cout << "\nSaliendo...\n";
            return;
        default:
            system("cls");

            cout << "\nOpcion invalida.\n";

            system("pause");
            system("cls");
        }
    }
    while(opcion != 0);
}
