#include "clsInscripcionActividad.h"
using namespace std;

InscripcionActividad::InscripcionActividad(int numSoc, int idA, Fecha f, bool est)
{
    numeroSocio = numSoc;
    idAct = idA;
    fechaInscripcion = f;
    estado = est;
}

void InscripcionActividad::setNumeroSocio(int n)
{
    numeroSocio = n;
}
void InscripcionActividad::setIdAct(int i)
{
    idAct = i;
}
void InscripcionActividad::setFechaInscripcion(Fecha f)
{
    fechaInscripcion = f;
}
void InscripcionActividad::setEstado(bool e)
{
    estado = e;
}

int InscripcionActividad::getNumeroSocio()
{
    return numeroSocio;
}
int InscripcionActividad::getIdAct()
{
    return idAct;
}
Fecha InscripcionActividad::getFechaInscripcion()
{
    return fechaInscripcion;
}
bool InscripcionActividad::getEstado()
{
    return estado;
}

void InscripcionActividad::cargar()
{
    cout << "Numero de Socio: ";
    cin >> numeroSocio;
    cout << "ID de Actividad: ";
    cin >> idAct;
    cout << "Estado (1 = activo, 0 = inactivo): ";
    cin >> estado;
}

void InscripcionActividad::mostrar()
{
    cout << "Socio: " << numeroSocio << endl;
    cout << "Actividad: " << idAct << endl;
    cout << "Fecha de inscripcion: ";
    fechaInscripcion.mostrar();
    cout << "Estado: " << (estado ? "Activo" : "Inactivo") << endl;
}
