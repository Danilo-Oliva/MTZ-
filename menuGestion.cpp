#include <iostream>
#include "cargarCadena.h"
#include "clsActividad.h"
#include "clsDomicilio.h"
#include "clsFecha.h"
#include "clsPersona.h"
#include "clsFichaMedica.h"
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
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

void accionarMenu()
{
    system("cls");
    ArchivoCliente arc;
    ArchivoActividad arcAct;
    Cliente cli;
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
            /// ---- Cargar cliente ----
            cli.p1.cargar();

            /// ---- Elegir actividad
            //GUARDAR EL CLIENTE EN EL .TXT
            arc.inscribirCliente(cli);

            act.cargar();
            arcAct.inscribirActividad(act);

            cout << "\nCliente cargado con exito.\n";
            system("pause");
            system("cls");
            break;
        }
        case 2:
            system("cls");
            int opc_mostrar;
            cout << "¿Que archivo quiere mostrar?" << endl;
            cout << "1. Mostrar Cliente" << endl;
            cout << "2. Mostrar Actividad" << endl;
            cout << "3. Mostrar Ficha Medica" << endl;
            cout << "0. Salir del menu" << endl;
            cout << "Elegir opcion: ";
            cin >> opc_mostrar;
            switch(opc_mostrar)
            {
            case 1:
                arc.listar();
                break;
            case 2:
                arcAct.listar();
                break;
            case 3:
                /// PONER ACA MOSTRAR FICHA MEDICA ///
                break;
            case 0:
                cout << "Saliendo... " << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
            }
            system("pause");
            system("cls");
            break;
        case 3:{
            system("cls");

            int dni;
            cout << "Ingrese DNI a buscar: ";
            cin >> dni;

            int pos = arc.buscarCliente(dni);
            if (pos >= 0)
            {
                Cliente cli = arc.leerArchivo(pos);
                cout << "\n=== Cliente encontrado ===\n";
                cli.p1.mostrar();
                cli.act.mostrar();
                cli.fm.mostrar();
            }
            else
            {
                cout << "No se encontró un cliente con DNI " << dni << endl;
            }

            system("pause");
            system("cls");
            break;
        }
        case 4:
            {
            system("cls");
            int dniBuscar;
            cout << "Ingrese DNI del cliente a modificar: ";
                cin >> dniBuscar;
                int pos = arc.buscarCliente(dniBuscar);
                if (pos < 0)
                {
                    cout << "No hay cliente con el DNI: " << dniBuscar << endl;
                    return;
                }
                Cliente cli = arc.leerArchivo(pos);
                char nuevoEmail[30];
                cout << "Ingrese el mail: ";
                    cin >> nuevoEmail;
                cli.p1.setEmail(nuevoEmail);
                arc.modificarCliente(cli, pos);
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
            cout << "\nOpcion invalida.\n";
        }
    }
    while(opcion != 0);
}
