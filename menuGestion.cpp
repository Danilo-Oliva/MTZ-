#include <iostream>
#include "rlutil.h"
#include "menusVisual.h"
#include "menuGestionCliente.h"
#include "menuGestionActividades.h"
#include "menuGestionInscripciones.h"
#include "menuReportes.h"
#include "tunearMenu.h"

using namespace std;


///ACTIVIDAD

///MENU INSCRIPCIONES


///MENU PRINCIPAL
void accionarMenu()
{
    int opcionMenu = -1, y = 0;
    rlutil::cls();

    imprimirMenuGestion();

    do
    {

        interactuarMenuGestion(opcionMenu, y);

        switch(opcionMenu)
        {
        case 1:
            menuClientes();
            break;
        case 2:
            menuActividades();
            break;
        case 3:
            menuInscripciones();

            rlutil::cls();
            imprimirMenuGestion();
            break;
        case 4:
            rlutil::cls();

            menuReportes();

            rlutil::anykey();
            rlutil::cls();
            imprimirMenuGestion();

            break;
        }
        if(opcionMenu != 0) opcionMenu = -1;
    }
    while(opcionMenu != 0);
}
