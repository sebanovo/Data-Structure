//---------------------------------------------------------------------------

#ifndef MatrizDispersaSMDobleH
#define MatrizDispersaSMDobleH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "1.-UCSMemoria/CSMemoria.h"

namespace UMatrizDispersaSMDoble {
    using namespace std;

    const string _col = "->col";
    const string _dato = "->dato";
    const string _sigC = "->sigC";
    const string _col_dato_sigC = "col,dato,sigC";

    const string _fil = "->fil";
    const string _antF = "->antF";
    const string _sigF = "->sigF";
    const string _ptrCol = "->ptrCol";
    const string _fil_antF_sigF_ptrCol = "fil,antF,sigF,ptrCol";

    class MatrizDispersaSMDoble {
       private:
        UCSMemoria::CSMemoria* mem;
        int PtrFil;
        int repe, df, dc, nt;

        int buscarC(int f, int c);
        int buscarF(int f);
        int posicionIns(int f);
        void insertar(int f, int c, int v);
        void suprimir2(int dirFil, int dirCol);
        void suprimir1(int dir);

       public:
        MatrizDispersaSMDoble();
        MatrizDispersaSMDoble(UCSMemoria::CSMemoria* m);
        void dimensionar(int f, int c);
        int dimension_fila();
        int dimension_columna();
        void poner(int f, int c, int elemento);
        int elemento(int f, int c);
        void definir_valor_repetido(int elemento);
        string mostrar();
    };
    int suma(MatrizDispersaSMDoble* m);
}  // namespace UMatrizDispersaSMDoble
#endif
