#ifndef _CAVION_H
#define _CAVION_H
#include "gbl.h"
#include "cVuelo.h"

class cAvion {

public: 
    cAvion(int cantidadPasajeros_, int cantidadActual_, bool permisoAterrizaje_, bool permisoDespegue_, float pesoMaximo_, bool volando_);
    ~cAvion();
    
    bool despegar();    
    bool aterrizar();
    bool pedirPermisoAterrizaje();
    bool pedirPermisoDespegue(cVuelo* vuelo);
    float getPesoTotalEquipaje();
    bool chequearCapacidadAvion();
    void chequearCargaMaxima(cVuelo* vuelo);

    bool conVueloAsignado();
    bool getVolando() { return this->volando; } // devuelve true si el avion esta volando y false si esta en tierra
    float getPesoMaximo() { return this->pesoMaximo; }
    void setVolando(bool vuela);
    string getID() { return this->id; }
   

    string tostring();
    void imprimir();

private: 
    const string id;
    float pesoMaximo;
    bool volando; //avion puede estar en tierra o en vuelo
    static unsigned int cantidad_aviones;
    
};

#endif 