#include<iostream>
#include "rlutil.h"
#include "tunearMenu.h"
#include "menusVisual.h"
#include "clsPersona.h"
#include "cargarCadena.h"
#include <string>

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
    escribirTexto("  VOLVER AL MENU PRICIPAL  ", 30, 17);
}

void imprimirMenuClientes()
{
    parteArribaMenu(24, 5, 33);
    bordesMenu(24, 6, 33);
    separarMenues(24, 7, 33);
    for (int i = 0; i < 12; i ++) bordesMenu(24, 8 + i, 33);
    parteAbajoMenu(24, 20, 33);


    escribirTexto("M E N U  D E  C L I E N T E S", 27, 6);
    escribirTexto("INGRESAR NUEVO CLIENTE ", 30, 9);
    escribirTexto("  MODIFICAR  CLIENTES  ", 30, 11);
    escribirTexto("   LISTAR   CLIENTES   ", 30, 13);
    escribirTexto("BUSCAR CLIENTES POR DNI", 30, 15);
    escribirTexto("  BORRAR  UN  CLIENTE  ", 30, 17);
    escribirTexto("VOLVER AL  MENU GESTION", 30, 19);
}

void imprimirMenuActividades()
{
    parteArribaMenu(24, 5, 31);
    bordesMenu(24, 6, 31);
    separarMenues(24, 7, 31);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 31);
    parteAbajoMenu(24, 17, 31);


    escribirTexto("M E N U   A C T I V I D A D E S", 25, 6);
    escribirTexto("CREAR NUEVA ACTIVIDAD", 30, 9);
    escribirTexto("MODIFICAR   ACTIVIDAD", 30, 11);
    escribirTexto(" LISTAR  ACTIVIDADES ", 30, 13);
    escribirTexto("VOLVER A MENU GESTION", 30, 15);
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

int mostrarMenuGestion(int &opcionMenu, int &y)
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

int mostrarMenuClientes(int &opcionMenu, int &y)
{



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
        case 4: opcionMenu = 5; break; // BORRAR UN CLIENTE
        case 5: opcionMenu = 0; break; // VOLVER
        }
    }
    else if(tecla > 13) y = accionarCursor(28, 54, 9, y, tecla, 5);

    return opcionMenu;
}

int mostrarMenuActividades(int &opcionMenu, int &y)
{



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
    else if(tecla > 13) y = accionarCursor(28, 52, 9, y, tecla, 3);

    return opcionMenu;
}

int mostrarMenuInscripciones(int &opcionMenu, int &y)
{


    mostrarCursor(28, 60, 9, y);
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
    else if(tecla > 13) y = accionarCursor(28, 60, 9, y, tecla, 3);

    return opcionMenu;

}
int mostrarMenuListarClientes(int &opcionMenu, int &y)
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



