//---------------------------------------------------------------------------

#ifndef UConjuntoPunteroH
#define UConjuntoPunteroH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UConjuntoPuntero {
    struct Nodo {
        int dato;
        Nodo* sig;
    };

    class ConjuntoPuntero {
       private:
        Nodo* PtrConj;
        int cant;

       public:
        ConjuntoPuntero();
        int cardinal();
        bool vacio();
        int ordinal(int e);
        void inserta(int e);
        void suprime(int e);
        bool pertenece(int e);
        int muestrea();
        ~ConjuntoPuntero();
        std::string mostrar();
    };
}  // namespace UConjuntoPuntero
#endif