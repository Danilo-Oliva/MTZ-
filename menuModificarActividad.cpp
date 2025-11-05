#include <iostream>
#include <cstring>
#include <cstdio>
#include "rlutil.h"
#include "clsArchivoActividad.h"
#include "clsActividad.h"
#include "cargarCadena.h"
#include "menusVisual.h"
#include "tunearMenu.h"

using namespace std;

void menuModificarActividad()
{
    rlutil::cls();

    ArchivoActividad arc("actividades.dat");
    int cantAct = arc.contarActividades();

    if(cantAct == 0)
    {
        cout << "No hay actividades registradas"<< endl;
        rlutil::anykey();
        rlutil::cls();
        imprimirMenuActividades();
        return;
    }

    int id;
    cout << "Ingrese ID de la actividad a modificar ndeah anashe input baby yoda: ";
    cin >> id;
    int pos = arc.buscarActividad(id);


    if (pos == -1)
    {
        mostrarMensaje("No se encontro ninguna actividad con ese ID.", rlutil::LIGHTRED);
        imprimirMenuActividades();
        return;
    }

    Actividad obj = arc.leerArchivo(pos);

while(true){
    rlutil::cls();
    obj.mostrar();

    ArchivoActividad arch("actividades.dat");
    int opcion;
    cout << endl;
    cout << "1- Cambiar nombre" <<endl;
    cout << "2- Cambiar cuota base" << endl;
    cout << "0- Salir" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cout << endl;

    switch(opcion)
    {
    case 1:
        cout<<"Ingrese el nuevo nombre: ";
        char nombre[50];
        cargarCadena(nombre, 49);
    if (arch.buscarActividadPorNombre(nombre) != -1)
    {
        mostrarMensaje("ERROR: Ya existe una actividad con ese nombre.", rlutil::LIGHTRED);
    }
    else
    {

        obj.setNombre(nombre);
        arc.modificarActividad(obj, pos);
    }
        rlutil::cls();
        break;
    case 2:
        cout << "Ingrese la nueva cuota base: ";
        float cuota;
        cin >> cuota;

        obj.setCuotaBase(cuota);
        arc.modificarActividad(obj, pos);
        rlutil::cls();
        break;
    case 0:
        rlutil::cls();
        imprimirMenuActividades();
        return;
        break;
    default:
        cout << "Opcion Incorrecta" << endl;
        rlutil::anykey();
        rlutil::cls();
        break;
    }

}
    rlutil::anykey();
    rlutil::cls();
    imprimirMenuActividades();

}

