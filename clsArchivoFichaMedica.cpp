#include <iostream>
#include <cstring>
#include "clsArchivoFichaMedica.h"
#include "clsFichaMedica.h"

using namespace std;

ArchivoFichaMedica::ArchivoFichaMedica(const char *n, FichaMedica _fm){
    strcpy(nombreArchivo, n);
    fm = _fm;
}

bool ArchivoFichaMedica::inscribirFichaMedica(FichaMedica fm){
    FILE *p = fopen(nombreArchivo, "ab");
    if(p == nullptr){
        return false;
    }

    int nuevoId = contarFichasMedicas() + 1;
    fm.setIdFM(nuevoId);

    bool escribio = fwrite(&fm, sizeof fm, 1, p);
    fclose(p);
    return escribio;
}

FichaMedica ArchivoFichaMedica::leerArchivo(int pos){
    FILE *p = fopen(nombreArchivo, "rb");

    if(p == nullptr)
    {
        fm.setIdFM(-1);
        return fm;
    }

    fseek(p, pos * sizeof fm, 0);
    fm.setIdFM(-2);

    fread(&fm, sizeof fm, 1, p);
    fclose(p);

    return fm;
}

int ArchivoFichaMedica::contarFichasMedicas(){
    FILE *p = fopen(nombreArchivo, "rb");

    if(p == nullptr){
        cout << "No se ha cargado clientes en el sistema" << endl;
        return -1;
    }

    fseek(p, SEEK_SET, SEEK_END);
    int bytes = ftell(p);

    fclose(p);
    return bytes/sizeof(fm);
}

void ArchivoFichaMedica::listar(){
    int cantFM = contarFichasMedicas();

    for(int i = 0; i < cantFM; i++){
        fm = leerArchivo(i);
        fm.mostrar();
    }
}

bool ArchivoFichaMedica::modificarFichaMedica(FichaMedica fm, int pos){
    FILE *p = fopen(nombreArchivo, "rb+");

    if (p == nullptr);
        return false;

    fseek(p, pos * sizeof fm, 0);
    bool escribio = fwrite(&fm, sizeof fm, 1, p);

    fclose(p);
    return escribio;
}
