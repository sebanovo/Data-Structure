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

    std::string infija_a_postfija(std::string expresionInfija);
    double evaluar_postfija(std::string postfija);
};  // namespace UPilaGenerica
#endif