//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListamemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaSM::ListaSM() {
    longitud = 0;
    PtrElementos = NULO;
    mem = new CSMemoria();
}

// retorna la dirección de memoria final
int ListaSM::fin() {
    // if (vacia())
    //     cout << "ERROR: LISTA VACIA\n";
    // else {
    //     int x = PtrElementos;
    //     int PtrFin;
    //     while (x != NULO) {
    //         PtrFin = x;
    //         x = mem->obtener_dato(x, sigL);  // x->sig;
    //     }
    //     return PtrFin;
    // }
    if (vacia())
        throw std::runtime_error("Lista vacia");
    int x = PtrElementos;
    int PtrFin;
    while (x != NULO) {
        PtrFin = x;
        x = mem->obtener_dato(x, sigL);
    }
    return PtrFin;
}

// retorna la dirección de memoria de la cabeza de la lista
int ListaSM::primero() {
    // if (!vacia())
    //     return PtrElementos;
    // else
    //     cout << "ERROR: LISTA VACIA\n";
    if (vacia())
        throw std::runtime_error("La lista esta vacía");
    return PtrElementos;
}

// retorna la dirección de memoria siguiente a este
int ListaSM::siguiente(int dir) {
    // if (vacia())
    //     cout << "ERROR: LISTA VACIA\n";
    // else {
    //     if (dir == fin())
    //         cout << "ERROR: DIRECCION ERRONEA\n";
    //     else
    //         return mem->obtener_dato(dir, sigL);  // d->sig;
    // }
    if (vacia())
        throw std::runtime_error("La lista esta vacia");
    else if (!esDireccionValida(dir))
        throw std::runtime_error("Esta dirección no es valida");
    else if (dir == fin())
        throw std::runtime_error("No hay siguiente luego de esta dirección");
    return mem->obtener_dato(dir, sigL);
}

