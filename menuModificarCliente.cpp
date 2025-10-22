#include <iostream>
#include <cstring>
#include "clsArchivoCliente.h"
#include "clsPersona.h"
#include "cargarCadena.h"
#include "listadoVisual.h"
#include "menusVisual.h"
#include "rlutil.h"

using namespace std;

void menuModificarCliente()
{
    ArchivoCliente arch("clientes.dat");

    int dni = pedirDNI("MODIFICAR CLIENTE: ");
    int pos = arch.buscarCliente(dni);

    if (pos == -1) {
        mostrarMensaje("No se encontro un cliente con ese DNI.", rlutil::LIGHTRED);
        rlutil::anykey();
        return;
    }
    Persona per = arch.leerArchivo(pos);

    int opcion = -1, y = 0;
    mostrarMenuModificarCliente(per, opcion, y);

    if(arch.modificarCliente(per, pos))
    {
        rlutil::locate(23, 25);
        cout << "Cliente modificado con exito." << endl;
    }
    else
    {
        rlutil::locate(23, 25);
        cout << "Error al modificar el cliente." << endl;
    }
    rlutil::anykey();
}
