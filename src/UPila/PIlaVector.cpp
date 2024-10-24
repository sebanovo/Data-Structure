//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaVector.h"
#include <math.h>
#include <stdexcept>
#include <cstring>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPilaVector
{
    PilaVector::PilaVector()
    {
        tope = 0;
        elementos = new char[MAX];
    }

    bool PilaVector::vacia()
    {
        return tope == 0;
    }

    void PilaVector::meter(char e)
    {
        if (tope >= MAX) return;
        tope++;
        elementos[tope] = e;
    }

    void PilaVector::sacar(char* e)
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
            sacar((char*)&e);
            s += "| " + std::to_string(e) + " |\n";
            aux->meter(e);
        }
        while (!aux->vacia())
        {
            int e;
            aux->sacar((char*)&e);
            meter(e);
        }
        return s;
    }

    PilaVector::~PilaVector()
    {
        delete[] elementos;
    }
}  // namespace UPilaVector