#include<iostream>
#include "clsArchivoCliente.h"
#include "clsArchivoInscripcion.h"
#include "clsPersona.h"
#include "menusVisual.h"
#include "listadoVisual.h"
#include "rlutil.h"
#include "menuModificarCliente.h"
#include "tunearMenu.h"

using namespace std;

void ingresarNuevoCliente()
{
    ArchivoCliente arch("clientes.dat");
    int dni = pedirDNI("NUEVO CLIENTE:");

    if (arch.buscarCliente(dni) != -1)
    {
        mostrarMensaje("ERROR: Ya existe un cliente con ese DNI.", rlutil::LIGHTRED);
        return;
    }

    Persona per;
    per.setDNI(dni);

    if (mostrarFormularioCargaCliente(per))
    {
        if (arch.inscribirCliente(per))
        {
            mostrarMensaje("Cliente guardado con exito.", rlutil::LIGHTGREEN);
        }
        else
        {
            mostrarMensaje("ERROR: No se pudo guardar el cliente.", rlutil::LIGHTRED);
        }
    }
    else
    {
        mostrarMensaje("Operacion cancelada por el usuario.", rlutil::YELLOW);
    }
        rlutil::cls();
        imprimirMenuClientes();
}

void menuListarClientes()
{
    ArchivoCliente arch("clientes.dat");
    int opcion, y = 0;
        system("cls");

    do
    {
        opcion = -1;

        opcion = mostrarMenuListarClientes(opcion, y);


        switch (opcion)
        {
        case 1:
            arch.listar(1);
            rlutil::anykey();
            rlutil::cls();
            break;
        case 2:
            arch.listar(2);
            rlutil::anykey();
            rlutil::cls();
            break;
        case 3:
            arch.listar(0);
            rlutil::anykey();
            rlutil::cls();
            break;
        }
    }
    while (opcion != 0);
        imprimirMenuClientes();
}
void eliminarClientePermanente()
{
    ArchivoCliente archClientes("clientes.dat");
    int dni = pedirDNI("ELIMINAR CLIENTE:");
    int pos = archClientes.buscarCliente(dni);

    if (pos == -1)
    {
        mostrarMensaje("ERROR: No se encontro cliente con ese DNI.", rlutil::LIGHTRED);
        rlutil::cls();
        imprimirMenuClientes();
        return;
    }

    Persona per = archClientes.leerArchivo(pos);


    if (mostrarConfirmacion("ADVERTENCIA!", "Esta accion es irreversible. Eliminar?"))
    {

        int nroSocioAEliminar = per.getNumeroSocio();
        ArchivoInscripcion archInscripciones("inscripciones.dat");
        int cantInscripciones = archInscripciones.contarInscripciones();

        for (int i = 0; i < cantInscripciones; i++)
        {
            InscripcionActividad ins = archInscripciones.leerInscripcion(i);
            if (ins.getNumeroSocio() == nroSocioAEliminar)
            {
                ins.setEstado(false);
                archInscripciones.modificarInscripcion(ins, i);
            }
        }

        if (archClientes.eliminarCliente(dni))
        {
            mostrarMensaje("Cliente eliminado y sus inscripciones desactivadas.", rlutil::YELLOW);
        }
        else
        {
            mostrarMensaje("ERROR: No se pudo eliminar el registro.", rlutil::LIGHTRED);
        }
    }
    else
    {
        mostrarMensaje("Operacion cancelada por el usuario.", rlutil::YELLOW);
    }
    rlutil::cls();
    imprimirMenuClientes();
}
void buscarClientePorDNI()
{
    ArchivoCliente arch("clientes.dat");
    int dni = pedirDNI("BUSCAR CLIENTE:");
    int pos = arch.buscarCliente(dni);

    if (pos != -1)
    {
        system("cls");
        Persona per = arch.leerArchivo(pos);
        dibujarFichaCliente(per);
        rlutil::anykey();
    }
    else
    {
        mostrarMensaje("ERROR: No se encontro cliente con ese DNI.", rlutil::LIGHTRED);
    }
    rlutil::cls();
    imprimirMenuClientes();
}
void menuClientes()
{
        rlutil::cls();
        imprimirMenuClientes();
    int opcion, y = 0;
    do
    {
        opcion = -1;

        opcion = interactuarMenuClientes(opcion, y);


        switch (opcion)
        {
        case 1:
            ingresarNuevoCliente();
            break;
        case 2:
            menuModificarCliente();
            break;
        case 3:
            menuListarClientes();
            break;
        case 4:
            buscarClientePorDNI();
            break;
        case 5:
            eliminarClientePermanente();
            break;
        }
    }
    while (opcion != 0);
        rlutil::cls();
        imprimirMenuGestion();
}