//void imprimirMenuModificarAct(Actividad &reg) {
//    rlutil::cls();
//    int x = 20, yStart = 5;
//    rlutil::hidecursor();
//
//    parteArribaMenu(x, yStart, 52);
//    for (int i = 0; i < 6; i++) bordesMenu(x, yStart + 1 + i, 52);
//    parteAbajoMenu(x, yStart + 7, 52);
//    separarMenues(x, yStart + 5, 52);
//
//    escribirTexto("  M O D I F I C A R  A C T I V I D A D ", x + 10, yStart + 1);
//
//    char texto[128];
//    char numero[32];
//    int anchoFijo = 40;
//    int len;
//
//    // NOMBRE
//    strcpy(texto, "NOMBRE        : ");
//    strcat(texto, reg.getNombre());
//    // rellenar a anchoFijo
//    len = (int)strlen(texto);
//    while (len < anchoFijo && len < (int)sizeof(texto) - 1) {
//        texto[len++] = ' ';
//    }
//    texto[len] = '\0';
//    escribirTexto(texto, x + 3, yStart + 3);
//
//    // CUOTA BASE (float) -> convertir a texto y concatenar
//    sprintf(numero, "%.2f", reg.getCuotaBase());
//    strcpy(texto, "CUOTA BASE    : ");
//    strcat(texto, numero);
//    // rellenar a anchoFijo
//    len = (int)strlen(texto);
//    while (len < anchoFijo && len < (int)sizeof(texto) - 1) {
//        texto[len++] = ' ';
//    }
//    texto[len] = '\0';
//    escribirTexto(texto, x + 3, yStart + 4);
//
//    escribirTexto("     GUARDAR Y VOLVER     ", x + 15, yStart + 6);
//}
//
//int interactuarMenuModificarAct(int &opcionMenu, int &y)
//{
//    int x = 20, yStart = 5;
//    mostrarSoloUnCursor(x + 1, yStart + 3, y);
//    int tecla = rlutil::getkey();
//    if(tecla == 1)
//    {
//        switch(y)
//        {
//        case 0:
//            opcionMenu = 1; /// MODIFICAR NOMBRE
//            break;
//        case 1:
//            opcionMenu = 2; /// MODIFICAR CUOTA
//            break;
//        case 3:
//            opcionMenu = 0; /// VOLVER
//            break;
//        }
//    }
//    else if(tecla > 13) y = accionarCursorCambios(x + 1, yStart + 3, y, tecla, 2);
//    return opcionMenu;
//}
//
//void menuModificarActividad() {
//    rlutil::cls();
//    int x = 20, yStart = 5;
//    ArchivoActividad arch("actividades.dat");
//
//    int cantAct = arch.contarActividades();
//
//    if(cantAct == 0){
//        mostrarMensaje("No hay actividades registradas", rlutil::YELLOW);
//        rlutil::cls();
//        imprimirMenuActividades();
//        return;
//    }
//
//    Actividad act;
//    int id, pos, y = 0;
//
//    cout << "Ingrese el ID de la actividad a modificar: ";
//    cin >> id;
//
//    pos = arch.buscarActividad(id);
//    act = arch.leerArchivo(pos);
//
//    if (pos == -1) {
//        cout << "ERROR: No se encontro una actividad con el ID " << id << "." << endl;
//        rlutil::anykey();
//        rlutil::cls();
//        imprimirMenuActividades();
//        return;
//    }
//
//        imprimirMenuModificarAct(act);
//
//
//    while (true) {
//        int yCursor = 0;
//        if (y == 0) yCursor = yStart + 3;      // DNI
//        else if (y == 1) yCursor = yStart + 4; // NOMBRE
//        else if (y == 2) yCursor = yStart + 6; // APELLIDO
//
//        if (y == 2) rlutil::locate(x + 15, yCursor);
//        else rlutil::locate(x + 1, yCursor);
//        cout << (char)175;
//
//        int tecla = rlutil::getkey();
//
//        if (y == 2) rlutil::locate(x + 15, yCursor);
//        else rlutil::locate(x + 1, yCursor);
//        cout << " " << endl;
//
////        system("cls");
////        cout << "--- MODIFICANDO ACTIVIDAD ---" << endl;
//        act = arch.leerArchivo(pos);
////        act.mostrar();
////        cout << endl;
//
//        if(tecla == 1)
//        {
//        switch (y) {
//            case 0:
//                {
//                    char nuevoNombre[50];
//                    rlutil::cls();
//
//                    cout << "Ingrese el nuevo nombre: ";
//                    cargarCadena(nuevoNombre, 49);
//                    act.setNombre(nuevoNombre);
//
//                }
//                break;
//            case 1:
//                {
//                    float nuevaCuota;
//                    rlutil::cls();
//                    cout << "Ingrese el nuevo valor de la cuota base: $";
//                    cin >> nuevaCuota;
//                    act.setCuotaBase(nuevaCuota);
//                    break;
//                }
//            case 2:
//                rlutil::cls();
//                if (arch.modificarActividad(act, pos)) {
//                    cout << "Actividad modificada con exito!" << endl;
//                } else {
//                    cout << "ERROR: No se pudo guardar la modificacion." << endl;
//                }
//                rlutil::anykey();
//
//                rlutil::cls();
//                imprimirMenuActividades();
//
//                return;
//            }
//        }
//        else if (tecla == rlutil::KEY_UP)
//        {
//            y--;
//            if (y < 0) y = 2;
//        }
//        else if (tecla == rlutil::KEY_DOWN)
//        {
//            y++;
//            if (y > 2) y = 0;
//        }
//
//
//    }
//
//
//}
