// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaPrioridad.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaPrioridad
{
    using UColaSM::ColaSM;
    ColaPrioridad ::ColaPrioridad()
    {
        vc = new ColaSM*[MAX];
        vf = new int[MAX];
        for(int i = 0; i < MAX; i++)
        {
            vc[i] = new ColaSM;
            vf[i] = 1;
        }
        colaAct = cant = 0;
    }

    ColaPrioridad ::ColaPrioridad(UCSMemoria::CSMemoria* m)
    {
        vc = new ColaSM*[MAX];
        vf = new int[MAX];
        for(int i = 0; i < MAX; i++)
        {
            vc[i] = new ColaSM(m);
            vf[i] = 1;
        }
        colaAct = cant = 0;
    }

    bool ColaPrioridad ::vacia()
    {
        for(int i = 0; i < MAX; i++)
        {
            if(!vc[i]->vacia())
                return false;
        }
        return true;
    }

    int ColaPrioridad ::primero()
    {
        if(vacia())
            throw std::runtime_error("No hay elementos en la cola");

        int ca  = cant;
        int act = colaAct;

        while(true)
        {
            if(ca == vf[act] || vc[act]->vacia())
            {
                if(act == MAX - 1)
                    act = 0;
                else
                    act++;
                ca = 0;
            }
            else
                return vc[act]->primero();
        }

        return 0; // default
    }

    void ColaPrioridad ::poner(int e, int prioridad)
    {
        if(prioridad < 0 || prioridad > MAX)
            throw std::runtime_error("Prioridad fuera de los límites");
        vc[prioridad]->poner(e);
    }

    void ColaPrioridad ::asignar_frecuencia_prioridad(int frec, int prioridad)
    {
        vf[prioridad] = frec;
    }

    void ColaPrioridad ::sacar(int& e)
    {
        if(vacia())
            throw std::runtime_error("Las colas estan vacias");

        while(true)
        {
            if(cant == vf[colaAct] || vc[colaAct]->vacia())
            {
                if(colaAct == MAX - 1)
                    colaAct = 0;
                else
                    colaAct++;
                cant = 0;
            }
            else
            {
                cant++;
                vc[colaAct]->sacar(e);
                break;
            }
        }
    }

    std::string ColaPrioridad ::mostrar()
    {
        std::string s = "";
        for(int i = 0; i < MAX; i++)
            s += vc[i]->mostrar() + "\n";
        return s;
    }

    ColaPrioridad ::~ColaPrioridad()
    {
        delete vc, vf;
    }
}; // namespace UColaPrioridad