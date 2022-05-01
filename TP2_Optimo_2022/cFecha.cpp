#include "cFecha.h"

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

cFecha::cFecha() {
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

cFecha::cFecha(int d, int m, int a, int hs, int min) {

	fecha.tm_hour = hs;
	fecha.tm_min = min;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m - 1;
	fecha.tm_year = a - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::~cFecha() {
}

int cFecha::DiasEntreFechas(cFecha * inicio, cFecha * fin)
{
	int dif = 0;
	time_t aux_inicio = mktime(&(inicio->fecha)); //paso las fechas a segundos
	time_t aux_fin = mktime(&(fin->fecha));

	//verifico que las fechas que recibo no sean null ni estén incompletas
	if ((inicio != NULL && fin != NULL) && inicio->FechaCompleta() && fin->FechaCompleta())
	{
		//verifico que fecha fin > fecha inicio con operador sobrecargado
		if (*inicio > *fin)
			throw exception("Las fechas no son válidas");
		else
		{
			dif = difftime(aux_fin, aux_inicio) / (60); //calculo la diferencia de tiempo en segundos, transforma a minutos, y la devuelvo
			return dif;
		}
	}
	else throw exception("Fechas incompletas");
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

bool cFecha::EstaAtrasado(cFecha* fecha_estimada, cFecha* fecha_vuelo)
{
	//Podemos utilizar la sobrecarga < para deteminar si el vuelo esta atrasado
	if (*fecha_estimada < *fecha_vuelo)
		return true;
	else
		return false;
}
