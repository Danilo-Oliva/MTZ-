#include<iostream>
#include <cstring>
#include <cstdio>
#include "rlutil.h"
#include "tunearMenu.h"
#include "menusVisual.h"
#include "clsArchivoCliente.h"
#include "clsPersona.h"
#include "cargarCadena.h"

using namespace std;

void imprimirMenuGestion()
{
    parteArribaMenu(24, 5, 37);
    bordesMenu(24, 6, 37);
    separarMenues(24, 7, 37);
    for (int i = 0; i < 11; i ++) bordesMenu(24, 8 + i, 37);
    parteAbajoMenu(24, 19, 37);

    escribirTexto("M E N U  D E  G E S T I O N", 30, 6);
    escribirTexto("GESTIONAR    LOS   CLIENTES", 30, 9);
    escribirTexto("GESTIONAR  LAS  ACTIVIDADES", 30, 11);
    escribirTexto("GESTIONAR LAS INSCRIPCIONES", 30, 13);
    escribirTexto("  REPORTES  DEL  PROGRAMA  ", 30, 15);
    escribirTexto("          SALIR   ", 30, 17);
}

void imprimirMenuClientes()
{
    parteArribaMenu(24, 5, 33);
    bordesMenu(24, 6, 33);
    separarMenues(24, 7, 33);
    for (int i = 0; i < 15; i ++) bordesMenu(24, 8 + i, 33);
    parteAbajoMenu(24, 23, 33);


    escribirTexto("M E N U  D E  C L I E N T E S", 27, 6);
    escribirTexto("INGRESAR NUEVO CLIENTE ", 30, 9);
    escribirTexto("  MODIFICAR  CLIENTES  ", 30, 11);
    escribirTexto("   LISTAR   CLIENTES   ", 30, 13);
    escribirTexto("BUSCAR CLIENTES POR DNI", 30, 15);
    escribirTexto("MODIFICAR ESTADO CLIENTE", 30, 17);
    escribirTexto("  BORRAR  UN  CLIENTE  ", 30, 19);
    escribirTexto("VOLVER AL  MENU GESTION", 30, 21);
}

void imprimirMenuActividades()
{
    parteArribaMenu(24, 5, 34);
    bordesMenu(24, 6, 34);
    separarMenues(24, 7, 34);
    for (int i = 0; i < 10; i ++) bordesMenu(24, 8 + i, 34);
    parteAbajoMenu(24, 18, 34);

    escribirTexto("M E N U   A C T I V I D A D E S", 25, 6);
    escribirTexto("INGRESAR NUEVA ACTIVIDAD", 30, 9);
    escribirTexto(" MODIFICAR    ACTIVIDAD ", 30, 11);
    escribirTexto("CAMBIAR ESTADO ACTIVIDAD", 30, 13);
    escribirTexto("  LISTAR   ACTIVIDADES  ", 30, 15);
    escribirTexto("VOLVER  A  MENU  GESTION", 30, 17);
}
void imprimirMenuInscripciones()
{
    parteArribaMenu(24, 5, 38);
    bordesMenu(24, 6, 38);
    separarMenues(24, 7, 38);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 38);
    parteAbajoMenu(24, 17, 38);

    escribirTexto("M E N U    I N S C R I P C I O N E S", 26, 6);
    escribirTexto(" INGRESAR NUEVA INSCRIPCION ", 30, 9);
    escribirTexto("CAMBIAR  ESTADO  INSCRIPCION", 30, 11);
    escribirTexto(" LISTAR  LAS  INSCRIPCIONES ", 30, 13);
    escribirTexto("VOLVER   AL   MENU   GESTION", 30, 15);
}

int interactuarMenuGestion(int &opcionMenu, int &y)
{
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
    else if(tecla > 13) y = accionarCursor(28, 58, 9, y, tecla, 4);

    return opcionMenu;

}

int interactuarMenuClientes(int &opcionMenu, int &y)
{
    mostrarCursor(28, 54, 9, y);
    int tecla = rlutil::getkey();
    if(tecla == 1)
    {
        switch(y)
        {
        case 0:
            opcionMenu = 1;
            break; // INGRESA NUEVO CLIENTE
        case 1:
            opcionMenu = 2;
            break; // MODIFICAR CLIENTES
        case 2:
            opcionMenu = 3;
            break; // LISTAR CLIENTES
        case 3:
            opcionMenu = 4;
            break; // BUSCAR CLIENTES POR DNI
        case 4:
            opcionMenu = 5;
            break; // MODIFICAR ESTADO DE CLIENTE
        case 5:
            opcionMenu = 6;
            break; // BORRAR UN CLIENTE
        case 6:
            opcionMenu = 0;
            break; // VOLVER
        }
    }
    else if(tecla > 13) y = accionarCursor(28, 54, 9, y, tecla, 6);

    return opcionMenu;
}

