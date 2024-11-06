//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaPuntero.h"
#include <stdexcept>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPilaPuntero
{
    PilaPuntero::PilaPuntero()
    {
        tope = nullptr;
    }

    bool PilaPuntero::vacia()
    {
        return tope == nullptr;
    }

    void PilaPuntero::meter(int e)
    {
        Nodo* x = new Nodo;
        if (x == nullptr) throw std::runtime_error("No hay espacio en la memoria");
        x->elemento = e;
        x->sig = tope;
        tope = x;
    }

    void PilaPuntero::sacar(int& e)
    {
        if (vacia()) throw std::runtime_error("No hay elementos que sacar");
        e = tope->elemento;
        Nodo* aux = tope;
        tope = tope->sig;
        delete aux;
    }

    int PilaPuntero::cima()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cima");
        return tope->elemento;
    }

    std::string PilaPuntero::mostrar()
    {
        std::string s = "";
        PilaPuntero aux;
        while (!vacia())
        {
            int e;
            sacar(e);
            s += "| " + std::to_string(e) + " |\n";
            aux.meter(e);
        }
        while (!aux.vacia())
        {
            int e;
            aux.sacar(e);
            meter(e);
        }
        return s;
    }

    PilaPuntero::~PilaPuntero()
    {
        Nodo* x = tope;
        while (x != nullptr)
        {
            Nodo* aux = tope;
            tope = tope->sig;
            delete aux;
        }
    }
}  // namespace UPilaPuntero