//---------------------------------------------------------------------------

#ifndef ColaGenericaH
#define ColaGenericaH
//---------------------------------------------------------------------------
#include <string>

namespace UColaGenerica
{
    template <typename T>
    class ColaGenerica
    {
       private:
        const int MAX = 1000;
        T *v;
        int ini, fin;

       public:
        ColaGenerica();
        bool vacia();
        void poner(T e);
        void sacar(T &e);
        T primero();
        std::string mostrar();
        ~ColaGenerica();
    };
};  // namespace UColaGenerica
#endif