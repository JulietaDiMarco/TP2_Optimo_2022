#include "cVuelo.h"
#include "cAeropuerto.h"

unsigned int cVuelo::Contador = 0;

cVuelo::cVuelo(bool estado_, eDestino destino_, eTramo tramo_, cAvion* avion_, cFecha* partida_, cFecha* aterrizaje_):nroVuelo(to_string(Contador)){
    Contador++;
    this->avion=avion_;
    this->estado = estado_;
    this->destino = destino_;
    this->tramo = tramo_;
    pasajeros = new cListaPasajero(avion->capacidad_maxima); //la lista tiene un tamaño máximo de la capacidad máxima del avion
    this->partida = new cFecha(*partida_);
    this->aterrizaje = new cFecha(*aterrizaje_);
    this->en_horario = false;
}

cVuelo::~cVuelo(){
    delete pasajeros;
    delete partida;
    delete aterrizaje;
}

float cVuelo::getpesoTotalEquipajes()
{
    return pasajeros->getpesoTotalEquipajes();
}

unsigned int cVuelo::getCantidadPasajeros()
{
    return pasajeros->CantidadActual;
}

bool cVuelo::RealizarDespegue(cAeropuerto* aeropuerto, cFecha* fecha)
{
    if (!avion->volando && tramo == eTramo::Partida) {
        try {
            avion->chequearCargaMaxima(this);
            avion->chequearCapacidadMaxima(this);
        }
        catch (exception* e) {
            delete e;
            return false;
        }
        avion->pedirPermisoDespegue(aeropuerto); //TODO try catch
        avion->despegar();
        verificarhorario(partida, fecha);
        aeropuerto->QuitarAvion(avion);
        return true;
    }
    else
        throw new exception("El vuelo ya despegó o es un arribo.");
}

void cVuelo::verificarhorario(cFecha* mi_hora, cFecha* fecha) {
    if (*fecha < *mi_hora || *fecha == *mi_hora)
        en_horario = true;
}

bool cVuelo::RealizarAterrizaje(cAeropuerto* aeropuerto, cFecha* fecha)
{
    if (avion->volando && tramo == eTramo::Arribo) {
        try {
            avion->pedirPermisoAterrizaje(aeropuerto);
        }
        catch (exception* e) {
            delete e;
            return false;
        }
        avion->aterrizar();
        verificarhorario(aterrizaje, fecha);
        aeropuerto->AgregarAvion(avion);
        return true;
    }
    else
        throw new exception("El vuelo ya aterrizó o es una partida.");
}

string cVuelo::tostring() {
    string text = "";
    text += "\nNroVuelo: " + this->nroVuelo + " Destino: " + eDestinoToString(this->destino);
    text += " Cantidad Pasajeros: " + std::to_string(this->pasajeros->CantidadActual);
    return text;
}

void cVuelo::imprimir() {
    
    cout << this->tostring() << endl;

}

void cVuelo::verPasajero(string DNI) {

    int pos = pasajeros->buscar(DNI);
    cPasajero* mi_pasajero = pasajeros->buscar(pos);
    mi_pasajero->imprimir();

}

bool cVuelo::AgregarPasajero(cPasajero* pasajero)
{
    return pasajeros->agregar(pasajero);
}

bool cVuelo::EliminarPasajero(cPasajero* pasajero)
{
    return pasajeros->quitar(pasajero) != NULL;
}

bool cVuelo::CambiarPasajero(cPasajero* eliminado, cPasajero* agregado)
{
    if (pasajeros->quitar(eliminado)) {
        return pasajeros->agregar(agregado);
    }
    else
        return false;
}

ostream& operator<<(ostream& out, cVuelo& vuelo)
{
    return out << vuelo.tostring() << endl;
}