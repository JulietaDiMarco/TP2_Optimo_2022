#include "gbl.h"

class cFecha
{
	private:
		#pragma region Atributos

			tm fecha;

		#pragma endregion	

		#pragma region Constructor y Destructor
		
		public:
			//Constructor por default, inicia en la fecha de hoy
			cFecha();

			//Constructor inicia en dia, mes, año
			cFecha(int d, int m, int a);

			cFecha(int dia, int mes, int anio, int hora, int minutos);

			~cFecha();

		#pragma endregion

		#pragma region Metodos
			
			//Calcula el numero de días entre dos fechas
			static int DiasEntreFechas(cFecha* inicio, cFecha* fin);

			//Devuelve si las fechas se superponen
			static bool IsOverlapped(cFecha* inicio1, cFecha* fin1, cFecha* inicio2, cFecha* fin2);

			//Cambia la fecha a la fecha actual
			void SetHoy();

			//Verifica que la fecha esté completa
			bool FechaCompleta();

			//Devuelve la fecha actual en forma de string
			string To_string();

			// Imprime fecha
			void ImprimirFecha();

			// Determina si el vuelo se encuentra atrasado o no
			static bool EstaAtrasado(cFecha* fecha1, cFecha* fecha2);

			// Determina si las dos fechas tiene el mismo dia
			static bool MismoDia(cFecha* fecha1, cFecha* fecha2);

		#pragma endregion

		#pragma region Sobrecarga de Operadores

			bool operator<(cFecha& otra) {
				time_t aux_this = mktime(&(this->fecha));
				time_t aux_otra = mktime(&(otra.fecha));
				return aux_this < aux_otra;
			}

			bool operator>(cFecha& otra) {
				time_t aux_this = mktime(&(this->fecha));
				time_t aux_otra = mktime(&(otra.fecha));
				return aux_this > aux_otra;
			}

			bool operator==(cFecha& otra) {
				time_t aux_this = mktime(&(this->fecha));
				time_t aux_otra = mktime(&(otra.fecha));
				return aux_this == aux_otra;
			}

			bool operator!=(cFecha& otra) {
				return !(*this == otra);
			}

		#pragma endregion
};
