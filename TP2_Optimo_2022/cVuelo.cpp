#include "cVuelo.h"
#include "cAvion.h"
/**
 * cVuelo implementation
 */

unsigned int cVuelo::Contador = 0;

cVuelo::cVuelo(bool estado_, eDestino destino_, eTramo tramo_, cAvion* avion_):nroVuelo(to_string(Contador)) {
    Contador++;
    this->avion=avion_;
    this->estado = estado_;
    this->destino = destino_;
    this->tramo = tramo_;
    pasajeros = new cListaPasajero();
}

cVuelo::~cVuelo() {
    delete pasajeros;
}

void cVuelo::verPasajero(string DNI) {
    
    int pos = pasajeros->buscar(DNI);
    //imprimir con sobrecarga de << pasajeros[pos];

}

/**
 * @return string
 */
string cVuelo::tostring() {
    return "";
}

/**
 * @return void
 */
void cVuelo::imprimir() {
    return;
}


float cVuelo::getpesoTotalEquipajes()
{
    pasajeros->getpesoTotalEquipajes();
}

bool cVuelo::IniciarDespegue()
{
    avion->pedirPermisoDespegue(this);
    return false;
}
