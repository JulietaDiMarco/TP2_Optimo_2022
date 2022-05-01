#include "cAvion.h"
#define N_TRIPULANTES 4
#define PESO_PROMEDIO 75
// #include "cAeropuerto.h" 

/**
 * cAvion implementation
 */

unsigned int cAvion::cantidad_aviones = 0;

cAvion::cAvion(int cantidadPasajeros_, int cantidadActual_, bool permisoAterrizaje_, bool permisoDespegue_, float pesoMaximo_, bool volando_):id(to_string(cantidad_aviones)) {
    cantidad_aviones++;
    this->pesoMaximo = pesoMaximo_;
    this->volando = volando_;
}

cAvion::~cAvion() {
}

/**
 * @return bool
 */
bool cAvion::despegar() {
    
    if (permisoDespegue) {
        setVolando(true); // cambio el estado del avion y lo paso a volando
        return true;
    }else
    return false;
}

/**
 * @return bool
 */
bool cAvion::aterrizar() {
    
    if (permisoAterrizaje) {

        setVolando(false); //cambio el estado del avion y lo paso a tierra (no volando)
        return true;
    }
    else
        return false;
}

/**
 * @return bool
 */
bool cAvion::pedirPermisoAterrizaje() {

    if (getVolando()) {
        return true;
    }
     return false;
}



bool cAvion::pedirPermisoDespegue(cVuelo* vuelo) {
  
    if (getVolando()) {
        return true;
    }
     return false;
}

/**
 * @return bool
 */


/**
 * @return bool
 */
void cAvion::chequearCargaMaxima(cVuelo* vuelo) {
    float peso_humano = (vuelo->pasajeros->getCantidadActual() + N_TRIPULANTES)* PESO_PROMEDIO;
    float peso_equipaje = vuelo->getpesoTotalEquipajes();
    float peso_total = peso_humano + peso_equipaje;

    if (peso_total > pesoMaximo)
        return;
    else
        throw new exception("Carga máxima superada. Despegue abortado.");

}




void cAvion::setVolando(bool vuela){
    volando = vuela;
}


/**
 * @return string
 */
string cAvion::tostring() {
    return "";
}

/**
 * @return void
 */
void cAvion::imprimir() {
    return;
}