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

int ArchivoActividad::contarActividades()
{
    FILE *p = fopen(nombreArchivo, "rb");
    if(p == nullptr)
    {
        return -1;
    }
    fseek(p, SEEK_SET, SEEK_END); /// BUSCAR REGISTROS

    int bytes = ftell(p); /// ESTABLECE LOS BYTES DE LA ULTIMA POSICION DEL ULTIMO REGISTRO

    fclose(p);
    return bytes/sizeof(act); /// DIVIDE LOS BYTES ESTABLECIDOS ANTES POR LOS BYTES TOTALES DE UN (1) REGISTRO
    /// EJ: 340/170 = 2 REGISTROS (el ejemplo es para guiarnos, no es realista)
}

Actividad ArchivoActividad::leerArchivo(int pos)
{
    FILE *p = fopen(nombreArchivo, "rb");
    Actividad act;
    if(p == nullptr)
    {
        setIdAct(-1);
        return idAct;
    }
    fseek(p, pos * sizeof act, 0); ///MOVER EL PUNTERO DEL ARCHIVO A LA POSICION DESEADA, POS LO CALCULA EN BYTES, 0 ES QUE VA DEL INICIO
    setIdAct(-2);
    fread(&act, sizeof act, 1, p); /// LEE EL ARCHIVO Y GUARDA EL DNI QUE SE BUSCA
    fclose(p);
    return act; /// RETORNA DNI QUE SE BUSCA (o errores si los hay)
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
    Actividad act;
    int cantAct = contarActividades();
    for(int i = 0; i < cantAct; i++)
    {
        act = leerArchivo(i);
        act.mostrar();
        cout << endl;
    }
}

