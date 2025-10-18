#include <iostream>
#include <cstring>
#include "clsArchivoCliente.h"

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
    fseek(p, SEEK_SET, SEEK_END); /// BUSCAR REGISTROS

    int bytes = ftell(p); /// ESTABLECE LOS BYTES DE LA ULTIMA POSICION DEL ULTIMO REGISTRO

    fclose(p);
    return bytes/sizeof(per); /// DIVIDE LOS BYTES ESTABLECIDOS ANTES POR LOS BYTES TOTALES DE UN (1) REGISTRO
    /// EJ: 340/170 = 2 REGISTROS (el ejemplo es para guiarnos, no es realista)
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

Persona ArchivoCliente::leerArchivo(int pos)
{
    FILE *p = fopen(nombreArchivo, "rb");
    Persona per;
    if(p == nullptr)
    {
        per.setDNI(-1);
        return per;
    }
    fseek(p, pos * sizeof per, 0); ///MOVER EL PUNTERO DEL ARCHIVO A LA POSICION DESEADA, POS LO CALCULA EN BYTES, 0 ES QUE VA DEL INICIO
    per.setDNI(-2); /// SE DEVUELVE -2 EN CASO DE NO ENCONTRAR EL DNI
    fread(&per, sizeof per, 1, p); /// LEE EL ARCHIVO Y GUARDA EL DNI QUE SE BUSCA
    fclose(p);
    return per; /// RETORNA DNI QUE SE BUSCA (o errores si los hay)
}
bool ArchivoCliente::inscribirCliente(Persona per)
{
    FILE *p = fopen(nombreArchivo, "ab");
    if(p == nullptr)
    {
        return false;
    }

    int numSocio = contarClientes() + 1;
    per.setNumeroSocio(numSocio);

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
/* Modo de listado:
  - modoListado = 1 : Muestra solo clientes ACTIVOS (por defecto)
  - modoListado = 2 : Muestra solo clientes INACTIVOS
  - Cualquier otro valor (ej. 0): Muestra TODOS los clientes
*/
    int contarCli = contarClientes();
    int contadorMostrados = 0;

    for(int i = 0; i < contarCli; i++)
    {
        Persona per = leerArchivo(i);
        bool mostrar = false;

        switch (modoListado) {
            case 1: // Activos
                if (per.getEstado() == true) mostrar = true;
                break;
            case 2: // Inactivos
                if (per.getEstado() == false) mostrar = true;
                break;
            default: // Todos
                mostrar = true;
                break;
        }

        if (mostrar) {
            per.mostrar();
            cout << endl;
            contadorMostrados++;
        }
    }

    if (contadorMostrados == 0) {
        cout << "No hay clientes que coincidan con el filtro seleccionado." << endl;
    }
}
bool ArchivoCliente::eliminarCliente(int dni) {
    int pos = buscarCliente(dni);
    if (pos == -1) {
        return false;
    }

    int cant = contarClientes();
    FILE *pOriginal = fopen(nombreArchivo, "rb");
    if (pOriginal == nullptr) return false;

    FILE *pTemporal = fopen("clientes.tmp", "wb");
    if (pTemporal == nullptr) {
        fclose(pOriginal);
        return false;
    }

    for (int i = 0; i < cant; i++) {
        Persona per = leerArchivo(i);
        if (per.getDNI() != dni) {
            fwrite(&per, sizeof(Persona), 1, pTemporal);
        }
    }

    fclose(pOriginal);
    fclose(pTemporal);

    if (remove(nombreArchivo) != 0) return false;
    if (rename("clientes.tmp", nombreArchivo) != 0) return false;

    return true;
}