int interactuarMenuActividades(int &opcionMenu, int &y)
{
    mostrarCursor(28, 55, 9, y);
    int tecla = rlutil::getkey();
    if(tecla == 1)
    {
        switch(y)
        {
        case 0:
            opcionMenu = 1; // CREAR NUEVA ACTIVIDAD
            break;
        case 1:
            opcionMenu = 2; // MODIFICAR ACTIVIDAD
            break;
        case 2:
            opcionMenu = 3; // CAMBIAR ESTADO ACTIVIDAD
            break;
        case 3:
            opcionMenu = 4; // LISTAR ACTIVIDADES
            break;
        case 4:
            opcionMenu = 0; // VOLVER
            break;
        }
    }
    else if(tecla > 13) y = accionarCursor(28, 55, 9, y, tecla, 4); // ahora 4 opciones (0..4)

    return opcionMenu;
}

int interactuarMenuInscripciones(int &opcionMenu, int &y)
{
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
    else if(tecla > 13) y = accionarCursor(28, 59, 9, y, tecla, 3);

    return opcionMenu;

}
void imprimirMenuListarClientes()
{
    parteArribaMenu(24, 5, 30);
    bordesMenu(24, 6, 30);
    separarMenues(24, 7, 30);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 30);
    parteAbajoMenu(24, 17, 30);

    escribirTexto("L I S T A D O  C L I E N T E S", 25, 6);

    escribirTexto("   LISTAR ACTIVOS   ", 30, 9);
    escribirTexto("  LISTAR INACTIVOS  ", 30, 11);
    escribirTexto("    LISTAR TODOS    ", 30, 13);
    escribirTexto("       VOLVER       ", 30, 15);
}
int interactuarMenuListarClientes(int &opcionMenu, int &y)
{
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
    else if(tecla > 13) y = accionarCursor(28, 51, 9, y, tecla, 3);
    return opcionMenu;
}

void imprimirMenuListarActividades()
{
    parteArribaMenu(24, 5, 36);
    bordesMenu(24, 6, 36);
    separarMenues(24, 7, 36);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 36);
    parteAbajoMenu(24, 17, 36);

    escribirTexto("L I S T A D O  A C T I V I D A D E S", 25, 6);

    escribirTexto("     LISTAR   ACTIVAS     ", 30, 9);
    escribirTexto("    LISTAR   INACTIVAS    ", 30, 11);
    escribirTexto("      LISTAR   TODAS      ", 30, 13);
    escribirTexto("VOLVER AL MENU ACTIVIDADES", 30, 15);
}
int interactuarMenuListarActividades(int &opcionMenu, int &y)
{
    mostrarCursor(28, 58, 9, y);
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
    else if(tecla > 13) y = accionarCursor(28, 58, 9, y, tecla, 3);
    return opcionMenu;
}
void imprimirMenuListarInscripciones()
{
    parteArribaMenu(24, 5, 47);
    bordesMenu(24, 6, 47);
    separarMenues(24, 7, 47);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 47);
    parteAbajoMenu(24, 17, 47);

    escribirTexto("L I S T A D O   I N S C R I P C I O N E S", 28, 6);

    escribirTexto(" LISTAR  LAS  INSCRIPCIONES  ACTIVAS ", 30, 9);
    escribirTexto("LISTAR  LAS  INSCRIPCIONES  INACTIVAS", 30, 11);
    escribirTexto("  LISTAR  TODAS  LAS  INSCRIPCIONES  ", 30, 13);
    escribirTexto("   VOLVER  AL  MENU  INSCRIPCIONES   ", 30, 15);
}

int interactuarMenuListarInscripciones(int &opcionMenu, int &y)
{
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
    else if(tecla > 13) y = accionarCursor(28, 68, 9, y, tecla, 3);
    return opcionMenu;
}

