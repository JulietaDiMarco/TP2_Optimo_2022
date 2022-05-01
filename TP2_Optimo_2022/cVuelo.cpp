#include "cVuelo.h"
#include "cAvion.h"
#include "cAeropuerto.h"

unsigned int cVuelo::Contador = 0;

cVuelo::cVuelo(bool estado_, eDestino destino_, eTramo tramo_, cAvion* avion_, cFecha* partida_, cFecha* aterrizaje_):nroVuelo(to_string(Contador)) {
    Contador++;
    this->avion=avion_;
    this->estado = estado_;
    this->destino = destino_;
    this->tramo = tramo_;
    pasajeros = new cListaPasajero();
    this->partida = new cFecha(*partida_);
    this->aterrizaje = new cFecha(*aterrizaje_);
}

cVuelo::~cVuelo() {
    delete pasajeros;
    delete partida;
    delete aterrizaje;
}

void cVuelo::verPasajero(string DNI) {
    
    int pos = pasajeros->buscar(DNI);
    //imprimir con sobrecarga de << pasajeros[pos];

}

string cVuelo::tostring() {
    return "";
}

void cVuelo::imprimir() {
    return;
}


float cVuelo::getpesoTotalEquipajes()
{
    return pasajeros->getpesoTotalEquipajes();
}

unsigned int cVuelo::getCantidadPasajeros()
{
    return pasajeros->CantidadActual;
}

bool cVuelo::RealizarDespegue(cAeropuerto* aeropuerto)
{
    try {
        avion->chequearCargaMaxima(this);
        avion->chequearCapacidadMaxima(this);
    }
    catch (...) {

    }
    avion->pedirPermisoDespegue(aeropuerto); //TODO try catch
    avion->despegar();
    aeropuerto->QuitarAvion(avion);
    return true;
}

bool cVuelo::RealizarAterrizaje(cAeropuerto* aeropuerto)
{
    avion->pedirPermisoAterrizaje(aeropuerto); //TODO try catch
    avion->aterrizar();
    aeropuerto->AgregarAvion(avion);
    return true;
}
