//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaVectorV3.h"
#include <math.h>
#include <stdexcept>
#include <cstring>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaVectorV3
{

    ColaVectorV3::ColaVectorV3()
    {
        fin = 0;
        ini = 1;
        v = new int[MAX];
    }

    bool ColaVectorV3 ::vacia()
    {
        return siguiente(fin) == ini;
    }

    void ColaVectorV3::poner(int e)
    {
        if (siguiente(siguiente(fin)) == ini) throw std::runtime_error("No hay espacio en la cola");
        fin = siguiente(fin);
        v[fin - 1] = e;
    }

    void ColaVectorV3 ::sacar(int& e)
    {
        if (vacia()) throw std::runtime_error("No hay elementos que sacar");
        e = v[ini - 1];
        ini = siguiente(ini);
    }

    int ColaVectorV3 ::primero()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cola");
        return v[ini - 1];
    }

    std::string ColaVectorV3::mostrar()
    {
        std::string s = "<<";
        ColaVectorV3 aux;
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

    ColaVectorV3 ::~ColaVectorV3()
    {
        delete[] v;
    }

    int ColaVectorV3::siguiente(int dir)
    {
        return dir == MAX ? 1 : dir + 1;
    }

    int ColaVectorV3::anterior(int dir)
    {
        return dir == 1 ? MAX : dir - 1;
    }

    int ColaVectorV3::ultimo()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cola");
        return v[fin - 1];
    }

    void ColaVectorV3::poner_frente(int e)
    {
        if (siguiente(siguiente(fin)) == ini) throw std::runtime_error("No hay espacio en la cola");
        ini = anterior(ini);
        v[ini - 1] = e;
    }

    void ColaVectorV3::sacar_final(int& e)
    {
        if (vacia()) throw std::runtime_error("No hay elementos que sacar");
        e = v[fin - 1];
        fin = anterior(fin);
    }
}  // namespace UColaVectorV3
