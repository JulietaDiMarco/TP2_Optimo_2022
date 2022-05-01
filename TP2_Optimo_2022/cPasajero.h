#ifndef _CPASAJERO_H
#define _CPASAJERO_H
#include "cListaEquipaje.h"
#include "cFecha.h"

class cPasajero {

public: 
    
    cPasajero(string DNI_, string nombre_, string apellido_, unsigned int asiento_, unsigned int cantTotal, unsigned int cantActual);
    ~cPasajero();
    
    string getDNI();
    string getNombre();
    string getApellido();
    float getPesoTotal();

    bool agregarEquipaje(cEquipaje * valija);
    bool eliminarEquipaje(string id);

    string tostring();
    void imprimir();
    
private: 
    string DNI;
    string nombre;
    string apellido;
    unsigned int asiento;
    cFecha* fecha_nacimiento;
    cListaEquipaje* valijas;

};

#endif //_CPASAJERO_H