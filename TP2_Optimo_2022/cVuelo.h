#ifndef _CVUELO_H
#define _CVUELO_H

#include "cListaPasajero.h"
#include "gbl.h"

class cAvion;
class cAeropuerto;
class cVuelo {

    friend class cAvion;
public:

    cVuelo(bool estado_, eDestino destino_, eTramo tramo_, cAvion* avion_);
    ~cVuelo();

    void verPasajero(string DNI);
   
    string tostring();
    void imprimir();

    string get_nroVuelo() { return this->nroVuelo; }
    bool getEstado() { return this->estado; }
    eDestino getDestino() { return this->destino; }
    float getpesoTotalEquipajes();

    bool RealizarDespegue(cAeropuerto * aeropuerto);
    bool RealizarAterrizaje(cAeropuerto* aeropuerto);

private:
    const string nroVuelo;
    bool estado; //true si esta volando, false si esta en tierra
    eDestino destino;
    eTramo tramo;
    cListaPasajero* pasajeros;
    cAvion* avion;
    static unsigned int Contador;
    
};

#endif //_CVUELO_H