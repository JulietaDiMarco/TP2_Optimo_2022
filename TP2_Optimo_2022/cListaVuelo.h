#pragma once
#include "cVuelo.h"
#define MAX_V 10

class cListaVuelo
{
	friend class cVuelo;

	private:
		bool eliminarNodos;
		cVuelo** Vuelos;
		unsigned int CantidadActual;
		unsigned int CantidadMaxima;

	public:

		#pragma region Constructores y destructores
	
			cListaVuelo(unsigned int longitud = MAX_V, bool eliminar = false);
			~cListaVuelo();

		#pragma endregion

		#pragma region Agregar y modificar

			bool agregar(cVuelo* nuevoVuelo);
			bool modificar(string id, cVuelo* nuevoVuelo);
			bool modificar(int posicion, cVuelo* nuevoVuelo);

		#pragma endregion

		#pragma region Eliminar y quitar

			bool eliminar(string id);
			bool eliminar(int posicion);
			bool eliminar(cVuelo* auxVuelo);

			cVuelo* quitar(string id);
			cVuelo* quitar(cVuelo* auxVuelo);
			cVuelo* quitar(int pos);

		#pragma endregion

		#pragma region Metodos

			int buscar(string id);
			cVuelo* buscar(int pos);
			int buscar(cVuelo* ptr_Vuelo);

			void imprimir();

			unsigned int getCantidadMaxima() { return CantidadMaxima; };
			unsigned int getCantidadActual() { return CantidadActual; };

		#pragma endregion
	
		#pragma region Operadores
		
			cVuelo* operator[](int pos);

		#pragma endregion
};

