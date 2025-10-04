#ifndef CLSARCHIVOACTIVIDAD_H_INCLUDED
#define CLSARCHIVOACTIVIDAD_H_INCLUDED
#include "clsActividad.h"

class ArchivoActividad
{
private:
    char nombreArchivo[30];
    Actividad act;
    int idAct;
public:
    ArchivoActividad(const char *n = "actividad.dat", Actividad _act = Actividad(0, false, 0), int _idAct = 0);
    void setIdAct(int _idAct);
    int getIdAct();

    bool inscribirActividad(Actividad);
    Actividad leerArchivo(int pos);
    int contarActividades();
    void listar();
    bool modificarActividad(Actividad, int);
};

#endif // CLSARCHIVOACTIVIDAD_H_INCLUDED
