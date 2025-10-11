#include <iostream>
#include <cstring>
#include "clsArchivoCliente.h"
#include "clsPersona.h"
#include "cargarCadena.h"

using namespace std;

int imprimirModificarCliente()
{
    int opcion;
    cout << "===============================" << endl;
    cout << "  ATRIBUTO A MODIFICAR" << endl;
    cout << "===============================" << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Apellido" << endl;
    cout << "3. Telefono" << endl;
    cout << "4. Email" << endl;
    cout << "5. Fecha de Nacimiento" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "===============================" << endl;
    cout << "seleccione una opcion: ";
    cin >> opcion;

    return opcion;
}

void menuModificarCliente()
{
    ArchivoCliente arch("clientes.dat");
    Persona per;
    int dni, pos;
    int opc;

    system("cls");

    cout << "Ingrese el DNI del cliente a modificar: ";
    cin >> dni;

    pos = arch.buscarCliente(dni);

    if (pos == -1)
    {
        cout << "No se encontro un cliente con el DNI ingresado." << endl;
        return;
    }

    per = arch.leerArchivo(pos);
    cout << endl << "CLIENTE ENCONTRADO:" << endl;
    per.mostrar();
    cout << endl;


    do
    {
        opc = imprimirModificarCliente();
        system("cls");

        switch(opc)
        {
        case 1:
            {
                system("cls");

                char nuevoNombre[30];
                cout << "Ingrese el nuevo nombre: ";
                cargarCadena(nuevoNombre, 29);
                per.setNombre(nuevoNombre);

                system("pause");
                system("cls");
            }
            break;
        case 2:
            {
                system("cls");

                char nuevoApellido[30];
                cout << "Ingrese el nuevo apellido: ";
                cargarCadena(nuevoApellido, 29);
                per.setApellido(nuevoApellido);

                system("pause");
                system("cls");
            }
            break;
        case 3:
            {
                system("cls");

                char nuevoTelefono[15];
                cout << "Ingrese el nuevo telefono: ";
                cargarCadena(nuevoTelefono, 14);
                per.setTelefono(nuevoTelefono);

                system("pause");
                system("cls");
            }
            break;
        case 4:
            {
                system("cls");

                char nuevoEmail[30];
                cout << "Ingrese el nuevo email: ";
                cargarCadena(nuevoEmail, 29);
                per.setEmail(nuevoEmail);

                system("pause");
                system("cls");
            }
            break;
        case 5:
            {
                system("cls");

                Fecha nuevaFecha;
                cout << "Ingrese la nueva fecha de nacimiento: " << endl;
                nuevaFecha.cargar();
                per.setFechaNacimiento(nuevaFecha);

                system("pause");
                system("cls");
            }
            break;
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            return;
        default:
            cout << "Opcion incorrecta. Intente de nuevo." << endl;
            break;

            system("pause");
            system("cls");
        }

        if (opc >= 1 && opc <= 5)
        {
             if(arch.modificarCliente(per, pos))
             {
                 cout << "Cliente modificado con exito" << endl;
             }
             else
             {
                 cout << "Error al modificar el cliente." << endl;
             }
        }
        cout << endl;

        system("pause");
        system("cls");

        cout << "DATOS ACTUALIZADOS:" << endl;
        per = arch.leerArchivo(pos);
        per.mostrar();
        cout << endl;


    } while (opc != 0);
}
