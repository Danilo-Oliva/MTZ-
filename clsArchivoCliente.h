#ifndef GUARDARDATOS_H_INCLUDED
#define GUARDARDATOS_H_INCLUDED

#include "clsPersona.h"
#include "clsFichaMedica.h"
#include "Cliente.h"

class ArchivoCliente
{
private:
    char nombreArchivo[30];
    Cliente cli;
public:
    ArchivoCliente(const char *n = "clientes.dat", Cliente _cli = Cliente());
    int contarClientes();
    int buscarCliente(int);
    Cliente leerArchivo(int);
    bool inscribirCliente(Cliente);
    bool modificarCliente(Cliente, int);
    void listar();
};

#endif // GUARDARDATOS_H_INCLUDED
