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
        rlutil::cls();
        imprimirMenuClientes();
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

    int cantClientes = arch.contarClientes();

    if(cantClientes == 0)
    {
        mostrarMensaje("No hay clientes registrados", rlutil::YELLOW);
        rlutil::cls();
        imprimirMenuClientes();
        return;

    }

    int opcion, y = 0;
    system("cls");
    imprimirMenuListarClientes();
    do
    {
        opcion = -1;

        opcion = interactuarMenuListarClientes(opcion, y);


        switch (opcion)
        {
        case 1:
            arch.listar(1);

            rlutil::anykey();
            rlutil::cls();
            imprimirMenuListarClientes();
            break;
        case 2:
            arch.listar(2);

            rlutil::anykey();
            rlutil::cls();
            imprimirMenuListarClientes();
            break;
        case 3:
            arch.listar(0);

            rlutil::anykey();
            rlutil::cls();
            imprimirMenuListarClientes();
            break;
        }
    }
    while (opcion != 0);
    imprimirMenuClientes();
}
void modificarEstadoCliente()
{
    rlutil::cls();
    Persona per;
    ArchivoCliente archCli("clientes.dat", per);

    int dni = pedirDNI("MODIFICAR ESTADO DE CLIENTE:");
    int pos = archCli.buscarCliente(dni);
    if (pos == -1)
    {
        mostrarMensaje("Cliente no encontrado.", rlutil::LIGHTRED);
        rlutil::anykey();
        return;
    }

    Persona cliente = archCli.leerArchivo(pos);

    bool salir = false;

        rlutil::cls();
        escribirTexto("MODIFICAR ESTADO DE CLIENTE", 5, 1);
        rlutil::locate(5, 3);
        cout << "NRO DE SOCIO : " << cliente.getNumeroSocio();
        rlutil::locate(5, 4);
        cout << "DNI          : " << cliente.getDNI();
        rlutil::locate(5, 5);
        cout << "NOMBRE       : " << cliente.getNombre() << " " << cliente.getApellido();
        rlutil::locate(5, 8);
        cout << "Presione ENTER para cambiar estado o ESC para volver.";

    while (!salir)
    {
        rlutil::locate(5, 6);
        cout << "                       ";
        rlutil::locate(5, 6);
        rlutil::setBackgroundColor(rlutil::LIGHTRED);
        rlutil::setColor(rlutil::BLACK);
        cout << "ESTADO       : " << (cliente.getEstado() ? "ACTIVO" : "INACTIVO");


        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::LIGHTRED);
        int tecla = rlutil::getkey();
        if (tecla == rlutil::KEY_ENTER)
        {
            cliente.setEstado(!cliente.getEstado());
        }
        else if (tecla == rlutil::KEY_ESCAPE)
        {
            mostrarMensaje("Estado modificado correctamente", rlutil::YELLOW);
            rlutil::cls();
            imprimirMenuClientes();
            salir = true;
        }
    }
}
void eliminarClientePermanente()
{
    ArchivoCliente arch("clientes.dat");
    int cantClientes = arch.contarClientes();

    if(cantClientes == 0)
    {
        mostrarMensaje("No hay clientes registrados", rlutil::YELLOW);
        rlutil::cls();
        imprimirMenuClientes();
        return;

    }

    int dni = pedirDNI("ELIMINAR CLIENTE:");
    int pos = arch.buscarCliente(dni);

    if (pos == -1)
    {
        mostrarMensaje("ERROR: No se encontro cliente con ese DNI.", rlutil::LIGHTRED);
        rlutil::cls();
        imprimirMenuClientes();
        return;
    }

    Persona per = arch.leerArchivo(pos);


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

        if (arch.eliminarCliente(dni))
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

    int cantClientes = arch.contarClientes();

    if(cantClientes == 0)
    {
        mostrarMensaje("No hay clientes registrados", rlutil::YELLOW);
        rlutil::cls();
        imprimirMenuClientes();
        return;

    }

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
            modificarEstadoCliente();
            break;
        case 6:
            eliminarClientePermanente();
            break;
        }
    }
    while (opcion != 0);
    rlutil::cls();
    imprimirMenuGestion();
}
