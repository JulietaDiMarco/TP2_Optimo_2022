
#include "cEquipaje.h"

// Este parametro nos va a ayudar a determinar la cantidad de equipaje
// al igual que asignar el ID de equipajes
unsigned int cEquipaje::contador_equipajes = 0;

cEquipaje::cEquipaje(float peso_):idEquipaje(to_string(contador_equipajes)) {
    contador_equipajes++;
    this->peso = peso_;
}

cEquipaje::~cEquipaje() {
    contador_equipajes--;
}

string cEquipaje::tostring() { 
    string text = "";
    text += "\nEquipaje ID:" + idEquipaje;
    text += "\nPeso:" + std::to_string(peso);
    return text;
}

void cEquipaje::imprimir() {
    cout << tostring() << endl;
}

float cEquipaje::getPeso() {
    return peso;
}

string cEquipaje::getIDequipaje() {
    return idEquipaje;
}
