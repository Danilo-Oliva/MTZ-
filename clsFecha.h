#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha(int d=0, int m=0, int a=0000);
    //setters
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    //getters
    int getDia();
    int getMes();
    int getAnio();
    //metodos
    void cargar(int x, int y, int x2, int x3);
    bool cargarCompacta(int xpos, int ypos);
    void mostrar();
    bool esBisiesto();
    bool esValida();
};

#endif // CLSFECHA_H_INCLUDED
