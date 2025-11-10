#include <iostream>
#include "clsArchivoActividad.h"
#include "clsArchivoCliente.h"
#include "clsArchivoInscripcion.h"
#include "clsActividad.h"
#include "clsPersona.h"
#include "clsInscripcionActividad.h"
#include "rlutil.h"

using namespace std;

void actMasIngreso()
{
    ArchivoInscripcion archIns("inscripciones.dat");
    ArchivoActividad archAct("actividades.dat");

    const int cantAct = 40;

    float totalIngreso[cantAct] = {};

    int totalInsc = archIns.contarInscripciones();

    if (totalInsc == 0)
    {
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
    cout << "La id de la actividad con mas ingresos es: " << maximo +1 << endl;
}
void actMasRecurrida()
{
    ArchivoInscripcion archIns("inscripciones.dat");
    ArchivoActividad archAct("actividades.dat");

    const int cantAct = 40;

    float totalClientes[cantAct] = {};

    int totalInsc = archIns.contarInscripciones();

    if (totalInsc == 0)
    {
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
    int anio;
    cout << "Ingrese anio(2023 - 2025): ";
    cin >> anio;

    while (anio < 2023 || anio > 2025)
    {
        cout << "Anio invalido. Reingrese (2023-2025): ";
        cin >> anio;
    }

    float ingresos[12][2] = {0};

    const char* nombresMeses[12] =
    {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    ArchivoInscripcion archIns("inscripciones.dat");
    ArchivoActividad archAct("actividades.dat");

    int cantIns = archIns.contarInscripciones();
    if (cantIns == 0)
    {
        cout << "No hay inscripciones registradas." << endl;
        rlutil::cls();
        return;
    }

    for(int i = 0; i < cantIns; i ++ )
    {
        InscripcionActividad ins = archIns.leerInscripcion(i);

        if(ins.getEstado() == true && ins.getFechaInscripcion().getAnio() == anio)
        {
            int posAct = archAct.buscarActividad(ins.getIdAct());
            if(posAct == -1)
            {
                continue;
            }

            Actividad act = archAct.leerArchivo(posAct);

            float precio  = ins.calcularCuota(act);

            int mes = ins.getFechaInscripcion().getMes();

            int modIdx = (ins.getLibre() ? 1 : 0);

            ingresos[mes - 1][modIdx] += precio;
        }

        rlutil::cls();
        cout << "--- INGRESOS TOTALES POR MES Y MODALIDAD PARA EL ANIO " << anio << " ---" << endl;

        float totalGeneral = 0;
        float totalMod3Veces = 0;
        float totalModPaseLibre = 0;

        for (int m = 0; m < 12; m++)
        {
            float totalMes = ingresos[m][0] + ingresos[m][1];

            if (totalMes > 0)
            {
                cout << "------------------------------------------" << endl;
                cout << "MES: " << nombresMeses[m] << endl;
                cout << "  3 Veces por Semana: $ " << ingresos[m][0] << endl;
                cout << "  Pase Libre:         $ " << ingresos[m][1] << endl;
                cout << "  Total del Mes:      $ " << totalMes << endl;
            }

            totalMod3Veces += ingresos[m][0];
            totalModPaseLibre += ingresos[m][1];
            totalGeneral += totalMes;
        }

        cout << "==========================================" << endl;
        cout << "           TOTALES GENERALES DEL ANIO " << anio << endl;
        cout << "==========================================" << endl;
        cout << "Total 3 Veces por Semana: $ " << totalMod3Veces << endl;
        cout << "Total Pase Libre:         $ " << totalModPaseLibre << endl;
        cout << "INGRESO TOTAL ANUAL:    $ " << totalGeneral << endl;
        cout << "==========================================" << endl;

        rlutil::anykey();
        rlutil::cls();
    }
}
void clientesNoAnotadosAnioActual()
{
    ArchivoInscripcion archIns("inscripciones.dat");
    ArchivoCliente archCli("clientes.dat");



    int cantIns = archIns.contarInscripciones();
    const int cantCli = archCli.contarClientes();
    bool noInscripto[8] = {false};

    for (int i = 0; i < cantCli; i++)
    {
        Persona cli = archCli.leerArchivo(i);
        for (int j = 0; j < cantIns; j++)
        {
            InscripcionActividad ins = archIns.leerInscripcion(j);
            if(cli.getNumeroSocio() == ins.getNumeroSocio() && ins.getFechaInscripcion().getAnio() == 2025)
            {
                cout << "Este chad si viene: " << cli.getNumeroSocio() << endl;
                noInscripto[i] = true;
            }
        }
        if(noInscripto[i] == false) cout << "Este puto no viene: " << cli.getNumeroSocio() << endl;


    }

}
