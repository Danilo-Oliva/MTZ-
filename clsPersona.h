#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED
#include <iostream>
#include <cstring>
#include "clsFecha.h"

class Persona{
protected:
    bool Estado;
    char Nombre[30];
    char Apellido[30];
    char Telefono[15];
    char Email[30];
    Fecha FechaNacimiento;
    int DNI;
    int NumeroSocio;

public:
    Persona(const char *nom="Sin registrar", const char *ape="Sin registrar", const char *tel="sin registrar", const char *eml = "Sin registrar" , Fecha fecNac=Fecha(0,0,0000), int d=0, int numSoc=0);
    //setters
    void setNombre(const char *);
    void setApellido(const char *);
    void setTelefono(const char *);
    void setEmail(const char *);
    void setFechaNacimiento(Fecha);
    void setDNI(int);
    void setNumeroSocio(int);
    void setEstado(bool);

    //Getters
    const char *getNombre();
    const char *getApellido();
    const char *getTelefono();
    const char *getEmail();
    Fecha getFechaNacimiento();
    int getDNI();
    int getNumeroSocio();
    bool getEstado();

    //metods
    void cargar();
    void mostrar();
};

#endif // CLSPERSONA_H_INCLUDED