void mostrarMenuModificarCliente(Persona &reg)
{
    int x = 20, yStart = 5;
    rlutil::hidecursor();

    parteArribaMenu(x, yStart, 52);

    for (int i = 0; i < 11; i++) bordesMenu(x, yStart + 1 + i, 52);
    parteAbajoMenu(x, yStart + 12, 52);

    escribirTexto("  M O D I F I C A R   C L I E N T E  ", x + 10, yStart + 1);

    char texto[200];
    char numero[64];
    int anchoFijo = 45;
    int len;

    sprintf(numero, "%d", reg.getNumeroSocio());
    strcpy(texto, "NRO DE SOCIO  : ");
    strcat(texto, numero);
    len = (int)strlen(texto);
    while (len < anchoFijo && len < (int)sizeof(texto) - 1) texto[len++] = ' ';
    texto[len] = '\0';
    escribirTexto(texto, x + 3, yStart + 3);

    sprintf(numero, "%d", reg.getDNI());
    strcpy(texto, "DNI           : ");
    strcat(texto, numero);
    len = (int)strlen(texto);
    while (len < anchoFijo && len < (int)sizeof(texto) - 1) texto[len++] = ' ';
    texto[len] = '\0';
    escribirTexto(texto, x + 3, yStart + 4);

    strcpy(texto, "NOMBRE        : ");
    strcat(texto, reg.getNombre());
    len = (int)strlen(texto);
    while (len < anchoFijo && len < (int)sizeof(texto) - 1) texto[len++] = ' ';
    texto[len] = '\0';
    escribirTexto(texto, x + 3, yStart + 5);

    strcpy(texto, "APELLIDO      : ");
    strcat(texto, reg.getApellido());
    len = (int)strlen(texto);
    while (len < anchoFijo && len < (int)sizeof(texto) - 1) texto[len++] = ' ';
    texto[len] = '\0';
    escribirTexto(texto, x + 3, yStart + 6);

    strcpy(texto, "TELEFONO      : ");
    strcat(texto, reg.getTelefono());
    len = (int)strlen(texto);
    while (len < anchoFijo && len < (int)sizeof(texto) - 1) texto[len++] = ' ';
    texto[len] = '\0';
    escribirTexto(texto, x + 3, yStart + 7);

    strcpy(texto, "EMAIL         : ");
    strcat(texto, reg.getEmail());
    len = (int)strlen(texto);
    while (len < anchoFijo && len < (int)sizeof(texto) - 1) texto[len++] = ' ';
    texto[len] = '\0';
    escribirTexto(texto, x + 3, yStart + 8);

    strcpy(texto, "FECHA NAC.    : ");
    len = (int)strlen(texto);
    while (len < anchoFijo && len < (int)sizeof(texto) - 1) texto[len++] = ' ';
    texto[len] = '\0';
    escribirTexto(texto, x + 3, yStart + 9);
    rlutil::locate(x + 19, yStart + 9);
    reg.getFechaNacimiento().mostrar();

    separarMenues(x, yStart + 10, 52);

    escribirTexto("     GUARDAR Y VOLVER        ", x + 12, yStart + 11);
}

int interactuarMenuModificarCliente(Persona &reg, int &opcionMenu, int &y)
{
    int x = 20, yStart = 5;
    y = 0;

    rlutil::hidecursor();

    Persona auxPer;
    ArchivoCliente archCli("clientes.dat", auxPer);


    mostrarMenuModificarCliente(reg);

    while (true)
    {
        int yCursor = 0;
        if (y == 0) yCursor = yStart + 4;      // DNI
        else if (y == 1) yCursor = yStart + 5; // NOMBRE
        else if (y == 2) yCursor = yStart + 6; // APELLIDO
        else if (y == 3) yCursor = yStart + 7; // TELEFONO
        else if (y == 4) yCursor = yStart + 8; // EMAIL
        else if (y == 5) yCursor = yStart + 9; // FECHA
        else if (y == 6) yCursor = yStart + 11;// GUARDAR

        if (y == 6) rlutil::locate(x + 15, yCursor);
        else rlutil::locate(x + 1, yCursor);
        cout << (char)175;

        int tecla = rlutil::getkey();

        if (y == 6) rlutil::locate(x + 15, yCursor);
        else rlutil::locate(x + 1, yCursor);
        cout << " ";


        if (tecla == 1)
        {
             if (y == 0)
             {
                 rlutil::showcursor();
                 int nuevoDniStr;
                 int yCampoActual = yStart + 4;
                 rlutil::locate(x + 19, yCampoActual);
                 cout << string(11, ' ');
                 rlutil::locate(x + 19, yCampoActual);
                 //cargarCadena(nuevoDniStr, 11);
                    cin>>nuevoDniStr;
                 int nuevoDni = nuevoDniStr;
                 if (!(nuevoDni >= 1000000 && nuevoDni <= 99999999))
                 {
                     rlutil::hidecursor();
                     mostrarMensaje("Formato DNI invalido (7-8 digitos).", rlutil::LIGHTRED);
                 }
                 else
                 {
                     int posActual = archCli.buscarCliente(reg.getDNI());
                     int posExistente = archCli.buscarCliente(nuevoDni);
                     if (posExistente != -1 && posExistente != posActual)
                     {
                         rlutil::hidecursor();
                         mostrarMensaje("Ese DNI ya pertenece a otro cliente.", rlutil::LIGHTRED);
                     }
                     else
                     {
                         reg.setDNI(nuevoDni);
                         rlutil::hidecursor();
                         mostrarMensaje("DNI actualizado (RECUERDE GUARDAR).", rlutil::YELLOW);
                     }
                 }
                 rlutil::hidecursor();
                 mostrarMenuModificarCliente(reg);
             }
             else if (y == 5)
             {
                 Fecha nuevaFecha;
                 if (nuevaFecha.cargarCompacta(x + 19, yStart + 9))
                 {
                     reg.setFechaNacimiento(nuevaFecha);
                 }
             }
             else if (y >= 1 && y <= 4)
             {
                 rlutil::showcursor();
                 char nuevoDato[60];
                 int yCampoActual = yStart + 5 + (y - 1);
                 rlutil::locate(x + 19, yCampoActual);
                 cout << string(30, ' ');
                 rlutil::locate(x + 19, yCampoActual);
                 cargarCadena(nuevoDato, 29);

                 switch (y)
                 {
                 case 1:
                     reg.setNombre(nuevoDato);
                     break;
                 case 2:
                     reg.setApellido(nuevoDato);
                     break;
                 case 3:
                     reg.setTelefono(nuevoDato);
                     break;
                 case 4:
                     reg.setEmail(nuevoDato);
                     break;
                 }
                 rlutil::hidecursor();
             }
             else if (y == 6) // GUARDAR Y VOLVER
             {
                 opcionMenu = 0;
                 return opcionMenu;
             }
        }
        else if (tecla == rlutil::KEY_UP)
        {
            y--;
            if (y < 0) y = 6;
        }
        else if (tecla == rlutil::KEY_DOWN)
        {
            y++;
            if (y > 6) y = 0;
        }
    }
}

