#include <iostream>
#include <cstring>
#include "clsArchivoCliente.h"

using namespace std;

ArchivoCliente::ArchivoCliente(const char *n, Cliente _cli)
{
    strcpy(nombreArchivo, n);
    cli = _cli;
}

int ArchivoCliente::contarClientes()
{
    FILE *p = fopen(nombreArchivo, "rb");
    if(p == nullptr)
    {
        return -1;
    }
    fseek(p, SEEK_SET, SEEK_END); /// BUSCAR REGISTROS

    int bytes = ftell(p); /// ESTABLECE LOS BYTES DE LA ULTIMA POSICION DEL ULTIMO REGISTRO

    fclose(p);
    return bytes/sizeof(cli); /// DIVIDE LOS BYTES ESTABLECIDOS ANTES POR LOS BYTES TOTALES DE UN (1) REGISTRO
    /// EJ: 340/170 = 2 REGISTROS (el ejemplo es para guiarnos, no es realista)
}

int ArchivoCliente::buscarCliente(int dniBuscado)
{
    int cantReg = contarClientes();
    for (int i = 0; i < cantReg; i++)
    {
        cli = leerArchivo(i);
        if(cli.p1.getDNI() == dniBuscado)
        {
            return i;
        }
    }
    return -1;
}

Cliente ArchivoCliente::leerArchivo(int pos)
{
    FILE *p = fopen(nombreArchivo, "rb");
    Cliente cli;
    if(p == nullptr)
    {
        cli.p1.setDNI(-1);
        return cli;
    }
    fseek(p, pos * sizeof cli, 0); ///MOVER EL PUNTERO DEL ARCHIVO A LA POSICION DESEADA, POS LO CALCULA EN BYTES, 0 ES QUE VA DEL INICIO
    cli.p1.setDNI(-2); /// SE DEVUELVE -2 EN CASO DE NO ENCONTRAR EL DNI
    fread(&cli.p1, sizeof cli, 1, p); /// LEE EL ARCHIVO Y GUARDA EL DNI QUE SE BUSCA
    fclose(p);
    return cli; /// RETORNA DNI QUE SE BUSCA (o errores si los hay)
}
bool ArchivoCliente::inscribirCliente(Cliente cli)
{
    FILE *p = fopen(nombreArchivo, "ab");
    if(p == nullptr)
    {
        return false;
    }

    int numSocio = contarClientes() + 1;
    cli.p1.setNumeroSocio(numSocio);

    bool escribio = fwrite(&cli, sizeof cli, 1, p);
    fclose(p);
    return escribio;
}
bool ArchivoCliente::modificarCliente(Cliente cli, int pos)
{
    FILE *p = fopen(nombreArchivo, "rb+");
    if(p==nullptr)
    {
        return false;
    }
    fseek(p, pos * sizeof cli, 0);
    bool escribio = fwrite(&cli, sizeof cli, 1, p);
    fclose(p);
    return escribio;
}
void ArchivoCliente::listar()
{
    Cliente cli;
    int contarCli = contarClientes();
    for(int i = 0; i < contarCli; i++)
    {
        cli = leerArchivo(i);
        cli.p1.mostrar();
        cli.act.mostrar();
        cli.fm.mostrar();
        cout << endl;
    }
}
