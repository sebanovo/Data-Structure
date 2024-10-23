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

    int evalua(int* op1, int* op2, char sim_operacion)
    {
        switch (sim_operacion)
        {
            case '+':
                return *op1 + *op2;
            case '-':
                return *op1 - *op2;
            case '*':
                return (*op1) * (*op2);
            case '/':
                return (*op1) / (*op2);
            case '^':
                return std::pow(*op1, *op2);
        }
        return 0;
    }

    int prioridad_infija(char c)
    {
        if (c == '^') return 4;
        if (c == '*' || c == '/') return 3;
        if (c == '+' || c == '-') return 2;
        if (c == '(') return 1;
        return 0;
    }

    bool tieneMayorPrioridad(char op1, char op2)
    {
        int nivelOp1 = prioridad_infija(op1);
        int nivelOp2 = prioridad_infija(op2);
        return nivelOp1 >= nivelOp2;
    }

    bool esOperador(char c)
    {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    bool esDigito(char c)
    {
        return std::isdigit(c);
    }

    int evaluar_postfija(std::string expPostFija)
    {
        PilaVector p;
        for (int i = 0; i < expPostFija.length(); i++)
        {
            if (esDigito(expPostFija[i]))
            {
                p.meter(expPostFija[i] - 48);
            }
            else
            {
                int op1, op2;
                p.sacar((char*)&op2);
                p.sacar((char*)&op1);
                char sim_operacion = expPostFija[i];
                int z = evalua(&op1, &op2, sim_operacion);
                p.meter(z);
            }
        }
        return p.cima();
    }

    std::string infija_a_postfija(std::string infija)
    {
        PilaVector p;
        std::string postfija = "";
        char elemento, operador;
        for (int i = 0; i < infija.size(); i++)
        {
            elemento = infija[i];
            if (esDigito(elemento))
            {
                postfija += elemento;
            }
            else if (esOperador(elemento))
            {
                if (!p.vacia())
                {
                    bool seDebeContinuar;
                    do
                    {
                        p.sacar((char*)&operador);
                        if (tieneMayorPrioridad(operador, elemento))
                        {
                            postfija += operador;
                            seDebeContinuar = true;
                        }
                        else
                        {
                            seDebeContinuar = false;
                            p.meter(operador);
                        }
                    } while (!p.vacia() && seDebeContinuar);
                }
                p.meter(elemento);
            }
            else if (elemento == '(')
            {
                p.meter(elemento);
            }
            else if (elemento == ')')
            {
                p.sacar((char*)&operador);
                while (!p.vacia() && operador != '(')
                {
                    postfija += operador;
                    p.sacar((char*)&operador);
                }
            }
        }
        while (!p.vacia())
        {
            p.sacar((char*)&operador);
            postfija += operador;
        }
        return postfija;
    }

}  // namespace UPilaVector