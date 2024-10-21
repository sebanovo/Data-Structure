//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaVector.h"
#include <stdexcept>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPilaVector
{
    PilaVector::PilaVector()
    {
        tope = 0;
        elementos = new int[MAX];
    }

    bool PilaVector::vacia()
    {
        return tope == 0;
    }

    void PilaVector::meter(int e)
    {
        if (tope >= MAX) return;
        tope++;
        elementos[tope] = e;
    }

    void PilaVector::sacar(int* e)
    {
        if (vacia()) throw std::runtime_error("No hay elementos que sacar");
        *e = elementos[tope];
        tope--;
    }

    int PilaVector::cima()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cima");
        return elementos[tope];
    }

    std::string PilaVector::mostrar()
    {
        std::string s = "";
        PilaVector* aux = new PilaVector;
        while (!vacia())
        {
            int e;
            sacar(&e);
            s += "| " + std::to_string(e) + " |\n";
            aux->meter(e);
        }
        while (!aux->vacia())
        {
            int e;
            aux->sacar(&e);
            meter(e);
        }
        return s;
    }

    PilaVector::~PilaVector()
    {
        delete[] elementos;
    }
}  // namespace UPilaVector