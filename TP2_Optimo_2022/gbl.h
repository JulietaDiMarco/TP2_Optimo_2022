#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

enum class eDestino{IGUAZU=0, MENDOZA, BARILOCHE, SALTA, JUJUY};

enum class eTramo{Arribo=0, Partida=1};

// Hay que usar inline porque no existe el cpp y estoy fuera de una clase
inline string eDestinoToString(eDestino destino) {
	switch (destino)
	{
		case eDestino::IGUAZU:
			return "Iguazu";
			break;
		case eDestino::MENDOZA:
			return "Mendoza";
			break;
		case eDestino::BARILOCHE:
			return "Bariloche";
			break;
		case eDestino::SALTA:
			return "Salta";
			break;
		case eDestino::JUJUY:
			return "Jujuy";
			break;
		default:
			return "";
			break;
	}
}

inline string eTramoToString(eTramo tramo) {
	switch (tramo)
	{
	case eTramo::Arribo:
		return "Arribo";
		break;
	case eTramo::Partida:
		return "Partida";
		break;
	default:
		return "";
		break;
	}
}
