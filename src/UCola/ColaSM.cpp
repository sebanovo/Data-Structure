// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaSM.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaSM
{
    using UCSMemoria::NULO;
    ColaSM::ColaSM()
    {
        mem = new UCSMemoria::CSMemoria;
        ini = fin = NULO;
    }

    ColaSM::ColaSM(UCSMemoria::CSMemoria* m)
    {
        mem = m;
        ini = fin = NULO;
    }

    bool ColaSM::vacia()
    {
        return ini == NULO;
    }

    void ColaSM::poner(int e)
    {
        int aux = mem->new_espacio(_elemento_sig);
        if (aux != NULO)
        {
            mem->poner_dato(aux, _elemento, e);
            mem->poner_dato(aux, _sig, NULO);
            if (vacia())
            {
                ini = fin = aux;
            }
            else
            {
                mem->poner_dato(fin, _sig, aux);
                fin = aux;
            }
        }
    }

    void ColaSM::sacar(int& e)
    {
        if (vacia()) throw std::runtime_error("No hay elementos que sacar");
        e = mem->obtener_dato(ini, _elemento);
        int x = ini;
        if (ini == fin)
            ini = fin = NULO;
        else
            ini = mem->obtener_dato(ini, _sig);
        mem->delete_espacio(x);
    }

    int ColaSM::primero()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cola");
        return mem->obtener_dato(ini, _elemento);
    }

    std::string ColaSM::mostrar()
    {
        std::string s = "<<";
        ColaSM aux;
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
}  // namespace UColaSM
