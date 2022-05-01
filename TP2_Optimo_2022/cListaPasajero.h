#pragma once
#include "cPasajero.h"
#define N_MAX 25

class cListaPasajero
{
	friend class cVuelo;
	private:
		bool eliminarNodos;
		cPasajero** pasajeros;
		unsigned int CantidadActual;
		unsigned int CantidadMaxima;

	public:
		cListaPasajero(unsigned int longitud = N_MAX, bool eliminar = false);
		~cListaPasajero();

		bool agregar(cPasajero* nuevoPasajero);
		bool modificar(int posicion, cPasajero* nuevoPasajero);
		bool eliminar(string DNI);
		bool eliminar(int pos);
		bool eliminar(cPasajero* pasajerito);
		cPasajero* quitar(string DNI);
		cPasajero* quitar(cPasajero* pasajerito);
		cPasajero* quitar(int pos);
		int buscar(string DNI);
		cPasajero* buscar(int pos); //hacer esta funci[on de buscar por posicion
		int buscar(cPasajero* ptr_Pasajero);
		//cPasajero** filtrar(float peso);
		void imprimir();
		unsigned int getCantidadActual();
		float getpesoTotalEquipajes();
};

