//---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjuntoPuntero.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UConjuntoPuntero {
    ConjuntoPuntero::ConjuntoPuntero() {}
    // cantidad de elementos del conjunto
    int ConjuntoPuntero::cardinal() {}
    // esta vacio?
    bool ConjuntoPuntero::vacio() {}
    // busca el lugar que ocupa el elemento E en el conjunto
    // en este caso el indice coincide con el elemento
    int ConjuntoPuntero::ordinal(int e) {}
    // inserta elementos en el conjunto
    void ConjuntoPuntero::inserta(int e) {}
    // elimna un elemento del conjunto
    void ConjuntoPuntero::suprime(int e) {}
    bool ConjuntoPuntero::pertenece(int e) {}
    // busca un elemento al azar que pertenezca al conjunto
    int ConjuntoPuntero::muestrea() {}
    ConjuntoPuntero::~ConjuntoPuntero() {}
    std::string ConjuntoPuntero::mostrar() {}
}  // namespace UConjuntoPuntero