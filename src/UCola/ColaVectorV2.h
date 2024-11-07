//---------------------------------------------------------------------------

#ifndef ColaVectorV2H
#define ColaVectorV2H
//---------------------------------------------------------------------------
#include <string>

namespace UColaVectorV2
{
    class ColaVectorV2
    {
       private:
        const int MAX = 1000;
        int *v;
        int ini, fin;

       public:
        ColaVectorV2();
        bool vacia();
        void poner(int e);
        void sacar(int &e);
        int primero();
        std::string mostrar();
        ~ColaVectorV2();

        // metodos para la dicola
        int ultimo();
        void poner_frente(int e);
        void sacar_final(int &e);
    };
};  // namespace UColaVectorV2
#endif