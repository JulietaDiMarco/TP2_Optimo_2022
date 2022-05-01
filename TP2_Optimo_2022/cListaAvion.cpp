#include "cListaAvion.h"

cListaAvion::cListaAvion(unsigned int longitud, bool eliminar) { //aca longitud debe ser max
	this->eliminarNodos = eliminar;
	this->Aviones = new cAvion * [longitud];
	cAvion::setCantidadTotalAviones(longitud);
	for (unsigned int i = 0; i < cAvion::getCantidadTotalAviones(); i++)
		this->Aviones[i] = NULL;
}

cListaAvion::~cListaAvion() {
	if (eliminarNodos) {
		for (unsigned int i = 0; i < cAvion::getCantidadTotalAviones(); i++)
			if (this->Aviones[i] != NULL)
				delete this->Aviones[i];
	}
	delete[] this->Aviones;
	cAvion::setCantidadTotalAviones(0);
}

bool cListaAvion::agregar(cAvion* nuevoAvion) {
	for (unsigned int i = 0; i < cAvion::getCantidadTotalAviones(); i++) {
		if (this->Aviones[i] == NULL) {
			this->Aviones[i] = nuevoAvion;
			return true;
		}
	} return false;
}

#pragma region Metodos_Modificar

bool cListaAvion::modificar(string idAvion, cAvion* nuevoAvion) {
	for (int i = 0; i < cAvion::getCantidadTotalAviones(); i++) {
		if (this->Aviones[i] != NULL && this->Aviones[i]->getID() == idAvion) {
			cAvion* Aux = this->Aviones[i];
			this->Aviones[i] = nuevoAvion;
			delete Aux;
			return true;
		}
	} return false;
}

#pragma endregion

#pragma region Metodos_Eliminar
bool cListaAvion::eliminar(int posicion) {
	if (posicion >= 0 && this->Aviones[posicion] != NULL) {
		delete this->Aviones[posicion];
		this->Aviones[posicion] = NULL;
		return true;
	} return false;
}

bool cListaAvion::eliminar(string idAvion) {
	for (int i = 0; i < cAvion::getCantidadTotalAviones(); i++) {
		if (this->Aviones[i] != NULL && this->Aviones[i]->getID() == idAvion) {
			delete this->Aviones[i];
			this->Aviones[i] = NULL;
			return true;
		}
	} return false;
}

bool cListaAvion::eliminar(cAvion* valija) {
	for (int i = 0; i < cAvion::getCantidadTotalAviones(); i++) {
		if (this->Aviones[i] != NULL && this->Aviones[i] == valija) {
			delete this->Aviones[i];
			this->Aviones[i] = NULL;
			return true;
		}
	} return false;
}
#pragma endregion

#pragma region Metodos_Quitar

cAvion* cListaAvion::quitar(string idAvion) {
	for (int i = 0; i < cAvion::getCantidadTotalAviones(); i++) {
		if (this->Aviones[i] != NULL && this->Aviones[i]->getID() == idAvion) {
			cAvion* Aux = this->Aviones[i];
			this->Aviones[i] = NULL;
			return Aux;
		}
	} return NULL;
}

cAvion* cListaAvion::quitar(cAvion* valija) {
	for (int i = 0; i < cAvion::getCantidadTotalAviones(); i++) {
		if (this->Aviones[i] != NULL && this->Aviones[i] == valija) {
			cAvion* Aux = this->Aviones[i];
			this->Aviones[i] = NULL;
			return Aux;
		}
	} return NULL;
}
#pragma endregion

#pragma region Metodos_Buscar
int cListaAvion::buscar(string idAvion) {
	for (int i = 0; i < cAvion::getCantidadTotalAviones(); i++)
		if (this->Aviones[i] != NULL && this->Aviones[i]->getID() == idAvion)
			return i;
	return -1;
}

cAvion* cListaAvion::buscar(int pos) {
	
		if (this->Aviones[pos] != NULL) {

			cAvion* aux = NULL;
			aux = Aviones[pos];
			return aux;
		}
		else {
			return NULL;
		}

}

int cListaAvion::buscar(cAvion* ptr_Avion) {
	for (int i = 0; i < cAvion::getCantidadTotalAviones(); i++)
		if (this->Aviones[i] != NULL && this->Aviones[i] == ptr_Avion)
			return i;
	return -1;
}
#pragma endregion

void cListaAvion::imprimir() {
	cout << "Mi Listado: " << endl;
	for (unsigned int i = 0; i < cAvion::getCantidadTotalAviones(); i++) // necesito la cantidad total de aviones, hacer un metodo para eso
		if (this->Aviones[i] != NULL) {
			cout << this->Aviones[i]->getCantidadActual() << " " <<
				this->Aviones[i]->getPesoMaximo() << " " <<
				this->Aviones[i]->getVolando() << " " <<
				this->Aviones[i]->getID() << endl;
		}
	cout << endl;
}