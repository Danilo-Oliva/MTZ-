#include<iostream>
#include "menusVisual.h"
#include "reportes.h"
#include "rlutil.h"

using namespace std;

void menuReportes(){
    rlutil::cls();
    imprimirMenuReportes();
    int opcion, y = 0;
    do
    {
        opcion = -1;

        opcion = interactuarMenuReportes(opcion, y);


        switch (opcion)
        {
        case 1:
            rlutil::cls();

            actMasIngreso();

            rlutil::anykey();
            rlutil::cls();
            imprimirMenuReportes();
            break;
        case 2:
            rlutil::cls();

            actMasRecurrida();

            rlutil::anykey();
            rlutil::cls();
            imprimirMenuReportes();
            break;
        case 3:
            rlutil::cls();

            ingresoPorMesYModalidad();

            rlutil::anykey();
            rlutil::cls();
            imprimirMenuReportes();
            break;
        case 4:
            rlutil::cls();

            clientesNoAnotadosAnioActual();

            rlutil::anykey();
            rlutil::cls();
            imprimirMenuReportes();
            break;
        }
    }
    while (opcion != 0);
    rlutil::cls();
    imprimirMenuGestion();
}
