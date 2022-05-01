#pragma once
#include "cVuelo.h"
#define MAX_V 10

class cListaVuelo
{
private:
	bool eliminarNodos;
	cVuelo** Vuelos;
	unsigned int CantidadActual;
	unsigned int CantidadMaxima;

public:
	cListaVuelo(unsigned int longitud = MAX_V, bool eliminar = false);
	~cListaVuelo();

	bool agregar(cVuelo* nuevoVuelo);
	bool modificar(string id, cVuelo* nuevoVuelo);
	bool modificar(int posicion, cVuelo* nuevoVuelo);
	bool eliminar(string id);
	bool eliminar(int posicion);
	bool eliminar(cVuelo* auxVuelo);
	cVuelo* quitar(string id);
	cVuelo* quitar(cVuelo* auxVuelo);
	cVuelo* quitar(int pos);
	int buscar(string id);
	cVuelo* buscar(int pos);
	int buscar(cVuelo* ptr_Vuelo);
	cVuelo** filtrar(float peso);

	void imprimir();

	unsigned int getCantidadMaxima() { return CantidadMaxima; };
	unsigned int getCantidadActual() { return CantidadActual; };

	cVuelo* operator[](unsigned int pos);

};

