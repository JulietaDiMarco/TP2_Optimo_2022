#include "cListaVuelo.h"

cListaVuelo::cListaVuelo(unsigned int longitud, bool eliminar) {
	this->eliminarNodos = eliminar;
	this->Vuelos = new cVuelo * [longitud];
	this->CantidadActual = 0;
	this->CantidadMaxima = longitud;
	for (unsigned int i = 0; i < CantidadMaxima; i++)
		this->Vuelos[i] = NULL;
}

cListaVuelo::~cListaVuelo() {
	if (eliminarNodos) {
		for (unsigned int i = 0; i < CantidadActual; i++)
			if (this->Vuelos[i] != NULL)
				delete this->Vuelos[i];
	}
	delete[] this->Vuelos;
	CantidadActual = 0;
}

bool cListaVuelo::agregar(cVuelo* nuevoVuelo) {
	for (unsigned int i = 0; i < CantidadActual; i++) {
		if (this->Vuelos[i] == NULL) {
			this->Vuelos[i] = nuevoVuelo;
			return true;
		}
	} return false;
}

#pragma region Metodos_Modificar
bool cListaVuelo::modificar(int pos, cVuelo* nuevoVuelo) {
	if (pos >= 0 && this->Vuelos[pos] != NULL) {
		cVuelo* Aux = this->Vuelos[pos];
		this->Vuelos[pos] = nuevoVuelo;
		delete Aux;
		return true;
	} return false;
}

bool cListaVuelo::modificar(string id, cVuelo* nuevoVuelo) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->Vuelos[i] != NULL && this->Vuelos[i]->get_nroVuelo() == id) {
			cVuelo* Aux = this->Vuelos[i];
			this->Vuelos[i] = nuevoVuelo;
			delete Aux;
			return true;
		}
	} return false;
}

#pragma endregion

#pragma region Metodos_Eliminar
bool cListaVuelo::eliminar(int pos) {
	if (pos >= 0 && this->Vuelos[pos] != NULL) {
		delete this->Vuelos[pos];
		this->Vuelos[pos] = NULL;
		return true;
	} return false;
}

bool cListaVuelo::eliminar(string id) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->Vuelos[i] != NULL && this->Vuelos[i]->get_nroVuelo() == id) {
			delete this->Vuelos[i];
			this->Vuelos[i] = NULL;
			return true;
		}
	} return false;
}

bool cListaVuelo::eliminar(cVuelo* auxVuelo) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->Vuelos[i] != NULL && this->Vuelos[i] == auxVuelo) {
			delete this->Vuelos[i];
			this->Vuelos[i] = NULL;
			return true;
		}
	} return false;
}
#pragma endregion

#pragma region Metodos_Quitar
cVuelo* cListaVuelo::quitar(int pos) {
	if (pos >= 0 && this->Vuelos[pos] != NULL) {
		cVuelo* Aux = this->Vuelos[pos];
		this->Vuelos[pos] = NULL;
		return Aux;
	} return NULL;
}

cVuelo* cListaVuelo::quitar(string id) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->Vuelos[i] != NULL && this->Vuelos[i]->get_nroVuelo() == id) {
			cVuelo* Aux = this->Vuelos[i];
			this->Vuelos[i] = NULL;
			return Aux;
		}
	} return NULL;
}

cVuelo* cListaVuelo::quitar(cVuelo* auxVuelo) {
	for (int i = 0; i < CantidadActual; i++) {
		if (this->Vuelos[i] != NULL && this->Vuelos[i] == auxVuelo) {
			cVuelo* Aux = this->Vuelos[i];
			this->Vuelos[i] = NULL;
			return Aux;
		}
	} return NULL;
}
#pragma endregion

#pragma region Metodos_Buscar
int cListaVuelo::buscar(string id) {
	for (int i = 0; i < CantidadActual; i++)
		if (this->Vuelos[i] != NULL && this->Vuelos[i]->get_nroVuelo() == id)
			return i;
	return -1;
}

cVuelo* cListaVuelo::buscar(int pos)
{
	if (this->Vuelos[pos] != NULL) {

		cVuelo* aux = NULL;
		aux = Vuelos[pos];
		return aux;
	}
	else {
		return NULL;
	}
}

int cListaVuelo::buscar(cVuelo* ptr_Vuelo) {
	for (int i = 0; i < CantidadActual; i++)
		if (this->Vuelos[i] != NULL && this->Vuelos[i] == ptr_Vuelo)
			return i;
	return -1;
}
#pragma endregion

#pragma region Metodos_Filtrar
cVuelo** cListaVuelo::filtrar(float peso) {
	cVuelo** Aux = NULL;
	Aux = new cVuelo * [CantidadActual];

	if (Aux != NULL) {
		for (int i = 0; i < CantidadActual; i++)
			if (this->Vuelos[i] != NULL && this->Vuelos[i]->getPesoValijas() == peso)
				Aux[i] = this->Vuelos[i];
	}
	return Aux;
}
#pragma endregion

void cListaVuelo::imprimir() {
	cout << "Mi Listado: " << endl;
	for (unsigned int i = 0; i < CantidadActual; i++)
		if (this->Vuelos[i] != NULL) {
			cout << this->Vuelos[i]->get_nroVuelo() << " " <<
				this->Vuelos[i]->getDestino() << " " <<
				this->Vuelos[i]->getEstado() << " " << endl;
		}
	cout << endl;
}

cVuelo* cListaVuelo::operator[](unsigned int pos)
{
	return this->Vuelos[pos];
}
