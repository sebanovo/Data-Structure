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
        char* elementos;
        int tope;

       public:
        PilaVector();
        bool vacia();
        void meter(char e);
        void sacar(char* e);
        int cima();
        std::string mostrar();
        ~PilaVector();
    };
};  // namespace UPilaVector

#endif