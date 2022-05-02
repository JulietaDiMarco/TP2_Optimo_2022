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

	#pragma region Constructores y destructores

		cListaPasajero(unsigned int longitud = N_MAX, bool eliminar = false);
		~cListaPasajero();

	#pragma endregion

	#pragma region Agregar y modificar

		bool agregar(cPasajero* nuevoPasajero);
		bool modificar(int posicion, cPasajero* nuevoPasajero);

	#pragma endregion

	#pragma region Eliminar y quitar

		bool eliminar(string DNI);
		bool eliminar(int pos);
		bool eliminar(cPasajero* pasajero);

		cPasajero* quitar(string DNI);
		cPasajero* quitar(cPasajero* pasajero);
		cPasajero* quitar(int pos);

	#pragma endregion

	#pragma region Metodos

		int buscar(string DNI);
		cPasajero* buscar(int pos); //hacer esta funci[on de buscar por posicion
		int buscar(cPasajero* ptr_Pasajero);

		void imprimir();

		unsigned int getCantidadActual();

		/// <summary>
		/// Retorna el peso total de todos los equipajes dentro 
		/// de la lista
		/// </summary>
		/// <returns></returns>
		float getpesoTotalEquipajes();

	#pragma endregion
	
};

