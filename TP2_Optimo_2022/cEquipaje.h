#ifndef _CEQUIPAJE_H
#define _CEQUIPAJE_H

#include "gbl.h"

class cEquipaje {
    private:
        const string idEquipaje;
        float peso;
        static unsigned int contador_equipajes;

    public: 
    #pragma region Constructores y Destructores
        cEquipaje(float peso_);
        ~cEquipaje();
    #pragma endregion

    #pragma region Getters y Setters
        float getPeso();
        string getIDequipaje();
    #pragma endregion

    #pragma region Metodos
        string tostring();
        void imprimir();
    #pragma endregion

};

#endif //_CEQUIPAJE_H