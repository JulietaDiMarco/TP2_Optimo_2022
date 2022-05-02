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

    cFecha* fnacimiento = new cFecha();

    cPasajero* pasajero = new cPasajero("4545545", "Bruno", "Cruz Franchi", "12A", fnacimiento);
    (*pasajero) + equipaje1;
    (*pasajero) + equipaje3;
    (*pasajero) + equipaje2;


    srand(time(NULL));
    ///Inicializo Fechas
  
    ///Inicializo pasajeros
    cPasajero** pasajeros = InicializarPasajeros();
    ///Inicializo equipajes
    cEquipaje** equipajes = InicializarEquipajes();
    ///Inicializo aviones
    cAvion** aviones = InicializarAviones();
    ///Inicializo vuelos

    

    BorrarPasajeros(pasajeros);
    BorrarAviones(aviones);
    BorrarEquipajes(equipajes);

}

cPasajero** InicializarPasajeros() {
    cFecha Nov8 = cFecha(8, 11, 1980);
    cFecha Dec13 = cFecha(13, 12, 1989);
    cFecha June5 = cFecha(5, 6, 1998);
    cPasajero** pasajeros = new cPasajero * [3];
    pasajeros[0] = new cPasajero("41258963", "Federico", "Serra", "5F", &Nov8);
    pasajeros[1] = new cPasajero("4455963", "Carolina", "Serra", "7F", &Dec13);
    pasajeros[0] = new cPasajero("61258963", "Tomas", "Serra", "5F", &June5);
    return pasajeros;
}

void BorrarPasajeros(cPasajero** pasajeros) {
    
    for (int i = 0; i < 3; i++)
    {
        delete pasajeros[i];
    }

    delete[] pasajeros;
}

cAvion** InicializarAviones() {

} //TODO

void BorrarAviones(cAvion** aviones) {

    for (int i = 0; i < 3; i++)
    {
        delete aviones[i];
    }

    delete[] aviones;
}

cEquipaje** InicializarEquipajes() { //me genero equipajes con pesos random para probar distintas formas en distintas corridas
    cEquipaje** equipajes = new cEquipaje * [5];
    for (int i = 0; i < 10; i++)
    {
        equipajes[i] = new cEquipaje(rand()%27);
    }
    return equipajes;
}

void BorrarEquipajes(cEquipaje** equipajes) {

    for (int i = 0; i < 10; i++)
    {
        delete equipajes[i];
    }

    delete[] equipajes;
}

cVuelo** InicializoVuelos(cVuelo** vuelos, cAvion** aviones) {
    cFecha Nov8 = cFecha(8, 11, 2021,12,54);
    cFecha Dec13p = cFecha(13, 12, 2021,4,6);
    cFecha Dec13a = cFecha(13, 12, 2021, 7, 6);
    cFecha June5p = cFecha(5, 6, 2021,18,42);
    cFecha June5a = cFecha(5, 6, 2021, 20, 42);
    cVuelo** vuelos = new cVuelo * [4];
    vuelos[0] = new cVuelo(true, eDestino::IGUAZU, eTramo::Arribo, aviones[2], &Dec13p, &Dec13a);
    vuelos[0] = new cVuelo(true, eDestino::BARILOCHE, eTramo::Arribo, aviones[0], &June5p, &June5a);

}
    