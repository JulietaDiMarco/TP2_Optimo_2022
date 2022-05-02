#ifndef _CAVION_H
#define _CAVION_H

#pragma once

#include "cVuelo.h"

class cAeropuerto;

class cAvion {
    friend class cVuelo;

    private: 
        const string id;
        float pesoMaximo;
        int capacidad_maxima;
        bool volando; //avion puede estar en tierra o en vuelo
        static unsigned int cantidad_aviones;

    public:
        
    #pragma region Constructores y destructores
        
        cAvion(float pesoMaximo_, float capacidad_maxima_, bool volando_);
        ~cAvion();
    
    #pragma endregion

    #pragma region Getter y setters

        bool getVolando() { return this->volando; } // devuelve true si el avion esta volando y false si esta en tierra
        float getPesoMaximo() { return this->pesoMaximo; }
        void setVolando(bool vuela);
        string getID() { return this->id; }

    #pragma endregion

    #pragma region Metodos

        void despegar();
        void aterrizar();
        bool pedirPermisoAterrizaje(cAeropuerto* aeropuerto);
        bool pedirPermisoDespegue(cAeropuerto* aeropuerto);
        void chequearCapacidadMaxima(cVuelo* vuelo);
        void chequearCargaMaxima(cVuelo* vuelo);

        string tostring();
        void imprimir();

    #pragma endregion

    #pragma region Operadores

        friend ostream& operator<<(ostream& out, cAvion& avion);

    #pragma endregion

};

#endif 