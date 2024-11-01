//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaGenerica.h"
#include <math.h>
#include <stdexcept>
#include <sstream>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPilaGenerica 
{
    double evaluar(double op1, double op2, char operacion)
    {
        switch (operacion)
        {
            case '+':
                return op2 + op1;
            case '-':
                return op2 - op1;
            case '*':
                return op2 * op1;
            case '/':
                return op2 / op1;
            case '^':
                return std::pow(op2, op1);
            default:
                throw std::invalid_argument("Operador inválido");
        }
    }

    int jerarquia(char operador)
    {
        switch (operador)
        {
            case '^':
                return 3;
            case '*':
            case '/':
                return 2;
            case '+':
            case '-':
                return 1;
            default:
                return 0;
        }
    }

    std::string infija_a_postfija(std::string expresionInfija)
    {
        PilaGenerica<char> pilaOp;
        std::string postfija;
        for (size_t i = 0; i < expresionInfija.length(); ++i)
        {
            char car = expresionInfija[i];
            if (std::isdigit(car))
            {
                postfija += car;
                while (i + 1 < expresionInfija.length() && std::isdigit(expresionInfija[i + 1]))
                {
                    postfija += expresionInfija[++i];
                }
                postfija += ' ';
            }
            else if (jerarquia(car) > 0)
            {
                while (!pilaOp.vacia() && jerarquia(pilaOp.cima()) >= jerarquia(car))
                {
                    char operacion;
                    pilaOp.sacar(operacion);
                    postfija += operacion;
                    postfija += ' ';
                }
                pilaOp.meter(car);
            }
            else if (car == '(')
            {
                pilaOp.meter(car);
            }
            else if (car == ')')
            {
                while (!pilaOp.vacia() && pilaOp.cima() != '(')
                {
                    char op;
                    pilaOp.sacar(op);
                    postfija += op;
                    postfija += ' ';
                }
                char any;
                pilaOp.sacar(any);
            }
        }
        while (!pilaOp.vacia())
        {
            char op;
            pilaOp.sacar(op);
            postfija += op;
            postfija += ' ';
        }
        return postfija;
    }

    double evaluar_postfija(std::string postfija)
    {
        PilaGenerica<double> pila;
        std::istringstream tokens(postfija);
        std::string token;
        while (tokens >> token)
        {
            if (token.size() == 1 && jerarquia(token[0]) > 0)
            {
                double op1, op2;
                pila.sacar(op1);
                pila.sacar(op2);
                pila.meter(evaluar(op1, op2, token[0]));
            }
            else
            {
                pila.meter(std::stod(token));
            }
        }

        double resultado ;
        pila.sacar(resultado);
        return resultado;
    }

    bool verificar_parentesis(std::string expresionInfija)
    {
        if (expresionInfija.empty())
        {
            std::cout << "La expresión infija no puede ser vacía";
            return false;
        }

        int balance = 0;
        for (char c : expresionInfija)
        {
            if (c == '(')
                ++balance;
            else if (c == ')')
                --balance;
            if (balance < 0)
            {
                std::cout << "Paréntesis inválidos";
                return false;
            }
        }
        if (balance != 0)
        {
            std::cout << "Paréntesis inválidos";
            return false;
        }
        return true;
    }

}  // namespace UPilaGenerica