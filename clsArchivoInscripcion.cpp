#include <iostream>
#include<cstring>
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
        return ins; // Devuelve objeto vacío con estado en false por defecto
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
        // La condición ahora es más estricta:
        if (ins.getNumeroSocio() == nroSocio && ins.getIdAct() == idAct && ins.getEstado() == true) {
            return i; // Solo la devuelve si está ACTIVA
        }
    }
    return -1; // No encontró una inscripción activa
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
