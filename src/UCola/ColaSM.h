// ---------------------------------------------------------------------------

#ifndef ColaSMH
#define ColaSMH
// ---------------------------------------------------------------------------
#include <string>
#include "UCSMemoria/CSMemoria.h"

namespace UColaSM
{
    const std::string _elemento_sig = "elemento,sig";
    const std::string _elemento = "->elemento";
    const std::string _sig = "->sig";

    class ColaSM
    {
       private:
        UCSMemoria::CSMemoria* mem;
        int ini, fin;

       public:
        ColaSM();
        ColaSM(UCSMemoria::CSMemoria* m);
        bool vacia();
        void poner(int e);
        void sacar(int& e);
        int primero();
        std::string mostrar();
    };
};  // namespace UColaSM
#endif
