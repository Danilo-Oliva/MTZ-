#include <iostream>
#include <cstring>
#include "clsArchivoActividad.h"

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
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Actividad);
}


int ArchivoActividad::buscarActividad(int idBuscado)
{
    int cantReg = contarActividades();
    for (int i = 0; i < cantReg; i++)
    {
        act = leerArchivo(i);
        if(act.getIdAct() == idBuscado)
        {
            return i;
        }
    }
    return -1;
}

int ArchivoActividad::buscarActividadPorNombre(const char* nombre)
{
    int cantReg = contarActividades();
    for (int i = 0; i < cantReg; i++)
    {
        act = leerArchivo(i);

        if(strcmp(act.getNombre(), nombre) == 0)
        {
            return i;
        }
    }
    return -1;
}

Actividad ArchivoActividad::leerArchivo(int pos)
{
    Actividad aux;
    FILE *p = fopen(nombreArchivo, "rb");
    if (p == nullptr)
    {
        return aux;
    }

    if (fseek(p, pos * sizeof(Actividad), SEEK_SET) != 0)
    {
        fclose(p);
        return aux;
    }

    size_t leidos = fread(&aux, sizeof(Actividad), 1, p);
    fclose(p);

    if (leidos != 1)
    {
        aux = Actividad();
    }

    return aux;
}



bool ArchivoActividad::inscribirActividad(Actividad act)
{
    FILE *p = fopen(nombreArchivo, "ab");
    if(p == nullptr)
    {
        return false;
    }

    bool escribio = fwrite(&act, sizeof(Actividad), 1, p);
    fclose(p);
    return escribio;
}


void ArchivoActividad::listar(int modoListado)
{
    int cantAct = contarActividades();
    int contadorMostrados = 0;

    if (cantAct == 0)
    {
        cout << "No hay Actividades para mostrar." << endl;
        system("pause");
        return;
    }

    for (int i = 0; i < cantAct; i++)
    {
        Actividad act = leerArchivo(i);

        if (act.getIdAct() == 0) continue;

        bool mostrar = false;

        switch (modoListado)
        {
        case 1:
            if (act.getEstado() == true) mostrar = true;
            break;
        case 2:
            if (act.getEstado() == false) mostrar = true;
            break;
        default:
            mostrar = true;
            break;
        }

        if (mostrar)
        {
            act.mostrar();
            cout << endl;
            contadorMostrados++;
        }
    }
}

bool ArchivoActividad::modificarActividad(Actividad act, int pos)
{
    FILE *p = fopen(nombreArchivo, "rb+");
    if(p == nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof(Actividad), 0);
    bool escribio = fwrite(&act, sizeof(Actividad), 1, p);
    fclose(p);
    return escribio;
}
