//---------------------------------------------------------------------------

#ifndef ConjuntoVectorH
#define ConjuntoVectorH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UConjuntoVector
{
    class ConjuntoVector
    {
        private:
        const int MAX = 100;
        bool* v;
        int cant;

        public:
        ConjuntoVector();
        int cardinal();
        bool vacio();
        int ordinal(int e);
        void inserta(int e);
        void suprime(int e);
        bool pertenece(int e);
        int muestrea();
        ~ConjuntoVector();
        std::string mostrar();

        // ejercicios
        static void _union(ConjuntoVector* a, ConjuntoVector* b, ConjuntoVector* c);
        static void _interseccion(ConjuntoVector* a, ConjuntoVector* b, ConjuntoVector* c);
        static bool _equivalentes(ConjuntoVector* a, ConjuntoVector* b);
    };
} // namespace UConjuntoVector
#endif