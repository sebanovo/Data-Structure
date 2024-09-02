
//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioLista.h"

#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPolinomioLista {
    using UCSMemoria::NULO;

    PolinomioLista::PolinomioLista() {
        mem = new UCSMemoria::CSMemoria;
        ls = new UListaSM::ListaSM(mem);
        // ls = new UListaVector::ListaVector;
    }

    PolinomioLista::PolinomioLista(UCSMemoria::CSMemoria* m) {
        ls = new UListaSM::ListaSM(m);
        // ls = new UListaVector::ListaVector;
    }

    int PolinomioLista::exponente(int i) {
        int dir = buscar_termino_n(i);

        if (dir != -1) {
            int x = ls->siguiente(dir);
            x = ls->recupera(x);
            return x;
        }
        // Retorna el exponente del término
    }

    void PolinomioLista::crear(UCSMemoria::CSMemoria* m) {
        // ls= new Lista(m); //ver el constructor de la clase lista a usar
        // ls = new ptrlista();
        // ls= new Vlista();
    }

    int PolinomioLista::buscar_exponente(int exp) {
        int dir = ls->siguiente(ls->primero());

        int x, q;

        q = ls->recupera(dir);
        int direxp = -1;
        if (dir != -1) {
            while (dir != -1 && direxp == -1 && dir <= ls->fin()) {
                if (dir <= ls->fin()) {
                    if (ls->recupera(dir) == exp) {
                        return direxp = dir;
                    }

                    dir = ls->siguiente(ls->siguiente(dir));
                }
            }
            return direxp;
        }
        return -1;
    }

    // busca el termino n
    int PolinomioLista::buscar_termino_n(int n) {
        int dir = ls->primero();
        int nt = 0;
        if (dir != -1) {
            int dirter = -1;
            while (dir != -1 && dirter == -1) {
                nt = nt + 1;
                if (nt == n) {
                    dirter = dir;
                }
                dir = ls->siguiente(ls->siguiente(dir));
            }
            return dirter;
        } else
            return -1;
    }

    bool PolinomioLista::es_cero() {
        return ls->_longitud() == 0;
    }

    int PolinomioLista::grado() {
        int dir = ls->siguiente(ls->primero());
        if (dir != -1) {
            int MaxG = ls->recupera(dir);
            while (dir != -1 && dir <= ls->fin()) {
                if (ls->recupera(dir) > MaxG) {
                    MaxG = ls->recupera(dir);
                }
                dir = ls->siguiente(ls->siguiente(dir));
            }
            return MaxG;
        } else
            return -1;
    }

    int PolinomioLista::coeficiente(int exp) {
        int dir = buscar_exponente(exp);
        if (dir != -1) {
            return ls->recupera(ls->anterior(dir));
        } else
            return -1;
    }

    void PolinomioLista::asignar_coeficiente(int coef, int exp) {
        int dir = buscar_exponente(exp);
        if (dir != -1) {
            int dirCoef = ls->anterior(dir);
            ls->modifica(dirCoef, coef);
            if (coef == 0) {
                ls->suprime(dir);
                ls->suprime(dirCoef);
            }
        }
    }

    void PolinomioLista::poner_termino(int coef, int exp) {
        int direxp = buscar_exponente(exp);
        if (direxp != -1) {
            int dirCoef = ls->anterior(direxp);
            ls->modifica(dirCoef, ls->recupera((dirCoef)) + coef);
            if (ls->recupera(dirCoef) == 0) {
                ls->suprime(direxp);
                ls->suprime(dirCoef);
            }
        } else {
            if (coef != 0) {
                ls->inserta_ultimo(exp);
                ls->inserta(ls->fin(), coef);
            }
        }
    }

    int PolinomioLista::numero_terminos() {
        return ls->_longitud() / 2;
    }

    void PolinomioLista::poner_en_cero() {
        int p = ls->primero();
        while (ls->_longitud()) {
            ls->suprime(p);
            p = ls->siguiente(p);
        }
    }

    void PolinomioLista::sumar(PolinomioLista* p1, PolinomioLista* p2) {
        poner_en_cero();
        int ex, co;
        for (int i = 0; i <= numero_terminos(); i++) {
            ex = p1->exponente(i);
            co = p1->coeficiente(ex);
            poner_termino(co, ex);
        }
        for (int i = 0; i <= numero_terminos(); i++) {
            ex = p2->exponente(i);
            co = p2->coeficiente(ex);
            poner_termino(co, ex);
        }
    }

    void PolinomioLista::restar(PolinomioLista* p1, PolinomioLista* p2) {
        poner_en_cero();
        int ex, co;
        for (int i = 0; i <= numero_terminos(); i++) {
            ex = p1->exponente(i);
            co = p1->coeficiente(ex);
            poner_termino(co, ex);
        }
        for (int i = 0; i <= numero_terminos(); i++) {
            ex = p2->exponente(i);
            co = p2->coeficiente(ex) * -1;
            poner_termino(co, ex);
        }
    }

    void PolinomioLista::multiplicar(PolinomioLista* p1, PolinomioLista* p2) {}

    int PolinomioLista::evaludar(int x) {
        int resultado = 0;
        for (int i = 1; i <= numero_terminos(); i++) {
            int exp = exponente(i);
            int coef = coeficiente(exp);

            // Evaluamos el término y lo sumamos al resultado
            resultado += coef * pow(x, exp);
        }
        return resultado;
    }

    PolinomioLista::~PolinomioLista() {
        delete ls;
        delete mem;
    }

}  // namespace UPolinomioLista