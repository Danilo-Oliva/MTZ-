#include <iostream>
#include "rlutil.h"
#include "listadoVisual.h"
#include "clsPersona.h"

using namespace std;

void dibujarTablaClientesHeader()
{
    int limiteTabla = 145;

    rlutil::locate(1, 2);
    cout << char(201) << endl;
    rlutil::locate(2, 2);
    for(int i = 0; i < limiteTabla; i++) cout << char(205);
    rlutil::locate(147, 2);
    cout << char(187) << endl;


    rlutil::locate(8, 2);
    cout << char(203);
    rlutil::locate(20, 2);
    cout << char(203);
    rlutil::locate(50, 2);
    cout << char(203);
    rlutil::locate(80, 2);
    cout << char(203);
    rlutil::locate(93, 2);
    cout << char(203);
    rlutil::locate(108, 2);
    cout << char(203);
    rlutil::locate(138, 2);
    cout << char(203);

    cout << endl;

    rlutil::locate(1, 4);
    cout << char(204) << endl;
    rlutil::locate(2, 4);
    for(int i = 0; i < limiteTabla; i++) cout << char(205);
    cout << char(185) << endl;


    rlutil::locate(8, 4);
    cout << char(206);
    rlutil::locate(20, 4);
    cout << char(206);
    rlutil::locate(50, 4);
    cout << char(206);
    rlutil::locate(80, 4);
    cout << char(206);
    rlutil::locate(93, 4);
    cout << char(206);
    rlutil::locate(108, 4);
    cout << char(206);
    rlutil::locate(138, 4);
    cout << char(206);

    rlutil::locate(1, 3);
    cout << char(186) << "SOCIO";
    rlutil::locate(8, 3);
    cout << char(186) << " DNI";
    rlutil::locate(20, 3);
    cout << char(186) << " NOMBRE";
    rlutil::locate(50, 3);
    cout << char(186) << " APELLIDO";
    rlutil::locate(80, 3);
    cout << char(186) << " NACIMIENTO";
    rlutil::locate(93, 3);
    cout << char(186) << " TELEFONO";
    rlutil::locate(108, 3);
    cout << char(186) << " EMAIL";
    rlutil::locate(138, 3);
    cout << char(186) << " ESTADO " << char(186);
    cout << endl;
}

void dibujarTablaClientesRow(Persona reg, int y)
{
    rlutil::locate(1, y);
    cout << char(186) << " " << reg.getNumeroSocio();
    rlutil::locate(8, y);
    cout << char(186) << " " << reg.getDNI();
    rlutil::locate(20, y);
    cout << char(186) << " " << reg.getNombre();
    rlutil::locate(50, y);
    cout << char(186) << " " << reg.getApellido();
    rlutil::locate(80, y);
    cout << char(186) << " ";
    reg.getFechaNacimiento().mostrar();
    rlutil::locate(93, y);
    cout << char(186) << " " << reg.getTelefono();
    rlutil::locate(108, y);
    cout << char(186) << " " << reg.getEmail();
    rlutil::locate(138, y);
    cout << char(186) << " " << (reg.getEstado() ? "Activo" : "Inactivo") << " " << char(186);
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
