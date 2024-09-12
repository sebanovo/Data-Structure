//---------------------------------------------------------------------------

#ifndef UConjuntoSMH
#define UConjuntoSMH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "1.-Memoria/UCSMemoria.h"

namespace UConjuntoSM {
    const std::string _dato_sig = "dato,sig";
    const std::string _dato = "->dato";
    const std::string _sig = "->sig";

    class ConjuntoSM {
       private:
        UCSMemoria::CSMemoria* mem;
        int PtrConj;
        int cant;

       public:
        ConjuntoSM();
        ConjuntoSM(UCSMemoria::CSMemoria* m);
        int cardinal();
        bool vacio();
        int ordinal(int e);
        void inserta(int e);
        void suprime(int e);
        bool pertenece(int e);
        int muestrea();
        ~ConjuntoSM();
        std::string mostrar();
    };

}  // namespace UConjuntoSM
#endif