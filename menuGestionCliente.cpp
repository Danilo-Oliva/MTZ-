#include<iostream>
#include"clsArchivoCliente.h"
#include"clsPersona.h"
#include "menusVisual.h"
#include "listadoVisual.h"
#include "rlutil.h"
#include "menuModificarCliente.h"

using namespace std;

void ingresarNuevoCliente() {
    ArchivoCliente arch("clientes.dat");
    int dni = pedirDNI("NUEVO CLIENTE:");

    if (arch.buscarCliente(dni) != -1) {
        mostrarMensaje("ERROR: Ya existe un cliente con ese DNI.", rlutil::LIGHTRED);
        return;
    }

    Persona per;
    per.setDNI(dni);

    if (mostrarFormularioCargaCliente(per)) {
        if (arch.inscribirCliente(per)) {
            mostrarMensaje("Cliente guardado con exito.", rlutil::LIGHTGREEN);
        } else {
            mostrarMensaje("ERROR: No se pudo guardar el cliente.", rlutil::LIGHTRED);
        }
    } else {
        mostrarMensaje("Operacion cancelada por el usuario.", rlutil::YELLOW);
    }
}

void menuListarClientes()
{
    ArchivoCliente arch("clientes.dat");
    int opcion, y = 0;

    do
    {
        opcion = -1;
        system("cls");

        opcion = mostrarMenuListarClientes(opcion, y);

        system("cls");

        switch (opcion)
        {
        case 1:
            arch.listar(1);
            rlutil::anykey();
            break;
        case 2:
            arch.listar(2);
            rlutil::anykey();
            break;
        case 3:
            arch.listar(0);
            rlutil::anykey();
            break;
        }
    }
    while (opcion != 0);
}
void eliminarClientePermanente() {
    ArchivoCliente arch("clientes.dat");
    int dni = pedirDNI("ELIMINAR CLIENTE:");
    int pos = arch.buscarCliente(dni);

    if (pos == -1) {
        mostrarMensaje("ERROR: No se encontro cliente con ese DNI.", rlutil::LIGHTRED);
        return;
    }

    system("cls");
    Persona per = arch.leerArchivo(pos);
    dibujarFichaCliente(per);
    rlutil::anykey();

    if (mostrarConfirmacion("ADVERTENCIA!", "Esta accion es irreversible. Eliminar?")) {
        if (arch.eliminarCliente(dni)) {
            mostrarMensaje("Cliente eliminado permanentemente.", rlutil::YELLOW);
        } else {
            mostrarMensaje("ERROR: No se pudo eliminar el registro.", rlutil::LIGHTRED);
        }
    }
}
void buscarClientePorDNI() {
    ArchivoCliente arch("clientes.dat");
    int dni = pedirDNI("BUSCAR CLIENTE:");
    int pos = arch.buscarCliente(dni);

    if (pos != -1) {
        system("cls");
        Persona per = arch.leerArchivo(pos);
        dibujarFichaCliente(per);
        rlutil::anykey();
    } else {
        mostrarMensaje("ERROR: No se encontro cliente con ese DNI.", rlutil::LIGHTRED);
    }
}
void menuClientes()
{
    int opcion, y = 0;
    do
    {
        opcion = -1;
        rlutil::cls();

        opcion = mostrarMenuClientes(opcion, y);
        rlutil::cls();


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
}
