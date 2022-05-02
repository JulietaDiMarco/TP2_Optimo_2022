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
        bool QuitarAvion(cAvion* avion_);
        bool AgregarAvion(cAvion* avion_);

        /// <summary>
        /// Determina la cantidad total de pasajeros que volaron en
        /// una determina fecha.
        /// </summary>
        /// <param name="fecha">Fecha para hacer la estadistica</param>
        /// <returns>Cantidad total de pasajeros</returns>
        int CantPasajerosVolaron(cFecha* fecha);
        
        /// <summary>
        /// Detemina la cantidad de vuelos aterrizados en un
        /// dia en particular
        /// </summary>
        /// <param name="fecha"></param>
        /// <returns></returns>
        int CantVuelosAterrizados(cFecha* fecha);

        /// <summary>
        /// Detemina la cantidad de vuelos despegados en un
        /// dia en particular
        /// </summary>
        /// <param name="fecha"></param>
        /// <returns></returns>
        int CantVuelosDespegaron(cFecha* fecha);

        float PorcentajeDespeguesEnHorario();

        float PorcentajeArribosEnHorario();

    private: 
        const string idAeropuerto;
        int capacidad;
        cListaVuelo* vuelos;
        cListaAvion* aviones;

};

#endif 