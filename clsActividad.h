#ifndef CLSACTIVIDAD_H_INCLUDED
#define CLSACTIVIDAD_H_INCLUDED

class Actividad{
protected:
    float CuotaBase;
    int opcion_act;
    bool Libre;
public:
    Actividad(float _Cuota = 0.0f, bool _Libre = false, int _opcion_act = 0);
    //setters
    void setCuotaBase(float);
    void setLibre(bool);
    void setOpcion_act(int);

    //getters
    float getCuotaBase();
    bool getLibre();
    int getOpcion_act();

    //metodos
    float calcularCuota();
    void cargar();
    void mostrar();
};

class Musculacion : public Actividad{
public:
    Musculacion(bool Libre = false);
};

class Funcional : public Actividad{
public:
    Funcional(bool Libre = false);
};

class Boxeo : public Actividad{
public:
    Boxeo(bool Libre = false);
};
#endif // CLSACTIVIDAD_H_INCLUDED
