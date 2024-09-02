//---------------------------------------------------------------------------

#pragma hdrstop

#include "PolinomioVector.h"

#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UPolinomioVector {
    using std::to_string;
    PolinomioVector::PolinomioVector() {
        nt = 0;
        vc = new int[MAX];
        ve = new int[MAX];
    }

    // verifica si no hay terminos
    bool PolinomioVector::es_cero() {
        return nt == 0;
    }

    // obtiene el grado del polinomio
    int PolinomioVector::grado() {
        if (nt <= 0)
            throw std::runtime_error("No existen terminos");
        int max = ve[1];
        for (int i = 1; i <= nt; i++) {
            if (ve[i] > max)
                max = ve[i];
        }
        return max;
    }

    // devuelve el coeficiente asociado a ese exponente
    int PolinomioVector::coeficiente(int exp) {
        for (int i = 1; i <= nt; i++) {
            if (ve[i] == exp)
                return vc[i];
        }
        return 0;
    }

    void PolinomioVector::sumar(PolinomioVector p1, PolinomioVector p2) {
        for (int i = 1; i <= p1.numero_terminos(); i++) {
            int exp = p1.exponente(i);
            int coef = p1.coeficiente(exp);
            poner_termino(coef, exp);
        }
        for (int i = 1; i <= p2.numero_terminos(); i++) {
            int exp = p2.exponente(i);
            int coef = p2.coeficiente(exp);
            poner_termino(coef, exp);
        }
    }

    void PolinomioVector::restar(PolinomioVector p1, PolinomioVector p2) {
        for (int i = 1; i <= p1.numero_terminos(); i++) {
            int exp = p1.exponente(i);
            int coef = p1.coeficiente(exp);
            poner_termino(coef, exp);
        }
        for (int i = 1; i <= p2.numero_terminos(); i++) {
            int exp = p2.exponente(i);
            int coef = p2.coeficiente(exp) * -1;
            poner_termino(coef, exp);
        }
    }

    void PolinomioVector::multiplicar(PolinomioVector p1, PolinomioVector p2) {
        // P1 * P2 = (2x + 1) * (3x + 3)
    }

    // retorna la posicion del exponenete
    int PolinomioVector::buscar_exponente(int exp) {
        for (int i = 1; i <= nt; i++) {
            if (ve[i] == exp)
                return i;
        }
        return -1;
    }

    // pone un termino al polinomio
    void PolinomioVector::poner_termino(int coef, int exp) {
        // if (nt >= MAX)
        //     throw std::runtime_error("Los vectores estan llenos");
        int dir_exp = buscar_exponente(exp);
        if (dir_exp == -1) {
            if (coef != 0) {
                vc[nt + 1] = coef;
                ve[nt + 1] = exp;
                nt++;
            }
        } else {
            vc[dir_exp] = coef + vc[dir_exp];
            if (vc[dir_exp] == 0) {
                for (int i = dir_exp; i < nt; i++) {
                    vc[i] = vc[i + 1];
                    ve[i] = ve[i + 1];
                }
                nt--;
            }
        }
    }

    // devuelve el número de terminos
    int PolinomioVector::numero_terminos() {
        return nt;
    }

    // devuelvo el exponente asociado al nro de termino
    int PolinomioVector::exponente(int nroTer) {
        // if (nroTer < 0 || nroTer > MAX)
        //     std::runtime_error("Fuera de los límites");
        return ve[nroTer];
    }

    // cambia el coeficiente del termino
    void PolinomioVector::asignar_coeficiente(int coef, int exp) {
        for (int i = 1; i <= numero_terminos(); i++) {
            if (ve[i] == exp)
                vc[i] = coef;
        }
    }

    // muestra el polinomio
    string PolinomioVector::mostrar() {
        string s = "";
        for (int i = 1; i <= nt; i++) {
            s += vc[i] >= 0 && s != "" ? "+" : "";
            s += to_string(vc[i]) + "x^" + to_string(ve[i]) + "  ";
        }
        return s;
    }

    PolinomioVector::~PolinomioVector() {
        delete[] vc;
        delete[] ve;
    }

    int PolinomioVector::evaluar(int x) {
        int resultado = 0;
        for (int i = 1; i <= numero_terminos(); i++) {
            int coe = vc[i];
            int exp = ve[i];
            resultado += coe * std::pow(x, exp);
        }
        return resultado;
    }

    void derivada(PolinomioVector p, PolinomioVector p1) {
        for (int i = 1; i <= p.numero_terminos(); i++) {
            int exp = p.exponente(i);
            int co = p.coeficiente(exp);
            p1.poner_termino(co * exp, exp - 1);
        }
    }

    string mostrar_integral(PolinomioVector p) {
        string s = "";
        for (int i = 1; i <= p.numero_terminos(); i++) {
            int exp = p.exponente(i);
            int co = p.coeficiente(exp);

            s += "(" + to_string(co) + "x^" + to_string(exp + 1) + ")/" + to_string(exp + 1) + " + ";
            if (i == p.numero_terminos())
                s += "C";
        }
        return s;
    }

}  // namespace UPolinomioVector