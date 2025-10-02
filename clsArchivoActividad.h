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
    int contarActividades();
    Actividad leerArchivo(int pos);
    bool inscribirActividad(Actividad);
    bool modificarActividad(Actividad, int);
    void listar();
};

#endif // CLSARCHIVOACTIVIDAD_H_INCLUDED
