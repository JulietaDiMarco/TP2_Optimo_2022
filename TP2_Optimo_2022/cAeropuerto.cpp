
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
bool cAeropuerto::darPermisoAterrizaje(cAvion& a){
    if (a.getVolando() && pistaDespejada()) {
        a.setPermisoAterrizaje(true);
        a.aterrizar();
        return true;
    }
    else if (a.getVolando() && !pistaDespejada()) {
        return false;
    }
}

bool cAeropuerto::darPermisoDespegue(cAvion& a) {

    if (!a.getVolando() && pistaDespejada()) {
        if (a.chequearPesoEquipaje() && a.chequearCapacidadAvion()) {
            a.setPermisoDespegue(true);
            a.despegar();
            return true;
        }
    }
    return false;
}

bool cAeropuerto::chequearCapacidadAvion(cAvion* a, cVuelo* v)
{
    if (a != NULL) {
        //float auxPeso = a->getPesoMaximo();
        float auxPeso = 0;
        auxPeso = (a->getCantidadActual() + 4) * 75 + a->getCantidadActual() * v->getPesoValijas();           //aca le tengo que sumar la cantidad de pasajeros por el peso de sus valijas
        if (auxPeso < a->getPesoMaximo()) { return true; }
        else { return false; }
    }
    return false;
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

int cAeropuerto::CantPasajerosVolaron(cFecha fecha)
{
    //TODO
    for (int i = 0; i < 25/*getCantidadActual*/; i++)
    {
        vuelos[i].
    }
}
