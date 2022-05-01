
#include "cAeropuerto.h"

cAeropuerto::cAeropuerto(string idAeropuerto_, int capacidad_):idAeropuerto(idAeropuerto_) {
    this->capacidad = capacidad_;
    aviones = new cListaAvion(capacidad, false);
    vuelos = new cListaVuelo(1, false);
}

cAeropuerto::~cAeropuerto() {
    delete vuelos;
    delete aviones;
}
/**
 * chequea si esta volando doy permiso de aterrizaje y sino le doy permiso de despegar
 */
bool cAeropuerto::darPermisoAterrizaje(){

    unsigned int CA = aviones->getCantidadActual();
    if (CA < capacidad)
        return true;
    else
        throw new exception("Hangar lleno. No se permite el aterrizaje");
}

bool cAeropuerto::darPermisoDespegue() {

    unsigned int CA = aviones->getCantidadActual();
    if (CA > 0)
        return true;
    else
        throw new exception("No hay aviones disponibles para realizar el despegue.");
}

/**
 * @return bool
 */

string cAeropuerto::tostring() {
    return "";
}

/**
 * @return void
 */
void cAeropuerto::imprimir() {
    return;
}

int cAeropuerto::avionesEstacionados()
{   
    int cantAviones = 0; 
    int aux = 0;

    while (aux < capacidad) {
        if (aviones != NULL) {
            cantAviones++;
        }
        aux++;
    }

    return cantAviones;
}

bool cAeropuerto::pistaDespejada()
{
    for (int i = 0; i < capacidad; i++) {
        cAvion* aux = aviones->buscar(i); // aca estuve probando varias cosas, es a chequear
        if (!aux->getVolando()) { // si el avion no esta volando, la pista no esta despejada
            delete aux;
            return false;
        }
        else {
            delete aux;
        }
    }    
    return true;
}

bool cAeropuerto::QuitarAvion(cAvion* avion_)
{
    cAvion* auxiliar;
    auxiliar = aviones->quitar(avion_);
    return auxiliar != NULL; //si auxiliar es != a NULL significa que lo encontré y lo quité de la lista
}

int cAeropuerto::CantPasajerosVolaron(cFecha* fecha)
{
    int acumulador_pasajeros = 0;

    for (int i = 0; i < vuelos->getCantidadActual(); i++)
        if(cFecha::MismoDia((*vuelos)[i]->getPartida(), fecha) ||
            cFecha::MismoDia((*vuelos)[i]->getAterrizaje(), fecha))
            acumulador_pasajeros += (*vuelos)[i]->getCantidadPasajeros();

    return acumulador_pasajeros;
}

int cAeropuerto::CantVuelosAterrizados(cFecha* fecha)
{
    int cont = 0;
    for (int i = 0; i < vuelos->getCantidadActual(); i++)
        if (cFecha::MismoDia((*vuelos)[i]->getAterrizaje(), fecha))
            cont++;
    return cont;
}

int cAeropuerto::CantVuelosDespegaron(cFecha* fecha)
{
    int cont = 0;
    for (int i = 0; i < vuelos->getCantidadActual(); i++)
        if (cFecha::MismoDia((*vuelos)[i]->getPartida(), fecha))
            cont++;
    return cont;
}
