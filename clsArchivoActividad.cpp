#include <iostream>
#include <cstring>
#include "clsArchivoActividad.h"
#include "clsActividad.h"

using namespace std;

ArchivoActividad::ArchivoActividad(const char *n, Actividad _act)
{
    strcpy(nombreArchivo, n);
    act = _act;
}

int ArchivoActividad::contarActividades()
{
    FILE *p = fopen(nombreArchivo, "rb");
    if(p == nullptr)
    {
        cout << "No se ha cargado clientes en el sistema" << endl;
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

    if(p == nullptr)
    {
        act.setIdAct(-1);
        return act;
    }
    fseek(p, pos * sizeof act, 0); ///MOVER EL PUNTERO DEL ARCHIVO A LA POSICION DESEADA, POS LO CALCULA EN BYTES, 0 ES QUE VA DEL INICIO
    act.setIdAct(-2);
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
    act.setIdAct(idAct);

    bool escribio = fwrite(&act, sizeof act, 1, p);
    fclose(p);
    return escribio;
}

void ArchivoActividad::listar()
{
    int cantAct = contarActividades();
    for(int i = 0; i < cantAct; i++)
    {
        act = leerArchivo(i);
        act.mostrar();
        cout << endl;
    }
}

bool ArchivoActividad::modificarActividad(Actividad act, int pos)
{
    FILE *p = fopen(nombreArchivo, "rb+");
    if(p == nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof act, 0);
    bool escribio = fwrite(&act, sizeof act, 1, p);
    fclose(p);
    return escribio;
}
