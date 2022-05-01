#include "cFecha.h"

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

/**
 * cFecha implementation
 */

cFecha::~cFecha() {
	/*
	//verifico que las fechas que recibo no sean null ni estén incompletas
	if ((inicio != NULL && fin != NULL) && inicio->FechaCompleta() && fin->FechaCompleta())
	{
		//verifico que fecha fin > fecha inicio con operador sobrecargado
		if (*inicio > *fin)
			throw exception("Las fechas no son válidas");
		else
		{
			dif = difftime(aux_fin, aux_inicio) / (86400); //calculo la diferencia de tiempo en segundos, transforma a dias,  y la devuelvo
			return dif;
		}
	}
	else throw exception("Fechas incompletas");
	*/
}

cFecha::cFecha() { //este pone la fecha de hoy como default
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = 0;
	fecha.tm_mon = 0;
	fecha.tm_year = 0;
	SetHoy();
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::cFecha(int d, int m, int a)
{
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m - 1;
	fecha.tm_year = a - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

int cFecha::DiasEntreFechas(cFecha * inicio, cFecha * fin)
{
	int dif = 0;
	time_t aux_inicio = mktime(&(inicio->fecha)); //paso las fechas  a segundos
	time_t aux_fin = mktime(&(fin->fecha));
	return 0; //Falta que retorne algo
}

/**
 * @param dia
 * @param mes
 * @param anio
 * @param hora
 * @param minutos
 */
cFecha::cFecha(int dia, int mes, int anio, int hora, int minutos) {

}

bool cFecha::IsOverlapped(cFecha* inicio1, cFecha* fin1, cFecha* inicio2, cFecha* fin2)
{
	if ((*inicio2 > *inicio1 && *inicio2 < *fin1) || *inicio1 == *inicio2)
		return true;
	if ((*fin2<*fin1 && *fin2>*inicio1) || *fin1 == *fin2)
		return true;
	if (*inicio2<*inicio1 && *fin2>*fin1)
		return true;
	return false;
}

void cFecha::SetHoy()
{
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual
	fecha.tm_mday = aux->tm_mday;
	fecha.tm_mon = aux->tm_mon;
	fecha.tm_year = aux->tm_year;
}

bool cFecha::FechaCompleta()
{
	if (fecha.tm_year != 0 && fecha.tm_mon != 0 && fecha.tm_mday != 0) //verifico que los parámetros de día no estén en sus valores nulos
		return true;
	return false;
}

string cFecha::To_string()
{
	return to_string(fecha.tm_year + 1900) +
		"/" + to_string(fecha.tm_mon + 1) +
		"/" + to_string(fecha.tm_mday);
}

void cFecha::ImprimirFecha() {
	cout << To_string() << endl;;
}