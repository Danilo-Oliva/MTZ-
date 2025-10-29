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
    ArchivoActividad archActividades("actividad.dat");
    ArchivoInscripcion archInscripciones("inscripciones.dat");

    int cantCli = archClientes.contarClientes();
    int cantAct = archActividades.contarActividades();
    if(cantCli == 0 || cantAct == 0){
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
    cout << "INGRESE EL DIA: ";
    cin >> dia;
    cout << "INGRESE EL MES: ";
    cin >> mes;
    cout << "INGRESE EL ANIO: ";
    cin >> anio;

    int opcionMod;
    cout << "--- MODALIDAD ---" << endl;
    cout << "1 para Pase Libre, 2 para 3 veces por semana: ";
    cin >> opcionMod;

    fechaInsc.setDia(dia);
    fechaInsc.setMes(mes);
    fechaInsc.setAnio(anio);

    InscripcionActividad nuevaIns;
    nuevaIns.setNumeroSocio(nroSocio);
    nuevaIns.setIdAct(idAct);
    nuevaIns.setFechaInscripcion(fechaInsc);
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
    ArchivoInscripcion archInscripciones("inscripciones.dat");
    int nroSocio, idAct, pos;
    char confirmacion;

    int cantInscrip = archInscripciones.contarInscripciones();
    if(cantInscrip == 0)
    {
        mostrarMensaje("No hay inscripciones registradas", rlutil::YELLOW);
        rlutil::cls();
        imprimirMenuInscripciones();
        return;
    }

    cout << "Ingrese el Numero de Socio: ";
    cin >> nroSocio;
    cout << "Ingrese el ID de la actividad de la inscripcion a gestionar: ";
    cin >> idAct;

    pos = archInscripciones.buscarInscripcionGlobal(nroSocio, idAct);

    if(pos == -1)
    {
        cout << "ERROR: No se encontro ninguna inscripcion para ese socio y actividad." << endl;
        return;
    }

    InscripcionActividad ins = archInscripciones.leerInscripcion(pos);

    if (ins.getEstado() == true)
    {
        cout << "\nLa inscripcion se encuentra ACTIVA." << endl;
        cout << "Desea anularla en este momento? (S/N): ";
        cin >> confirmacion;
        if (confirmacion == 'S' || confirmacion == 's')
        {
            ins.setEstado(false);
            if(archInscripciones.modificarInscripcion(ins, pos))
            {
                cout << "Inscripcion anulada con exito." << endl;
            }
            else
            {
                cout << "ERROR: No se pudo anular la inscripcion." << endl;
            }
        }
        else
        {
            cout << "Operacion cancelada." << endl;
        }
    }
    else
    {
        cout << "\nLa inscripcion se encuentra INACTIVA." << endl;
        cout << "Desea reactivarla en este momento? (S/N): ";
        cin >> confirmacion;
        if (confirmacion == 'S' || confirmacion == 's')
        {
            ins.setEstado(true);
            if(archInscripciones.modificarInscripcion(ins, pos))
            {
                cout << "Inscripcion reactivada con exito." << endl;
            }
            else
            {
                cout << "ERROR: No se pudo reactivar la inscripcion." << endl;
            }
        }
        else
        {
            cout << "Operacion cancelada." << endl;
        }
    }
}
void menuListarInscripciones()
{
    ArchivoInscripcion archInscripciones("inscripciones.dat");

    int cantIns = archInscripciones.contarInscripciones();
    if(cantIns == 0){
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
