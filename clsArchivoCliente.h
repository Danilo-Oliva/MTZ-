#ifndef GUARDARDATOS_H_INCLUDED
#define GUARDARDATOS_H_INCLUDED

#include "clsPersona.h"


class ArchivoCliente
{
private:
    char nombreArchivo[30];
    Persona per;
public:
    ArchivoCliente(const char *n = "clientes.dat", Persona _per = Persona());
    int contarClientes();
    int buscarCliente(int);
    Persona leerArchivo(int);
    bool inscribirCliente(Persona);
    bool modificarCliente(Persona, int);
    void listar(int modoListado = 1);
    bool eliminarCliente(int dni);
};

#endif // GUARDARDATOS_H_INCLUDED
