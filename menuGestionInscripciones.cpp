#include <iostream>
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
#include "clsArchivoInscripcion.h"
#include "clsFecha.h"
#include "menusVisual.h"
#include "tunearMenu.h"

using namespace std;

void listarInscripciones(int modoListado = 1)
{
    ArchivoCliente archClientes("clientes.dat");
    ArchivoActividad archActividades("actividad.dat");
    ArchivoInscripcion archInscripciones("inscripciones.dat");

    int cant = archInscripciones.contarInscripciones();
    int contadorMostrados = 0;

    switch(modoListado)
    {
    case 1:
        cout << "--- LISTADO DE INSCRIPCIONES ACTIVAS ---" << endl;
        break;
    case 2:
        cout << "--- LISTADO DE INSCRIPCIONES INACTIVAS ---" << endl;
        break;
    default:
        cout << "--- LISTADO DE TODAS LAS INSCRIPCIONES ---" << endl;
        break;
    }

    for(int i=0; i<cant; i++)
    {
        InscripcionActividad ins = archInscripciones.leerInscripcion(i);
        bool mostrar = false;

        switch(modoListado)
        {
        case 1:
            if (ins.getEstado() == true) mostrar = true;
            break;
        case 2:
            if (ins.getEstado() == false) mostrar = true;
            break;
        default:
            mostrar = true;
            break;
        }

        if (mostrar)
        {
            Persona per;
            int cantClientes = archClientes.contarClientes();
            for(int j=0; j<cantClientes; j++)
            {
                Persona aux = archClientes.leerArchivo(j);
                if(aux.getNumeroSocio() == ins.getNumeroSocio())
                {
                    per = aux;
                    break;
                }
            }
            Actividad act = archActividades.leerArchivo(archActividades.buscarActividad(ins.getIdAct()));

            cout << "Socio: " << per.getNombre() << " " << per.getApellido();
            cout << " (Socio Nro: " << ins.getNumeroSocio() << ")" << endl;
            cout << "Actividad: " << act.getNombre() << " (ID: " << ins.getIdAct() << ")" << endl;
            cout << "Fecha de Inscripcion: ";
            ins.getFechaInscripcion().mostrar();
            cout << "Estado: " << (ins.getEstado() ? "ACTIVA" : "INACTIVA") << endl;
            cout << "--------------------------------" << endl;
            contadorMostrados++;
        }
    }

    if (contadorMostrados == 0)
    {
        cout << "\nNo hay inscripciones que coincidan con el filtro seleccionado." << endl;
    }
}
void nuevaInscripcion()
{
    ArchivoCliente archClientes("clientes.dat");
    ArchivoActividad archActividades("actividad.dat");
    ArchivoInscripcion archInscripciones("inscripciones.dat");
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

    if(archInscripciones.buscarInscripcion(nroSocio, idAct) != -1)
    {
        cout << "ERROR: El cliente ya se encuentra inscripto en esa actividad." << endl;
        rlutil::anykey();
        return;
    }

    Fecha fechaInsc;
    int dia, mes, anio;

    cout << "--- FECHA DE INSCRIPCION ---" << endl;
    cout << "INGRESE EL DIA: ";
    cin >> dia;
    cout << "INGRESE EL MES: ";
    cin >> mes;
    cout << "INGRESE EL ANIO: ";
    cin >> anio;

    fechaInsc.setDia(dia);
    fechaInsc.setMes(mes);
    fechaInsc.setAnio(anio);

    cin.ignore();

    InscripcionActividad nuevaIns;
    nuevaIns.setNumeroSocio(nroSocio);
    nuevaIns.setIdAct(idAct);
    nuevaIns.setFechaInscripcion(fechaInsc);
    nuevaIns.setEstado(true);

    if (archInscripciones.grabarInscripcion(nuevaIns))
    {
        cout << "\nInscripcion realizada con exito!" << endl;
    }
    else
    {
        cout << "\nERROR: No se pudo realizar la inscripcion." << endl;
    }
}

void gestionarEstadoInscripcion()
{
    ArchivoInscripcion archInscripciones("inscripciones.dat");
    int nroSocio, idAct, pos;
    char confirmacion;
    int cantInscrip = archInscripciones.contarInscripciones();
    if(cantInscrip == 0)
    {
        cout << "ERROR: No hay inscripciones. Por favor ingrese inscripciones" << endl;
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
    int opcion, y = 0;
    do
    {
        opcion = -1;
        system("cls");

        opcion = mostrarMenuListarInscripciones(opcion, y);
        system("cls");

        switch (opcion)
        {
        case 1:
            listarInscripciones(1);
            rlutil::anykey();
            break;
        case 2:
            listarInscripciones(2);
            rlutil::anykey();
            break;
        case 3:
            listarInscripciones(0);
            rlutil::anykey();
            break;
        }
    }
    while (opcion != 0);
}
