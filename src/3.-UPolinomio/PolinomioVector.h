//---------------------------------------------------------------------------

#ifndef PolinomioVectorH
#define PolinomioVectorH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

namespace UPolinomioVector {
    using std::string;
    class PolinomioVector {
       private:
        const int MAX = 100;
        int *vc;
        int *ve;
        int nt;

        int buscar_exponente(int exp);
        int buscar_termino_n(int n);

       public:
        PolinomioVector();
        bool es_cero();
        int grado();
        int coeficiente(int exp);
        void sumar(PolinomioVector *p1, PolinomioVector *p2);
        void restar(PolinomioVector *p1, PolinomioVector *p2);
        void multiplicar(PolinomioVector *p1, PolinomioVector *p3);
        void poner_termino(int coef, int exp);
        int numero_terminos();
        int exponente(int nroTer);
        void asignar_coeficiente(int coef, int exp);
        string mostrar();
        ~PolinomioVector();
        int evaluar(int x);
    };
    void derivada(PolinomioVector *p, PolinomioVector *p1);
    string mostrar_integral(PolinomioVector *p);
}  // namespace UPolinomioVector

#endif
