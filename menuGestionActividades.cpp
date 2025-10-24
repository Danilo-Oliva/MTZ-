#include<iostream>
#include "rlutil.h"
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
    rlutil::cls();
    imprimirMenuActividades();
}
void menuListarActividades() {
    ArchivoActividad arch("actividad.dat");
    int opcion, y = 0;

    do {
        rlutil::cls();
        opcion = -1;

        opcion = mostrarMenuListarActividades(opcion, y);

        switch (opcion)
        {
        case 1: // Activas
            arch.listar(1);
            rlutil::anykey();
            rlutil::cls();            break;
        case 2: // Inactivas
            arch.listar(2);
            rlutil::anykey();
            rlutil::cls();            break;
        case 3: // Todos
            arch.listar(0);
            rlutil::anykey();
            rlutil::cls();
            break;
        }
    } while (opcion != 0);
    rlutil::anykey();
    rlutil::cls();
    imprimirMenuActividades();
}
