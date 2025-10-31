#include <iostream>
#include "rlutil.h"
#include "clsArchivoActividad.h"
#include "clsActividad.h"
#include "cargarCadena.h"
#include "menusVisual.h"
#include "tunearMenu.h"

using namespace std;

void imprimirMenuModificarAct(Actividad &reg) {
    rlutil::cls();
    int x = 20, yStart = 5;
    rlutil::hidecursor();

    parteArribaMenu(x, yStart, 52);
    for (int i = 0; i < 6; i++) bordesMenu(x, yStart + 1 + i, 52);
    parteAbajoMenu(x, yStart + 7, 52);
    separarMenues(x, yStart + 5, 52);

    escribirTexto("  M O D I F I C A R  A C T I V I D A D ", x + 10, yStart + 1);

    string texto;
    int anchoFijo = 40;

        texto = "NOMBRE        : " + string(reg.getNombre());
        texto.resize(anchoFijo, ' ');
        escribirTexto(texto.c_str(), x + 3, yStart + 3);

        texto = "CUOTA BASE    : " + to_string(reg.getCuotaBase());
        texto.resize(anchoFijo, ' ');
        escribirTexto(texto.c_str(), x + 3, yStart + 4);

        escribirTexto("     GUARDAR Y VOLVER     ", x + 15, yStart + 6);
}

void menuModificarActividad() {
    rlutil::cls();
    ArchivoActividad arch("actividades.dat");

    int cantAct = arch.contarActividades();

    if(cantAct == 0){
        mostrarMensaje("No hay actividades registradas", rlutil::YELLOW);
        rlutil::cls();
        imprimirMenuActividades();
        return;
    }

    Actividad act;
    int id, pos, opcion;

    cout << "Ingrese el ID de la actividad a modificar: ";
    cin >> id;

    pos = arch.buscarActividad(id);
    act = arch.leerArchivo(pos);

    if (pos == -1) {
        cout << "ERROR: No se encontro una actividad con el ID " << id << "." << endl;
        rlutil::anykey();
        rlutil::cls();
        imprimirMenuActividades();
        return;
    }

    do {
        system("cls");
        cout << "--- MODIFICANDO ACTIVIDAD ---" << endl;
        act = arch.leerArchivo(pos);
        act.mostrar();
        cout << endl;

        imprimirMenuModificarAct(act);
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
            case 0:
                cout << "Volviendo al menu anterior..." << endl;
                break;
            default:
                cout << "Opcion incorrecta." << endl;
                break;
        }

        if (opcion >= 1 && opcion <= 2) {
            if (arch.modificarActividad(act, pos)) {
                    cout << opcion;
                cout << "Actividad modificada con exito!" << endl;
            } else {
                cout << "ERROR: No se pudo guardar la modificacion." << endl;
            }
        }

        if (opcion != 0){
            rlutil::anykey();
        }

    } while (opcion != 0);
    rlutil::cls();
    imprimirMenuActividades();
}
