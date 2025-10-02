#include<iostream>
#include <cstring>
#include "cargarCadena.h"
#include "clsDomicilio.h"

using namespace std;

Domicilio::Domicilio(const char *_calle, const char *_CodigoPostal, const char *_Localidad, const char *_Partido, int _altura)
{
    strcpy(Calle, _calle);
    strcpy(CodigoPostal, _CodigoPostal);
    strcpy(Localidad, _Localidad);
    strcpy(Partido, _Partido);
    Altura = _altura;
}

/// SETTERS
    void Domicilio::setCalle(const char *_calle)
    {
        strcpy(Calle, _calle);
    }
    void Domicilio::setCodigoPostal(const char *_CodigoPostal)
    {
        strcpy(CodigoPostal, _CodigoPostal);
    }
    void Domicilio::setLocalidad(const char *_Localidad)
    {
        strcpy(Localidad, _Localidad);
    }
    void Domicilio::setPartido(const char *_Partido)
    {
        strcpy(Partido, _Partido);
    }
    void Domicilio::setAltura(int _altura)
    {
        Altura = _altura;
    }

    /// GETTERS
    const char *Domicilio::getCalle()
    {
        return Calle;
    }
    const char *Domicilio::getCodigoPostal()
    {
        return CodigoPostal;
    }
    const char *Domicilio::getLocalidad()
    {
        return Localidad;
    }
    const char *Domicilio::getPartido()
    {
        return Partido;
    }
    int Domicilio::getAltura()
    {
        return Altura;
    }

void Domicilio::Cargar()
{
    cout << "Ingrese nombre de la calle: ";
    cargarCadena(Calle, 29);

    cout << "Ingrese la altura: ";
    cin >> Altura;

    cout << "Ingrese la Localidad: ";
    cargarCadena(Localidad, 29);

    cout << "Ingrese el Partido: ";
    cargarCadena(Partido, 29);

    cout << "Ingrese codigo postal: ";
    cargarCadena(CodigoPostal, 5);
}
void Domicilio::Mostrar()
{
    cout<<"Calle: "         <<  Calle          <<endl;
    cout<<"Altura: "        <<  Altura         <<endl;
    cout<<"Localidad: "     <<  Localidad      <<endl;
    cout<<"Partido: "       <<  Partido        <<endl;
    cout<<"Codigo Postal: " <<  CodigoPostal   <<endl;
}
