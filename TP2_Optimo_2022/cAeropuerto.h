#ifndef _CAEROPUERTO_H
#define _CAEROPUERTO_H

#include "cListaVuelo.h"
#include "cListaAvion.h"

class cAeropuerto {
    public: 
    
        cAeropuerto(string idAeropuerto_, int capacidad_);
        ~cAeropuerto();
    
        bool darPermisoAterrizaje(cAvion& a);
        bool darPermisoDespegue(cAvion& a);

        bool chequearCapacidadAvion(cAvion* a, cVuelo* v);

        string tostring();    
        void imprimir();

        string getIdAeropuerto() { return this->idAeropuerto; }
        int getCapacidad() { return this->capacidad; }
        //unsigned int getAvionesEstacionados() { return this->avionesEstacionados; }

        int avionesEstacionados();
        bool pistaDespejada();
        
        /// <summary>
        /// Determina la cantidad total de pasajeros que volaron en
        /// una determina fecha.
        /// </summary>
        /// <param name="fecha">Fecha para hacer la estadistica</param>
        /// <returns>Cantidad total de pasajeros</returns>
        int CantPasajerosVolaron(cFecha fecha);

    private: 
        const string idAeropuerto;
        int capacidad;
        cListaVuelo* vuelos;
        cListaAvion* aviones;

};

#endif //_CAEROPUERTO_H