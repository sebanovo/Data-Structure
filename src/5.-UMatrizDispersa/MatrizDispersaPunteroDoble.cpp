// ---------------------------------------------------------------------------

#pragma hdrstop

#include <sstream>
#include "MatrizDispersaPunteroDoble.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UMatrizDispersaPunteroDoble {

    MatrizDispersaPunteroDoble::MatrizDispersaPunteroDoble() {
        PtrFil = nullptr;
        df = dc = repe = 0;
        nt = 0;
    }

    void MatrizDispersaPunteroDoble::dimensionar(int f, int c) {
        df = f;
        dc = c;
    }

    int MatrizDispersaPunteroDoble::dimension_fila() {
        return df;
    }

    int MatrizDispersaPunteroDoble::dimension_columna() {
        return dc;
    }

    NodoColumna* MatrizDispersaPunteroDoble::buscar(int f, int c) {
        NodoFila* auxf = PtrFil;
        while (auxf != nullptr) {
            if (auxf->fil == f) {
                NodoColumna* auxc = auxf->PtrCol;
                while (auxc != nullptr) {
                    if (auxc->col == c)
                        return auxc;
                    auxc = auxc->sigC;
                }
                return nullptr;
            }
            auxf = auxf->sigF;
        }
        return nullptr;
    }

    NodoFila* MatrizDispersaPunteroDoble::buscar(int f) {
        NodoFila* auxf = PtrFil;
        while (auxf != nullptr) {
            if (auxf->fil == f)
                return auxf;
            auxf = auxf->sigF;
        }
        return nullptr;
    }

    NodoFila* MatrizDispersaPunteroDoble::posicionIns(int f) {
        NodoFila* aux = PtrFil;
        while (aux != nullptr) {
            if (f < aux->fil)
                return aux;
            aux = aux->sigF;
        }
        return nullptr;
    }

    void MatrizDispersaPunteroDoble::suprimir(NodoFila* dirFil, NodoColumna* dirCol) {
        if (dirCol == dirFil->PtrCol)
            dirFil->PtrCol = dirFil->PtrCol->sigC;
        else {
            NodoColumna* ant;
            // Codido de anterior
            NodoColumna* x = dirFil->PtrCol;
            ant = nullptr;
            while (x != nullptr) {
                if (x == dirCol)
                    break;
                ant = x;
                x = x->sigC;
            }

            ant->sigC = dirCol->sigC;
        }
        delete dirCol;
        nt--;
        if (dirFil->PtrCol == nullptr) {
            suprimir(dirFil);
        }
    }

    void MatrizDispersaPunteroDoble::suprimir(NodoFila* dir) {
        if (dir == PtrFil) {
            PtrFil = PtrFil->sigF;
        } else {
            NodoFila* ant = dir->antF;
            NodoFila* sig = dir->sigF;
            ant->sigF = sig;
            if (sig != nullptr)
                sig->antF = ant;
        }
        delete (dir);
    }

    void MatrizDispersaPunteroDoble::insertar(int f, int c, int v) {
        NodoColumna* x = new NodoColumna;
        if (x != nullptr) {
            x->col = c;
            x->dato = v;
            x->sigC = nullptr;
            NodoFila* dirFila = buscar(f);  // Buscamos si ya existe la fila
            if (dirFila != nullptr) {       // Ya existe la fila, insertamos el nodo de columna
                x->sigC = dirFila->PtrCol;
                dirFila->PtrCol = x;
            } else {  // Insercion nueva, hay dos casos
                NodoFila* xf = new NodoFila;
                if (xf != nullptr) {
                    xf->fil = f;
                    xf->antF = nullptr;
                    xf->sigF = nullptr;
                    xf->PtrCol = nullptr;
                    NodoFila* posF = posicionIns(f);
                    if (posF == nullptr) {      // No  hay datos en los nodos o se tendra q insertar al final
                        if (PtrFil == nullptr)  // No hay datos
                            PtrFil = xf;
                        else {  // Insercion a lo ultimo
                            NodoFila* fin = PtrFil;
                            while (fin->sigF != nullptr)
                                fin = fin->sigF;
                            xf->antF = fin;
                            fin->sigF = xf;
                        }
                    } else {                   // Se inserta en el primero, o algun nodo que no sea al final
                        if (posF == PtrFil) {  // Inserta al inicio
                            xf->sigF = PtrFil;
                            PtrFil->antF = xf;
                            PtrFil = xf;
                        } else {  // Insercion por el medio
                            NodoFila* ant = posF->antF;
                            NodoFila* sig = posF;
                            xf->sigF = sig;
                            xf->antF = ant;
                            ant->sigF = xf;
                            sig->antF = xf;
                        }
                    }
                    x->sigC = xf->PtrCol;
                    xf->PtrCol = x;
                }
            }
            nt++;
        } else
            throw std::runtime_error("No hay espacio en la memoria");
    }

    void MatrizDispersaPunteroDoble::poner(int f, int c, int elemento) {
        if ((f < 1 || f > df) || (c < 1 || c > dc)) throw std::runtime_error("Indices fuera de rango!!");
        NodoColumna* dir = buscar(f, c);
        if (dir != nullptr) {
            dir->dato = elemento;
            // Analizar si valor == repe
            if (elemento == repe) {
                NodoFila* dirFila = buscar(f);
                suprimir(dirFila, dir);
            }
        } else if (elemento != repe)  // Insercion nueva
            insertar(f, c, elemento);
    }

    int MatrizDispersaPunteroDoble::elemento(int f, int c) {
        if ((f < 1 || f > df) || (c < 1 || c > dc)) throw std::runtime_error("Indices fuera de rango!!");
        NodoColumna* dir = buscar(f, c);
        if (dir != nullptr)
            return dir->dato;
        else
            return repe;
    }

    void MatrizDispersaPunteroDoble::definir_valor_repetido(int elemento) {
        bool hayRepe = false;
        NodoFila* auxF = PtrFil;
        while (auxF != nullptr && hayRepe == false) {
            NodoColumna* auxC = auxF->PtrCol;
            while (auxC != nullptr && hayRepe == false) {
                if (auxC->dato == elemento)
                    hayRepe = true;
                auxC = auxC->sigC;
            }
            auxF = auxF->sigF;
        }
        if (PtrFil == nullptr || hayRepe == false) {
            repe = elemento;
        } else {
            int nRep = elemento;
            int aRep = repe;
            for (int i = 1; i <= df; i++) {
                for (int j = 1; j <= dc; j++) {
                    int e = this->elemento(i, j);
                    if (e == nRep) {
                        NodoFila* dirF = buscar(i);
                        NodoColumna* dirC = buscar(i, j);
                        suprimir(dirF, dirC);
                    } else if (e == aRep)
                        insertar(i, j, aRep);
                }
            }
            repe = elemento;
        }
    }

    std::string MatrizDispersaPunteroDoble::mostrar() {
        std::string s = "";
        for (int i = 1; i <= df; i++) {
            for (int j = 1; j <= dc; j++) {
                s += std::to_string(elemento(i, j)) + "\t";
            }
            s += "\r\n";
        }

        std::stringstream info;
        info << "\n-----------------------------------\n";
        info << "nt = " << std::to_string(nt) << "\n";
        info << "df = " << std::to_string(df) << "\n";
        info << "dc = " << std::to_string(dc) << "\n";
        info << "repe = " << std::to_string(repe) << "\n";
        return s + info.str();
    }

    int suma(MatrizDispersaPunteroDoble* m) {
        int suma = 0;
        for (int f = 1; f <= m->dimension_fila(); f++) {
            for (int c = 1; c <= m->dimension_columna(); c++) {
                suma += m->elemento(f, c);
            }
        }
        return suma;
    }
}  // namespace UMatrizDispersaPunteroDoble