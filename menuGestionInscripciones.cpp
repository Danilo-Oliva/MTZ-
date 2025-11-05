#include <iostream>
#include <cstdio>
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
#include "clsArchivoInscripcion.h"
#include "clsFecha.h"
#include "menusVisual.h"
#include "tunearMenu.h"

using namespace std;

void nuevaInscripcion()
{
    ArchivoCliente archClientes("clientes.dat");
    ArchivoActividad archActividades("actividades.dat");
    ArchivoInscripcion archInscripciones("inscripciones.dat");
    InscripcionActividad nuevaIns;

    int cantCli = archClientes.contarClientes();
    int cantAct = archActividades.contarActividades();
    if(cantCli == 0 || cantAct == 0)
    {
        mostrarMensaje("No hay clientes o actividades registradas", rlutil::YELLOW);
        rlutil::cls();
        imprimirMenuInscripciones();
        return;
    }

    Persona per;

    int dni, idAct, posCliente;

    cout << "--- LISTA DE CLIENTES DISPONIBLES ---" << endl;
    archClientes.listar();
    cout << "---------------------------------------" << endl;

    cout << "Ingrese el DNI del cliente a inscribir: ";
    cin >> dni;

    posCliente = archClientes.buscarCliente(dni);
    if (posCliente == -1)
    {
        cout << "ERROR: No se encontro ningun cliente con ese DNI." << endl;
        rlutil::anykey();
        return;
    }

    per = archClientes.leerArchivo(posCliente);
    int nroSocio = per.getNumeroSocio();

    if (!per.getEstado())
    {
        cout << "ERROR: El cliente se encuentra INACTIVO. No se puede realizar la inscripcion." << endl;
        rlutil::anykey();
        return;
    }

    system("cls");

    cout << endl << "--- LISTA DE ACTIVIDADES DISPONIBLES ---" << endl;
    archActividades.listar();
    cout << "------------------------------------------" << endl;
    cout << "Ingrese el ID de la actividad: ";
    cin >> idAct;

    if (archActividades.buscarActividad(idAct) == -1)
    {
        cout << "ERROR: El ID de actividad no existe." << endl;
        rlutil::anykey();
        return;
    }
    int posAct = archActividades.buscarActividad(idAct);
    Actividad act = archActividades.leerArchivo(posAct);
    if (!act.getEstado())
    {
        rlutil::setColor(rlutil::YELLOW);
        cout << "ERROR: La actividad se encuentra INACTIVA. No se puede realizar la inscripcion." << endl;
        rlutil::anykey();
        return;
    }

    if(archInscripciones.buscarInscripcion(nroSocio, idAct) != -1)
    {
        rlutil::setColor(rlutil::YELLOW);
        cout << "ERROR: El cliente ya se encuentra inscripto en esa actividad." << endl;
        rlutil::anykey();
        return;
    }

    system("cls");

    Fecha fechaInsc;
    int dia, mes, anio;

    cout << "--- FECHA DE INSCRIPCION ---" << endl;
    cout << "Ingrese fecha de inscripcion (DD/MM/ANIO):";
    int x = 40, yStart = 11;
    Fecha nuevaFecha;
    nuevaFecha.cargarCompacta(x + 19, yStart + 9);
    nuevaIns.setFechaInscripcion(nuevaFecha);

    int opcionMod;
    cout << "--- MODALIDAD ---" << endl;
    cout << "1 para Pase Libre, 2 para 3 veces por semana: ";
    cin >> opcionMod;



    nuevaIns.setNumeroSocio(nroSocio);
    nuevaIns.setIdAct(idAct);
    nuevaIns.setLibre(opcionMod == 1);
    nuevaIns.setEstado(true);


    if (archInscripciones.grabarInscripcion(nuevaIns))
    {
        rlutil::setColor(rlutil::GREEN);
        cout << "\nInscripcion realizada con exito!" << endl;
    }
    else
    {
        rlutil::setColor(rlutil::RED);
        cout << "\nERROR: No se pudo realizar la inscripcion." << endl;
    }
    rlutil::anykey();
}

