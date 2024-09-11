//---------------------------------------------------------------------------

#pragma hdrstop

#include "UConjuntoVector.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UConjuntoVector {
    ConjuntoVector::ConjuntoVector() {
        v = new bool[MAX];
        cant = 0;
        for (int i = 1; i <= MAX; i++) {
            v[i] = 0;
        }
    }

    // cantidad de elementos del conjunto
    int ConjuntoVector::cardinal() {
        return cant;
    }

    // esta vacio?
    bool ConjuntoVector::vacio() {
        return cant == 0;
    }

    // busca el lugar que ocupa el elemento E en el conjunto
    // en este caso el indice coincide con el elemento
    int ConjuntoVector::ordinal(int e) {
        int resp = 0;
        for (int i = 1; i <= MAX; i++) {
            if (v[i] != 0) {
                resp++;
                if (e == i)
                    return resp;
            }
        }
        return resp;
    }

    // inserta elementos en el conjunto
    void ConjuntoVector::inserta(int e) {
        if (!pertenece(e)) {
            v[e] = 1;
            cant++;
        }
    }

    // elimna un elemento del conjunto
    void ConjuntoVector::suprime(int e) {
        if (pertenece(e)) {
            v[e] = 0;
            cant--;
        }
    }

    bool ConjuntoVector::pertenece(int e) {
        return v[e] == 1;
    }

    // busca un elemento al azar que pertenezca al conjunto
    int ConjuntoVector::muestrea() {
        int resp = 0, elemento = 0;
        int lug = rand() % cardinal() + 1;  // >= 1 && <= cant
        for (int i = 1; i <= MAX; i++) {
            if (v[i] != 0) {
                resp++;
                if (resp == lug)
                    elemento = v[i];
            }
        }
        return elemento;
    }

    std::string ConjuntoVector::mostrar() {
        std::string s = "{";
        for (int i = 1, j = 0; i <= MAX; i++) {
            if (v[i]) {
                j++;
                s += std::to_string(i);
                s += j < cardinal() ? "," : "";
            }
        }
        return s + "}";
    }

    ConjuntoVector::~ConjuntoVector() {
        delete[] v;
    }

}  // namespace UConjuntoVector