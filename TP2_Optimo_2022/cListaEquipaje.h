#pragma once
#include "cEquipaje.h"
#define MAX_E 3

class cListaEquipaje
{
	private:

		bool eliminarNodos;
		cEquipaje** Equipajes;
		unsigned int CantidadActual;
		unsigned int CantidadMaxima;

	public:

		#pragma region Constructores y destructores

			cListaEquipaje(unsigned int longitud = MAX_E, bool eliminar = false);
			~cListaEquipaje();

		#pragma endregion

		#pragma region Agregar y modificar

			bool agregar(cEquipaje* nuevoEquipaje);
			bool modificar(string idEquipaje, cEquipaje* nuevoEquipaje);
			bool modificar(int pos, cEquipaje* nuevoEquipaje);

		#pragma endregion

		#pragma region Eliminar y quitar

			bool eliminar(string idEquipaje);
			bool eliminar(int pos);
			bool eliminar(cEquipaje* valija);

			cEquipaje* quitar(string idEquipaje);
			cEquipaje* quitar(cEquipaje* valija);

		#pragma endregion

		#pragma region Metodos
		
			/// <summary>
			/// Retorna el peso total de los equipajes dentro de la lista
			/// </summary>
			/// <returns></returns>
			float getpesototal();

			int buscar(string idEquipaje);
			int buscar(cEquipaje* ptr_Equipaje);

			void imprimir();

		#pragma endregion
};

