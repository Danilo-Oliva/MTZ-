#include<iostream>
#include "cargarCadena.h"
#include "clsActividad.h"
#include "clsDomicilio.h"
#include "clsFecha.h"
#include "clsPersona.h"
#include "clsFichaMedica.h"
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
#include "clsArchivoFichaMedica.h"
#include "rlutil.h"
using namespace std;

int gestionMenuMostrar(){
    int opc_mostrar;
    cout << "Que archivo quiere mostrar?" << endl;
    cout << "1. Mostrar Cliente" << endl;
    cout << "2. Mostrar Actividad" << endl;
    cout << "3. Mostrar Ficha Medica" << endl;
    cout << "0. Salir del menu" << endl;
    cout << "Elegir opcion: ";
    cin >> opc_mostrar;
    return opc_mostrar;
}

void accionarMenuMostrar(){
    ArchivoCliente arc;
    ArchivoActividad arcAct;
    ArchivoFichaMedica arcFM;

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
                case 3:
                    system("cls");

                    arcFM.listar();

                    system("pause");
                    system("cls");
                    break;
                case 0:
                    cout << "Volviendo... " << endl;
                    break;
                default:
                    cout << "Opcion incorrecta" << endl;
                    break;
                }
    }while(opc_mostrar != 0);
}