int pedirDNI(const char* titulo)
{
    int dni;
    int x = 25, y = 8;
    rlutil::cls();
    parteArribaMenu(x, y, 40);
    for(int i=0; i<4; i++) bordesMenu(x, y + 1 + i, 40);
    parteAbajoMenu(x, y + 5, 40);
    escribirTexto(titulo, x + 2, y + 1);

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
    rlutil::cls();
    parteArribaMenu(x, y, 40);
    for(int i=0; i<4; i++) bordesMenu(x, y + 1 + i, 40);
    parteAbajoMenu(x, y + 5, 40);
    escribirTexto(titulo, x + 2, y + 1);

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
    rlutil::cls();
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

    int x = 20, yStart = 5;

    rlutil::cls();
    parteArribaMenu(x, yStart, 52);
    for (int i = 0; i < 12; i++) bordesMenu(x, yStart + 1 + i, 52);
    parteAbajoMenu(x, yStart + 13, 52);
    escribirTexto("  I N G R E S A R   N U E V O   C L I E N T E  ", x + 6, yStart + 1);

    rlutil::locate(x + 3, yStart + 3);
    cout << "DNI           : " << reg.getDNI();

    rlutil::showcursor();
    rlutil::locate(x + 3, yStart + 4);
    cout << "NOMBRE        : ";
    cargarCadena(nombre, 29);
    rlutil::locate(x + 3, yStart + 5);
    cout << "APELLIDO      : ";
    cargarCadena(apellido, 29);
    rlutil::locate(x + 3, yStart + 6);
    cout << "TELEFONO      : ";
    cargarCadena(telefono, 14);
    rlutil::locate(x + 3, yStart + 7);
    cout << "EMAIL         : ";
    cargarCadena(email, 29);
    rlutil::locate(x + 3, yStart + 8);
    cout << "FECHA DE NAC. (DD/MM/AAAA): ";
    fechaNac.cargarCompacta(x + 3, yStart + 9);
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
    rlutil::cls();
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
    rlutil::cls();
}

bool mostrarConfirmacion(const char* titulo, const char* cuerpo)
{
    int tecla = 0;
    bool respuesta = false;
    int movimiento = 0;
    rlutil::cls();
    do
    {
        int x = 25, y = 8;
        parteArribaMenu(x, y, 40);
        for(int i = 0; i < 6; i++) bordesMenu(x, y + 1 + i, 40);
        parteAbajoMenu(x, y + 7, 40);
        escribirTexto(titulo, x + 2, y + 1);
        rlutil::locate(x + 5, y + 3);
        cout << cuerpo;
        escribirTexto("SI", x + 9, y + 5);
        escribirTexto("NO", x + 31, y + 5);

        mostrarCursorConfirmacion(32, 37, 13, movimiento);
        tecla = rlutil::getkey();
        if(tecla == rlutil::KEY_LEFT || tecla == rlutil::KEY_RIGHT) movimiento = accionarCursorConfirmacion(32, 37, 13, movimiento, tecla, 1);
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
    rlutil::cls();
    return respuesta;

}
