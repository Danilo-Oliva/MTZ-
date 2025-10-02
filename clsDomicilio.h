#ifndef CLSDOMICILIO_H_INCLUDED
#define CLSDOMICILIO_H_INCLUDED

class Domicilio{
private:
    char Calle[30];
    char CodigoPostal[6];
    char Localidad[30];
    char Partido[30];
    int Altura;
public:
    Domicilio(const char *_calle = "Sin registrar", const char *_CodigoPostal = "Sin registrar", const char *_Localidad = "Sin registrar", const char *_Partido = "Sin registrar", int _altura = 0);
    /// SETTERS
    void setCalle(const char *_calle);
    void setCodigoPostal(const char *_CodigoPostal);
    void setLocalidad(const char *_Localidad);
    void setPartido(const char *_Partido);
    void setAltura(int _altura);

    /// GETTERS
    const char *getCalle();
    const char *getCodigoPostal();
    const char *getLocalidad();
    const char *getPartido();
    int getAltura();


    /// METODOS
    void Cargar();
    void Mostrar();
};

#endif // CLSDOMICILIO_H_INCLUDED
