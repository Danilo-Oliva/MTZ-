#include <iostream>
#include <cstring>
#include "clsArchivoCliente.h"
#include "listadoVisual.h"
#include "rlutil.h"

using namespace std;

ArchivoCliente::ArchivoCliente(const char *n, Persona _per)
{
    strcpy(nombreArchivo, n);
    per = _per;
}

int ArchivoCliente::contarClientes()
{
    FILE *p = fopen(nombreArchivo, "rb");
    if(p == nullptr)
    {
        cout << "No se ha cargado clientes en el sistema" << endl;
        return -1;
    }
    fseek(p, SEEK_SET, SEEK_END);

    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(per);
}

int ArchivoCliente::buscarCliente(int dniBuscado)
{
    int cantReg = contarClientes();
    for (int i = 0; i < cantReg; i++)
    {
        per = leerArchivo(i);
        if(per.getDNI() == dniBuscado)
        {
            return i;
        }
    }
    return -1;
}

int ArchivoCliente::buscarSocio(int numSocio)
{
    int cantReg = contarClientes();
    for (int i = 0; i < cantReg; i++)
    {
        per = leerArchivo(i);
        if(per.getNumeroSocio() == numSocio)
        {
            return i;
        }
    }
    return -1;
}

Persona ArchivoCliente::leerArchivo(int pos)
{
    FILE *p = fopen(nombreArchivo, "rb");
    Persona per;
    if(p == nullptr)
    {
        per.setDNI(-1);
        return per;
    }
    fseek(p, pos * sizeof per, 0);
    per.setDNI(-2);
    fread(&per, sizeof per, 1, p);
    fclose(p);
    return per;
}
int ArchivoCliente::getProximoID() {
    int cant = contarClientes();
    if (cant == 0) {
        return 1;
    }

    int maxID = 0;
    for (int i = 0; i < cant; i++) {
        Persona per = leerArchivo(i);
        if (per.getNumeroSocio() > maxID) {
            maxID = per.getNumeroSocio();
        }
    }
    return maxID + 1;
}
bool ArchivoCliente::inscribirCliente(Persona per)
{
    FILE *p = fopen(nombreArchivo, "ab");
    if(p == nullptr)
    {
        return false;
    }

    int proximoNroSocio = getProximoID();
    per.setNumeroSocio(proximoNroSocio);
    per.setEstado(true);

    bool escribio = fwrite(&per, sizeof per, 1, p);
    fclose(p);
    return escribio;
}
bool ArchivoCliente::modificarCliente(Persona per, int pos)
{
    FILE *p = fopen(nombreArchivo, "rb+");
    if(p==nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof per, 0);
    bool escribio = fwrite(&per, sizeof per, 1, p);
    fclose(p);
    return escribio;
}
void ArchivoCliente::listar(int modoListado)
{
    int contarCli = contarClientes();
    int contadorMostrados = 0;

    const int filaInicial = 5;

    system("cls");
    dibujarTablaClientesHeader();

    if (contarCli > 0)
    {
        for(int i = 0; i < contarCli; i++)
        {
            Persona per = leerArchivo(i);
            bool mostrar = false;

            switch (modoListado)
            {
            case 1:
                if (per.getEstado() == true) mostrar = true;
                break;
            case 2:
                if (per.getEstado() == false) mostrar = true;
                break;
            default:
                mostrar = true;
                break;
            }

            if (mostrar)
            {
                dibujarTablaClientesRow(per, filaInicial + contadorMostrados);
                contadorMostrados++;
            }
        }
    }

    if (contadorMostrados == 0)
    {
        rlutil::locate(5, filaInicial);
        cout << "No hay clientes que coincidan con el filtro seleccionado." << endl;
    }


    rlutil::locate(1, filaInicial + contadorMostrados + 2);
}
bool ArchivoCliente::eliminarCliente(int dni)
{
    int pos = buscarCliente(dni);
    if (pos == -1)
    {
        return false;
    }

    int cant = contarClientes();
    FILE *pOriginal = fopen(nombreArchivo, "rb");
    if (pOriginal == nullptr) return false;

    FILE *pTemporal = fopen("clientes.tmp", "wb");
    if (pTemporal == nullptr)
    {
        fclose(pOriginal);
        return false;
    }

    for (int i = 0; i < cant; i++)
    {
        Persona per = leerArchivo(i);
        if (per.getDNI() != dni)
        {
            fwrite(&per, sizeof(Persona), 1, pTemporal);
        }
    }

    fclose(pOriginal);
    fclose(pTemporal);

    if (remove(nombreArchivo) != 0) return false;
    if (rename("clientes.tmp", nombreArchivo) != 0) return false;

    return true;
}
