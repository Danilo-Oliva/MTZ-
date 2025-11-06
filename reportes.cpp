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
    ArchivoInscripcion archIns("inscripciones.dat");
    ArchivoActividad archAct("actividades.dat");

    const int cantAct = 40;

    float totalIngreso[cantAct] = {};

    int totalInsc = archIns.contarInscripciones();

    if (totalInsc == 0) {
        cout << "No hay inscripciones registradas" << endl;
        return;
    }

    for (int i = 0; i < totalInsc; i++)
    {
        InscripcionActividad ins = archIns.leerInscripcion(i);

        int idAct = ins.getIdAct();

        if (idAct >= 1 && idAct <= cantAct)
        {
            Actividad act = archAct.leerArchivo(idAct - 1);

            totalIngreso[idAct - 1] += ins.calcularCuota(act);
        }
    }

    float maxIngresos = totalIngreso[0];
    int maximo = 0;

    cout << "--- INGRESOS TOTALES POR ACTIVIDAD ---" << endl;
    for (int i = 1; i < cantAct; i++)
    {
        if (totalIngreso[i] > maximo)
        {
            maxIngresos = totalIngreso[i];
            maximo = i;
        }
    }
    cout << "La id de la actividad con mas ingresos es: " << maximo << endl;
}
void actMasRecurrida()
{
    ArchivoInscripcion archIns("inscripciones.dat");
    ArchivoActividad archAct("actividades.dat");

    const int cantAct = 40;

    float totalClientes[cantAct] = {};

    int totalInsc = archIns.contarInscripciones();

    if (totalInsc == 0) {
        cout << "No hay inscripciones registradas" << endl;
        return;
    }

    for (int i = 0; i < totalInsc; i++)
    {
        InscripcionActividad ins = archIns.leerInscripcion(i);

        int idAct = ins.getIdAct();

        if (idAct >= 1 && idAct <= cantAct)
        {
            Actividad act = archAct.leerArchivo(idAct - 1);

            totalClientes[idAct - 1] ++;
        }
    }

    float maxClientes = totalClientes[0];
    int maximo = 0;

    cout << "--- INGRESOS TOTALES POR ACTIVIDAD ---" << endl;
    for (int i = 1; i < cantAct; i++)
    {
        if (totalClientes[i] > maxClientes)
        {
            maxClientes = totalClientes[i];
            maximo = i;
        }
    }
    cout << "La actividad con mas clientes es: " << maximo + 1 << endl;
}

void ingresoPorMesYModalidad()
{

}

void clientesNoAnotadosAnioActual()
{

}
