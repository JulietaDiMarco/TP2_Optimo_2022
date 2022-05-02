// TP2_Optimo_2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "cAeropuerto.h"

int main()
{
    cAvion* avion = new cAvion(10, 4, false, false, 1000, 12, false);
    cFecha* fecha1 = new cFecha();
    cFecha* fecha2 = new cFecha(2,5,2022);
    cVuelo* vuelo = new cVuelo(false, eDestino::BARILOCHE, eTramo::Arribo, avion, fecha1, fecha2);
    cout << (*vuelo);

    cEquipaje* equipaje1 = new cEquipaje(10.0);
    cEquipaje* equipaje2 = new cEquipaje(10.0);
    cEquipaje* equipaje3 = new cEquipaje(10.0);

    cPasajero* pasajero = new cPasajero("4545545", "Bruno", "Cruz Franchi", 12, 12, 2);
    (*pasajero) + equipaje1;
    (*pasajero) + equipaje3;
    (*pasajero) + equipaje2;


}

