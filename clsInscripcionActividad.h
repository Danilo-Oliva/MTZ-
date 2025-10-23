#ifndef CLSINSCRIPCIONACTIVIDAD_H_INCLUDED
#define CLSINSCRIPCIONACTIVIDAD_H_INCLUDED

#include <iostream>
#include "clsFecha.h"

class InscripcionActividad {
private:
    int numeroSocio;
    int idAct;
    Fecha fechaInscripcion;
    bool Libre;
    bool Estado;

public:
    InscripcionActividad(int numSoc = 0, int idA = 0, Fecha f = Fecha(), bool libre = true, bool est = true);

    // Setters
    void setNumeroSocio(int);
    void setIdAct(int);
    void setFechaInscripcion(Fecha);
    void setEstado(bool);
    void setLibre(bool);

    // Getters
    int getNumeroSocio();
    int getIdAct();
    Fecha getFechaInscripcion();
    bool getEstado();
    bool getLibre();

    // Métodos
    void cargar();
    void mostrar();
};

#endif // CLSINSCRIPCIONACTIVIDAD_H_INCLUDED
