#ifndef TUNEARMENU_H_INCLUDED
#define TUNEARMENU_H_INCLUDED
#include "rlutil.h"

void resaltarMenu(const char* texto, int posX, int posY, bool seleccionado);
void parteArribaMenu(int posX, int posY, int espacios);
void bordesMenu(int posX, int posY, int espacios);
void separarMenues(int posX, int posY, int espacios);
void parteAbajoMenu(int posX, int posY, int espacios);
void mostrarCursor(int posX1, int posX2, int posY, int y);
int accionarCursor(int y, int tecla, int limiteCursor);
int mostrarMenuPrincipal(int &opcionMenu, int &y);

#endif // TUNEARMENU_H_INCLUDED
