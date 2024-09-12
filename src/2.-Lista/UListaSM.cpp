//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaSM.h"

#include <iostream>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UListaSM {
    using std::runtime_error;
    using std::string;
    using std::to_string;
    using UCSMemoria::NULO;

    ListaSM::ListaSM() {
        longitud = 0;
        PtrElementos = NULO;
        mem = new UCSMemoria::CSMemoria();
    }

    ListaSM::ListaSM(UCSMemoria::CSMemoria* m) {
        longitud = 0;
        PtrElementos = NULO;
        mem = m;
    }

    // retorna la dirección de memoria final
    int ListaSM::fin() {
        int x = PtrElementos;
        int PtrFin;
        while (x != NULO) {
            PtrFin = x;
            x = mem->obtener_dato(x, _sig);
        }
        return PtrFin;
    }

    // retorna la dirección de memoria de la cabeza de la lista
    int ListaSM::primero() {
        return PtrElementos;
    }

    // retorna la dirección de memoria siguiente a este
    int ListaSM::siguiente(int dir) {
        // if (vacia())
        //     throw std::runtime_error("La lista esta vacia");
        // else if (!es_direccion_valida(dir))
        //     throw std::runtime_error("Esta dirección no es valida");
        // else if (dir == fin())
        //     throw std::runtime_error("No hay siguiente luego de esta dirección");
        return mem->obtener_dato(dir, _sig);
    }

    // retorna la dirección de memoria anterior a esta
    int ListaSM::anterior(int dir) {
        // if (vacia())
        //     throw std::runtime_error("La lista esta vacía");
        // if (!es_direccion_valida(dir))
        //     throw std::runtime_error("No existe esta dirección en la Lista");
        // if (dir == primero())
        //     throw std::runtime_error("No existe la dirección anterior a esta\n");

        int x = PtrElementos;
        int ant = NULO;
        while (x != NULO) {
            if (x == dir)
                return ant;
            ant = x;
            x = mem->obtener_dato(x, _sig);
        }
        return NULO;
    }

    // esta vacía?
    bool ListaSM::vacia() {
        return longitud == 0 || PtrElementos == NULO;
    }

    // recupera el elemento de la dirección de memoria
    int ListaSM::recupera(int dir) {
        // if (vacia())
        //     throw std::runtime_error("La lista esta vacía\n");
        // if (!es_direccion_valida(dir))
        //     throw std::runtime_error("No existe esta dirección en la Lista");
        return mem->obtener_dato(dir, _elemento);
    }

    // retorna la longitud
    int ListaSM::_longitud() {
        return longitud;
    }

    // insertar un _elemento en una dirección de memoria
    void ListaSM::inserta(int dir, int element) {
        int x = mem->new_espacio(_elemento_sig);
        mem->poner_dato(x, _elemento, element);
        mem->poner_dato(x, _sig, NULO);

        if (vacia())
            PtrElementos = x;
        else if (dir == primero()) {  // caso especial
            mem->poner_dato(x, _sig, PtrElementos);
            PtrElementos = x;
        } else {
            int ant = anterior(dir);
            mem->poner_dato(x, _sig, mem->obtener_dato(ant, _sig));
            mem->poner_dato(ant, _sig, x);
        }
        longitud++;
    }

    // insertar un _elemento al principio de la lista
    void ListaSM::inserta_primero(int element) {
        int x = mem->new_espacio(_elemento_sig);
        mem->poner_dato(x, _elemento, element);
        mem->poner_dato(x, _sig, PtrElementos);
        PtrElementos = x;
        longitud++;
    }

    // inserta un _elemento al final de la lista
    void ListaSM::inserta_ultimo(int element) {
        int x = mem->new_espacio(_elemento_sig);
        mem->poner_dato(x, _elemento, element);
        mem->poner_dato(x, _sig, NULO);

        if (vacia()) {
            PtrElementos = x;
            longitud++;
            return;
        }

        mem->poner_dato(fin(), _sig, x);
        longitud++;
    }

    // elimina un _elemento de la lista
    void ListaSM::suprime(int dir) {
        // if (vacia())
        //     throw std::runtime_error("La lista esta vacía");
        // if (!es_direccion_valida(dir))
        //     throw std::runtime_error("La dirección no es valida");
        if (PtrElementos == dir) {
            int temp = PtrElementos;
            PtrElementos = mem->obtener_dato(PtrElementos, _sig);
            mem->delete_espacio(temp);
            // return;
        } else {
            int ant = anterior(dir);
            mem->poner_dato(ant, _sig, mem->obtener_dato(dir, _sig));
            mem->delete_espacio(dir);
        }
        longitud--;
    }

    // modifica el _elemento de una direccion de la lista
    void ListaSM::modifica(int dir, int element) {
        // if (vacia())
        //     throw std::runtime_error("La lista esta vacía");
        // if (!es_direccion_valida(dir))
        //     throw std::runtime_error("La dirección no es valida");
        mem->poner_dato(dir, _elemento, element);
    }

    // muestra la lista
    string ListaSM::mostrar() {
        // mem->mostrar();
        string s = "<";
        int x = PtrElementos;
        while (x != NULO) {
            int el = mem->obtener_dato(x, _elemento);
            s += to_string(el);
            x = mem->obtener_dato(x, _sig);
            if (x != NULO)
                s += ",";
        }
        return s + ">";
    }

    ListaSM::~ListaSM() {
        delete mem;
    }

    // retorna la direccion de memoria de la primera ocurrencia del _elemento
    int ListaSM::localiza(int element) {
        int x = PtrElementos;
        while (x != NULO) {
            if (mem->obtener_dato(x, _elemento) == element)
                return x;
            x = mem->obtener_dato(x, _sig);
        }
        return NULO;
    }

    // elimina todas las ocurrencias del _elemento
    void ListaSM::elimina_dato(int element) {
        int x = PtrElementos;
        while (x != NULO) {
            if (mem->obtener_dato(x, _elemento) == element) {
                int elim = x;
                x = mem->obtener_dato(x, _sig);
                suprime(elim);
            } else {
                x = mem->obtener_dato(x, _sig);
            }
        }
    }

    // elimina todos los nodos y elementos de la lista
    void ListaSM::anula() {
        while (!vacia())
            suprime(primero());
    }

    // verifica que la dirección exista
    bool ListaSM::es_direccion_valida(int dir) {
        int x = PtrElementos;
        while (x != NULO) {
            if (x == dir)
                return true;
            x = mem->obtener_dato(x, _sig);
        }
        return false;
    }

    // ejercicio
    void ListaSM::bubble_sort() {
        int x = PtrElementos;
        int y;
        while (x != NULO) {
            y = mem->obtener_dato(x, _sig);
            while (y != NULO) {
                if (mem->obtener_dato(x, _elemento) > mem->obtener_dato(y, _elemento)) {
                    int temp = mem->obtener_dato(x, _elemento);
                    mem->poner_dato(x, _elemento, mem->obtener_dato(y, _elemento));
                    mem->poner_dato(y, _elemento, temp);
                }
                y = mem->obtener_dato(y, _sig);
            }
            x = mem->obtener_dato(x, _sig);
        }
    }
}  // namespace UListaSM