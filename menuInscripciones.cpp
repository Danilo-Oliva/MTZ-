#include <iostream>
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
#include "clsArchivoInscripcion.h"
#include "clsFecha.h"
#include "tunearMenu.h"

using namespace std;

void nuevaInscripcion() {
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
    if (posCliente == -1) {
        cout << "ERROR: No se encontro ningun cliente con ese DNI." << endl;
        system("pause");
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

    if (archActividades.buscarActividad(idAct) == -1) {
        cout << "ERROR: El ID de actividad no existe." << endl;
        system("pause");
        return;
    }

    if(archInscripciones.buscarInscripcion(nroSocio, idAct) != -1){
        cout << "ERROR: El cliente ya se encuentra inscripto en esa actividad." << endl;
        system("pause");
        return;
    }

    Fecha fechaInsc;
    cout << "\nIngrese la fecha de inscripcion:" << endl;
    fechaInsc.cargar();

    InscripcionActividad nuevaIns;
    nuevaIns.setNumeroSocio(nroSocio);
    nuevaIns.setIdAct(idAct);
    nuevaIns.setFechaInscripcion(fechaInsc);
    nuevaIns.setEstado(true);

    if (archInscripciones.grabarInscripcion(nuevaIns)) {
        cout << "\nInscripcion realizada con exito!" << endl;
    } else {
        cout << "\nERROR: No se pudo realizar la inscripcion." << endl;
    }
}

void gestionarEstadoInscripcion(){
    ArchivoInscripcion archInscripciones("inscripciones.dat");
    int nroSocio, idAct, pos;
    char confirmacion;
    int cantInscrip = archInscripciones.contarInscripciones();
    if(cantInscrip == 0){
        cout << "ERROR: No hay inscripciones. Por favor ingrese inscripciones" << endl;
        return;
    }

    cout << "Ingrese el Numero de Socio: ";
    cin >> nroSocio;
    cout << "Ingrese el ID de la actividad de la inscripcion a gestionar: ";
    cin >> idAct;

    pos = archInscripciones.buscarInscripcionGlobal(nroSocio, idAct);

    if(pos == -1){
        cout << "ERROR: No se encontro ninguna inscripcion para ese socio y actividad." << endl;
        return;
    }

    InscripcionActividad ins = archInscripciones.leerInscripcion(pos);

    if (ins.getEstado() == true) {
        cout << "\nLa inscripcion se encuentra ACTIVA." << endl;
        cout << "Desea anularla en este momento? (S/N): ";
        cin >> confirmacion;
        if (confirmacion == 'S' || confirmacion == 's') {
            ins.setEstado(false);
            if(archInscripciones.modificarInscripcion(ins, pos)){
                cout << "Inscripcion anulada con exito." << endl;
            } else {
                cout << "ERROR: No se pudo anular la inscripcion." << endl;
            }
        } else {
            cout << "Operacion cancelada." << endl;
        }
    } else {
        cout << "\nLa inscripcion se encuentra INACTIVA." << endl;
        cout << "Desea reactivarla en este momento? (S/N): ";
        cin >> confirmacion;
        if (confirmacion == 'S' || confirmacion == 's') {
            ins.setEstado(true);
            if(archInscripciones.modificarInscripcion(ins, pos)){
                cout << "Inscripcion reactivada con exito." << endl;
            } else {
                cout << "ERROR: No se pudo reactivar la inscripcion." << endl;
            }
        } else {
            cout << "Operacion cancelada." << endl;
        }
    }
}

void listarInscripciones(){
    ArchivoCliente archClientes("clientes.dat");
    ArchivoActividad archActividades("actividad.dat");
    ArchivoInscripcion archInscripciones("inscripciones.dat");

    int cant = archInscripciones.contarInscripciones();
    if (cant == 0) {
        cout << "No hay inscripciones para mostrar." << endl;
        return;
    }
    cout << "--- LISTADO DE INSCRIPCIONES ---" << endl;

    for(int i=0; i<cant; i++){
        InscripcionActividad ins = archInscripciones.leerInscripcion(i);


        Persona per;
        int cantClientes = archClientes.contarClientes();
        for(int j=0; j<cantClientes; j++){
            Persona aux = archClientes.leerArchivo(j);
            if(aux.getNumeroSocio() == ins.getNumeroSocio()){
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
    }
}

int mostrarMenuInscripciones(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 31);
    bordesMenu(24, 6, 31);
    separarMenues(24, 7, 31);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 31);
    parteAbajoMenu(24, 17, 31);


    resaltarMenu("M E N U   A C T I V I D A D E S", 25, 6, false);
    resaltarMenu(" NUEVA   INSCRIPCION ", 30, 9, y == 0);
    resaltarMenu(" CAMBIAR ESTADO INSCRIPCION ", 27, 11, y == 1);
    resaltarMenu("LISTAR  INSCRIPCIONES", 30, 13, y == 2);
    resaltarMenu("VOLVER A MENU GESTION", 30, 15, y == 3);


    mostrarCursor(26, 55, 9, y);
    int tecla = rlutil::getkey();
    if(tecla == 1)
    {
        switch(y)
        {
        case 0:
        {
            opcionMenu = 1; /// NUEVA
            break;
        }
        case 1:
        {
            opcionMenu = 2; /// ANULAR
            break;
        }
        case 2:
        {
            opcionMenu = 3; /// LISTAR
            break;
        }
        case 3:
            {
                opcionMenu = 0; /// SALIDA
                break;
            }
        }
    }
    else if(tecla > 13) y = accionarCursor(y, tecla, 3);

    return opcionMenu;

}

void menuInscripciones() {
    int opcion, y = 0;
    do {
        system("cls");
        opcion = -1;

        mostrarMenuInscripciones(opcion, y);

        system("cls");

        switch (opcion) {
            case 1:
                system("cls");

                nuevaInscripcion();

                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");

                gestionarEstadoInscripcion();

                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");

                listarInscripciones();

                system("pause");
                system("cls");
                break;
        }

    } while (opcion != 0);
}
