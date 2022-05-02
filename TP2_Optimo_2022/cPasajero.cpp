#include "cPasajero.h"
#define MAX_EQUIPAJE 2
/**
 * cPasajero implementation
 */

cPasajero::cPasajero(string DNI_, string nombre_, string apellido_, string asiento_, cFecha* fn) {
    this->DNI = DNI_;
    this->nombre = nombre_;
    this->apellido = apellido_;
    this->asiento = asiento_;
    this->fecha_nacimiento = new cFecha(*fn);
    valijas = new cListaEquipaje(MAX_EQUIPAJE, false); //le asigno por defecto una valija sola
}

cPasajero::~cPasajero() {
    //hacer el for de delete blbablabla
    delete valijas;
    
}

string cPasajero::getDNI() {
    return this->DNI;
}


string cPasajero::getNombre() {
    return this->nombre;
}

string cPasajero::getApellido() {
    return this->apellido;
}

float cPasajero::getPesoTotal()
{
    return valijas->getpesototal();
}


/**
 chequear
 */
bool cPasajero::agregarEquipaje(cEquipaje* valija) {
    if (valijas->getpesototal() <= 25){
        valijas->agregar(valija);
        return true;
    }
    else
        throw new exception("Este pasaje ha alcanzado excedido el peso/la cantidad maxima");
}

/**
 * @return string
 */
string cPasajero::tostring() {
    return "";
}

/**
 * @return void
 */
void cPasajero::imprimir() {
    string concatenado;
    concatenado = tostring();
    cout << concatenado << endl;
}

void cPasajero::operator+(cEquipaje* equipaje)
{
    agregarEquipaje(equipaje);
 }

void cPasajero::operator-(cEquipaje* equipaje)
{
    if (!(valijas->eliminar(equipaje)))
        throw new exception("No se logro eliminar el equipaje al pasajero");
}

bool cPasajero::eliminarEquipaje(string id) {
    if (valijas->eliminar(id))
        return true;
    else 
        throw new exception("Este pasaje no se ha logrado eliminar");
}


