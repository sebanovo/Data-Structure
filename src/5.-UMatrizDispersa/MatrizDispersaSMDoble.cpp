// ---------------------------------------------------------------------------

#pragma hdrstop

#include <sstream>
#include "MatrizDispersaSMDoble.h"
// ---------------------------------------------------------------------------

#pragma package(smart_init)

namespace UMatrizDispersaSMDoble {
    using UCSMemoria::NULO;
    MatrizDispersaSMDoble::MatrizDispersaSMDoble() {
        mem = new UCSMemoria::CSMemoria;
        PtrFil = NULO;
        df = dc = repe = nt = 0;
    }

    MatrizDispersaSMDoble::MatrizDispersaSMDoble(UCSMemoria::CSMemoria* m) {
        mem = m;
        PtrFil = NULO;
        df = dc = repe = 0;
        nt = 0;
    }

    void MatrizDispersaSMDoble::dimensionar(int f, int c) {
        df = f;
        dc = c;
    }

    int MatrizDispersaSMDoble::dimension_fila() {
        return df;
    }

    int MatrizDispersaSMDoble::dimension_columna() {
        return dc;
    }

    int MatrizDispersaSMDoble::buscarC(int f, int c) {
        int auxf = PtrFil;
        while (auxf != NULO) {
            int auxf_fil = mem->obtener_dato(auxf, _fil);
            if (auxf_fil == f) {
                int auxc = mem->obtener_dato(auxf, _ptrCol);
                while (auxc != NULO) {
                    int auxc_col = mem->obtener_dato(auxc, _col);
                    if (auxc_col == c)
                        return auxc;
                    auxc = mem->obtener_dato(auxc, _sigC);
                }
                return NULO;
            }
            auxf = mem->obtener_dato(auxf, _sigF);
        }
        return NULO;
    }

    int MatrizDispersaSMDoble::buscarF(int f) {
        int auxf = PtrFil;
        while (auxf != NULO) {
            int auxf_fil = mem->obtener_dato(auxf, _fil);
            if (auxf_fil == f)
                return auxf;
            auxf = mem->obtener_dato(auxf, _sigF);
        }
        return NULO;
    }

    int MatrizDispersaSMDoble::posicionIns(int f) {
        int aux = PtrFil;
        while (aux != NULO) {
            int aux_fil = mem->obtener_dato(aux, _fil);
            if (f < aux_fil)
                return aux;
            aux = mem->obtener_dato(aux, _sigF);
        }
        return NULO;
    }

    void MatrizDispersaSMDoble::suprimir2(int dirFil, int dirCol) {
        int dirFil_ptrCol = mem->obtener_dato(dirFil, _ptrCol);
        if (dirCol == dirFil_ptrCol) {
            int dirFil_ptrCol_sigC = mem->obtener_dato(dirFil_ptrCol, _sigC);
            mem->poner_dato(dirFil, _ptrCol, dirFil_ptrCol_sigC);
        } else {
            int ant;
            // Codido de anterior
            int x = mem->obtener_dato(dirFil, _ptrCol);
            ant = NULO;
            while (x != NULO) {
                if (x == dirCol)
                    break;
                ant = x;
                x = mem->obtener_dato(x, _sigC);
            }
            //
            int dirCol_sigC = mem->obtener_dato(dirCol, _sigC);
            mem->poner_dato(ant, _sigC, dirCol_sigC);
        }
        mem->delete_espacio(dirCol);
        nt--;
        dirFil_ptrCol = mem->obtener_dato(dirFil, _ptrCol);
        if (dirFil_ptrCol == NULO) {
            suprimir1(dirFil);
        }
    }

    void MatrizDispersaSMDoble::suprimir1(int dir) {
        if (dir == PtrFil) {
            int ptrFil_sigF = mem->obtener_dato(PtrFil, _sigF);
            PtrFil = ptrFil_sigF;
        } else {
            int ant = mem->obtener_dato(dir, _antF);
            int sig = mem->obtener_dato(dir, _sigF);
            mem->poner_dato(ant, _sigF, sig);
            if (sig != NULO) {
                mem->poner_dato(sig, _antF, ant);
            }
        }
        mem->delete_espacio(dir);
    }

