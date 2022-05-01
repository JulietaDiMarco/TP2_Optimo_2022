#ifndef _CEQUIPAJE_H
#define _CEQUIPAJE_H

#include "gbl.h"
//#include "cPasajero.h"

class cEquipaje {
    public: 
        cEquipaje(float peso_);
        ~cEquipaje();
    
        string tostring();  
        void imprimir();
    
        float getPeso();
        string getIDequipaje();
        //cPasajero* getDueno();
       

    private: 
        const string idEquipaje;
        float peso;
        static unsigned int contador_equipajes;
     
};

#endif //_CEQUIPAJE_H