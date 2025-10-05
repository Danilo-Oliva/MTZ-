#ifndef CLSARCHIVOFICHAMEDICA_H_INCLUDED
#define CLSARCHIVOFICHAMEDICA_H_INCLUDED
#include"clsFichaMedica.h"

class ArchivoFichaMedica{
private:
    char nombreArchivo[30];
    FichaMedica fm;
public:
    ArchivoFichaMedica(const char *n = "fichaMedica.dat", FichaMedica _fm = FichaMedica());

    bool inscribirFichaMedica(FichaMedica);
    FichaMedica leerArchivo(int);
    int contarFichasMedicas();
    void listar();
    bool modificarFichaMedica(FichaMedica, int);
};

#endif // CLSARCHIVOFICHAMEDICA_H_INCLUDED
