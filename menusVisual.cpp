#include<iostream>
#include "rlutil.h"
#include "tunearMenu.h"
#include "menusVisual.h"
#include "clsPersona.h"
#include "cargarCadena.h"
#include <string>

using namespace std;

int mostrarMenuGestion(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 37);
    bordesMenu(24, 6, 37);
    separarMenues(24, 7, 37);
    for (int i = 0; i < 11; i ++) bordesMenu(24, 8 + i, 37);
    parteAbajoMenu(24, 19, 37);

    resaltarMenu("M E N U  D E  G E S T I O N", 30, 6, false);
    resaltarMenu("GESTIONAR    LOS   CLIENTES", 30, 9, y == 0);
    resaltarMenu("GESTIONAR  LAS  ACTIVIDADES", 30, 11, y == 1);
    resaltarMenu("GESTIONAR LAS INSCRIPCIONES", 30, 13, y == 2);
    resaltarMenu("  REPORTES  DEL  PROGRAMA  ", 30, 15, y == 3);
    resaltarMenu("  VOLVER AL MENU PRICIPAL  ", 30, 17, y == 4);


    mostrarCursor(28, 58, 9, y);
    int tecla = rlutil::getkey();
    if(tecla == 1) /// NO SE PASA A LA FUNCION PORQUE TIRA ERROR
    {
        switch(y)
        {
        case 0:
        {
            opcionMenu = 1; /// GESTIONAR LOS CLIENTES
            break;
        }
        case 1:
        {
            opcionMenu = 2; /// GESTIONAR LAS ACTIVIDADES
            break;
        }
        case 2:
        {
            opcionMenu = 3; /// GESTIONAR LAS INSCRIPCIONES
            break;
        }
        case 3:
        {
            opcionMenu = 4; /// REPORTES DEL PROGRAMA
            break;
        }
        case 4:
        {
            opcionMenu = 0; /// VOLVER AL MENU PRICIPAL
            break;
        }
        }
    }
    else if(tecla > 13) y = accionarCursor(y, tecla, 4);

    return opcionMenu;

}
int mostrarMenuClientes(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 33);
    bordesMenu(24, 6, 33);
    separarMenues(24, 7, 33);
    for (int i = 0; i < 14; i ++) bordesMenu(24, 8 + i, 33);
    parteAbajoMenu(24, 22, 33);


    resaltarMenu("M E N U  D E  C L I E N T E S", 27, 6, false);
    resaltarMenu("INGRESAR NUEVO CLIENTE ", 30, 9, y == 0);
    resaltarMenu("  MODIFICAR  CLIENTES  ", 30, 11, y == 1);
    resaltarMenu("   LISTAR   CLIENTES   ", 30, 13, y == 2);
    resaltarMenu("BUSCAR CLIENTES POR DNI", 30, 15, y == 3);
    resaltarMenu("CAMBIAR ESTADO CLIENTES", 30, 17, y == 4);
    resaltarMenu("  BORRAR  UN  CLIENTE  ",30, 19, y == 5 );
    resaltarMenu("VOLVER AL  MENU GESTION", 30, 21, y == 6);


    mostrarCursor(28, 54, 9, y);
    int tecla = rlutil::getkey();
    if(tecla == 1)
    {
        switch(y)
        {
        case 0:
        {
            opcionMenu = 1; /// INGRESA NUEVO CLIENTE
            break;
        }
        case 1:
        {
            opcionMenu = 2; /// MODIFICAR CLIENTES
            break;
        }
        case 2:
        {
            opcionMenu = 3; /// LISTAR   CLIENTES
            break;
        }
        case 3:
        {
            opcionMenu = 4; /// BUSCAR CLIENTES POR DNI
            break;
        }
        case 4:
        {
            opcionMenu = 5; /// CAMBIAR ESTADO CLIENTES
            break;
        }
        case 5:
        {
            opcionMenu = 6; /// BORRAR  UN  CLIENTE
            break;
        }
        case 6:
        {
            opcionMenu = 0; /// VOLVER
            break;
        }
        }
    }
    else if(tecla > 13) y = accionarCursor(y, tecla, 6);

    return opcionMenu;

}
int mostrarMenuActividades(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 31);
    bordesMenu(24, 6, 31);
    separarMenues(24, 7, 31);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 31);
    parteAbajoMenu(24, 17, 31);


    resaltarMenu("M E N U   A C T I V I D A D E S", 25, 6, false);
    resaltarMenu("CREAR NUEVA ACTIVIDAD", 30, 9, y == 0);
    resaltarMenu("MODIFICAR   ACTIVIDAD", 30, 11, y == 1);
    resaltarMenu(" LISTAR  ACTIVIDADES ", 30, 13, y == 2);
    resaltarMenu("VOLVER A MENU GESTION", 30, 15, y == 3);


    mostrarCursor(28, 52, 9, y);
    int tecla = rlutil::getkey();
    if(tecla == 1)
    {
        switch(y)
        {
        case 0:
        {
            opcionMenu = 1; /// CREAR NUEVA ACTIVIDAD
            break;
        }
        case 1:
        {
            opcionMenu = 2; /// MODIFICAR ACTIVIDAD
            break;
        }
        case 2:
        {
            opcionMenu = 3; /// LISTAR ACTIVIDADES
            break;
        }
        case 3:
        {
            opcionMenu = 0; /// VOLVER
            break;
        }
        }
    }
    else if(tecla > 13) y = accionarCursor(y, tecla, 3);

    return opcionMenu;
}
int mostrarMenuInscripciones(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 31);
    bordesMenu(24, 6, 31);
    separarMenues(24, 7, 31);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 31);
    parteAbajoMenu(24, 17, 31);


    resaltarMenu("M E N U   A C T I V I D A D E S", 25, 6, false);
    resaltarMenu("REGISTRAR NUEVA INSCRIPCION ", 30, 9, y == 0);
    resaltarMenu("CAMBIAR  ESTADO  INSCRIPCION", 27, 11, y == 1);
    resaltarMenu(" LISTAR  LAS  INSCRIPCIONES ", 30, 13, y == 2);
    resaltarMenu("VOLVER   AL   MENU   GESTION", 30, 15, y == 3);


    mostrarCursor(26, 55, 9, y);
    int tecla = rlutil::getkey();
    if(tecla == 1)
    {
        switch(y)
        {
        case 0:
        {
            opcionMenu = 1; /// REGISTRAR NUEVA INSCRIPCION
            break;
        }
        case 1:
        {
            opcionMenu = 2; /// CAMBIAR  ESTADO  INSCRIPCION
            break;
        }
        case 2:
        {
            opcionMenu = 3; /// LISTAR  LAS  INSCRIPCIONES
            break;
        }
        case 3:
        {
            opcionMenu = 0; /// VOLVER   AL   MENU   GESTION
            break;
        }
        }
    }
    else if(tecla > 13) y = accionarCursor(y, tecla, 3);

    return opcionMenu;

}
int mostrarMenuListarClientes(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 39);
    bordesMenu(24, 6, 39);
    separarMenues(24, 7, 39);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 39);
    parteAbajoMenu(24, 17, 39);

    resaltarMenu("L I S T A D O  D E  C L I E N T E S", 27, 6, false);

    resaltarMenu("      LISTAR  ACTIVOS      ", 30, 9, y == 0);
    resaltarMenu("     LISTAR  INACTIVOS     ", 30, 11, y == 1);
    resaltarMenu("       LISTAR  TODOS       ", 30, 13, y == 2);
    resaltarMenu("          VOLVER           ", 30, 15, y == 3);

    mostrarCursor(28, 62, 9, y);
    int tecla = rlutil::getkey();
    if(tecla == 1)
    {
        switch(y)
        {
        case 0:
            opcionMenu = 1; /// LISTAR  ACTIVOS
            break;
        case 1:
            opcionMenu = 2; /// LISTAR  INACTIVOS
            break;
        case 2:
            opcionMenu = 3; /// LISTAR  TODOS
            break;
        case 3:
            opcionMenu = 0; /// VOLVER
            break;
        }
    }
    else if(tecla > 13) y = accionarCursor(y, tecla, 3);
    return opcionMenu;
}



