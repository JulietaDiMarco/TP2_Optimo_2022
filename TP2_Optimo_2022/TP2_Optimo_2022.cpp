// TP2_Optimo_2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "cAeropuerto.h"
#include "cPasajero.h"

using namespace std;
//Declaro funciones

cPasajero** InicializarPasajeros();
void BorrarPasajeros(cPasajero** pasajeros);
cAvion** InicializarAviones();
void BorrarAviones(cAvion** aviones);
cEquipaje** InicializarEquipajes();
void BorrarEquipajes(cEquipaje** equipajes);
cVuelo** InicializarVuelos(cAvion** aviones);
void BorrarVuelos(cVuelo** vuelos);
void AgregarValijas(cPasajero** pasajeros, cEquipaje** equipajes);

int main()
{
    srand(time(NULL));
    ///Inicializo Fechas
  
    ///Inicializo pasajeros
    cPasajero** pasajeros = InicializarPasajeros();
    ///Inicializo equipajes
    cEquipaje** equipajes = InicializarEquipajes();
    ///Inicializo aviones
    cAvion** aviones = InicializarAviones();
    ///Inicializo vuelos
    cVuelo** vuelos = InicializarVuelos(aviones);
    ///Inicializo Aeroparque

    cAeropuerto* aeropuerto = new cAeropuerto("AEP", 2);

    //Agrego los vuelos a aeropuerto
    for (int i = 0; i <3; i++)
    {
        aeropuerto->AgregarAvion(aviones[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        aeropuerto->AgregarVuelo(vuelos[i]);
    }
    
    //Agrego valijas a mis pasajeros

    AgregarValijas(pasajeros, equipajes);
    
    //Agrego pasajeros a mi vuelo
    for (int i = 0; i < 3; i++)
    {
        vuelos[0]->AgregarPasajero(pasajeros[i]);
        vuelos[2]->AgregarPasajero(pasajeros[i]);
    }
    
    cFecha Nov8a = cFecha(8, 11, 2021, 13, 31); //aterriza atrasado
    cFecha Nov8p = cFecha(8, 11, 2021, 9, 31);  //despega atrasado
    cFecha Dec13p = cFecha(13, 12, 2021, 4, 6);
    cFecha Dec13a = cFecha(13, 12, 2021, 7, 6);
    cFecha June5p = cFecha(5, 6, 2021, 18, 40); //aterriza adelantado dos minutos
    cFecha June5a = cFecha(5, 6, 2021, 20, 42);
    cFecha July13a = cFecha(13, 7, 2021, 17, 50); //aterriza atrasado por pocos minutos
    cFecha July13p = cFecha(13, 7, 2021, 13, 42);

    vuelos[0]->RealizarDespegue(aeropuerto, &Nov8p);
    vuelos[0]->RealizarAterrizaje(aeropuerto, &Nov8p);
    vuelos[1]->RealizarDespegue(aeropuerto, &Dec13p);
    vuelos[1]->RealizarAterrizaje(aeropuerto, &Dec13a);
    vuelos[2]->RealizarDespegue(aeropuerto, &June5p);
    vuelos[2]->RealizarAterrizaje(aeropuerto, &June5a);
    vuelos[3]->RealizarDespegue(aeropuerto, &July13p);
    vuelos[4]->RealizarAterrizaje(aeropuerto, &July13a);

    aeropuerto->CantPasajerosVolaron(&Nov8a);
    aeropuerto->CantPasajerosVolaron(&Dec13a);
    aeropuerto->CantPasajerosVolaron(&June5a);
    aeropuerto->CantPasajerosVolaron(&July13a);

    aeropuerto->CantVuelosAterrizados(&Nov8a);
    aeropuerto->CantVuelosAterrizados(&Dec13a);
    aeropuerto->CantVuelosAterrizados(&June5a);
    aeropuerto->CantVuelosAterrizados(&July13a);

    aeropuerto->CantVuelosDespegaron(&Nov8a);
    aeropuerto->CantVuelosDespegaron(&Dec13a);
    aeropuerto->CantVuelosDespegaron(&June5a);
    aeropuerto->CantVuelosDespegaron(&July13a);

    //fechas de prueba fuera de los vuelos que ya tengo
    cFecha fecha1 = cFecha(9, 12, 2021);
    cFecha fecha2 = cFecha(14, 3, 2021);
                
    aeropuerto->CantVuelosAterrizados(&fecha1);   //creo fecha de prueba para ver que no me devuelva nada en un dia que no hubo vuelos
    aeropuerto->CantVuelosDespegaron(&fecha2);   //hago lo mismo ocn los despegues

    aeropuerto->PorcentajeArribosEnHorario();
    aeropuerto->PorcentajeDespeguesEnHorario();

    ///Libero memoria
    BorrarPasajeros(pasajeros);
    BorrarAviones(aviones);
    BorrarEquipajes(equipajes);
    BorrarVuelos(vuelos);

    return 0;

}

cPasajero** InicializarPasajeros() {
    cFecha Nov8 = cFecha(8, 11, 1980);
    cFecha Dec13 = cFecha(13, 12, 1989);
    cFecha June5 = cFecha(5, 6, 1998);
    cPasajero** pasajeros = new cPasajero * [3];
    pasajeros[0] = new cPasajero("41258963", "Federico", "Serra", "5F", &Nov8);
    pasajeros[1] = new cPasajero("4455963", "Carolina", "Serra", "7F", &Dec13);
    pasajeros[2] = new cPasajero("61258963", "Tomas", "Serra", "5F", &June5);
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
    cAvion** aviones = new cAvion * [3];
    aviones[0] = new cAvion(2500, 120, false);
    aviones[1] = new cAvion(2250, 135, true);
    aviones[2] = new cAvion(2123, 110, false);
    return aviones;
} 

void BorrarAviones(cAvion** aviones) {

    for (int i = 0; i < 3; i++)
    {
        delete aviones[i];
    }

    delete[] aviones;
}

cEquipaje** InicializarEquipajes() { //me genero equipajes con pesos random para probar distintas formas en distintas corridas
    cEquipaje** equipajes = new cEquipaje * [10];
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

cVuelo** InicializarVuelos(cAvion** aviones) {
    cFecha Nov8a = cFecha(8, 11, 2021,12,54);
    cFecha Nov8p = cFecha(8, 11, 2021, 8, 54);
    cFecha Dec13p = cFecha(13, 12, 2021,4,6);
    cFecha Dec13a = cFecha(13, 12, 2021, 7, 6);
    cFecha June5p = cFecha(5, 6, 2021,18,42);
    cFecha June5a = cFecha(5, 6, 2021, 20, 42);
    cFecha July13a = cFecha(13, 7, 2021, 17, 42);
    cFecha July13p = cFecha(13, 7, 2021, 13, 42);
    cVuelo** vuelos = new cVuelo * [4];
    vuelos[0] = new cVuelo(true, eDestino::IGUAZU, eTramo::Arribo, aviones[2], &Dec13p, &Dec13a);
    vuelos[1] = new cVuelo(true, eDestino::BARILOCHE, eTramo::Arribo, aviones[0], &June5p, &June5a);
    vuelos[2] = new cVuelo(false, eDestino::SALTA, eTramo::Partida, aviones[1], &Nov8p, &Nov8a);
    vuelos[3] = new cVuelo(false, eDestino::JUJUY, eTramo::Partida, aviones[0], &July13p, &July13a);
    return vuelos;
}

void BorrarVuelos(cVuelo** vuelos) {

    for (int i = 0; i < 4; i++)
    {
        delete vuelos[i];
    }

    delete[] vuelos;
}

void AgregarValijas(cPasajero** pasajeros, cEquipaje** equipajes) {
    for (int i = 0; i < 5; i++)
    {
        try {
            *(pasajeros[rand() % 3]) + equipajes[rand() % 10];
        }
        catch (exception* e) {
            cout << string(e->what()) << endl;
        }
    }
}
    