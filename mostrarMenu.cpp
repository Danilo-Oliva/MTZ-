#include<iostream>
#include "clsActividad.h"
#include "clsFecha.h"
#include "clsPersona.h"
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
#include "rlutil.h"
using namespace std;

int gestionMenuMostrar(){
    int opc_mostrar;
    cout << "Que archivo quiere mostrar?" << endl;
    cout << "1. Mostrar Cliente" << endl;
    cout << "2. Mostrar Actividad" << endl;
    cout << "0. Salir del menu" << endl;
    cout << "Elegir opcion: ";
    cin >> opc_mostrar;
    return opc_mostrar;
}

void accionarMenuMostrar(){
    ArchivoCliente arc;
    ArchivoActividad arcAct;

    int opc_mostrar;

    do {
        opc_mostrar = gestionMenuMostrar();

        switch(opc_mostrar)
                {
                case 1:
                    system("cls");

                    arc.listar();

                    system("pause");
                    system("cls");
                    break;
                case 2:
                    system("cls");

                    arcAct.listar();

                    system("pause");
                    system("cls");
                    break;
                case 0:
                    cout << "Volviendo... " << endl;
                    break;
                default:
                    system("cls");

                    cout << "Opcion incorrecta" << endl;

                    system("pause");
                    system("cls");
                    break;
                }
    }while(opc_mostrar != 0);
}
