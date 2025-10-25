#include<iostream>
#include "rlutil.h"
#include "clsArchivoActividad.h"
#include "clsActividad.h"
#include "menusVisual.h"

using namespace std;

void ingresarNuevaActividad()
{
    system("cls");
    ArchivoActividad arch("actividad.dat");
    Actividad act;

    int proximoID = arch.contarActividades() + 1;
    act.cargar(proximoID);
    if (arch.buscarActividadPorNombre(act.getNombre()) != -1)
    {
        mostrarMensaje("ERROR: Ya existe una actividad con ese nombre.", rlutil::LIGHTRED);
    }
    else
    {

        if (arch.inscribirActividad(act))
        {
            mostrarMensaje("Actividad guardada con exito.", rlutil::LIGHTGREEN);
        }
        else
        {
            mostrarMensaje("Error al guardar la actividad.", rlutil::LIGHTRED);
        }
    }
    rlutil::cls();
    imprimirMenuActividades();
}
void menuListarActividades() {
    ArchivoActividad arch("actividad.dat");
    int opcion, y = 0;
    imprimirMenuListarActividades();
    do {
        opcion = -1;

        opcion = interactuarMenuListarActividades(opcion, y);

        switch (opcion)
        {
        case 1: // Activas
            rlutil::cls();

            arch.listar(1);

            rlutil::anykey();
            rlutil::cls();            imprimirMenuListarActividades();
            break;
        case 2: // Inactivas
            rlutil::cls();

            arch.listar(2);

            rlutil::anykey();
            rlutil::cls();            imprimirMenuListarActividades();
            break;
        case 3: // Todos
            rlutil::cls();

            arch.listar(0);
            rlutil::anykey();
            rlutil::cls();

            imprimirMenuListarActividades();
            break;
        }
    } while (opcion != 0);
    rlutil::cls();
    imprimirMenuActividades();
}
