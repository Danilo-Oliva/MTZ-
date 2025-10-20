#include<iostream>
#include "clsArchivoActividad.h"
#include "clsActividad.h"
#include "menusVisual.h"

using namespace std;

void ingresarNuevaActividad()
{
    ArchivoActividad arch("actividad.dat");
    Actividad act;

    int proximoID = arch.contarActividades() + 1;
    act.cargar(proximoID);

    if (arch.inscribirActividad(act))
    {
        cout << "Actividad guardada con exito." << endl;
    }
    else
    {
        cout << "Error al guardar la actividad." << endl;
    }
}
void menuListarActividades() {
    ArchivoActividad arch("actividad.dat");
    int opcion, y = 0;

    do {
        opcion = -1;
        system("cls");

        opcion = mostrarMenuListarActividades(opcion, y);

        system("cls");

        switch (opcion)
        {
        case 1: // Activas
            arch.listar(1);
            system("pause");
            break;
        case 2: // Inactivas
            arch.listar(2);
            system("pause");
            break;
        case 3: // Todos
            arch.listar(0);
            system("pause");
            break;
        }
    } while (opcion != 0);
}
