#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "clsPersona.h"
#include "clsActividad.h"
#include "clsFichaMedica.h"

struct Cliente
{
    Persona p1;
    Actividad act;
    FichaMedica fm;
};

#endif // CLIENTE_H_INCLUDED
