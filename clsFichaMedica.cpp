#include<iostream>
#include "cargarCadena.h"
#include "clsFichaMedica.h"
#include "clsDomicilio.h"

using namespace std;

FichaMedica::FichaMedica(Domicilio dom, float _peso, float _altura, const char *nroemerg, const char *nomemerg , const char *paren, const char *obraSoc){
    domicilio = dom;
    Peso = _peso;
    Altura = _altura;
    strcpy(NroEmergencia, nroemerg);
    strcpy(NombreEmergencia, nomemerg);
    strcpy(Parentesco, paren);
    strcpy(ObraSocial, obraSoc);
}

void FichaMedica::setDomicilio(Domicilio dom){
    domicilio = dom;
}
void FichaMedica::setPeso(float _peso){
    Peso = _peso;
}
void FichaMedica::setAltura(float _altura){
    Altura = _altura;
}
void FichaMedica::setNroEmergencia(const char *nroemerg){
    strcpy(NroEmergencia, nroemerg);
}
void FichaMedica::setNombreEmergencia(const char *nomemerg){
    strcpy(NombreEmergencia, nomemerg);
}
void FichaMedica::setParentesco(const char *paren){
    strcpy(Parentesco, paren);
}
void FichaMedica::setObraSocial(const char *obraSoc){
    strcpy(ObraSocial, obraSoc);
}
Domicilio FichaMedica::getDomicilio(){
    return domicilio;
}
float FichaMedica::getPeso(){
    return Peso;
}
float FichaMedica::getAltura(){
    return Altura;
}
const char *FichaMedica::getNroEmergencia(){
    return NroEmergencia;
}
const char *FichaMedica::getNomEmergencia(){
    return NombreEmergencia;
}
const char *FichaMedica::getParentesco(){
    return Parentesco;
}
const char *FichaMedica::getObraSocial(){
    return ObraSocial;
}
void FichaMedica::cargar(){
    cout << "======= INGRESO FICHA MEDICA =======" << endl;
    cout << "Ingrese su domicilio: " << endl;
    domicilio.Cargar();
    cout << "Ingrese su peso: ";
    cin >> Peso;
    cout << "Ingrese su altura (en cm): ";
    cin >> Altura;
    cout << "Ingrese un numero de emergencia: ";
    cargarCadena(NroEmergencia, 29);
    cout << "Ingrese el nombre de la persona: ";
    cargarCadena(NombreEmergencia, 29);
    cout << "Ingrese su parentesco con esta persona: ";
    cargarCadena(Parentesco, 29);
    cout << "Ingrese su obra social: ";
    cargarCadena(ObraSocial, 14);
    cout << "====================================" << endl;
}
void FichaMedica::mostrar(){
    cout << "======= INGRESO FICHA MEDICA =======" << endl;
    cout << "Domicilio: " << endl;
    domicilio.Mostrar();
    cout << "Peso: " << Peso << "kg" << endl;
    cout << "Altura: " << Altura << "cm" << endl;
    cout << "Numero de emergencia: " << NroEmergencia << endl;
    cout << "Nombre de la persona: " << NombreEmergencia << endl;
    cout << "Parentesco: " << Parentesco << endl;
    cout << "Obra Social: " << ObraSocial << endl;
    cout << "====================================" << endl;
}
