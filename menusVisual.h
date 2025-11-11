#ifndef MENUSVISUAL_H_INCLUDED
#define MENUSVISUAL_H_INCLUDED
#include "clsPersona.h"

void imprimirMenuGestion();
void imprimirMenuClientes();
void imprimirMenuActividades();
void imprimirMenuInscripciones();
void imprimirMenuReportes();

int interactuarMenuGestion(int &opcionMenu, int &y);
int interactuarMenuClientes(int &opcionMenu, int &y);
int interactuarMenuActividades(int &opcionMenu, int &y);
int interactuarMenuInscripciones(int &opcionMenu, int &y);
int interactuarMenuReportes(int &opcionMenu, int &y);

void imprimirMenuListarInscripciones();
int interactuarMenuListarInscripciones(int &opcionMenu, int &y);

void imprimirMenuListarActividades();
int interactuarMenuListarActividades(int &opcionMenu, int &y);

void imprimirMenuListarClientes();
int interactuarMenuListarClientes(int &opcionMenu, int &y);

void mostrarMenuModificarCliente();
int interactuarMenuModificarCliente(Persona &reg, int &opcionMenu, int &y);

int pedirDNI(const char* titulo);
int pedirNuevoDNI(const char* titulo);
int pedirNumSocio(const char* titulo);
int pedirIdActividad();

bool mostrarFormularioCargaCliente(Persona &reg);
void mostrarMensaje(const char* mensaje, int color);
bool mostrarConfirmacion(const char* titulo, const char* cuerpo);

#endif // MENUSVISUAL_H_INCLUDED
