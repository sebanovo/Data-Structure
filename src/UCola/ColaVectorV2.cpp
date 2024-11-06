//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaVectorV2.h"
#include <math.h>
#include <stdexcept>
#include <cstring>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaVectorV2
{
    ColaVectorV2::ColaVectorV2()
    {
        fin = 0;
        ini = 1;
        v = new int[MAX];
    }

    bool ColaVectorV2 ::vacia()
    {
        return ini > fin;
    }

    void ColaVectorV2::poner(int e)
    {
        if (fin >= MAX) return;
        v[++fin] = e;
    }

    void ColaVectorV2 ::sacar(int& e)
    {
        if (vacia()) throw std::runtime_error("No hay elementos que sacar");
        // e = v[ini++];
        e = v[1];
        for (int i = ini; i < fin; i++)
            v[i] = v[i + 1];
        fin--;
    }

    int ColaVectorV2 ::primero()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cola");
        return v[ini];
    }

    std::string ColaVectorV2::mostrar()
    {
        std::string s = "<<";
        ColaVectorV2 aux;
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

    ColaVectorV2 ::~ColaVectorV2()
    {
        delete[] v;
    }
}  // namespace UColaVectorV2
