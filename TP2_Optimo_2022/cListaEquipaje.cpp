#include "cListaEquipaje.h"

cListaEquipaje::cListaEquipaje(unsigned int longitud, bool eliminar) { //la longitud es max
	this->eliminarNodos = eliminar;
	this->CantidadActual = 0;
	this->CantidadMaxima = longitud;
	this->Equipajes = new cEquipaje * [longitud];
	for (unsigned int i = 0; i < CantidadMaxima; i++)
		this->Equipajes[i] = NULL;
}

cListaEquipaje::~cListaEquipaje() {
	if (eliminarNodos) {
		for (unsigned int i = 0; i < CantidadActual; i++)
			if (this->Equipajes[i] != NULL)
				delete this->Equipajes[i];
	}
	delete[] this->Equipajes;
	CantidadActual = 0;
}

bool cListaEquipaje::agregar(cEquipaje* nuevoEquipaje) {
	int i;
	for (i = 0; i < this->CantidadMaxima; i++) {
		if (this->Equipajes[i] == NULL) {
			this->Equipajes[i] = nuevoEquipaje;
			CantidadActual++;
			return true;
		}
	} return false;
}

#pragma region Metodos_Modificar
bool cListaEquipaje::modificar(int pos, cEquipaje* nuevoEquipaje) {
	if (pos >= 0 && this->Equipajes[pos] != NULL) {
		cEquipaje* aux = this->Equipajes[pos];
		this->Equipajes[pos] = nuevoEquipaje;
		delete aux;
		return true;
	} return false;
}

bool cListaEquipaje::modificar(string idEquipaje, cEquipaje* nuevoEquipaje) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->Equipajes[i] != NULL && this->Equipajes[i]->getIDequipaje() == nuevoEquipaje->getIDequipaje()) {
			cEquipaje* aux = this->Equipajes[i];
			this->Equipajes[i] = nuevoEquipaje;
			delete aux;
			return true;
		}
	} return false;
}

#pragma endregion

#pragma region Metodos_Eliminar
bool cListaEquipaje::eliminar(int pos) {
	if (pos >= 0 && this->Equipajes[pos] != NULL) {
		delete this->Equipajes[pos];
		this->Equipajes[pos] = NULL;
		return true;
	} return false;
}

bool cListaEquipaje::eliminar(string idEquipaje) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->Equipajes[i] != NULL && this->Equipajes[i]->getIDequipaje() == idEquipaje) {
			delete this->Equipajes[i];
			this->Equipajes[i] = NULL;
			return true;
		}
	} return false;
}

bool cListaEquipaje::eliminar(cEquipaje* valija) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->Equipajes[i] != NULL && this->Equipajes[i] == valija) {
			delete this->Equipajes[i];
			this->Equipajes[i] = NULL;
			return true;
		}
	} return false;
}
#pragma endregion

#pragma region Metodos_Quitar
cEquipaje* cListaEquipaje::quitar(string idEquipaje) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->Equipajes[i] != NULL && this->Equipajes[i]->getIDequipaje() == idEquipaje) {
			cEquipaje* aux = this->Equipajes[i];
			this->Equipajes[i] = NULL;
			return aux;
		}
	} return NULL;
}

cEquipaje* cListaEquipaje::quitar(cEquipaje* valija) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->Equipajes[i] != NULL && this->Equipajes[i] == valija) {
			cEquipaje* aux = this->Equipajes[i];
			this->Equipajes[i] = NULL;
			return aux;
		}
	} return NULL;
}
#pragma endregion

#pragma region Metodos_Buscar
int cListaEquipaje::buscar(string idEquipaje) {
	for (int i = 0; i < CantidadActual; i++)
		if (this->Equipajes[i] != NULL && this->Equipajes[i]->getIDequipaje() == idEquipaje)
			return i;
	return -1;
}

int cListaEquipaje::buscar(cEquipaje* ptr_Equipaje) {
	for (int i = 0; i < CantidadActual; i++)
		if (this->Equipajes[i] != NULL && this->Equipajes[i] == ptr_Equipaje)
			return i;
	return -1;
}
#pragma endregion

#pragma region Metodos_Filtrar
cEquipaje** cListaEquipaje::filtrar(float peso) {
	cEquipaje** aux = NULL;
	aux = new cEquipaje * [CantidadActual];

	if (aux != NULL) {
		for (int i = 0; i < CantidadActual; i++)
			if (this->Equipajes[i] != NULL && this->Equipajes[i]->getPeso() == peso)
				aux[i] = this->Equipajes[i];
	}
	return aux;
}
float cListaEquipaje::getpesototal()
{
	float pesototal = 0;
		
	for (int i = 0; i < CantidadActual; i++)
	{
		pesototal += Equipajes[i]->getPeso();
	}

	return pesototal;
	
}
#pragma endregion

void cListaEquipaje::imprimir() {
	cout << "Mi Listado: " << endl;
	for (unsigned int i = 0; i < CantidadActual; i++)
		if (this->Equipajes[i] != NULL) {
			cout << this->Equipajes[i]->getIDequipaje() << " " <<
				this->Equipajes[i]->getPeso() << " " << endl;
		}
	cout << endl;
}