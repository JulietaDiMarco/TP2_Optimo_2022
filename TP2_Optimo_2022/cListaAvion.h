#pragma once
#include "cAvion.h"

#define L_MAX 25

class cListaAvion
{
private:
	bool eliminarNodos;
	cAvion** Aviones;
	unsigned int CantidadActual;
	unsigned int CantidadMaxima;

public:

	#pragma region Constructores y destructores

		cListaAvion(unsigned int longitud = L_MAX, bool eliminar = false);
		~cListaAvion();

	#pragma endregion

	#pragma region Agregar y modificar

		bool agregar(cAvion* nuevoAvion);
		bool modificar(string idAvion, cAvion* nuevoAvion);

	#pragma endregion

	#pragma region Eliminar y quitar

		bool eliminar(string idAvion);
		bool eliminar(int posicion);
		bool eliminar(cAvion* avion);

		cAvion* quitar(string idAvion);
		cAvion* quitar(cAvion* avion);

	#pragma endregion

	#pragma region Metodos

		int buscar(string idAvion);
		cAvion* buscar(int pos);
		int buscar(cAvion* ptr_Avion);

		void imprimir();

		unsigned int getCantidadActual() { return CantidadActual; };

	#pragma endregion

};

