//---------------------------------------------------------------------------

#ifndef ColaVectorV1H
#define ColaVectorV1H
//---------------------------------------------------------------------------
#include <string>

namespace UColaVectorV1
{
    class ColaVectorV1
    {
       private:
        const int MAX = 1000;
        int *v;
        int ini, fin;

       public:
        ColaVectorV1();
        bool vacia();
        void poner(int e);
        void sacar(int &e);
        int primero();
        std::string mostrar();
        ~ColaVectorV1();
    };
};  // namespace UColaVectorV1
#endif