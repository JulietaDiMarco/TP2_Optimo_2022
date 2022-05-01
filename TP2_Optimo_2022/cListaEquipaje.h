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
	cListaEquipaje(unsigned int longitud = MAX_E, bool eliminar = false);
	~cListaEquipaje();

	bool agregar(cEquipaje* nuevoEquipaje);
	bool modificar(string idEquipaje, cEquipaje* nuevoEquipaje);
	bool modificar(int pos, cEquipaje* nuevoEquipaje);
	bool eliminar(string idEquipaje);
	bool eliminar(int pos);
	bool eliminar(cEquipaje* valija);
	cEquipaje* quitar(string idEquipaje);
	cEquipaje* quitar(cEquipaje* valija);
	int buscar(string idEquipaje);
	int buscar(cEquipaje* ptr_Equipaje);
	cEquipaje** filtrar(float peso);
	float getpesototal();
	void imprimir();
};

