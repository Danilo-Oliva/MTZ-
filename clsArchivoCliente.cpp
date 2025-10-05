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
void ArchivoCliente::listar()
{
    Persona per;
    int contarCli = contarClientes();


    for(int i = 0; i < contarCli; i++)
    {
        per = leerArchivo(i);
        per.mostrar();
        cout << endl;
    }
}
