#ifndef _CAVION_H
#define _CAVION_H
#include "gbl.h"
#include "cVuelo.h"

class cAeropuerto;

class cAvion {

public: 
    cAvion(int cantidadPasajeros_, int cantidadActual_, bool permisoAterrizaje_, bool permisoDespegue_, float pesoMaximo_, bool volando_);
    ~cAvion();
    
    void despegar();    
    void aterrizar();
    bool pedirPermisoAterrizaje(cAeropuerto* aeropuerto);
    bool pedirPermisoDespegue(cAeropuerto* aeropuerto);
    float getPesoTotalEquipaje();
    void chequearCapacidadMaxima(cVuelo* vuelo);
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
    int capacidad_maxima;
    bool volando; //avion puede estar en tierra o en vuelo
    static unsigned int cantidad_aviones;
    
};

#endif 