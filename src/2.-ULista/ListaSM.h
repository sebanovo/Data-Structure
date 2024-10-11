//---------------------------------------------------------------------------

#ifndef ListaSMH
#define ListaSMH
//---------------------------------------------------------------------------
#include <string>

#include "1.-UCSMemoria/CSMemoria.h"

namespace UListaSM {
    using std::string;
    const string _elemento_sig = "elemento,sig";
    const string _elemento = "->elemento";
    const string _sig = "->sig";

    class ListaSM {
       private:
        int PtrElementos;
        int longitud;
        UCSMemoria::CSMemoria* mem;

       public:
        ListaSM();
        ListaSM(UCSMemoria::CSMemoria* m);
        int fin();
        int primero();
        int siguiente(int dir);
        int anterior(int dir);
        bool vacia();
        int recupera(int dir);
        int _longitud();
        void inserta(int dir, int element);
        void inserta_primero(int element);
        void inserta_ultimo(int element);
        void suprime(int dir);
        void modifica(int dir, int element);
        string mostrar();
        ~ListaSM();

        // extra
        int localiza(int element);
        void elimina_dato(int element);
        void anula();

        bool es_direccion_valida(int dir);

        // ejercicio
        void bubble_sort();
    };

}  // namespace UListaSM

#endif