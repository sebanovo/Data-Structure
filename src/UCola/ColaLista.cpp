// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaLista.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaLista
{

    ColaLista::ColaLista()
    {
        // mem = new UCSMemoria::CSMemoria;
        // ls = new UListaSM::ListaSM(mem);
        ls = new UListaVector::ListaVector;
    }

    ColaLista::ColaLista(UCSMemoria::CSMemoria* m)
    {
        // mem = m;
        // ls = new UListaSM::ListaSM(mem);
        ls = new UListaVector::ListaVector;
    }

    bool ColaLista::vacia()
    {
        return ls->vacia();
    }

    void ColaLista::poner(int e)
    {
        ls->inserta_ultimo(e);
    }

    void ColaLista::sacar(int& e)
    {
        if (vacia()) throw std::runtime_error("No hay elementos que sacar");
        e = ls->recupera(ls->primero());
        ls->suprime(ls->primero());
    }

    int ColaLista::primero()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cola");
        return ls->recupera(ls->primero());
    }

    std::string ColaLista::mostrar()
    {
        std::string s = "<<";
        ColaLista aux;
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

    ColaLista::~ColaLista()
    {
        // delete mem;
        delete ls;
    }

    int ColaLista::ultimo()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cola");
        return ls->recupera(ls->fin());
    }

    void ColaLista::poner_frente(int e)
    {
        ls->inserta(ls->primero(), e);
    }

    void ColaLista::sacar_final(int& e)
    {
        e = ls->recupera(ls->fin());
        ls->suprime(ls->fin());
    }

    void ColaLista::concatenar(ColaLista* c1, ColaLista* c2, ColaLista* c3)
    {
        ColaLista aux;
        while (!c1->vacia())
        {
            int e;
            c1->sacar(e);
            aux.poner(e);
        }
        while (!aux.vacia())
        {
            int e;
            aux.sacar(e);
            c3->poner(e);
            c1->poner(e);
        }
        while (!c2->vacia())
        {
            int e;
            c2->sacar(e);
            aux.poner(e);
        }
        while (!aux.vacia())
        {
            int e;
            aux.sacar(e);
            c3->poner(e);
            c2->poner(e);
        }
    }
}  // namespace UColaLista
