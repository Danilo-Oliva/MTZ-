#include <iostream>
#include "cargarCadena.h"
#include "clsActividad.h"
#include "clsDomicilio.h"
#include "clsFecha.h"
#include "clsPersona.h"
#include "clsFichaMedica.h"
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
#include "clsArchivoFichaMedica.h"
#include "mostrarMenu.h"
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
    //archivos
    ArchivoCliente arc;
    ArchivoActividad arcAct;
    ArchivoFichaMedica arcFM;

    //objetos (ya se que archivos son objetos, pero es para guiarnos)
    Persona per;
    Actividad act;
    FichaMedica fm;

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
            per.cargar();
            act.cargar();
            fm.cargar();

            /// ---- Elegir actividad
            //GUARDAR EL CLIENTE EN EL .dat
            arc.inscribirCliente(per);
            arcAct.inscribirActividad(act);
            arcFM.inscribirFichaMedica(fm);

            cout << "\nCliente cargado con exito.\n";
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
        case 3:{
            system("cls");

            int dni;
            cout << "Ingrese DNI a buscar: ";
            cin >> dni;

            int pos = arc.buscarCliente(dni);
            if (pos >= 0)
            {
                Persona per = arc.leerArchivo(pos);
                Actividad act = arcAct.leerArchivo(pos);
                FichaMedica fm = arcFM.leerArchivo(pos);
                cout << "\n=== Cliente encontrado ===\n" << endl;;
                per.mostrar();
                act.mostrar();
                fm.mostrar();
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
            int dniBuscar;
            cout << "Ingrese DNI del cliente a modificar: ";
                cin >> dniBuscar;
                int pos = arc.buscarCliente(dniBuscar);
                if (pos < 0)
                {
                    cout << "No hay cliente con el DNI: " << dniBuscar << endl;
                    return;
                }
                Persona per = arc.leerArchivo(pos);
                char nuevoEmail[30];
                cout << "Ingrese el mail: ";
                    cin >> nuevoEmail;
                per.setEmail(nuevoEmail);
                arc.modificarCliente(per, pos);
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