    void MatrizDispersaSMDoble::insertar(int f, int c, int v) {
        int x = mem->new_espacio(_col_dato_sigC);
        if (x != NULO) {
            mem->poner_dato(x, _col, c);
            mem->poner_dato(x, _dato, v);
            mem->poner_dato(x, _sigC, NULO);
            int dirFila = buscarF(f);  // Buscamos si ya existe la fila
            if (dirFila != NULO) {     // Ya existe la fila, insertamos el nodo de columna
                int dirFila_ptrCol = mem->obtener_dato(dirFila, _ptrCol);
                mem->poner_dato(x, _sigC, dirFila_ptrCol);
                mem->poner_dato(dirFila, _ptrCol, x);
            } else {  // Insercion nueva, hay dos casos
                int xf = mem->new_espacio(_fil_antF_sigF_ptrCol);
                if (xf != NULO) {
                    mem->poner_dato(xf, _fil, f);
                    mem->poner_dato(xf, _antF, NULO);
                    mem->poner_dato(xf, _sigF, NULO);
                    mem->poner_dato(xf, _ptrCol, NULO);
                    int posF = posicionIns(f);
                    if (posF == NULO) {      // No  hay datos en los nodos o se tendra q insertar al final
                        if (PtrFil == NULO)  // No hay datos
                            PtrFil = xf;
                        else {  // Insercion a lo ultimo
                            int fin = PtrFil;
                            int fin_sigF = mem->obtener_dato(fin, _sigF);
                            while (fin_sigF != NULO) {
                                fin_sigF = mem->obtener_dato(fin, _sigF);
                                fin = fin_sigF;
                            }
                            mem->poner_dato(xf, _antF, fin);
                            mem->poner_dato(fin, _sigF, xf);
                        }
                    } else {                   // Se inserta en el primero, o algun nodo que no sea al final
                        if (posF == PtrFil) {  // Inserta al inicio
                            mem->poner_dato(xf, _sigF, PtrFil);
                            mem->poner_dato(PtrFil, _antF, xf);
                            PtrFil = xf;
                        } else {  // Insercion por el medio
                            int ant = mem->obtener_dato(posF, _antF);
                            ;
                            int sig = posF;
                            mem->poner_dato(xf, _sigF, sig);
                            mem->poner_dato(xf, _antF, ant);
                            mem->poner_dato(ant, _sigF, xf);
                            mem->poner_dato(sig, _antF, xf);
                        }
                    }
                    int xf_ptrCol = mem->obtener_dato(xf, _ptrCol);
                    mem->poner_dato(x, _sigC, xf_ptrCol);
                    mem->poner_dato(xf, _ptrCol, x);
                }
            }
            nt++;
        } else
            cout << "ERROR NO EXISTE ESPACIO DE MEMORIA\n";
    }

    void MatrizDispersaSMDoble::poner(int f, int c, int elemento) {
        if ((f < 1 || f > df) || (c < 1 || c > dc)) throw std::runtime_error("Indices fuera de rango!!");
        int dir = buscarC(f, c);
        if (dir != NULO) {
            mem->poner_dato(dir, _dato, elemento);
            // Analizar si elemento == repe
            if (elemento == repe) {
                int dirFila = buscarF(f);
                suprimir2(dirFila, dir);
            }
        } else if (elemento != repe)  // Insercion nueva
            insertar(f, c, elemento);
    }

    int MatrizDispersaSMDoble::elemento(int f, int c) {
        if ((f < 1 || f > df) || (c < 1 || c > dc)) throw std::runtime_error("Indices fuera de rango!!");
        int dir = buscarC(f, c);
        if (dir != NULO)
            return mem->obtener_dato(dir, _dato);
        else
            return repe;
    }

    void MatrizDispersaSMDoble::definir_valor_repetido(int elemento) {
        bool hayRepe = false;
        int auxF = PtrFil;
        while (auxF != NULO && hayRepe == false) {
            int auxC = mem->obtener_dato(auxF, _ptrCol);
            while (auxC != NULO && hayRepe == false) {
                if (mem->obtener_dato(auxC, _dato) == elemento)
                    hayRepe = true;
                auxC = mem->obtener_dato(auxC, _sigC);
            }
            auxF = mem->obtener_dato(auxF, _sigF);
        }
        if (PtrFil == NULO || hayRepe == false) {
            repe = elemento;
        } else {
            int nRep = elemento;
            int aRep = repe;
            for (int i = 1; i <= df; i++) {
                for (int j = 1; j <= dc; j++) {
                    int e = this->elemento(i, j);
                    if (e == nRep) {
                        int dirF = buscarF(i);
                        int dirC = buscarC(i, j);
                        suprimir2(dirF, dirC);
                    } else if (e == aRep)
                        insertar(i, j, aRep);
                }
            }
            repe = elemento;
        }
    }

    string MatrizDispersaSMDoble::mostrar() {
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

    int suma(MatrizDispersaSMDoble* m) {
        int suma = 0;
        for (int f = 1; f <= m->dimension_fila(); f++) {
            for (int c = 1; c <= m->dimension_columna(); c++) {
                suma += m->elemento(f, c);
            }
        }
        return suma;
    }
}  // namespace UMatrizDispersaSMDoble