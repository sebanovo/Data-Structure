// ---------------------------------------------------------------------------

#pragma hdrstop

#include <iostream>
#include <stdexcept>
#include "ColaPuntero.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaPuntero
{
    ColaPuntero::ColaPuntero()
    {
        ini = fin = nullptr;
    }

    bool ColaPuntero::vacia()
    {
        return ini == nullptr;
    }

    void ColaPuntero::poner(int e)
    {
        Nodo* aux = new Nodo;
        if (aux == nullptr) return;
        aux->elemento = e;
        aux->sig = nullptr;
        if (vacia())
        {
            ini = fin = aux;
        }
        else
        {
            fin->sig = aux;
            fin = aux;
        }
    }

    void ColaPuntero::sacar(int& e)
    {
        if (vacia()) throw std::runtime_error("No hay elementos que sacar");
        e = ini->elemento;
        Nodo* x = ini;
        if (ini == fin)
            ini = fin = nullptr;
        else
            ini = ini->sig;
        delete x;
    }

    int ColaPuntero::primero()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cola");
        return ini->elemento;
    }

    std::string ColaPuntero::mostrar()
    {
        std::string s = "<<";
        ColaPuntero aux;
        while (!vacia())
        {
            int e;
            sacar(e);
            aux.poner(e);
            s += std::to_string(e);
            if (!vacia())
                s += ",";
        }
        while (!aux.vacia())
        {
            int e;
            aux.sacar(e);
            poner(e);
        }

        return s + "<<";
    }

    ColaPuntero::~ColaPuntero()
    {
        Nodo* x = ini;
        while (x != nullptr)
        {
            Nodo* aux = x;
            x = x->sig;
            delete aux;
        }
    }
}  // namespace UColaPuntero