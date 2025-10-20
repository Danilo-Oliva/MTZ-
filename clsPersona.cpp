#include<iostream>
#include "clsFecha.h"
#include "clsPersona.h"
#include "cargarCadena.h"

using namespace std;

Persona::Persona(const char *nom, const char *ape, const char *tel,const char *eml, Fecha fecNac, int d, int numSoc){
    strcpy(Nombre, nom);
    strcpy(Apellido, ape);
    strcpy(Telefono, tel);
    strcpy(Email, eml);
    FechaNacimiento = fecNac;
    DNI = d;
    NumeroSocio = numSoc;
    Estado = true;
}
void Persona::setNombre(const char *nom){
    strcpy(Nombre, nom);
}
void Persona::setApellido(const char *ape){
    strcpy(Apellido, ape);
}
void Persona::setTelefono(const char *tel){
    strcpy(Telefono, tel);
}
void Persona::setEmail(const char *eml){
    strcpy(Email, eml);
}
void Persona::setFechaNacimiento(Fecha fecNac){
    FechaNacimiento = fecNac;
}
void Persona::setDNI(int d){
    DNI = d;
}
void Persona::setNumeroSocio(int numSoc){
    NumeroSocio = numSoc;
}
void Persona::setEstado(bool e){
    Estado = e;
}
const char *Persona::getNombre(){
    return Nombre;
}
const char *Persona::getApellido(){
    return Apellido;
}
const char *Persona::getTelefono(){
    return Telefono;
}
const char *Persona::getEmail(){
    return Email;
}
Fecha Persona::getFechaNacimiento(){
    return FechaNacimiento;
}
int Persona::getDNI(){
    return DNI;
}
int Persona::getNumeroSocio(){
    return NumeroSocio;
}
bool Persona::getEstado(){
    return Estado;
}
void Persona::cargar(){

    cout << "Ingrese el nombre: ";
    char nomAux[30];
    cargarCadena(nomAux, 29);
    setNombre(nomAux);

    cout << "Ingrese el apellido: ";
    cargarCadena(Apellido, 29);

    cout << "Ingrese el telefono: ";
    cargarCadena(Telefono, 14);

    cout << "Ingrese el email: ";
    cargarCadena(Email, 29);

}
void Persona::mostrar(){
    cout << "======= DATOS PERSONALES =======" << endl;
    cout << "Numero de Socio: " << NumeroSocio << endl;
    cout << "DNI: " << DNI << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Apellido: " << Apellido << endl;
    cout << "Telefono: " << Telefono << endl;
    cout << "Email: " << Email << endl;
    cout << "Fecha de Nacimiento: ";
    FechaNacimiento.mostrar();
    cout << "Estado: " << (Estado ? "Activo" : "Inactivo") << endl;
}
