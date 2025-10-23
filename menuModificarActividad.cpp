#include <iostream>
#include "rlutil.h"
#include "clsArchivoActividad.h"
#include "clsActividad.h"
#include "cargarCadena.h"

using namespace std;

void imprimirMenuModificarAct() {
    cout << "===============================" << endl;
    cout << "   QUE ATRIBUTO MODIFICAR?" << endl;
    cout << "===============================" << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Cuota base" << endl;
    cout << "3. Estado (Activar / Desactivar)" << endl;
    cout << "-------------------------------" << endl;
    cout << "0. VOLVER" << endl;
    cout << "===============================" << endl;
    cout << "SELECCIONE UNA OPCION: ";
}

void menuModificarActividad() {
    ArchivoActividad arch("actividad.dat");
    Actividad act;
    int id, pos, opcion;

    cout << "Ingrese el ID de la actividad a modificar: ";
    cin >> id;

    pos = arch.buscarActividad(id);

    if (pos == -1) {
        cout << "ERROR: No se encontro una actividad con el ID " << id << "." << endl;
        rlutil::anykey();
        return;
    }

    do {
        system("cls");
        cout << "--- MODIFICANDO ACTIVIDAD ---" << endl;
        act = arch.leerArchivo(pos);
        act.mostrar();
        cout << endl;

        imprimirMenuModificarAct();
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case 1:
                {
                    char nuevoNombre[50];
                    cout << "Ingrese el nuevo nombre: ";
                    cargarCadena(nuevoNombre, 49);
                    act.setNombre(nuevoNombre);
                }
                break;
            case 2:
                {
                    float nuevaCuota;
                    cout << "Ingrese el nuevo valor de la cuota base: $";
                    cin >> nuevaCuota;
                    act.setCuotaBase(nuevaCuota);
                }
                break;

            case 3:
                {
                    bool estadoActual = act.getEstado();
                    act.setEstado(!estadoActual);
                    cout << "Estado cambiado a: " << (act.getEstado() ? "Activo" : "Inactivo") << endl;
                }
                break;
            case 0:
                cout << "Volviendo al menu anterior..." << endl;
                break;
            default:
                cout << "Opcion incorrecta." << endl;
                break;
        }

        if (opcion >= 1 && opcion <= 4) {
            if (arch.modificarActividad(act, pos)) {
                cout << "Actividad modificada con exito!" << endl;
            } else {
                cout << "ERROR: No se pudo guardar la modificacion." << endl;
            }
        }

        if (opcion != 0){
            rlutil::anykey();
        }

    } while (opcion != 0);
}
