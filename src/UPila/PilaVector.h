//---------------------------------------------------------------------------

#ifndef PilaVectorH
#define PilaVectorH
//---------------------------------------------------------------------------
#include <string>

namespace UPilaVector
{
    class PilaVector
    {
       private:
        const int MAX = 1000;
        int* elementos;
        int tope;

       public:
        PilaVector();
        bool vacia();
        void meter(int e);
        void sacar(int* e);
        int cima();
        std::string mostrar();
        ~PilaVector();
    };
    int evaluar_postfija(std::string expPostfija);
    std::string infija_a_postfija(std::string infija);
};  // namespace UPilaVector

#endif