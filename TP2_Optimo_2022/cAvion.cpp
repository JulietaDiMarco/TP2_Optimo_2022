
#include "cAvion.h"
#include "cAeropuerto.h" 

#define N_TRIPULANTES 4
#define PESO_PROMEDIO 75

unsigned int cAvion::cantidad_aviones = 0;

cAvion::cAvion(float pesoMaximo_, float capacidad_maxima_, bool volando_):id(to_string(cantidad_aviones)) {
    cantidad_aviones++;
    this->pesoMaximo = pesoMaximo_;
    this->volando = volando_;
    this->capacidad_maxima = capacidad_maxima_;
}

cAvion::~cAvion() {
}

void cAvion::despegar() {
    
    if (volando)
        throw new exception("El avion ya se encuentra en el aire");
    volando = true;
}

void cAvion::aterrizar() {
    
    if (!volando)
        throw new exception("El avion ya se encuentra en tierra");
    volando = false;
}

bool cAvion::pedirPermisoAterrizaje(cAeropuerto* aeropuerto) {
    bool permiso;
    permiso = aeropuerto->darPermisoAterrizaje();
    return permiso;
}

bool cAvion::pedirPermisoDespegue(cAeropuerto* aeropuerto) {
  
    return aeropuerto->darPermisoDespegue(); 
}

void cAvion::chequearCapacidadMaxima(cVuelo* vuelo)
{
    if (capacidad_maxima < vuelo->getCantidadPasajeros())
        throw new exception("La cantidad de pasajeros supera la capacidad máxima del avión.");
}

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

string cAvion::tostring() {

    string text = "";
    text += "\nID Avion: " + this->id + " Capacidad Max: " + std::to_string(this->capacidad_maxima);
    if (this->volando)
        text += " El avion se encuentra volando";
    else
        text += " El avion se encuentra en tierra";
    return text;
}

void cAvion::imprimir() {
    
    cout << this->tostring() << endl;

}

ostream& operator<<(ostream& out, cAvion& avion)
{
    return out << avion.tostring() << endl;
}