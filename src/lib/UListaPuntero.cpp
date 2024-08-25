//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListapuntero.h"

#include <iostream>
#include <string>

#include "string.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace std;

// inicializa las variables
ListaP::ListaP() {
    longitud = 0;
    PtrElementos = nullptr;
}

// retorna la dirección de memoria final
direccionP ListaP::fin() {
    NodoL *x = PtrElementos;
    NodoL *PtrFin;
    while (x != nullptr) {
        PtrFin = x;
        x = x->sig;
    }
    return PtrFin;
}

// retorna la dirección de memoria de la cabeza de la lista
direccionP ListaP::primero() {
    return PtrElementos;
}

// retorna la dirección de memoria siguiente a este
direccionP ListaP::siguiente(direccionP dir) {
    if (vacia())
        throw std::runtime_error("La lista esta vacía\n");
    if (!esDireccionValida(dir))
        throw std::runtime_error("No existe esta dirección en la Lista");
    if (dir == fin())
        throw std::runtime_error("No existe la dirección siguiente a esta\n");

    return dir->sig;
}

// retorna la dirección de memoria anterior a esta
direccionP ListaP::anterior(direccionP dir) {
    if (vacia())
        throw std::runtime_error("La lista esta vacía\n");
    if (!esDireccionValida(dir))
        throw std::runtime_error("No existe esta dirección en la Lista");
    if (dir == primero())
        throw std::runtime_error("No existe la dirección anterior a esta\n");

    NodoL *x = PtrElementos;
    NodoL *ant;
    while (x != nullptr) {
        if (x == dir) {
            return ant;
        }
        ant = x;
        x = x->sig;
    }
    return nullptr;
}

// esta vacia?
bool ListaP::vacia() {
    return longitud == 0 || PtrElementos == nullptr;
}

// recupera el elemento de la dirección de la lista
int ListaP::recupera(direccionP dir) {
    if (vacia())
        throw std::runtime_error("La lista esta vacía\n");
    if (!esDireccionValida(dir))
        throw std::runtime_error("No existe esta dirección en la Lista");
    return dir->elemento;
}

// retorna la lontitud
int ListaP::longuitud() {
    return longitud;
}

// insertar un elemento en una dirección de memoria
void ListaP::inserta(direccionP dir, int element) {
    NodoL *x = new NodoL;
    x->elemento = element;
    x->sig = nullptr;

    if (vacia()) {
        PtrElementos = x;
    } else if (!esDireccionValida(dir))
        throw std::runtime_error("La dirección no es valida");
    else if (dir == primero()) {  // caso especial
        x->sig = PtrElementos;
        PtrElementos = x;
    } else {
        NodoL *ant = anterior(dir);
        x->sig = ant->sig;
        ant->sig = x;
    }
    longitud++;
}

// insertar un elemento al principio de la lista
void ListaP::inserta_primero(int element) {
    NodoL *x = new NodoL;
    x->elemento = element;
    x->sig = PtrElementos;
    PtrElementos = x;
    longitud++;
}

// insertar un elemento al final de la lista
void ListaP::inserta_ultimo(int element) {
    NodoL *x = new NodoL;
    x->elemento = element;
    x->sig = nullptr;

    if (vacia()) {
        PtrElementos = x;
        longitud++;
        return;
    }

    fin()->sig = x;
    longitud++;
}

// elimina un elemento
void ListaP::suprime(direccionP dir) {
    if (vacia())
        throw std::runtime_error("La lista esta vacía");
    if (!esDireccionValida(dir))
        throw std::runtime_error("La dirección no es valida");
    if (PtrElementos == dir) {
        NodoL *temp = PtrElementos;
        PtrElementos = PtrElementos->sig;
        delete temp;
        return;
    } else {
        NodoL *ant = anterior(dir);
        ant->sig = dir->sig;
        delete dir;
    }
    longitud--;
}

// modifica el elemento de una direccion de la lista
void ListaP::modifica(direccionP dir, int element) {
    if (vacia())
        throw std::runtime_error("La lista esta vacía");
    if (!esDireccionValida(dir))
        throw std::runtime_error("La dirección no es valida");
    dir->elemento = element;
}

// muestra la lista
string ListaP::mostrar() {
    string s = "[";
    direccionP x = PtrElementos;
    while (x != nullptr) {
        int numero = x->elemento;
        s += to_string(numero);
        x = x->sig;
        if (x != nullptr)
            s += ",";
    }
    return s + "]";
}

ListaP::~ListaP() {
    while (!vacia())
        suprime(primero());
}

// retorna la direccion de memoria de la primera ocurrencia del elemento
direccionP ListaP::localiza(int element) {
    NodoL *x = PtrElementos;
    while (x != nullptr) {
        if (x->elemento == element)
            return x;
        x = x->sig;
    }
    return nullptr;
}

// elimina una dirección del elemento ocurrente
void ListaP::elimina_dato(int element) {
    NodoL *x = PtrElementos;
    while (x != nullptr) {
        if (x->elemento == element) {
            suprime(x);
            return;
        }
        x = x->sig;
    }
}

// elimina todos los nodos y elementos de la lista
void ListaP::anula() {
    while (!vacia())
        suprime(primero());
}

// verifica que la dirección exista
bool ListaP::esDireccionValida(direccionP dir) {
    NodoL *x = PtrElementos;
    while (x != nullptr) {
        if (x == dir)
            return true;
        x = x->sig;
    }
    return false;
}