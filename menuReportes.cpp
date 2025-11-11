#include<iostream>
#include "reportes.h"
#include "rlutil.h"

using namespace std;

void menuReportes(){
    int opcionReporte;

    cout << " == REPORTES == " << endl;
    cout << "1 - Actividad con mas ingresos" << endl;
    cout << "2 - Actividad mas recurrida" << endl;
    cout << "3 - Ingresos por mes y modalidad" << endl;
    cout << "4 - Clientes no anotados en el anio actual" << endl;
    cout << "Opcion: ";
    cin >> opcionReporte;

    rlutil::cls();

    do
    {
        switch(opcionReporte)
        {
        case 1:
            rlutil::cls();

            actMasIngreso();

            rlutil::anykey();
            rlutil::cls();
            break;
        case 2:
            rlutil::cls();

            actMasRecurrida();

            rlutil::anykey();
            rlutil::cls();
            break;
        case 3:
            rlutil::cls();

            ingresoPorMesYModalidad();

            rlutil::anykey();
            rlutil::cls();
            break;
        case 4:
            rlutil::cls();

            clientesNoAnotadosAnioActual();

            rlutil::anykey();
            rlutil::cls();

            break;
        }
    }while(opcionReporte != 0);
}
