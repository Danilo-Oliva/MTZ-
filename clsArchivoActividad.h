#ifndef CLSARCHIVOACTIVIDAD_H_INCLUDED
#define CLSARCHIVOACTIVIDAD_H_INCLUDED
#include "clsActividad.h"

class ArchivoActividad
{
private:
    char nombreArchivo[30];
    Actividad act;
public:
    ArchivoActividad(const char *n = "actividad.dat", Actividad _act = Actividad());

    bool inscribirActividad(Actividad);
    int buscarActividad(int);
    Actividad leerArchivo(int pos);
    int contarActividades();
    void listar(int modoListado = 1);
    bool modificarActividad(Actividad, int);
};

#endif // CLSARCHIVOACTIVIDAD_H_INCLUDED