int mostrarMenuListarActividades(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 45);
    bordesMenu(24, 6, 45);
    separarMenues(24, 7, 45);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 45);
    parteAbajoMenu(24, 17, 45);

    resaltarMenu("L I S T A D O  D E  A C T I V I D A D E S", 27, 6, false);

    resaltarMenu("        LISTAR   ACTIVAS        ", 30, 9, y == 0);
    resaltarMenu("       LISTAR   INACTIVAS       ", 30, 11, y == 1);
    resaltarMenu("         LISTAR    TODAS         ", 30, 13, y == 2);
    resaltarMenu("            VOLVER             ", 30, 15, y == 3);

    mostrarCursor(28, 66, 9, y);
    int tecla = rlutil::getkey();
    if(tecla == 1)
    {
        switch(y)
        {
        case 0:
            opcionMenu = 1; /// LISTAR  ACTIVOS
            break;
        case 1:
            opcionMenu = 2; /// LISTAR  INACTIVOS
            break;
        case 2:
            opcionMenu = 3; /// LISTAR  TODOS
            break;
        case 3:
            opcionMenu = 0; /// VOLVER
            break;
        }
    }
    else if(tecla > 13) y = accionarCursor(y, tecla, 3);
    return opcionMenu;
}
int mostrarMenuListarInscripciones(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 47);
    bordesMenu(24, 6, 47);
    separarMenues(24, 7, 47);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 47);
    parteAbajoMenu(24, 17, 47);

    resaltarMenu("L I S T A D O  DE  I N S C R I P C I O N E S", 26, 6, false);

    resaltarMenu("        LISTAR ACTIVAS        ", 30, 9, y == 0);
    resaltarMenu("       LISTAR   INACTIVAS       ", 30, 11, y == 1);
    resaltarMenu("        LISTAR TODAS         ", 30, 13, y == 2);
    resaltarMenu("            VOLVER             ", 30, 15, y == 3);

    mostrarCursor(28, 68, 9, y);
    int tecla = rlutil::getkey();
    if(tecla == 1)
    {
        switch(y)
        {
        case 0:
            opcionMenu = 1; /// LISTAR  ACTIVOS
            break;
        case 1:
            opcionMenu = 2; /// LISTAR  INACTIVOS
            break;
        case 2:
            opcionMenu = 3; /// LISTAR  TODOS
            break;
        case 3:
            opcionMenu = 0; /// VOLVER
            break;
        }
    }
    else if(tecla > 13) y = accionarCursor(y, tecla, 3);
    return opcionMenu;
}
int mostrarMenuModificarCliente(Persona &reg, int &opcionMenu, int &y)
{
    int x = 20, y_start = 5;
    int x_labels = x + 3;
    int x_data = x + 19;
    y = 0;

    rlutil::hidecursor();

    while (true)
    {
        parteArribaMenu(x, y_start, 52);
        for (int i = 0; i < 13; i++) bordesMenu(x, y_start + 1 + i, 52);
        parteAbajoMenu(x, y_start + 13, 52);
        resaltarMenu("  M O D I F I C A R   C L I E N T E  ", x + 10, y_start + 1, false);
        separarMenues(x, y_start + 9, 52);


        rlutil::locate(x_labels, y_start + 3);
        cout << "NRO DE SOCIO  : " << reg.getNumeroSocio();
        rlutil::locate(x_labels, y_start + 4);
        cout << "DNI           : " << reg.getDNI();

        string texto;
        int anchoFijo = 45;


        texto = "NOMBRE        : " + string(reg.getNombre());
        texto.resize(anchoFijo, ' ');
        resaltarMenu(texto.c_str(), x_labels, y_start + 5, y == 0);

        texto = "APELLIDO      : " + string(reg.getApellido());
        texto.resize(anchoFijo, ' ');
        resaltarMenu(texto.c_str(), x_labels, y_start + 6, y == 1);


        texto = "TELEFONO      : " + string(reg.getTelefono());
        texto.resize(anchoFijo, ' ');
        resaltarMenu(texto.c_str(), x_labels, y_start + 7, y == 2);


        texto = "EMAIL         : " + string(reg.getEmail());
        texto.resize(anchoFijo, ' ');
        resaltarMenu(texto.c_str(), x_labels, y_start + 8, y == 3);

        resaltarMenu("      GUARDAR Y VOLVER       ", x + 12, y_start + 11, y == 4);

        int tecla = rlutil::getkey();
        switch (tecla)
        {
        case 14:
            y--;
            if (y < 0) y = 4;
            break;
        case 15:
            y++;
            if (y > 4) y = 0;
            break;
        case 1:
            if (y == 4)
            {
                opcionMenu = 0;
                rlutil::setBackgroundColor(rlutil::BLACK);
                rlutil::setColor(rlutil::LIGHTRED);
                return opcionMenu;
            }
            else
            {
                rlutil::showcursor();
                string nuevoDato;
                int y_campo_actual = y_start + 5 + y;
                rlutil::locate(x_data, y_campo_actual);
                cout << string(30, ' ');
                rlutil::locate(x_data, y_campo_actual);
                cin.ignore();
                getline(cin, nuevoDato);

                switch (y)
                {
                case 0:
                    reg.setNombre(nuevoDato.c_str());
                    break;
                case 1:
                    reg.setApellido(nuevoDato.c_str());
                    break;
                case 2:
                    reg.setTelefono(nuevoDato.c_str());
                    break;
                case 3:
                    reg.setEmail(nuevoDato.c_str());
                    break;
                }
                rlutil::hidecursor();
            }
            break;
        }
    }
}
int pedirDNI(const char* titulo)
{
    int dni;
    int x = 25, y = 8;
    system("cls");
    parteArribaMenu(x, y, 40);
    for(int i=0; i<3; i++) bordesMenu(x, y + 1 + i, 40);
    parteAbajoMenu(x, y + 5, 40);
    resaltarMenu(titulo, x + 2, y + 1, false);

    rlutil::locate(x + 5, y + 3);
    cout << "INGRESE EL DNI: ";
    rlutil::showcursor();
    cin >> dni;
    rlutil::hidecursor();
    return dni;
}

