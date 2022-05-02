#ifndef _CPASAJERO_H
#define _CPASAJERO_H

#include "cListaEquipaje.h"
#include "cFecha.h"

class cPasajero {
    friend class cListaPasajeros;

    private:
        string DNI;
        string nombre;
        string apellido;
        string asiento;
        cFecha* fecha_nacimiento;
        cListaEquipaje* valijas;

    public: 

        #pragma region Constructores y Destructores

            cPasajero(string DNI_, string nombre_, string apellido_, string asiento_, cFecha* fn);
            ~cPasajero();

        #pragma endregion

        #pragma region Getters y setters

            string getDNI();
            string getNombre();
            string getApellido();
            float getPesoTotal();

        #pragma endregion

        #pragma region Metodos
        
            bool agregarEquipaje(cEquipaje* valija);
        
            bool eliminarEquipaje(string id);
        
            string tostring();
        
            void imprimir();
    
        #pragma endregion

        #pragma region Operadores
            bool operator+(cEquipaje* equipaje);
            bool operator-(cEquipaje* equipaje);
        #pragma endregion
};

#endif //_CPASAJERO_H