#include "cPasajero.h"
#define MAX_EQUIPAJE 2
/**
 * cPasajero implementation
 */

cPasajero::cPasajero(string DNI_, string nombre_, string apellido_, unsigned int asiento_, unsigned int cantTotal, unsigned int cantActual) {
    this->DNI = DNI_;
    this->nombre = nombre_;
    this->apellido = apellido_;
    this->asiento = asiento_;
    cListaEquipaje* valijas = new cListaEquipaje(MAX_EQUIPAJE, false); //le asigno por defecto una valija sola
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

/**
 * @return bool
 */
bool cPasajero::eliminarEquipaje(string id) {//TODO
    //llamo a cListaEquipaje::eliminar(string id)
    return false;
}


