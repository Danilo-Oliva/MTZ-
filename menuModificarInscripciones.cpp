#include <iostream>
#include <cstring>
#include "clsArchivoInscripcion.h"
#include "clsPersona.h"
#include "cargarCadena.h"
#include "listadoVisual.h"
#include "menusVisual.h"
#include "rlutil.h"

using namespace std; /// ESTO HAY QUE HACERLO BIEN DESPUES
/*
void menuModificarInscripcion()
{
    ArchivoInscripcion archInscripciones("inscripciones.dat");
    int cantInscrip = archInscripciones.contarInscripciones();

    if(cantInscrip == 0)
    {
        cout << "ERROR: No hay inscripciones. Por favor ingrese inscripciones" << endl;
        return;
    }
    int nroSocio = pedirNumSocio("MODIFICAR INSCRIPCION");
    int idAct = pedirIdActividad();


    int pos = archInscripciones.buscarInscripcionGlobal(nroSocio, idAct);

    if (pos == -1) {
        mostrarMensaje("No se encontro la inscripcion del cliente a esta actividad.", rlutil::RED);
        rlutil::anykey();
        return;
    }
    Persona per = archInscripciones.leerArchivo(pos);

    int opcion = -1, y = 0;
    mostrarMenuModificarCliente(per, opcion, y);

    if(archInscripciones.modificarInscripcion(per, pos))
    {
        rlutil::locate(23, 25);
        cout << "Inscripcion modificada con exito." << endl;
    }
    else
    {
        rlutil::locate(23, 25);
        cout << "Error al modificar la inscripcion." << endl;
    }
    rlutil::anykey();
}

*/
