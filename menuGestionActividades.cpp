#include<iostream>
#include "rlutil.h"
#include "clsArchivoActividad.h"
#include "menuModificarActividad.h"
#include "clsActividad.h"
#include "menusVisual.h"
#include "tunearMenu.h"

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
    ArchivoActividad arch("actividades.dat");

    int cantAct = arch.contarActividades();

    if(cantAct == 0){
        mostrarMensaje("No hay actividades registradas", rlutil::YELLOW);
        rlutil::cls();
        imprimirMenuActividades();
        return;
    }

    int opcion, y = 0;
    imprimirMenuListarActividades();
    do {
        opcion = -1;

        opcion = interactuarMenuListarActividades(opcion, y);

        switch (opcion)
        {
        case 1:
            rlutil::cls();

            arch.listar(1);

            rlutil::anykey();
            rlutil::cls();            imprimirMenuListarActividades();
            break;
        case 2:
            rlutil::cls();

            arch.listar(2);

            rlutil::anykey();
            rlutil::cls();            imprimirMenuListarActividades();
            break;
        case 3:
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
void modificarEstadoActividad()
{
    rlutil::cls();
    Actividad act;
    ArchivoActividad archAct("actividades.dat", act);

    int id = pedirIdActividad();
    int pos = archAct.buscarActividad(id);
    if (pos == -1)
    {
        mostrarMensaje("Actividad no encontrada.", rlutil::LIGHTRED);
        rlutil::anykey();
        return;
    }

    Actividad actividad = archAct.leerArchivo(pos);

    bool salir = false;
    while (!salir)
    {
        rlutil::cls();

        parteArribaMenu(20, 5, 52);
        for (int i = 0; i < 6; i++) bordesMenu(20, 6 + i, 52);
        parteAbajoMenu(20, 12, 52);
        escribirTexto("MODIFICAR ESTADO ACTIVIDAD", 26, 6);

        rlutil::locate(22, 8); cout << "ID         : " << actividad.getIdAct();
        rlutil::locate(22, 9); cout << "Actividad  : " << actividad.getNombre();
        rlutil::locate(22, 10); cout << "Cuota base : $" << actividad.getCuotaBase();
        rlutil::locate(22, 11); cout << "Estado     : " << (actividad.getEstado() ? "Activa" : "Inactiva");

        rlutil::locate(22, 13);
        cout << "Presione ENTER para cambiar estado o ESC para volver.";

        int tecla = rlutil::getkey();
        if (tecla == rlutil::KEY_ENTER)
        {
            actividad.setEstado(!actividad.getEstado());
        }
        else if (tecla == rlutil::KEY_ESCAPE)
        {
            salir = true;
            rlutil::cls();
            imprimirMenuActividades();
        }
    }
}

void menuActividades()
{
    ArchivoActividad arch("actividades.dat");
    Actividad act;
    int opcion, y = 0;

    rlutil::cls();
    imprimirMenuActividades();

    do
    {
        opcion = -1;

        interactuarMenuActividades(opcion, y);

        switch (opcion)
        {
        case 1:
            ingresarNuevaActividad();
            break;

        case 2:
            menuModificarActividad();
            break;

        case 3:
            modificarEstadoActividad();
            break;
        case 4:
            menuListarActividades();
            break;
        }
    }
    while (opcion != 0);
    rlutil::cls();
    imprimirMenuGestion();
}
