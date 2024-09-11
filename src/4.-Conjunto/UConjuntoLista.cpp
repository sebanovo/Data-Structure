//---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjuntoLista.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UConjuntoLista {
    ConjuntoLista::ConjuntoLista() {}
    // cantidad de elementos del conjunto
    int ConjuntoLista::cardinal() {}
    // esta vacio?
    bool ConjuntoLista::vacio() {}
    // busca el lugar que ocupa el elemento E en el conjunto
    // en este caso el indice coincide con el elemento
    int ConjuntoLista::ordinal(int e) {}
    // inserta elementos en el conjunto
    void ConjuntoLista::inserta(int e) {}
    // elimna un elemento del conjunto
    void ConjuntoLista::suprime(int e) {}
    bool ConjuntoLista::pertenece(int e) {}
    // busca un elemento al azar que pertenezca al conjunto
    int ConjuntoLista::muestrea() {}
    ConjuntoLista::~ConjuntoLista() {}
    std::string ConjuntoLista::mostrar() {}
}  // namespace UConjuntoLista