int mostrarMenuListarActividades(int &opcionMenu, int &y)
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
    else if(tecla > 13) y = accionarCursor(28, 57, 9, y, tecla, 3);
    return opcionMenu;
}
int mostrarMenuListarInscripciones(int &opcionMenu, int &y)
{
    parteArribaMenu(24, 5, 47);
    bordesMenu(24, 6, 47);
    separarMenues(24, 7, 47);
    for (int i = 0; i < 9; i ++) bordesMenu(24, 8 + i, 47);
    parteAbajoMenu(24, 17, 47);

    escribirTexto("L I S T A D O   I N S C R I P C I O N E S", 26, 6);

    escribirTexto(" LISTAR  LAS  INSCRIPCIONES  ACTIVAS ", 30, 9);
    escribirTexto("LISTAR  LAS  INSCRIPCIONES  INACTIVAS", 30, 11);
    escribirTexto("  LISTAR  TODAS  LAS  INSCRIPCIONES  ", 30, 13);
    escribirTexto("   VOLVER  AL  MENU  INSCRIPCIONES   ", 30, 15);

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

int mostrarMenuModificarCliente(Persona &reg, int &opcionMenu, int &y)
{
    int x = 20, yStart = 5;
    y = 0;

    rlutil::hidecursor();

    while (true)
    {
        system("cls");
        rlutil::setBackgroundColor(rlutil::BLACK);
        parteArribaMenu(x, yStart, 52);

        for (int i = 0; i < 13; i++) bordesMenu(x, yStart + 1 + i, 52);
        parteAbajoMenu(x, yStart + 14, 52);
        escribirTexto("  M O D I F I C A R   C L I E N T E  ", x + 10, yStart + 1);
        separarMenues(x, yStart + 11, 52);

        rlutil::locate(x + 3, yStart + 3);
        cout << "NRO DE SOCIO  : " << reg.getNumeroSocio();
        rlutil::locate(x + 3, yStart + 4);
        cout << "DNI           : " << reg.getDNI();


        string texto;
        int anchoFijo = 45;


        texto = "ESTADO        : " + string(reg.getEstado() ? "ACTIVO  " : "INACTIVO");
        texto.resize(anchoFijo, ' ');
        escribirTexto(texto.c_str(), x + 3, yStart + 6);

        texto = "NOMBRE        : " + string(reg.getNombre());
        texto.resize(anchoFijo, ' ');
        escribirTexto(texto.c_str(), x + 3, yStart + 7);

        texto = "APELLIDO      : " + string(reg.getApellido());
        texto.resize(anchoFijo, ' ');
        escribirTexto(texto.c_str(), x + 3, yStart + 8);

        texto = "TELEFONO      : " + string(reg.getTelefono());
        texto.resize(anchoFijo, ' ');
        escribirTexto(texto.c_str(), x + 3, yStart + 9);

        texto = "EMAIL         : " + string(reg.getEmail());
        texto.resize(anchoFijo, ' ');
        escribirTexto(texto.c_str(), x + 3, yStart + 10);


        escribirTexto("      GUARDAR Y VOLVER       ", x + 12, yStart + 12);
//1
// 1. Mapear el índice 'y' (0-5) a la coordenada Y real de la opción
        int yCursor = 0;
        if (y == 0) yCursor = yStart + 6;      // Opción ESTADO
        else if (y == 1) yCursor = yStart + 7;  // Opción NOMBRE
        else if (y == 2) yCursor = yStart + 8;  // Opción APELLIDO
        else if (y == 3) yCursor = yStart + 9;  // Opción TELEFONO
        else if (y == 4) yCursor = yStart + 10; // Opción EMAIL
        else if (y == 5) yCursor = yStart + 12; // Opción GUARDAR Y VOLVER

        // 2. Dibujar el cursor en la posición correcta
        rlutil::locate(x + 1, yCursor);
        cout << (char)175;

        // 3. Obtener la tecla presionada
        int tecla = rlutil::getkey();

        // 4. Borrar el cursor de la posición actual (para el próximo frame)
        rlutil::locate(x + 1, yCursor);
        cout << " ";

        // 5. Procesar la tecla
        if(tecla == 1) // ENTER
        {
            if (y == 0) // ESTADO
            {
                reg.setEstado(!reg.getEstado());
            }
            else if (y >= 1 && y <= 4) // CAMPOS DE TEXTO
            {
                rlutil::showcursor();
                char nuevoDato[30];
                // Esta lógica calcula la línea correcta para editar
                int yCampoActual = yStart + 7 + (y-1);
                rlutil::locate(x + 19, yCampoActual);
                cout << string(30, ' ');
                rlutil::locate(x + 19, yCampoActual);
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
            else if (y == 5) // GUARDAR Y VOLVER
            {
                opcionMenu = 0;
                return opcionMenu; // Sale del while(true) y de la función
            }
        }
        else if (tecla == rlutil::KEY_UP) // FLECHA ARRIBA
        {
            y--;
            if (y < 0) y = 5; // 5 es el último índice (0-5)
        }
        else if (tecla == rlutil::KEY_DOWN) // FLECHA ABAJO
        {
            y++;
            if (y > 5) y = 0; // 0 es el primer índice
        }
//1
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
    system("cls");
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

    int x = 20, yStart = 5;

    system("cls");
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
    fechaNac.cargar(x + 3, yStart + 9);
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
    system("cls");
}

bool mostrarConfirmacion(const char* titulo, const char* cuerpo)
{
    int tecla = 0;
    bool respuesta = false;
    int movimiento = 0;
        system("cls");
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
        system("cls");
    return respuesta;

}
