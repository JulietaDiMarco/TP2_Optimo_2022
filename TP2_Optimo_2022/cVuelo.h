#ifndef _CVUELO_H
#define _CVUELO_H

#include "cListaPasajero.h"

class cAvion;
class cAeropuerto;

class cVuelo {
    friend class cAvion;

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

    public:

    #pragma region Constructores y destructores
        
        cVuelo(bool estado_, eDestino destino_, eTramo tramo_, cAvion* avion_, cFecha* partida_, cFecha* aterrizaje_);
        ~cVuelo();

    #pragma endregion

    #pragma region Getter y setters
        
        string get_nroVuelo() { return this->nroVuelo; }
        
        bool getEstado() { return this->estado; }
        
        eDestino getDestino() { return this->destino; }
        
        eTramo getTramo() { return this->tramo; };

        bool getEnHorario() { return en_horario; };
        
        cFecha* getPartida() { return partida; };
        
        cFecha* getAterrizaje() { return aterrizaje; };
        
        void setEnHorario(bool enHorario) {
            this->en_horario = enHorario;
        }

        /// <summary>
        /// Retorna el peso total del equipaje que transporta el avion
        /// </summary>
        /// <returns></returns>
        float getpesoTotalEquipajes();
        
        /// <summary>
        /// Retorna la cantidad de Pasajeros en el vuelo
        /// </summary>
        /// <returns></returns>
        unsigned int getCantidadPasajeros();
    
    #pragma endregion

    #pragma region Metodos

        string tostring();
        void imprimir();

        bool RealizarDespegue(cAeropuerto* aeropuerto, cFecha* fecha);
        bool RealizarAterrizaje(cAeropuerto* aeropuerto, cFecha* fecha);

        /// <summary>
        /// Metodo que determina si el vuelo esta en horario o se atraso
        /// </summary>
        /// <param name="mi_hora"></param>
        /// <param name="fecha"></param>
        void verificarhorario(cFecha* mi_hora, cFecha* fecha);

        void verPasajero(string DNI);
        bool AgregarPasajero(cPasajero* pasajero);
        bool EliminarPasajero(cPasajero* pasajero);
        bool CambiarPasajero(cPasajero* eliminado, cPasajero* agregado);
    
    #pragma endregion

    #pragma region Operadores
        
        friend ostream& operator<<(ostream& out, cVuelo& vuelo);

    #pragma endregion

};

#endif //_CVUELO_H