//---------------------------------------------------------------------------

#ifndef UConjuntoListaH
#define UConjuntoListaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "2.-Lista/UListaPuntero.h"
#include "2.-Lista/UListaVector.h"

namespace UConjuntoLista {
    struct Nodo {
        int dato;
        Nodo* sig;
    };

    class ConjuntoLista {
       private:
        UListaVector::ListaVector* elem;
        // UListaPuntero::ListaPuntero* elem;

       public:
        ConjuntoLista();
        int cardinal();
        bool vacio();
        int ordinal(int e);
        void inserta(int e);
        void suprime(int e);
        bool pertenece(int e);
        int muestrea();
        ~ConjuntoLista();
        std::string mostrar();
    };
}  // namespace UConjuntoLista
#endif