#include "cListaPasajero.h"


cListaPasajero::cListaPasajero(unsigned int longitud, bool eliminar) {
	this->eliminarNodos = eliminar;
	this->CantidadActual = 0;
	this->CantidadMaxima = longitud;
	this->pasajeros = new cPasajero * [longitud];
	for (unsigned int i = 0; i < CantidadMaxima; i++)
		this->pasajeros[i] = NULL;
}

cListaPasajero::~cListaPasajero() {
	if (eliminarNodos) {
		for (unsigned int i = 0; i < CantidadActual; i++)
			if (this->pasajeros[i] != NULL)
				delete this->pasajeros[i];
	}
	delete[] this->pasajeros;
	CantidadActual = 0;
}

bool cListaPasajero::agregar(cPasajero* nuevoPasajero) { //TODO: chequear que entren en la lista 
	for (unsigned int i = 0; i < CantidadMaxima; i++) {
		if (this->pasajeros[i] == NULL) {
			this->pasajeros[i] = nuevoPasajero;
			CantidadActual++;
			return true;
		}
	} return false;
}

#pragma region Metodos_Modificar
bool cListaPasajero::modificar(int pos, cPasajero* nuevoPasajero) {
	if (pos >= 0 && this->pasajeros[pos] != NULL) {
		cPasajero* Aux = this->pasajeros[pos];
		this->pasajeros[pos] = nuevoPasajero;
		delete Aux;
		return true;
	} return false;
}

#pragma endregion

#pragma region Metodos_Eliminar
bool cListaPasajero::eliminar(int pos) {
	if (pos >= 0 && this->pasajeros[pos] != NULL) {
		delete this->pasajeros[pos];
		this->pasajeros[pos] = NULL;
		return true;
	} return false;
}

bool cListaPasajero::eliminar(string DNI) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->pasajeros[i] != NULL && this->pasajeros[i]->getDNI() == DNI) {
			delete this->pasajeros[i];
			this->pasajeros[i] = NULL;
			return true;
		}
	} return false;
}

bool cListaPasajero::eliminar(cPasajero* pasajerito) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->pasajeros[i] != NULL && this->pasajeros[i] == pasajerito) {
			delete this->pasajeros[i];
			this->pasajeros[i] = NULL;
			return true;
		}
	} return false;
}
#pragma endregion

#pragma region Metodos_Quitar
cPasajero* cListaPasajero::quitar(int pos) {
	if (pos >= 0 && this->pasajeros[pos] != NULL) {
		cPasajero* Aux = this->pasajeros[pos];
		this->pasajeros[pos] = NULL;
		return Aux;
	} return NULL;
}

cPasajero* cListaPasajero::quitar(string DNI) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->pasajeros[i] != NULL && this->pasajeros[i]->getDNI() == DNI) {
			cPasajero* Aux = this->pasajeros[i];
			this->pasajeros[i] = NULL;
			return Aux;
		}
	} return NULL;
}

cPasajero* cListaPasajero::quitar(cPasajero* pasajerito) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->pasajeros[i] != NULL && this->pasajeros[i] == pasajerito) {
			cPasajero* Aux = this->pasajeros[i];
			this->pasajeros[i] = NULL;
			return Aux;
		}
	} return NULL;
}
#pragma endregion

#pragma region Metodos_Buscar
int cListaPasajero::buscar(string DNI) {
	
	for (int i = 0; i < CantidadActual; i++)
		if (this->pasajeros[i] != NULL && this->pasajeros[i]->getDNI() == DNI)
			return i;
	return -1;
}

cPasajero* cListaPasajero::buscar(int pos)
{
	return nullptr;
}

int cListaPasajero::buscar(cPasajero* ptr_Pasajero) {
	for (int i = 0; i < CantidadActual; i++)
		if (this->pasajeros[i] != NULL && this->pasajeros[i] == ptr_Pasajero)
			return i;
	return -1;
}
#pragma endregion


void cListaPasajero::imprimir() {
	cout << "Mi Listado: " << endl;
	for (unsigned int i = 0; i < CantidadActual; i++)
		if (this->pasajeros[i] != NULL) {
			cout << this->pasajeros[i]->getNombre() << " " <<
				this->pasajeros[i]->getApellido() << " " <<
				this->pasajeros[i]->getDNI() << " " << endl;
			}
	cout << endl;
}

unsigned int cListaPasajero::getCantidadActual()
{
	return CantidadActual;
}

float cListaPasajero::getpesoTotalEquipajes() {
	float pesototal = 0;
	for (int i = 0; i < CantidadActual; i++)
	{
		pesototal += pasajeros[i]->getPesoTotal();
	}
	return pesototal;
}