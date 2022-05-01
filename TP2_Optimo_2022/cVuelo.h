#ifndef _CVUELO_H
#define _CVUELO_H

#include "cListaPasajero.h"

class cAvion;
class cAeropuerto;

class cVuelo {
    friend class cAvion;

public:

    cVuelo(bool estado_, eDestino destino_, eTramo tramo_, cAvion* avion_, cFecha* partida_, cFecha* aterrizaje_);
    ~cVuelo();

    void verPasajero(string DNI);
   
    string tostring();
    void imprimir();

    string get_nroVuelo() { return this->nroVuelo; }
    bool getEstado() { return this->estado; }
    eDestino getDestino() { return this->destino; }
    eTramo getTramo() { return this->tramo; };
    float getpesoTotalEquipajes();
    unsigned int getCantidadPasajeros();

    bool RealizarDespegue(cAeropuerto * aeropuerto, cFecha* fecha);
    bool RealizarAterrizaje(cAeropuerto* aeropuerto, cFecha* fecha);

    void verificarhorario(cFecha* mi_hora, cFecha* fecha);

    bool AgregarPasajero(cPasajero* pasajero);
    bool EliminarPasajero(cPasajero* pasajero);
    bool CambiarPasajero(cPasajero* eliminado, cPasajero* agregado);
    
    cFecha* getPartida() { return partida; };
    cFecha* getAterrizaje() { return aterrizaje; };

private:
    const string nroVuelo;
    bool estado; //true si esta volando, false si esta en tierra
    eDestino destino;
    eTramo tramo;
    cListaPasajero* pasajeros;
    cAvion* avion;
    static unsigned int Contador;
    cFecha* partida;
    cFecha* aterrizaje;
    bool en_horario;
    
};

#endif //_CVUELO_H