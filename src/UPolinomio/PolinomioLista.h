//---------------------------------------------------------------------------

#ifndef PolinomioListaH
#define PolinomioListaH
//---------------------------------------------------------------------------
#include <ULista/ListaSM.h>
#include <ULista/ListaVector.h>

#include <iostream>
#include <string>

// POLINOMIO LISTA
// SOLO FUNCIONA PARA UNA (LISTA SM) Y (LISTA VECTOR)

namespace UPolinomioLista
{
    class PolinomioLista
    {
        private:
        // UListaSM::ListaSM* ls;
        UCSMemoria::CSMemoria* mem;
        UListaVector::ListaVector* ls;

        int buscar_exponente(int exp);
        int buscar_termino_n(int n);

        public:
        PolinomioLista();
        PolinomioLista(UCSMemoria::CSMemoria* m);
        bool es_cero();
        int grado();
        void poner_en_cero();
        int coeficiente(int exp);
        void asignar_coeficiente(int coef, int exp);
        void poner_termino(int coef, int exp);
        int numero_terminos();
        int exponente(int nroTerm);
        void sumar(PolinomioLista* p1, PolinomioLista* p2);
        void restar(PolinomioLista* p1, PolinomioLista* p2);
        void multiplicar(PolinomioLista* P1, PolinomioLista* P2);
        int evaluar(int x);
        std::string mostrar();
        ~PolinomioLista();

        // ejercicios
        static void derivada(PolinomioLista* p, PolinomioLista* p1);
        static std::string mostrar_integral(PolinomioLista* p);
    };
} // namespace UPolinomioLista

#endif