void gestionarEstadoInscripcion()
{
    rlutil::cls();
    ArchivoInscripcion archInscripciones("inscripciones.dat");

    int nroSocio = pedirNumSocio("GESTIONAR ESTADO DE INSCRIPCION:");
    int idAct = pedirIdActividad();
    int pos = archInscripciones.buscarInscripcionGlobal(nroSocio, idAct);

    if (pos == -1)
    {
        mostrarMensaje("No se encontro ninguna inscripcion para ese socio y actividad.", rlutil::LIGHTRED);
        rlutil::anykey();
        return;
    }

    InscripcionActividad ins = archInscripciones.leerInscripcion(pos);

    bool salir = false;
    int seleccion = 0;

    rlutil::cls();
    while (!salir)
    {
        escribirTexto("GESTIONAR ESTADO DE INSCRIPCION", 5, 1);

        rlutil::locate(5, 3);
        cout << "NRO SOCIO    : " << ins.getNumeroSocio();
        rlutil::locate(5, 4);
        cout << "ID ACTIVIDAD : " << ins.getIdAct();


        rlutil::locate(5, 6);
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
        cout << "ESTADO       : " << (ins.getEstado() ? "ACTIVA   " : "INACTIVA ");

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
                // Alternar estado en la vista (no guardado todavía)
                ins.setEstado(!ins.getEstado());
            }
            else if (seleccion == 1)
            {
                // Guardar cambios en el archivo
                if (archInscripciones.modificarInscripcion(ins, pos))
                {
                    mostrarMensaje("Estado de inscripcion modificado correctamente", rlutil::YELLOW);
                }
                else
                {
                    mostrarMensaje("Error al guardar cambios", rlutil::LIGHTRED);
                }
                rlutil::cls();
                imprimirMenuInscripciones();
                salir = true;
            }
        }
        // si el usuario presiona ESC u otra tecla, se mantiene en el loop (consistente con otros menús)
    }
}
void menuListarInscripciones()
{
    ArchivoInscripcion archInscripciones("inscripciones.dat");

    int cantIns = archInscripciones.contarInscripciones();
    if(cantIns == 0)
    {
        mostrarMensaje("No hay inscripciones registradas", rlutil::YELLOW);
        rlutil::cls();
        imprimirMenuInscripciones();
        return;
    }

    int opcion, y = 0;
    imprimirMenuListarInscripciones();
    do
    {
        opcion = -1;

        opcion = interactuarMenuListarInscripciones(opcion, y);

        switch (opcion)
        {
        case 1:
            rlutil::cls();

            archInscripciones.listar(1);

            rlutil::anykey();
            rlutil::cls();
            imprimirMenuListarInscripciones();
            break;
        case 2:
            rlutil::cls();

            archInscripciones.listar(2);
            rlutil::anykey();
            rlutil::cls();
            imprimirMenuListarInscripciones();

            break;
        case 3:
            rlutil::cls();

            archInscripciones.listar(0);

            rlutil::anykey();
            rlutil::cls();
            imprimirMenuListarInscripciones();

            break;
        }
    }
    while (opcion != 0);

    rlutil::anykey();
    rlutil::cls();
    imprimirMenuInscripciones();
}
void menuInscripciones() {
    int opcion, y = 0;
    system("cls");

    imprimirMenuInscripciones();

    do {
        opcion = -1;

        interactuarMenuInscripciones(opcion, y);

        switch (opcion) {
            case 1:
                system("cls");

                nuevaInscripcion();

                system("cls");
                imprimirMenuInscripciones();

                break;
            case 2:
                system("cls");

                gestionarEstadoInscripcion();

                rlutil::anykey();
                system("cls");
                imprimirMenuInscripciones();

                break;
            case 3:
                menuListarInscripciones();

                system("cls");
                imprimirMenuInscripciones();

                break;
        }

    } while (opcion != 0);
}
