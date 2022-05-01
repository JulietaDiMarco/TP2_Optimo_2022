#ifndef _CAEROPUERTO_H
#define _CAEROPUERTO_H

#include "cListaAvion.h"
#include "cListaVuelo.h"

class cAeropuerto {    
    friend class cAvion;
public: 
    
        cAeropuerto(string idAeropuerto_, int capacidad_);
        ~cAeropuerto();
    
        bool darPermisoAterrizaje();
        bool darPermisoDespegue();

        bool chequearCapacidadAvion(cAvion* a, cVuelo* v);

        string tostring();    
        void imprimir();

        string getIdAeropuerto() { return this->idAeropuerto; }
        int getCapacidad() { return this->capacidad; }
        unsigned int getAvionesEstacionados() { return aviones->getCantidadActual(); }

        int avionesEstacionados();
        bool pistaDespejada();
        bool QuitarAvion(cAvion* avion_);

    private: 
        const string idAeropuerto;
        int capacidad;
        cListaVuelo* vuelos;
        cListaAvion* aviones;

};

#endif 