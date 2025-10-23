#ifndef CLSACTIVIDAD_H_INCLUDED
#define CLSACTIVIDAD_H_INCLUDED

class Actividad{
private:
    int idAct;
    char Nombre[50];
    float CuotaBase;
    bool Estado;

public:
    // Constructores
    Actividad(const char* nombre = "Sin nombre", float cuota = 0.0f, bool estado = true);

    // Setters
    void setIdAct(int);
    void setNombre(const char*);
    void setCuotaBase(float);
    void setEstado(bool);

    // Getters
    int getIdAct();
    const char* getNombre();
    float getCuotaBase();
    bool getEstado();

    // M�todos
    float calcularCuota();
    void cargar(int proximoId);
    void mostrar();
};

#endif // CLSACTIVIDAD_H_INCLUDED