bool mostrarFormularioCargaCliente(Persona &reg)
{
    char nombre[30], apellido[30], telefono[15], email[30];
    Fecha fechaNac;

    int x = 20, y_start = 5;

    system("cls");
    parteArribaMenu(x, y_start, 52);
    for (int i = 0; i < 11; i++) bordesMenu(x, y_start + 1 + i, 52);
    parteAbajoMenu(x, y_start + 13, 52);
    resaltarMenu("  I N G R E S A R   N U E V O   C L I E N T E  ", x + 6, y_start + 1, false);

    rlutil::locate(x + 3, y_start + 3);
    cout << "DNI           : " << reg.getDNI();

    rlutil::showcursor();
    rlutil::locate(x + 3, y_start + 4);
    cout << "NOMBRE        : ";
    cargarCadena(nombre, 29);
    rlutil::locate(x + 3, y_start + 5);
    cout << "APELLIDO      : ";
    cargarCadena(apellido, 29);
    rlutil::locate(x + 3, y_start + 6);
    cout << "TELEFONO      : ";
    cargarCadena(telefono, 14);
    rlutil::locate(x + 3, y_start + 7);
    cout << "EMAIL         : ";
    cargarCadena(email, 29);
    rlutil::locate(x + 3, y_start + 8);
    cout << "FECHA DE NAC. (DD/MM/AAAA): ";
    fechaNac.cargar(x + 3, y_start + 9);
    rlutil::hidecursor();

    reg.setNombre(nombre);
    reg.setApellido(apellido);
    reg.setTelefono(telefono);
    reg.setEmail(email);
    reg.setFechaNacimiento(fechaNac);

    return true;
}


void mostrarMensaje(const char* mensaje, int color = rlutil::WHITE)
{
    int x = 25, y = 10;
    system("cls");
    rlutil::setColor(color);
    parteArribaMenu(x, y, 40);
    bordesMenu(x, y + 1, 40);
    bordesMenu(x, y + 2, 40);
    bordesMenu(x, y + 3, 40);
    parteAbajoMenu(x, y + 4, 40);
    rlutil::locate(x + 2, y + 2);
    cout << mensaje;
    rlutil::resetColor();
    cout << endl << endl;
    system("pause");
}

bool mostrarConfirmacion(const char* titulo, const char* cuerpo)
{
    char confirmacion;
    int x = 25, y = 8;
    system("cls");
    parteArribaMenu(x, y, 40);
    for(int i=0; i<3; i++) bordesMenu(x, y + 1 + i, 40);
    parteAbajoMenu(x, y + 5, 40);
    resaltarMenu(titulo, x + 2, y + 1, false);
    rlutil::locate(x + 5, y + 3);
    cout << cuerpo << " (S/N): ";
    rlutil::showcursor();
    cin >> confirmacion;
    rlutil::hidecursor();
    return (confirmacion == 'S' || confirmacion == 's');
}
