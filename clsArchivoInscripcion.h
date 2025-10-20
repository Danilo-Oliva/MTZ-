#ifndef CLSARCHIVOINSCRIPCION_H_INCLUDED
#define CLSARCHIVOINSCRIPCION_H_INCLUDED

#include "clsInscripcionActividad.h"

class ArchivoInscripcion {
private:
    char nombreArchivo[30];

public:
    ArchivoInscripcion(const char *n = "inscripciones.dat");
    bool grabarInscripcion(InscripcionActividad);
    int contarInscripciones();
    InscripcionActividad leerInscripcion(int pos);
    int buscarInscripcion(int nroSocio, int idAct);
    int buscarInscripcionGlobal(int nroSocio, int idAct);
    bool modificarInscripcion(InscripcionActividad, int pos);
};

#endif // CLSARCHIVOINSCRIPCION_H_INCLUDED
