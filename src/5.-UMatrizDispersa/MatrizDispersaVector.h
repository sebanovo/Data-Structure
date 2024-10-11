//---------------------------------------------------------------------------

#ifndef MatrizDispersaVectorH
#define MatrizDispersaVectorH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UMatrizDispersaVector {
    class MatrizDispersaVector {
       private:
        const int MAX = 100;
        int *vf;  // vector filas
        int *vc;  // vector columnas
        int *vd;  // vector datos
        int df, dc, repe, nt;
        int buscar_posicion(int f, int c);
        bool hay(int elemento);

       public:
        MatrizDispersaVector();
        void dimensionar(int df, int dc);
        int dimension_fila();
        int dimension_columna();
        void poner(int f, int c, int elemento);
        int elemento(int f, int c);
        void definir_valor_repetido(int elemento);
        std::string mostrar();
        ~MatrizDispersaVector();

        // void  traspuesta();
    };

    int suma(MatrizDispersaVector *m);
}  // namespace UMatrizDispersaVector
#endif