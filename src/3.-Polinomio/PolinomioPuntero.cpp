
//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioPuntero.h"

#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPolinomioPuntero {
    PolinomioPuntero::PolinomioPuntero() {
        nt = 0;
        PtrPoli = nullptr;
    }

    direccion PolinomioPuntero::buscar_exponente(int exp) {
        Nodo* dir = PtrPoli;
        int x;

        if (dir != nullptr) {
            Nodo* dirEx = nullptr;
            while ((dir != nullptr) && (dirEx == nullptr)) {
                if (dir->exp == exp)
                    dirEx = dir;
                dir = dir->sig;
            }
            return dirEx;
        } else
            return nullptr;
    }
    direccion PolinomioPuntero::buscar_termino_n(int n) {
        Nodo* Dir = PtrPoli;
        if (Dir != nullptr) {
            Nodo* dirTer = nullptr;
            int Nt = 0;
            while ((Dir != nullptr) && (dirTer == nullptr)) {
                Nt = Nt + 1;
                if (Nt == n) {
                    dirTer = Dir;
                }
                Dir = Dir->sig;
            }
            return dirTer;

        } else
            return nullptr;
    }

    bool PolinomioPuntero::es_cero() {}
    int PolinomioPuntero::grado() {}
    int PolinomioPuntero::coeficiente(int exp) {
        Nodo* dir = buscar_exponente(exp);
        return dir != nullptr ? dir->coef : throw std::runtime_error("No existe ese termino");
    }
    void PolinomioPuntero::sumar(PolinomioPuntero p1, PolinomioPuntero p2) {}
    void PolinomioPuntero::restar(PolinomioPuntero p1, PolinomioPuntero p2) {}
    void PolinomioPuntero::multiplicar(PolinomioPuntero p1, PolinomioPuntero p3) {}
    void PolinomioPuntero::poner_termino(int coef, int exp) {
        Nodo* existe = buscar_exponente(exp);
        if (existe == nullptr) {
            Nodo* aux = new Nodo;
            aux->sig = nullptr;
            if (aux != nullptr) {
                aux->coef = coef;
                aux->exp = exp;
                aux->sig = PtrPoli;
                PtrPoli = aux;
                nt++;
            } else {
                throw std::runtime_error("Error de espacio de memoria");
            }
        } else {
            int NuevoCoef = existe->coef + coef;
            existe->coef = NuevoCoef;
        }
    }

    int PolinomioPuntero::numero_terminos() {
        return nt;
    }
    int PolinomioPuntero::exponente(int nroTer) {
        Nodo* dir = buscar_termino_n(nroTer);
        return dir != nullptr ? dir->exp : throw std::runtime_error("No existe este exponente");
    }
    void PolinomioPuntero::asignar_coeficiente(int coef, int exp) {}
    string PolinomioPuntero::mostrar() {}
    PolinomioPuntero::~PolinomioPuntero() {
        Nodo* current = PtrPoli;
        while (current != nullptr) {
            Nodo* next = current->sig;
            delete current;
            current = next;
        }
        PtrPoli = nullptr;
    }

    void derivada(PolinomioPuntero p, PolinomioPuntero p1) {
        for (int i = 1; i <= p.numero_terminos(); i++) {
            int exp = p.exponente(i);
            int coef = p.coeficiente(exp);
            p1.poner_termino(coef * exp, exp - 1);
        }
    }
}  // namespace UPolinomioPuntero