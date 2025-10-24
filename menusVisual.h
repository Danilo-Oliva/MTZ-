#ifndef MENUSVISUAL_H_INCLUDED
#define MENUSVISUAL_H_INCLUDED
#include "clsPersona.h"

void imprimirMenuGestion();
void imprimirMenuClientes();
void imprimirMenuActividades();
void imprimirMenuInscripciones();

int mostrarMenuGestion(int &opcionMenu, int &y);
int mostrarMenuClientes(int &opcionMenu, int &y);
int mostrarMenuActividades(int &opcionMenu, int &y);
int mostrarMenuInscripciones(int &opcionMenu, int &y);

int mostrarMenuListarClientes(int &opcionMenu, int &y);
int mostrarMenuListarActividades(int &opcionMenu, int &y);
int mostrarMenuListarInscripciones(int &opcionMenu, int &y);

int mostrarMenuModificarCliente(Persona &reg, int &opcionMenu, int &y);

int pedirDNI(const char* titulo);
int pedirNumSocio(const char* titulo);
int pedirIdActividad();

bool mostrarFormularioCargaCliente(Persona &reg);
void mostrarMensaje(const char* mensaje, int color);
bool mostrarConfirmacion(const char* titulo, const char* cuerpo);

#endif // MENUSVISUAL_H_INCLUDED
