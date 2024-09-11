//---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjuntoSM.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UConjuntoSM {
    ConjuntoSM::ConjuntoSM() {}
    // cantidad de elementos del conjunto
    int ConjuntoSM::cardinal() {}
    // esta vacio?
    bool ConjuntoSM::vacio() {}
    // busca el lugar que ocupa el elemento E en el conjunto
    // en este caso el indice coincide con el elemento
    int ConjuntoSM::ordinal(int e) {}
    // inserta elementos en el conjunto
    void ConjuntoSM::inserta(int e) {}
    // elimna un elemento del conjunto
    void ConjuntoSM::suprime(int e) {}
    bool ConjuntoSM::pertenece(int e) {}
    // busca un elemento al azar que pertenezca al conjunto
    int ConjuntoSM::muestrea() {}
    ConjuntoSM::~ConjuntoSM() {}
    std::string ConjuntoSM::mostrar() {}
}  // namespace UConjuntoSM