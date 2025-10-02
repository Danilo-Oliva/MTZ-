#include <iostream>
#include <cstring>
#include "clsArchivoActividad.h"
#include "clsActividad.h"

using namespace std;

ArchivoActividad::ArchivoActividad(const char *n, Actividad _act, int _idAct)
{
    strcpy(nombreArchivo, n);
    act = _act;
    idAct = _idAct;
}

void ArchivoActividad::setIdAct(int _idAct)
{
    idAct = _idAct;
}

int ArchivoActividad::getIdAct()
{
    return idAct;
}


bool ArchivoActividad::inscribirActividad(Actividad act)
{
    FILE *p = fopen(nombreArchivo, "ab");
    if(p == nullptr)
    {
        return false;
    }

    int idAct = act.getOpcion_act();
    setIdAct(idAct);

    bool escribio = fwrite(&act, sizeof act, 1, p);
    fclose(p);
    return escribio;
}

void ArchivoActividad::listar()
{
        act.mostrar();
        cout << endl;
}
