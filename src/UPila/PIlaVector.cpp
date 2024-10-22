//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaVector.h"
#include <math.h>
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

    int evalua(int* op1, int* op2, char sim_operacion)
    {
        int resultado = 0;
        switch (sim_operacion)
        {
            case '+':
                resultado += *op1 + *op2;
                break;
            case '-':
                resultado += *op1 - *op2;
                break;
            case '*':
                resultado += (*op1) * (*op2);
                break;
            case '/':
                resultado += (*op1) / (*op2);
                break;
            case '^':
                resultado += std::pow(*op1, *op2);
                break;
            default:
                break;
        }
        return resultado;
    }

    int evaluar_postfija(std::string expPostFija)
    {
        PilaVector p;
        std::string numeros = "0123456789";
        for (int i = 0; i < expPostFija.length(); i++)
        {
            if (static_cast<int>(numeros.find(expPostFija[i])) >= 0)
            {
                p.meter(expPostFija[i] - 48);
            }
            else
            {
                int op1, op2;
                p.sacar(&op2);
                p.sacar(&op1);
                char sim_operacion = expPostFija[i];
                int z = evalua(&op1, &op2, sim_operacion);
                p.meter(z);
            }
        }
        return p.cima();
    }
    
    int prioridad_infija(char c)
    {
        int prioridad;
        switch (c)
        {
            case '^':
                prioridad = 4;
                break;
            case '*':
                prioridad = 2;
                break;
            case '/':
                prioridad = 2;
                break;
            case '+':
                prioridad = 1;
                break;
            case '-':
                prioridad = 1;
                break;
            case '(':
                prioridad = 5;
                break;
            default:
                break;
        }
        return prioridad;
    }
    int prioridad_pila(char c)
    {
        int prioridad;
        switch (c)
        {
            case '^':
                prioridad = 3;
                break;
            case '*':
                prioridad = 2;
                break;
            case '/':
                prioridad = 2;
                break;
            case '+':
                prioridad = 1;
                break;
            case '-':
                prioridad = 1;
                break;
            case '(':
                prioridad = 0;
                break;
            default:
                break;
        }
        return prioridad;
    }

    std::string infija_a_postfija(std::string infija)
    {
        PilaVector p;
        std::string PostFija = "";
        std::string numeros = "0123456789";
        std::string operador = "^*/+-(";
        for (int i = 0; i < infija.length(); i++)
        {
            if ((int)numeros.find(infija[i]) >= 0)
            {
                PostFija = PostFija + infija[i];
            }
            else
            {
                if ((int)operador.find(infija[i]) >= 0)
                {
                    bool b = false;
                    while (!b)
                    {
                        int aux = p.cima();
                        if (p.vacia() || prioridad_infija(infija[i]) > prioridad_pila(aux))
                        {
                            p.meter(infija[i] - 48);
                            b = true;
                        }
                        else
                        {
                            p.sacar(&aux);
                            PostFija = PostFija + std::to_string(aux);
                        }
                    }
                }
                else
                {
                    if (infija[i] == ')')
                    {
                        int aux;
                        do
                        {
                            p.sacar(&aux);
                            if (aux != '(')
                            {
                                PostFija = PostFija + std::to_string(aux);
                            }
                        } while (aux == 'C');
                    }
                }
            }
        }
        while(!p.vacia()) {
            int aux;
            p.sacar(&aux);
            PostFija = PostFija + std::to_string(aux);
        }
        return PostFija;
    }
}  // namespace UPilaVector