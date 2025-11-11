#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "clsArchivoActividad.h"
#include "listadoVisual.h"
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
    rlutil::cls();
    int cantAct = contarActividades();
    int contadorMostrados = 0;

    const int filaInicial = 5; // coincide con el header en listadoVisual.cpp

    rlutil::cls();
    dibujarTablaActividadesHeader();

    if (cantAct > 0)
    {
        for (int i = 0; i < cantAct; i++)
        {
            Actividad reg = leerArchivo(i);
            bool mostrar = false;

            switch (modoListado)
            {
            case 1: // sólo activos
                if (reg.getEstado() == true) mostrar = true;
                break;
            case 2: // sólo inactivos
                if (reg.getEstado() == false) mostrar = true;
                break;
            default: // todos
                mostrar = true;
                break;
            }

            if (mostrar)
            {
                // dibuja la fila usando la misma alineación que el listado de clientes
                dibujarTablaActividadesRow(reg, filaInicial + contadorMostrados);
                contadorMostrados++;
            }
        }

        int y = filaInicial + contadorMostrados;
        dibujarFinalTablaActividades(y);
    }

    if (contadorMostrados == 0)
    {
        rlutil::locate(5, filaInicial);
        cout << "No hay actividades que coincidan con el filtro seleccionado." << endl;
    }

    rlutil::locate(1, filaInicial + contadorMostrados + 2);
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