// retorna la dirección de memoria anterior a esta
int ListaSM::anterior(int dir) {
    // if (vacia())
    //     cout << "ERROR: LISTA VACIA\n";
    // else {
    //     if (dir == primero())
    //         cout << "ERROR: DIRECCION ERRONEA\n";
    //     else {
    //         int x = PtrElementos;
    //         int ant = NULO;
    //         while (x != NULO) {
    //             if (x == dir)
    //                 return ant;
    //             ant = x;
    //             x = mem->obtener_dato(x, sigL);  // x->sig;
    //         }
    //         return NULO;
    //     }
    // }
    if (vacia())
        throw std::runtime_error("La lista esta vacía");
    if (!esDireccionValida(dir))
        throw std::runtime_error("No existe esta dirección en la Lista");
    if (dir == primero())
        throw std::runtime_error("No existe la dirección anterior a esta\n");

    int x = PtrElementos;
    int ant = NULO;
    while (x != NULO) {
        if (x == dir)
            return ant;
        ant = x;
        x = mem->obtener_dato(x, sigL);
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
    //     cout << "ERROR: LISTA VACIA\n";
    // else
    //     return mem->obtener_dato(dir, elementL);  // d->elemento;
    if (vacia())
        throw std::runtime_error("La lista esta vacía\n");
    if (!esDireccionValida(dir))
        throw std::runtime_error("No existe esta dirección en la Lista");
    return mem->obtener_dato(dir, elementL);
}

// retorna la longitud
int ListaSM::longuitud() {
    return longitud;
}

// insertar un elemento en una dirección de memoria
void ListaSM::inserta(int dir, int element) {
    // int x = mem->new_espacio(
    //     datoL);  // NodoL* x = new NodoL; //creacion de un nuevo nodo es distinto a null
    // if (x != NULL) {
    //     mem->poner_dato(x, elementL, element);  // x->elemento = e;
    //     mem->poner_dato(x, sigL, NULO);         // x->sig = NULL;
    //     if (vacia()) {
    //         PtrElementos = x;
    //         longitud = 1;
    //     } else {
    //         longitud++;
    //         if (dir == primero()) {
    //             mem->poner_dato(x, sigL, dir);  // x->sig = dir;
    //             PtrElementos = x;               // variable apunta al primer elemento
    //         } else {
    //             int ant = anterior(dir);        // nodo anterior del ingresado
    //             mem->poner_dato(ant, sigL, x);  // ant->sig = x;
    //             mem->poner_dato(x, sigL, dir);  // x->sig = d;
    //         }
    //     }
    // } else {
    //     cout << "Error: No exite espacio en la memoria\n";
    // }
    int x = mem->new_espacio(datoL);
    mem->poner_dato(x, elementL, element);
    mem->poner_dato(x, sigL, NULO);

    if (x == NULO)
        throw std::runtime_error("No hay espacio en la memoria");
    if (vacia())
        PtrElementos = x;
    else if (!esDireccionValida(dir))
        std::runtime_error("La dirección no es valida");
    else if (dir == primero()) {  // caso especial
        mem->poner_dato(x, sigL, PtrElementos);
        PtrElementos = x;
    } else {
        int ant = anterior(dir);
        mem->poner_dato(x, sigL, mem->obtener_dato(ant, sigL));
        mem->poner_dato(ant, sigL, x);
    }
    longitud++;
}

// insertar un elemento al principio de la lista
void ListaSM::inserta_primero(int element) {
    // int x = mem->new_espacio(datoL);  // NodoL* x = new NodoL;
    // if (x != NULL) {
    //     mem->poner_dato(x, elementL, element);   // x->elemento = e;
    //     mem->poner_dato(x, sigL, PtrElementos);  // x->sig = ptr_elementos
    //     longitud++;
    //     PtrElementos = x;
    // } else {
    //     cout << "Error: No existe espacio en la memoria\n";
    // }
    int x = mem->new_espacio(datoL);
    mem->poner_dato(x, elementL, element);
    mem->poner_dato(x, sigL, PtrElementos);
    PtrElementos = x;
    longitud++;
}

// inserta un elemento al final de la lista
void ListaSM::inserta_ultimo(int element) {
    // int x = mem->new_espacio(datoL);  // NodoL* x = new NodoL;
    // if (x != NULO) {
    //     mem->poner_dato(x, elementL, element);  // x->elemento = e;
    //     mem->poner_dato(x, sigL, NULO);         // x->sig = NULL;
    //     if (longitud == 0) {                    // al principio
    //         PtrElementos = x;
    //     } else {
    //         mem->poner_dato(fin(), sigL, x);  // fin()->sig = x;
    //     }
    //     longitud++;
    // } else {
    //     cout << "Error: No exite espacio en la memoria\n";
    // }

    int x = mem->new_espacio(datoL);
    mem->poner_dato(x, elementL, element);
    mem->poner_dato(x, sigL, NULO);
    if (x == NULO)
        throw std::runtime_error("No hay espacio en la memoria");
    if (vacia()) {
        PtrElementos = x;
        longitud++;
        return;
    }

    mem->poner_dato(fin(), sigL, x);
    longitud++;
}

// elimina un elemento de la lista
void ListaSM::suprime(int dir) {
    // if (longitud == 0) {
    //     cout << "Error: La lista esta vacia\n";
    // } else {
    //     if (dir == PtrElementos) {  // primer nodo
    //         int x = PtrElementos;
    //         PtrElementos = mem->obtener_dato(PtrElementos, sigL);
    //         // ptr_elementos->sig;
    //         mem->delete_espacio(x);  // delete(x);
    //     } else {
    //         int ant = anterior(dir);
    //         mem->poner_dato(ant, sigL, mem->obtener_dato(dir, sigL));
    //         // ant->sig = d->sig;
    //         mem->delete_espacio(dir);  // delete(d);
    //     }
    // }
    // longitud--;
    if (vacia())
        throw std::runtime_error("La lista esta vacía");
    if (!esDireccionValida(dir))
        throw std::runtime_error("La dirección no es valida");
    if (PtrElementos == dir) {
        int temp = PtrElementos;
        PtrElementos = mem->obtener_dato(PtrElementos, sigL);
        mem->delete_espacio(temp);
        return;
    } else {
        int ant = anterior(dir);
        mem->poner_dato(ant, sigL, mem->obtener_dato(dir, sigL));
        mem->delete_espacio(dir);
    }
    longitud--;
}

// modifica el elemento de una direccion de la lista
void ListaSM::modifica(int dir, int element) {
    // if (vacia()) {
    //     cout << "Error: La lista esta vacia\n";
    // } else {
    //     mem->poner_dato(dir, elementL, element);  // d->elemento = e;//modificar elemento que tiene por otro
    // }
    if (vacia())
        throw std::runtime_error("La lista esta vacía");
    if (!esDireccionValida(dir))
        throw std::runtime_error("La dirección no es valida");
    mem->poner_dato(dir, elementL, element);
}

// muestra la lista
string ListaSM::mostrar() {
    mem->mostrar();
    string s = "[";
    int x = PtrElementos;
    while (x != NULO) {
        int el = mem->obtener_dato(x, elementL);
        s += to_string(el);
        x = mem->obtener_dato(x, sigL);
        if (x != NULO)
            s += ",";
    }
    return s + "]";
}

ListaSM::~ListaSM() {
    while (!vacia())
        suprime(primero());
}

// retorna la direccion de memoria de la primera ocurrencia del elemento
int ListaSM::localiza(int element) {
    // int aux = PtrElementos;
    // while (aux != NULO) {
    //     if (mem->obtener_dato(aux, elementL) == e)
    //         return aux;
    //     aux = mem->obtener_dato(aux, sigL);  // aux->sig;
    // }
    // return NULO;
    int x = PtrElementos;
    while (x != NULO) {
        if (mem->obtener_dato(x, elementL) == element)
            return x;
        x = mem->obtener_dato(x, sigL);
    }
    return NULO;
}

// elimina una dirección del elemento ocurrente
void ListaSM::elimina_dato(int element) {
    int x = PtrElementos;
    while (x != NULO) {
        if (mem->obtener_dato(x, elementL) == element) {
            suprime(x);
            return;
        }
        x = mem->obtener_dato(x, sigL);
    }
}

// elimina todos los nodos y elementos de la lista
void ListaSM::anula() {
    while (!vacia())
        suprime(primero());
}

// verifica que la dirección exista
bool ListaSM::esDireccionValida(int dir) {
    int x = PtrElementos;
    while (x != NULO) {
        if (x == dir)
            return true;
        x = mem->obtener_dato(x, sigL);
    }
    return false;
}