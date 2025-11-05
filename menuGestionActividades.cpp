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
    ArchivoActividad arch("actividades.dat");
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
    rlutil::cls();
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
    ArchivoActividad arch("actividades.dat", act);

    int id = pedirIdActividad();
    int pos = arch.buscarActividad(id);
    if (pos == -1)
    {
        mostrarMensaje("Actividad no encontrada.", rlutil::LIGHTRED);
        rlutil::anykey();
        return;
    }

    Actividad actividad = arch.leerArchivo(pos);

    bool salir = false;
    int seleccion = 0;

    rlutil::cls();
    while (!salir)
    {
        escribirTexto("MODIFICAR ESTADO DE ACTIVIDAD", 5, 1);
        rlutil::locate(5, 3);
        cout << "ID ACTIVIDAD : " << actividad.getIdAct();
        rlutil::locate(5, 4);
        cout << "NOMBRE       : " << actividad.getNombre();
        rlutil::locate(5, 6);

        rlutil::locate(5, 5);
        if (seleccion == 0)
        {
            rlutil::setBackgroundColor(rlutil::LIGHTRED);
            rlutil::setColor(rlutil::BLACK);
        }
        else
        {
            rlutil::setBackgroundColor(rlutil::BLACK);
            rlutil::setColor(rlutil::LIGHTRED);
        }
        cout << "ESTADO       : " << (actividad.getEstado() ? "ACTIVA   " : "INACTIVA ");
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::LIGHTRED);

        int btnX = 5;
        int btnY = 8;
        rlutil::locate(btnX, btnY);
        if (seleccion == 1)
        {
            rlutil::setBackgroundColor(rlutil::LIGHTRED);
            rlutil::setColor(rlutil::BLACK);
        }
        else
        {
            rlutil::setBackgroundColor(rlutil::BLACK);
            rlutil::setColor(rlutil::LIGHTRED);
        }
        cout << "   GUARDAR Y VOLVER   ";

        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::LIGHTRED);

        int tecla = rlutil::getkey();

        if (tecla == rlutil::KEY_UP)
        {
            if (seleccion > 0) seleccion--;
        }
        else if (tecla == rlutil::KEY_DOWN)
        {
            if (seleccion < 1) seleccion++;
        }
        else if (tecla == rlutil::KEY_ENTER)
        {
            if (seleccion == 0)
            {
                actividad.setEstado(!actividad.getEstado());
            }
            else if (seleccion == 1)
            {
                if (arch.modificarActividad(actividad, pos))
                {
                    mostrarMensaje("Estado modificado correctamente", rlutil::YELLOW);
                }
                else
                {
                    mostrarMensaje("Error al guardar cambios", rlutil::LIGHTRED);
                }
                rlutil::cls();
                imprimirMenuActividades();
                salir = true;
            }
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
