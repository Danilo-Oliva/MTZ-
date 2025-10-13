#ifndef CLSACTIVIDAD_H_INCLUDED
#define CLSACTIVIDAD_H_INCLUDED

class Actividad{
private:
    int idAct;
    char Nombre[50];
    float CuotaBase;
    bool Libre;
    bool Estado;

public:
    // Constructores
    Actividad(const char* nombre = "Sin nombre", float cuota = 0.0f, bool libre = true, bool estado = true);

    // Setters
    void setIdAct(int);
    void setNombre(const char*);
    void setCuotaBase(float);
    void setLibre(bool);
    void setEstado(bool);

    // Getters
    int getIdAct();
    const char* getNombre();
    float getCuotaBase();
    bool getLibre();
    bool getEstado();

    // Métodos
    float calcularCuota();
    void cargar(int proximoId);
    void mostrar();
};

#endif // CLSACTIVIDAD_H_INCLUDED
