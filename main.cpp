#include <iostream>
#include "clsActividad.h"
#include "clsPersona.h"
#include "cargarDatos.h"
#include "clsArchivoCliente.h"
#include "menuGestion.h"
#include "rlutil.h"
#include "tunearMenu.h"

using namespace std;


int main()
{
    rlutil::hidecursor();
    int opcionMenu = -1, y = 0;

    while(true)
    {
        mostrarMenuPrincipal(opcionMenu, y);

        if (opcionMenu != -1)
        {
            switch(opcionMenu)
            {
            case 1:
                system("cls");
                cout << "Por ahora nada :v" << endl;
                system("pause");
                break;

            case 2:
                accionarMenu();
                break;

            case 0:
                return 0;
            }
            system("cls");

            opcionMenu = -1;
        } /// CIERRA IF

    } ///FIN WHILE TRUE
}
