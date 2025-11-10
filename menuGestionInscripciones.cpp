#include <iostream>
#include <cstdio>
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
#include "clsArchivoInscripcion.h"
#include "clsPersona.h"
#include "clsActividad.h"
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

    int id, idAct, posCliente;

    cout << "--- LISTA DE CLIENTES DISPONIBLES ---" << endl;
    archClientes.listar();
    cout << "---------------------------------------" << endl;

    cout << "Ingrese el ID del socio a inscribir: ";
    cin >> id;

    posCliente = archClientes.buscarSocio(id);
    if (posCliente == -1)
    {
        cout << "ERROR: No se encontro ningun cliente con ese ID." << endl;
        return;
    }

    per = archClientes.leerArchivo(posCliente);
    int nroSocio = per.getNumeroSocio();

    if (!per.getEstado())
    {
        cout << "ERROR: El cliente se encuentra INACTIVO. No se puede realizar la inscripcion." << endl;
        return;
    }

    rlutil::cls();

    cout << endl << "--- LISTA DE ACTIVIDADES DISPONIBLES ---" << endl;
    archActividades.listar();
    cout << "------------------------------------------" << endl;
    cout << "Ingrese el ID de la actividad: ";
    cin >> idAct;

    if (archActividades.buscarActividad(idAct) == -1)
    {
        cout << "ERROR: El ID de actividad no existe." << endl;
        return;
    }
    int posAct = archActividades.buscarActividad(idAct);
    Actividad act = archActividades.leerArchivo(posAct);
    if (!act.getEstado())
    {
        rlutil::setColor(rlutil::YELLOW);
        cout << "ERROR: La actividad se encuentra INACTIVA. No se puede realizar la inscripcion." << endl;
        return;
    }

    if(archInscripciones.buscarInscripcion(nroSocio, idAct) != -1)
    {
        rlutil::setColor(rlutil::YELLOW);
        cout << "ERROR: El cliente ya se encuentra inscripto en esa actividad." << endl;
        rlutil::anykey();
        return;
    }

    rlutil::cls();

    Fecha fechaInsc;
    int dia, mes, anio;

    cout << "--- FECHA DE INSCRIPCION ---" << endl;
    cout << "Ingrese fecha de inscripcion (DD/MM/ANIO):";
    int x = 0, yStart = 0;
    Fecha nuevaFecha;
    nuevaFecha.cargarCompacta(x, yStart);
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
        rlutil::setColor(rlutil::YELLOW);
        cout << "\nInscripcion realizada con exito!" << endl;
    }
    else
    {
        rlutil::setColor(rlutil::RED);
        cout << "\nERROR: No se pudo realizar la inscripcion." << endl;
    }
}

void gestionarEstadoInscripcion()
{
    rlutil::cls();
    ArchivoInscripcion archInscripciones("inscripciones.dat");

    archInscripciones.listar();
    rlutil::anykey();

    int nroSocio = pedirNumSocio("GESTIONAR ESTADO DE INSCRIPCION:");
    int idAct = pedirIdActividad();
    int pos = archInscripciones.buscarInscripcionGlobal(nroSocio, idAct);

    if (pos == -1)
    {
        mostrarMensaje("No se encontro ninguna inscripcion para ese socio y actividad.", rlutil::LIGHTRED);
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
        cout << "ESTADO       : " << (ins.getEstado() ? "ACTIVA   " : "INACTIVA ") << endl;

        rlutil::locate(5, 7);
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
        cout << "LIBRE        : " << (ins.getLibre() ? "SI" : "NO") ;

        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::LIGHTRED);

        int btnX = 5;
        int btnY = 8;
        rlutil::locate(btnX, btnY);
        if (seleccion == 2)
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
            if (seleccion < 2) seleccion++;
        }
        else if (tecla == rlutil::KEY_ENTER)
        {
            if (seleccion == 0)
            {
                ins.setEstado(!ins.getEstado());
            }
            else if(seleccion == 1){
                ins.setLibre(!ins.getLibre());
            }
            else if (seleccion == 2)
            {
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

            rlutil::anykey();            rlutil::cls();
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

            rlutil::anykey();            rlutil::cls();
            imprimirMenuListarInscripciones();

            break;
        }
    }
    while (opcion != 0);

    rlutil::cls();
    imprimirMenuInscripciones();
}
void menuInscripciones() {
    int opcion, y = 0;
    rlutil::cls();

    imprimirMenuInscripciones();

    do {
        opcion = -1;

        interactuarMenuInscripciones(opcion, y);

        switch (opcion) {
            case 1:
                rlutil::cls();

                nuevaInscripcion();

                rlutil::anykey();
                rlutil::cls();
                imprimirMenuInscripciones();

                break;
            case 2:
                rlutil::cls();


                gestionarEstadoInscripcion();

                rlutil::cls();
                imprimirMenuInscripciones();

                break;
            case 3:
                menuListarInscripciones();

                rlutil::cls();
                imprimirMenuInscripciones();

                break;
        }

    } while (opcion != 0);
}
