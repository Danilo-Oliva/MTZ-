#include "clsInscripcionActividad.h"
using namespace std;

InscripcionActividad::InscripcionActividad(int numSoc, int idA, Fecha f, bool libre, bool est)
{
    numeroSocio = numSoc;
    idAct = idA;
    fechaInscripcion = f;
    Libre = libre;
    Estado = est;
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
    Estado = e;
}
void InscripcionActividad::setLibre(bool l)
{
    Libre = l;
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
    return Estado;
}
bool InscripcionActividad::getLibre()
{
    return Libre;
}

void InscripcionActividad::cargar()
{
    int opcion_mod;
    cout << "Numero de Socio: ";
    cin >> numeroSocio;
    cout << "ID de Actividad: ";
    cin >> idAct;
    cout << "Modalidad (1 para Pase Libre, 2 para 3 veces por semana): ";
    cin >> opcion_mod;
    Libre = (opcion_mod == 1);
    cout << "Estado (1 = activo, 0 = inactivo): ";
    cin >> Estado;
}

void InscripcionActividad::mostrar()
{
    cout << "Socio: " << numeroSocio << endl;
    cout << "Actividad: " << idAct << endl;
    cout << "Fecha de inscripcion: ";
    fechaInscripcion.mostrar();
    cout << "Modalidad: " << (Libre ? "Pase Libre" : "3 veces por semana") << endl;
    cout << "Estado: " << (Estado ? "Activo" : "Inactivo") << endl;
}
float InscripcionActividad::calcularCuota(const Actividad &act)
{
    if (Libre == true) return act.getCuotaBase();
    return act.getCuotaBase() * 0.85f;
}
