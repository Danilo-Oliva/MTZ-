#ifndef LISTADOVISUAL_H_INCLUDED
#define LISTADOVISUAL_H_INCLUDED
#include "clsPersona.h"
#include "clsActividad.h"

void dibujarTablaClientesHeader();
void dibujarTablaClientesRow(Persona reg, int y);
void dibujarFinalTablaClientes(int y);
void dibujarFichaCliente(Persona reg);

void dibujarTablaActividadesRow(Actividad reg, int y);
void dibujarTablaActividadesHeader();
void dibujarFinalTablaActividades(int y);
#endif // LISTADOVISUAL_H_INCLUDED
