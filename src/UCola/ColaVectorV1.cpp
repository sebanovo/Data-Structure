//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaVectorV1.h"
#include <stdexcept>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaVectorV1
{

    ColaVectorV1::ColaVectorV1()
    {
        fin = 0;
        ini = 1;
        v = new int[MAX];
    }

    bool ColaVectorV1 ::vacia()
    {
        return ini > fin;
    }

    void ColaVectorV1::poner(int e)
    {
        if (fin >= MAX) throw std::runtime_error("No hay espacio en la cola");
        v[++fin] = e;
    }

    void ColaVectorV1::sacar(int& e)
    {
        if (vacia()) throw std::runtime_error("No hay elementos que sacar");
        e = v[ini++];
    }

    int ColaVectorV1::primero()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cola");
        return v[ini];
    }

    std::string ColaVectorV1::mostrar()
    {
        std::string s = "<<";
        ColaVectorV1 aux;
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

    ColaVectorV1 ::~ColaVectorV1()
    {
        delete[] v;
    }

    int ColaVectorV1::ultimo()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cola");
        return v[fin];
    }

    void ColaVectorV1::poner_frente(int e)
    {
        if (fin >= MAX) throw std::runtime_error("No hay espacio en la cola");
        fin++;
        for (int i = fin; i > ini; i--)
        {
            v[i] = v[i - 1];
        }
        v[ini] = e;
    }

    void ColaVectorV1::sacar_final(int& e)
    {
        if (vacia()) throw std::runtime_error("No hay elementos que sacar");
        e = v[fin];
        fin--;
    }
}  // namespace UColaVectorV1
