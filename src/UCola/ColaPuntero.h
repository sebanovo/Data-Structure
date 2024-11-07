// ---------------------------------------------------------------------------

#ifndef ColaPunteroH
#define ColaPunteroH
// ---------------------------------------------------------------------------
#include <string>

namespace UColaPuntero
{
    struct Nodo
    {
        int elemento;
        Nodo* sig;
    };

    class ColaPuntero
    {
       private:
        Nodo* ini;
        Nodo* fin;

       public:
        ColaPuntero();
        bool vacia();
        void poner(int e);
        void sacar(int& e);
        int primero();
        std::string mostrar();
        ~ColaPuntero();

        // metodos para la dicola
        int ultimo();
        void poner_frente(int e);
        void sacar_final(int& e);
    };
};  // namespace UColaPuntero
#endif
