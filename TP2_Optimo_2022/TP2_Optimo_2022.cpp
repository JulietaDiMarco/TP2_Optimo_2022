// TP2_Optimo_2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "cAeropuerto.h"
#include "cPasajero.h"
#define N_FECHAS 8
#define N_VUELO 4

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
cFecha** InicializarFechas();
void ProbarDespegarVuelos(cAeropuerto* aeropuerto,cVuelo** vuelos,cFecha** fechas);
void ProbarAterrizarVuelos(cAeropuerto* aeropuerto, cVuelo** vuelos, cFecha** fechas);
void BorrarFechas(cFecha** fechas);

int main()
{
    srand(time(NULL));
    ///Inicializo Fechas
    cFecha** fechas = InicializarFechas();
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
    
    ProbarDespegarVuelos(aeropuerto, vuelos, fechas);
    ProbarAterrizarVuelos(aeropuerto, vuelos, fechas);
    
    cFecha* fecharand = fechas[rand() % N_FECHAS];
    cout << "Cantidad de pasajeros que volaron el  "<< fecharand->To_string() <<": "
        << aeropuerto->CantPasajerosVolaron(fecharand)<< endl;
    cout << "Cantidad de vuelos aterrizados el  " << fecharand->To_string() << ": "
        << aeropuerto->CantVuelosAterrizados(fecharand)<< endl;
    cout << "Cantidad de vuelos despegados el  " << fecharand->To_string() << ": "
        << aeropuerto->CantVuelosDespegaron(fecharand) << endl;
    cout << "Porcentaje despegues en horario: "<< aeropuerto->PorcentajeArribosEnHorario()<< endl;
    cout<< "Porcentaje despegues en horario: "<< aeropuerto->PorcentajeDespeguesEnHorario()<< endl;
    ///Libero memoria
    BorrarFechas(fechas);
    BorrarPasajeros(pasajeros);
    BorrarAviones(aviones);
    BorrarEquipajes(equipajes);
    BorrarVuelos(vuelos);

}

cFecha** InicializarFechas() {
    cFecha** fechas = new cFecha * [N_FECHAS];
    for (int i = 0; i < N_FECHAS; i++)
    {
        fechas[i] = new cFecha(rand() % 28 + 1, rand() % 11 + 1, 2021, rand() % 24, rand() % 59);
    }
    return fechas;
}

void BorrarFechas(cFecha** fechas) {
    for (int i = 0; i < N_FECHAS; i++)
    {
        delete fechas[i];
    }

    delete[] fechas;
}

void ProbarDespegarVuelos(cAeropuerto* aeropuerto, cVuelo** vuelos, cFecha** fechas) {
    for (int i = 0; i < 5; i++)
    {
        int k = rand() % N_VUELO;
        try {
            vuelos[k]->RealizarDespegue(aeropuerto, vuelos[k]->getPartida());
        }
        catch (exception* e) {
            cout << string(e->what()) << endl;
            delete e;
        }
    }
}

void ProbarAterrizarVuelos(cAeropuerto* aeropuerto, cVuelo** vuelos, cFecha** fechas) {
    for (int i = 0; i < 5; i++)
    {
        try {
            vuelos[rand() % N_VUELO]->RealizarAterrizaje(aeropuerto, fechas[rand() % N_FECHAS]);
        }
        catch (exception* e) {
            cout << string(e->what()) << endl;
            delete e;
        }
    }
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
    cFecha July13p = cFecha(5, 6, 2021, 13, 42);
    cVuelo** vuelos = new cVuelo * [N_VUELO];
    vuelos[0] = new cVuelo(true, eDestino::IGUAZU, eTramo::Arribo, aviones[2], &Dec13p, &Dec13a);
    vuelos[1] = new cVuelo(true, eDestino::BARILOCHE, eTramo::Arribo, aviones[0], &June5p, &June5a);
    vuelos[2] = new cVuelo(false, eDestino::SALTA, eTramo::Partida, aviones[1], &Nov8p, &Nov8a);
    vuelos[3] = new cVuelo(false, eDestino::JUJUY, eTramo::Partida, aviones[0], &July13p, &July13a);
    return vuelos;
}

void BorrarVuelos(cVuelo** vuelos) {

    for (int i = 0; i < N_VUELO; i++)
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
    