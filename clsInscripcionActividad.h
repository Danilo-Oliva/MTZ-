#ifndef CLSINSCRIPCIONACTIVIDAD_H_INCLUDED
#define CLSINSCRIPCIONACTIVIDAD_H_INCLUDED

#include <iostream>
#include "clsFecha.h"

class InscripcionActividad {
private:
    int numeroSocio;   // FK -> Cliente (Persona.NumeroSocio)
    int idAct;         // FK -> Actividad (Actividad.idAct)
    Fecha fechaInscripcion;
    bool estado;       // true = activa, false = inactiva/baja

public:
    // Constructor
    InscripcionActividad(int numSoc = 0, int idA = 0, Fecha f = Fecha(), bool est = true);

    // Setters
    void setNumeroSocio(int);
    void setIdAct(int);
    void setFechaInscripcion(Fecha);
    void setEstado(bool);

    // Getters
    int getNumeroSocio();
    int getIdAct();
    Fecha getFechaInscripcion();
    bool getEstado();

    // Métodos
    void cargar();
    void mostrar();
};

#endif // CLSINSCRIPCIONACTIVIDAD_H_INCLUDED
