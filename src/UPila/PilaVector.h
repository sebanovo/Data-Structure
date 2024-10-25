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
};  // namespace UPilaVector

#endif