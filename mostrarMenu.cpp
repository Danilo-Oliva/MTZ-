#include<iostream>
#include "cargarCadena.h"
#include "clsActividad.h"
#include "clsDomicilio.h"
#include "clsFecha.h"
#include "clsPersona.h"
#include "clsFichaMedica.h"
#include "clsArchivoCliente.h"
#include "clsArchivoActividad.h"
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
    Actividad act;
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
                case 3:
                    /// PONER ACA MOSTRAR FICHA MEDICA ///
                    break;
                case 0:
                    cout << "Saliendo... " << endl;
                    break;
                default:
                    cout << "Opcion incorrecta" << endl;
                    break;
                }
    }while(opc_mostrar != 0);
}
