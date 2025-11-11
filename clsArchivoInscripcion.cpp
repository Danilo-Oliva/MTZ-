#include <iostream>
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
#include "clsPersona.h"
#include "clsActividad.h"
#include "rlutil.h"
#include "clsArchivoInscripcion.h"
#include "cargarCadena.h"

using namespace std;

ArchivoInscripcion::ArchivoInscripcion(const char *n) {
    strcpy(nombreArchivo, n);
}

bool ArchivoInscripcion::grabarInscripcion(InscripcionActividad ins) {
    FILE *p = fopen(nombreArchivo, "ab");
    if (p == nullptr) {
        return false;
    }
    bool escribio = fwrite(&ins, sizeof(InscripcionActividad), 1, p);
    fclose(p);
    return escribio;
}

int ArchivoInscripcion::contarInscripciones() {
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr) {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(InscripcionActividad);
}

InscripcionActividad ArchivoInscripcion::leerInscripcion(int pos) {
    InscripcionActividad ins;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr) {
        return ins;
    }
    fseek(p, pos * sizeof(InscripcionActividad), 0);
    fread(&ins, sizeof(InscripcionActividad), 1, p);
    fclose(p);
    return ins;
}

int ArchivoInscripcion::buscarInscripcion(int nroSocio, int idAct) {
    int cant = contarInscripciones();
    for (int i = 0; i < cant; i++) {
        InscripcionActividad ins = leerInscripcion(i);
        if (ins.getNumeroSocio() == nroSocio && ins.getIdAct() == idAct && ins.getEstado() == true) {
            return i;
        }
    }
    return -1;
}
int ArchivoInscripcion::buscarInscripcionGlobal(int nroSocio, int idAct) {
    int cant = contarInscripciones();
    for (int i = 0; i < cant; i++) {
        InscripcionActividad ins = leerInscripcion(i);
        if (ins.getNumeroSocio() == nroSocio && ins.getIdAct() == idAct) {
            return i;
        }
    }
    return -1;
}

bool ArchivoInscripcion::modificarInscripcion(InscripcionActividad ins, int pos) {
    FILE *p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, pos * sizeof(InscripcionActividad), 0);
    bool escribio = fwrite(&ins, sizeof(InscripcionActividad), 1, p);
    fclose(p);
    return escribio;
}
void ArchivoInscripcion::listar(int modoListado)
{
    int cantIns = contarInscripciones();
    int contadorMostrados = 0;

    if (cantIns == 0)
    {
        cout << "No hay inscripciones para mostrar." << endl;
        rlutil::anykey();
        return;
    }

    Persona per;
    ArchivoCliente archCli("clientes.dat", per);

    Actividad act;
    ArchivoActividad archAct("actividades.dat", act);


    for (int i = 0; i < cantIns; i++)
    {
        InscripcionActividad ins = leerInscripcion(i);
        bool mostrar = false;


        switch (modoListado)
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
            int posSocio = archCli.buscarSocio(ins.getNumeroSocio());
            Persona socio;
            if (posSocio != -1) {
                socio = archCli.leerArchivo(posSocio);
            }

            int posAct = archAct.buscarActividad(ins.getIdAct());
            Actividad act;
            if (posAct != -1) {
                act = archAct.leerArchivo(posAct);
            }

            cout << "----------------------------------------" << endl;

            cout << "Socio: " << socio.getNombre() << " " << socio.getApellido() << " (ID: " << ins.getNumeroSocio() << ")" << endl;

            cout << "Actividad: " << act.getNombre() << " (ID: " << ins.getIdAct() << ")" << endl;

            cout << "Fecha Insc.: ";
            ins.getFechaInscripcion().mostrar();
            cout << endl;

            cout << "Modalidad: " << (ins.getLibre() ? "Pase Libre" : "3 veces por semana") << endl;

            cout << "Estado: " << (ins.getEstado() ? "Activa" : "Inactiva") << endl;

            float precio = ins.calcularCuota(act);
            cout << "Precio Final: $" << precio << endl;

            contadorMostrados++;
        }
    }

    if (contadorMostrados == 0)
    {
        cout << "No hay inscripciones que coincidan con el filtro seleccionado." << endl;
    }
}
