// ---------------------------------------------------------------------------

#ifndef ColaPrioridadH
#define ColaPrioridaddH
// ---------------------------------------------------------------------------
#include <string>
#include "UCola/ColaVectorV3.h"
#include "UCola/ColaSM.h"
#include "UCSMemoria/CSMemoria.h"

namespace UColaPrioridad
{
    const int MAXCP = 3;
    using namespace std;

    class ColaPrioridad
    {
       private:
        UColaSM::ColaSM*(*vc);
        int* vf;
        int colaAct;
        int cant;

       public:
        ColaPrioridad();
        ColaPrioridad(UCSMemoria::CSMemoria* m);
        bool vacia();
        int primero();
        void poner(int e, int prioridad);
        void asignar_frec_prioridad(int frec, int prioridad);
        void sacar(int& e);
        std::string mostrar();

        ~ColaPrioridad();
    };
}  // namespace UColaPrioridad
#endif
