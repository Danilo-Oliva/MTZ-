#include <iostream>
#include "clsArchivoActividad.h"
#include "clsArchivoCliente.h"
#include "clsArchivoInscripcion.h"
#include "clsActividad.h"
#include "clsPersona.h"
#include "clsInscripcionActividad.h"


using namespace std;

void actMasIngreso()
{
    ArchivoInscripcion arch("activades.dat");
    Actividad act;
    InscripcionActividad ins;
    float totalIngreso[40];
    int totalInsc = arch.contarInscripciones();


    for (int i = 0; i < totalInsc; i++)
    {
        arch.leerInscripcion(i);

    }
}

void actMasRecurrida()
{

}

void ingresoPorMesYModalidad()
{

}

void clientesNoAnotadosAnioActual()
{

}
