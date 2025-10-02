#include "cargarDatos.h"
#include "clsPersona.h"
#include "clsActividad.h"
#include "clsFecha.h"
#include "clsFichaMedica.h"
#include "clsDomicilio.h"
using namespace std;

int contarSocios(const char *clientesArchivo){
    ifstream archivo(clientesArchivo);
    if (!archivo) return 0; //por si no existe todavia

    int contador = 0;
    string linea;
    while(getline(archivo, linea)){
        if(linea.find("Nro Socio: ") != string::npos){
            contador ++;
        }
    }
    archivo.close();
    return contador;
}

void guardarCliente(Persona &p, Actividad &act, const char *clientesArchivo, FichaMedica &fm) {
    int nroSocio = contarSocios(clientesArchivo) + 1;
    p.setNumeroSocio(nroSocio);

    ofstream archivo(clientesArchivo, ios::app); // abrimos en modo append
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    archivo << "DNI: " << p.getDNI() << endl;
    archivo << "Nro Socio: " << p.getNumeroSocio() << endl;
    archivo << "Nombre: " << p.getNombre() << endl;
    archivo << "Apellido: " << p.getApellido() << endl;
    archivo << "Telefono: " << p.getTelefono() << endl;
    archivo << "Email: " << p.getEmail() << endl;

    Fecha f = p.getFechaNacimiento();
    archivo << "Fecha Nac: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;

    archivo << "Cuota Base: $" << act.getCuotaBase() << endl;
    switch(act.getOpcion_act())
    {
    case 1:
        archivo << "Actividad: Funcional" << endl;
        break;
    case 2:
        archivo << "Actividad: Musculacion" << endl;
        break;
    case 3:
        archivo << "Actividad: Boxeo" << endl;
        break;
    default:
        archivo << "No se ha registrado la actividad" << endl;
        break;
    }
    archivo << "Modalidad: " << (act.getLibre() ? "Libre" : "3 veces/semana") << endl;
    archivo << "Cuota Final: $" << act.calcularCuota() << endl;

    archivo << "========== FICHA MEDICA ==========" << endl;
    archivo << "Domicilio: " << endl;
    Domicilio d = fm.getDomicilio();
    archivo << "Calle: " << d.getCalle() << d.getAltura() << endl;
    archivo << "Localidad: " << d.getLocalidad() << endl;
    archivo << "Codigo Postal: " << d.getCodigoPostal() << endl;
    archivo << "Partido: " << d.getPartido() << endl;
    archivo << "Peso: " << fm.getPeso() << "kg" << endl;
    archivo << "Altura: " << fm.getAltura() << "cm" << endl;
    archivo << "Numero de emergencia: " << fm.getNroEmergencia() << endl;
    archivo << "Nombre de la persona: " << fm.getNomEmergencia() << endl;
    archivo << "Parentesco: " << fm.getParentesco() << endl;
    archivo << "Obra Social: " << fm.getObraSocial() << endl;
    archivo << "====================================" << endl;
    archivo << endl << "------------------------------------" << endl;

    archivo.close();
    cout <<endl << "Cliente guardado en archivo con exito." << endl;
}

void mostrarArchivo(const char *clientesArchivo) {
    ifstream archivo(clientesArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

