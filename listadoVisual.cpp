#include <iostream>
#include "rlutil.h"
#include "listadoVisual.h"
#include "clsPersona.h"

using namespace std;

void dibujarTablaClientesHeader()
{
    rlutil::locate(1, 2);
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    rlutil::locate(2, 3);
    cout << "SOCIO";
    rlutil::locate(10, 3);
    cout << "| DNI";
    rlutil::locate(22, 3);
    cout << "| NOMBRE";
    rlutil::locate(40, 3);
    cout << "| APELLIDO";
    rlutil::locate(60, 3);
    cout << "| EMAIL";
    rlutil::locate(90, 3);
    cout << "| ESTADO";
    rlutil::locate(1, 4);
    cout << "------------------------------------------------------------------------------------------------------" << endl;
}

void dibujarTablaClientesRow(Persona reg, int y)
{
    rlutil::locate(2, y);
    cout << reg.getNumeroSocio();
    rlutil::locate(10, y);
    cout << "| " << reg.getDNI();
    rlutil::locate(22, y);
    cout << "| " << reg.getNombre();
    rlutil::locate(40, y);
    cout << "| " << reg.getApellido();
    rlutil::locate(60, y);
    cout << "| " << reg.getEmail();
    rlutil::locate(90, y);
    cout << "| " << (reg.getEstado() ? "Activo" : "Inactivo");
}
void dibujarFichaCliente(Persona reg)
{

    int x = 20, y = 5;


    rlutil::locate(x, y);
    cout << (char)201;
    for(int i=0; i<50; i++) cout << (char)205;
    cout << (char)187;

    for(int i=0; i<10; i++)
    {
        rlutil::locate(x, y + 1 + i);
        cout << (char)186;
        rlutil::locate(x + 51, y + 1 + i);
        cout << (char)186;
    }

    rlutil::locate(x, y + 11);
    cout << (char)200;
    for(int i=0; i<50; i++) cout << (char)205;
    cout << (char)188;

    rlutil::locate(x + 18, y + 1);
    cout << "FICHA DEL CLIENTE";

    rlutil::locate(x + 3, y + 3);
    cout << "NRO DE SOCIO: " << reg.getNumeroSocio();
    rlutil::locate(x + 3, y + 4);
    cout << "DNI           : " << reg.getDNI();
    rlutil::locate(x + 3, y + 5);
    cout << "NOMBRE        : " << reg.getNombre();
    rlutil::locate(x + 3, y + 6);
    cout << "APELLIDO      : " << reg.getApellido();
    rlutil::locate(x + 3, y + 7);
    cout << "TELEFONO      : " << reg.getTelefono();
    rlutil::locate(x + 3, y + 8);
    cout << "EMAIL         : " << reg.getEmail();

    rlutil::locate(x + 3, y + 9);
    cout << "FECHA DE NAC. : ";
    reg.getFechaNacimiento().mostrar();

    rlutil::locate(x + 3, y + 10);
    cout << "ESTADO        : " << (reg.getEstado() ? "Activo" : "Inactivo");

    cout << endl << endl << endl << endl;
}
