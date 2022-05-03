

#include "cAeropuerto.h"

cAeropuerto::cAeropuerto(string idAeropuerto_, int capacidad_):idAeropuerto(idAeropuerto_) {
    this->capacidad = capacidad_;
    aviones = new cListaAvion(capacidad, false);
    vuelos = new cListaVuelo(capacidad, false);
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
    string concat = "";
    concat = "ID Aeropuerto: " + getIdAeropuerto();
    concat += "\nCapacidad Aeropuerto: " + to_string(getCapacidad());

    return concat;
}

/**
 * @return void
 */
void cAeropuerto::imprimir() {
    cout << tostring() << endl;
    return;
}


bool cAeropuerto::QuitarAvion(cAvion* avion_)
{
    cAvion* auxiliar;
    auxiliar = aviones->quitar(avion_);
    return auxiliar != NULL; //si auxiliar es != a NULL significa que lo encontré y lo quité de la lista
}

bool cAeropuerto::AgregarAvion(cAvion* avion_)
{
    return aviones->agregar(avion_); //TODO check
}

bool cAeropuerto::AgregarVuelo(cVuelo* vuelo_)
{
    return vuelos->agregar(vuelo_);
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

float cAeropuerto::PorcentajeDespeguesEnHorario() {

    int cont_enHorario = 0;

    for (int i = 0; i < vuelos->getCantidadActual(); i++)
    {
        if ((*vuelos)[i]->getTramo() == eTramo::Partida
            && (*vuelos)[i]->getEnHorario())
            cont_enHorario++;
    }
    
    return (float)cont_enHorario / (float)vuelos->getCantidadActual();

}

float cAeropuerto::PorcentajeArribosEnHorario() {

    int cont_enHorario = 0;

    for (int i = 0; i < vuelos->getCantidadActual(); i++)
    {
        if ((*vuelos)[i]->getTramo() == eTramo::Arribo
           && (*vuelos)[i]->getEnHorario())
        {
            cont_enHorario++;
        }
    }

    float porcentaje = (cont_enHorario) / (vuelos->getCantidadActual());

    return (porcentaje * 100);

}

