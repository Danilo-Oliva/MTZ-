#ifndef CLSFICHAMEDICA_H_INCLUDED
#define CLSFICHAMEDICA_H_INCLUDED
#include <iostream>
#include <cstring>
#include "clsDomicilio.h"

class FichaMedica{
private:
    Domicilio domicilio;
    float Peso;
    float Altura;
    char NroEmergencia[30];
    char NombreEmergencia[30];
    char Parentesco[30];
    char ObraSocial[15];
public:
    FichaMedica(Domicilio dom = Domicilio("sin registrar", "sin registrar", "sin registrar",  "sin registrar", 0), float _peso = 0, float _altura = 0, const char *nroemerg = "911", const char *nomemerg = "Hospital", const char *paren = "Doctor", const char *obraSoc = "sin registrar");
    void setDomicilio(Domicilio);
    void setPeso(float);
    void setAltura(float);
    void setNroEmergencia(const char *);
    void setNombreEmergencia(const char *);
    void setParentesco(const char *);
    void setObraSocial(const char *);

    //getters
    Domicilio getDomicilio();
    float getPeso();
    float getAltura();
    const char *getNroEmergencia();
    const char *getNomEmergencia();
    const char *getParentesco();
    const char *getObraSocial();

    //metodos
    void cargar();
    void mostrar();
};

#endif // CLSFICHAMEDICA_H_INCLUDED
