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
	cListaAvion(unsigned int longitud = L_MAX, bool eliminar = false);
	~cListaAvion();

	bool agregar(cAvion* nuevoAvion);
	bool modificar(string idAvion, cAvion* nuevoAvion);
	bool eliminar(string idAvion);
	bool eliminar(int posicion);
	bool eliminar(cAvion* avion);
	cAvion* quitar(string idAvion);
	cAvion* quitar(cAvion* avion);
	int buscar(string idAvion);
	cAvion* buscar(int pos);
	int buscar(cAvion* ptr_Avion);
	void imprimir();
	unsigned int getCantidadActual();

};

