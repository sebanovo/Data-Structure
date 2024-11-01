//---------------------------------------------------------------------------

#ifndef PilaGenericaH
#define PilaGenericaH
//---------------------------------------------------------------------------
#include <string>
#include <stdexcept>
#include <cmath>
#include <iostream>

namespace UPilaGenerica
{
    template <typename T>
    class PilaGenerica
    {
       private:
        const int MAX = 1000;
        T* elementos;
        int tope;

       public:
        PilaGenerica();
        bool vacia();
        void meter(T e);
        void sacar(T& e);
        T cima();
        std::string mostrar();
        ~PilaGenerica();
    };

    // Implementación de las funciones plantilla
    template <typename T>
    PilaGenerica<T>::PilaGenerica()
    {
        tope = 0;
        elementos = new T[MAX];
    }

    template <typename T>
    bool PilaGenerica<T>::vacia()
    {
        return tope == 0;
    }

    template <typename T>
    void PilaGenerica<T>::meter(T e)
    {
        if (tope >= MAX) return;
        tope++;
        elementos[tope] = e;
    }

    template <typename T>
    void PilaGenerica<T>::sacar(T& e)
    {
        if (vacia()) throw std::runtime_error("No hay elementos que sacar");
        e = elementos[tope];
        tope--;
    }

    template <typename T>
    T PilaGenerica<T>::cima()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cima");
        return elementos[tope];
    }

    template <typename T>
    std::string PilaGenerica<T>::mostrar()
    {
        std::string s = "";
        PilaGenerica<T>* aux = new PilaGenerica<T>();
        while (!vacia())
        {
            T e;
            sacar(e);
            s += "| " + std::to_string(e) + " |\n";
            aux->meter(e);
        }
        while (!aux->vacia())
        {
            T e;
            aux->sacar(e);
            meter(e);
        }
        return s;
    }

    template <typename T>
    PilaGenerica<T>::~PilaGenerica()
    {
        delete[] elementos;
    }

    double evaluar(double op1, double op2, char operacion);
    int jerarquia(char operador);
    std::string infija_a_postfija(std::string expresionInfija);
    double evaluar_postfija(std::string postfija);
    bool verificar_parentesis(std::string expresionInfija);

};  // namespace UPilaGenerica
#endif