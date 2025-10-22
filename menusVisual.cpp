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
    // Reducimos el tama�o del men� porque hay una opci�n menos
    for (int i = 0; i < 12; i ++) bordesMenu(24, 8 + i, 33);
    parteAbajoMenu(24, 20, 33);


    resaltarMenu("M E N U  D E  C L I E N T E S", 27, 6, false);
    resaltarMenu("INGRESAR NUEVO CLIENTE ", 30, 9, y == 0);
    resaltarMenu("  MODIFICAR  CLIENTES  ", 30, 11, y == 1);
    resaltarMenu("   LISTAR   CLIENTES   ", 30, 13, y == 2);
    resaltarMenu("BUSCAR CLIENTES POR DNI", 30, 15, y == 3);
    // La opci�n de "Cambiar Estado" se elimina de aqu�
    resaltarMenu("  BORRAR  UN  CLIENTE  ",30, 17, y == 4 ); // Antes era y == 5
    resaltarMenu("VOLVER AL  MENU GESTION", 30, 19, y == 5); // Antes era y == 6


    mostrarCursor(28, 54, 9, y);
    int tecla = rlutil::getkey();
    if(tecla == 1)
    {
        switch(y)
        {
        case 0: opcionMenu = 1; break; // INGRESA NUEVO CLIENTE
        case 1: opcionMenu = 2; break; // MODIFICAR CLIENTES
        case 2: opcionMenu = 3; break; // LISTAR CLIENTES
        case 3: opcionMenu = 4; break; // BUSCAR CLIENTES POR DNI
        case 4: opcionMenu = 5; break; // BORRAR UN CLIENTE (antes era la opci�n 6)
        case 5: opcionMenu = 0; break; // VOLVER (antes era la opci�n 7)
        }
    }
    // Ajustamos el l�mite del cursor a 5 (de 0 a 5 son 6 opciones)
    else if(tecla > 13) y = accionarCursor(y, tecla, 5);

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
    parteArribaMenu(24, 5, 38);
    bordesMenu(24, 6, 38);
    separarMenues(24, 7, 38);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 38);
    parteAbajoMenu(24, 17, 38);


    resaltarMenu("M E N U    I N S C R I P C I O N E S", 26, 6, false);
    resaltarMenu("REGISTRAR NUEVA INSCRIPCION ", 30, 9, y == 0);
    resaltarMenu("CAMBIAR  ESTADO  INSCRIPCION", 30, 11, y == 1);
    resaltarMenu(" LISTAR  LAS  INSCRIPCIONES ", 30, 13, y == 2);
    resaltarMenu("VOLVER   AL   MENU   GESTION", 30, 15, y == 3);


    mostrarCursor(28, 59, 9, y);
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
    parteArribaMenu(24, 5, 30);
    bordesMenu(24, 6, 30);
    separarMenues(24, 7, 30);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 30);
    parteAbajoMenu(24, 17, 30);

    resaltarMenu("L I S T A D O  C L I E N T E S", 25, 6, false);

    resaltarMenu("   LISTAR ACTIVOS   ", 30, 9, y == 0);
    resaltarMenu("  LISTAR INACTIVOS  ", 30, 11, y == 1);
    resaltarMenu("    LISTAR TODOS    ", 30, 13, y == 2);
    resaltarMenu("       VOLVER       ", 30, 15, y == 3);

    mostrarCursor(28, 51, 9, y);
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
    parteArribaMenu(24, 5, 36);
    bordesMenu(24, 6, 36);
    separarMenues(24, 7, 36);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 36);
    parteAbajoMenu(24, 17, 36);

    resaltarMenu("L I S T A D O  A C T I V I D A D E S", 25, 6, false);

    resaltarMenu("     LISTAR   ACTIVAS     ", 30, 9, y == 0);
    resaltarMenu("    LISTAR   INACTIVAS    ", 30, 11, y == 1);
    resaltarMenu("      LISTAR   TODAS      ", 30, 13, y == 2);
    resaltarMenu("VOLVER AL MENU ACTIVIDADES", 30, 15, y == 3);

    mostrarCursor(28, 57, 9, y);
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

    resaltarMenu("L I S T A D O   I N S C R I P C I O N E S", 26, 6, false);

    resaltarMenu(" LISTAR  LAS  INSCRIPCIONES  ACTIVAS ", 30, 9, y == 0);
    resaltarMenu("LISTAR  LAS  INSCRIPCIONES  INACTIVAS", 30, 11, y == 1);
    resaltarMenu("  LISTAR  TODAS  LAS  INSCRIPCIONES  ", 30, 13, y == 2);
    resaltarMenu("   VOLVER  AL  MENU  INSCRIPCIONES   ", 30, 15, y == 3);

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
    y = 0;

    rlutil::hidecursor();

    while (true)
    {
        system("cls");
        rlutil::setBackgroundColor(rlutil::BLACK);
        parteArribaMenu(x, y_start, 52);

        for (int i = 0; i < 13; i++) bordesMenu(x, y_start + 1 + i, 52);
        parteAbajoMenu(x, y_start + 14, 52);
        resaltarMenu("  M O D I F I C A R   C L I E N T E  ", x + 10, y_start + 1, false);
        separarMenues(x, y_start + 11, 52);

        rlutil::locate(x + 3, y_start + 3);
        cout << "NRO DE SOCIO  : " << reg.getNumeroSocio();
        rlutil::locate(x + 3, y_start + 4);
        cout << "DNI           : " << reg.getDNI();


        string texto;
        int anchoFijo = 45;


        texto = "ESTADO        : " + string(reg.getEstado() ? "ACTIVO  " : "INACTIVO");
        texto.resize(anchoFijo, ' ');
        resaltarMenu(texto.c_str(), x + 3, y_start + 6, y == 0);

        texto = "NOMBRE        : " + string(reg.getNombre());
        texto.resize(anchoFijo, ' ');
        resaltarMenu(texto.c_str(), x + 3, y_start + 7, y == 1);

        texto = "APELLIDO      : " + string(reg.getApellido());
        texto.resize(anchoFijo, ' ');
        resaltarMenu(texto.c_str(), x + 3, y_start + 8, y == 2);

        texto = "TELEFONO      : " + string(reg.getTelefono());
        texto.resize(anchoFijo, ' ');
        resaltarMenu(texto.c_str(), x + 3, y_start + 9, y == 3);

        texto = "EMAIL         : " + string(reg.getEmail());
        texto.resize(anchoFijo, ' ');
        resaltarMenu(texto.c_str(), x + 3, y_start + 10, y == 4);


        resaltarMenu("      GUARDAR Y VOLVER       ", x + 12, y_start + 12, y == 5);

        int tecla = rlutil::getkey();
        switch (tecla)
        {
        case 14:
            y--;
            if (y < 0) y = 5;
            break;
        case 15:
            y++;
            if (y > 5) y = 0;
            break;
        case 1:
            if (y == 0)
            {
                reg.setEstado(!reg.getEstado());
            }
            else if (y >= 1 && y <= 4)
            {
                rlutil::showcursor();
                char nuevoDato[30];
                int y_campo_actual = y_start + 7 + (y-1);
                rlutil::locate(x + 19, y_campo_actual);
                cout << string(30, ' ');
                rlutil::locate(x + 19, y_campo_actual);
                cargarCadena(nuevoDato, 29);

                switch (y)
                {
                case 1: reg.setNombre(nuevoDato); break;
                case 2: reg.setApellido(nuevoDato); break;
                case 3: reg.setTelefono(nuevoDato); break;
                case 4: reg.setEmail(nuevoDato); break;
                }
                rlutil::hidecursor();
            }
            else if (y == 5)
            {
                opcionMenu = 0;
                return opcionMenu;
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
    for(int i=0; i<4; i++) bordesMenu(x, y + 1 + i, 40);
    parteAbajoMenu(x, y + 5, 40);
    resaltarMenu(titulo, x + 2, y + 1, false);

    rlutil::locate(x + 5, y + 3);
    cout << "INGRESE EL DNI: ";
    rlutil::showcursor();
    cin >> dni;
    rlutil::hidecursor();
    return dni;
}

int pedirNumSocio(const char* titulo)
{
    int numSocio;
    int x = 25, y = 8;
    system("cls");
    parteArribaMenu(x, y, 40);
    for(int i=0; i<4; i++) bordesMenu(x, y + 1 + i, 40);
    parteAbajoMenu(x, y + 5, 40);
    resaltarMenu(titulo, x + 2, y + 1, false);

    rlutil::locate(x + 5, y + 3);
    cout << "INGRESE EL NUMERO DE SOCIO: ";
    rlutil::showcursor();
    cin >> numSocio;
    rlutil::hidecursor();
    return numSocio;
}

int pedirIdActividad()
{
    int idActividad;
    int x = 25, y = 8;
    system("cls");
    parteArribaMenu(x, y, 40);
    for(int i=0; i<4; i++) bordesMenu(x, y + 1 + i, 40);
    parteAbajoMenu(x, y + 5, 40);
    rlutil::locate(x + 5, y + 3);
    cout << "INGRESE ID DE LA ACTIVIDAD: ";
    rlutil::showcursor();
    cin >> idActividad;
    rlutil::hidecursor();
    return idActividad;
}



bool mostrarFormularioCargaCliente(Persona &reg)
{
    char nombre[30], apellido[30], telefono[15], email[30];
    Fecha fechaNac;

    int x = 20, y_start = 5;

    system("cls");
    parteArribaMenu(x, y_start, 52);
    for (int i = 0; i < 12; i++) bordesMenu(x, y_start + 1 + i, 52);
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
    parteArribaMenu(x, y, 40);
    bordesMenu(x, y + 1, 40);
    bordesMenu(x, y + 2, 40);
    bordesMenu(x, y + 3, 40);
    parteAbajoMenu(x, y + 4, 40);
    rlutil::setColor(color);
    rlutil::locate(x + 2, y + 2);
    cout << mensaje;
    rlutil::resetColor();
    cout << endl << endl;
    rlutil::anykey();
}

bool mostrarConfirmacion(const char* titulo, const char* cuerpo)
{
    int tecla = 0;
    bool respuesta = false;
    int movimiento = 0;
    do
    {
        int x = 25, y = 8;
        system("cls");
        parteArribaMenu(x, y, 40);
        for(int i = 0; i < 6; i++) bordesMenu(x, y + 1 + i, 40);
        parteAbajoMenu(x, y + 7, 40);
        resaltarMenu(titulo, x + 2, y + 1, false);
        rlutil::locate(x + 5, y + 3);
        cout << cuerpo;
        resaltarMenu("SI", x + 9, y + 5, movimiento == 0);
        resaltarMenu("NO", x + 31, y + 5, movimiento == 1);

        mostrarCursorConfirmacion(32, 37, 13, movimiento);
        tecla = rlutil::getkey();
        if(tecla == rlutil::KEY_LEFT || tecla == rlutil::KEY_RIGHT) movimiento = accionarCursorConfirmacion(movimiento, tecla, 1);
        else if(tecla == 1) /// NO SE PASA A LA FUNCION PORQUE TIRA ERROR
        {
            if(movimiento == 0)
            {
                respuesta = true; /// SI
            }
            else if (movimiento == 1)
            {
                respuesta = false; /// NO
            }
            break;
        }
    }
    while(tecla != 1);
    return respuesta;

}
