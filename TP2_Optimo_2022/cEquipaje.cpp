/**
 * Project Untitled
 */


#include "cEquipaje.h"

/**
 * cEquipaje implementation
 */

unsigned int cEquipaje::contador_equipajes = 0;

cEquipaje::cEquipaje(float peso_):idEquipaje(to_string(contador_equipajes)) {
    contador_equipajes++;
    this->peso = peso_;
}

cEquipaje::~cEquipaje() {

}

/**
 * @return string
 */
string cEquipaje::tostring() { //TODO
    return "";
}

/**
 * @return void
 */
void cEquipaje::imprimir() {//TODO
    return;
}

/**
 * @return float
 */
float cEquipaje::getPeso() {
    return peso;
}

/**
 * @return string
 */
string cEquipaje::getIDequipaje() {
    return idEquipaje;
}

/**
 * @return cPasajero
 */
/*
cPasajero* cEquipaje::getDueno() {
    return NULL;
}
*/

