#include <iostream>
#include <limits>

#include "1.-Memoria/UCSMemoria.h"
#include "2.-Lista/UListaPuntero.h"
#include "2.-Lista/UListaSM.h"
#include "2.-Lista/UListaVector.h"
#include "3.-Polinomio/UPolinomioLista.h"
#include "3.-Polinomio/UPolinomioPuntero.h"
#include "3.-Polinomio/UPolinomioSM.h"
#include "3.-Polinomio/UPolinomioVector.h"
#include "4.-Conjunto/UConjuntoLista.h"
#include "4.-Conjunto/UConjuntoPuntero.h"
#include "4.-Conjunto/UConjuntoSM.h"
#include "4.-Conjunto/UConjuntoVector.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void mostrarMemoria() {
    UCSMemoria::CSMemoria* mem = nullptr;
    int opcion;
    do {
        cout << "1. Crear Memoria" << endl;
        cout << "2. Pedir espacio" << endl;
        cout << "3. Liberar espacio" << endl;
        cout << "4. Poner dato" << endl;
        cout << "5. Mostrar Memoria" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Entrada no válida. Inténtalo de nuevo.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                if (mem != nullptr) {
                    delete mem;
                }
                mem = new UCSMemoria::CSMemoria();
                cout << "Memoria Creada\n";
            } break;

            case 2: {
                if (mem == nullptr) {
                    cout << "Error: Debes crear la memoria primero (opcion 1)." << endl;
                    break;
                }
                string ids;
                cout << "Ids: ";
                cin.ignore();
                getline(cin, ids);
                mem->new_espacio(ids);
            } break;

            case 3: {
                if (mem == nullptr) {
                    cout << "Error: Debes crear la memoria primero (opcion 1)." << endl;
                    break;
                }
                int dir_delete;
                cout << "Direccion a liberar: ";
                cin >> dir_delete;
                mem->delete_espacio(dir_delete);
            } break;

            case 4: {
                if (mem == nullptr) {
                    cout << "Error: Debes crear la memoria primero (opcion 1)." << endl;
                    break;
                }
                int dir;
                cout << "Direccion: ";
                cin >> dir;
                string id;
                cout << "Id: ";
                cin.ignore();
                getline(cin, id);
                int valor;
                cout << "Valor: ";
                cin >> valor;
                mem->poner_dato(dir, id, valor);
            } break;

            case 5: {
                if (mem == nullptr) {
                    cout << "Error: Debes crear la memoria primero (opcion 1)." << endl;
                    break;
                }
                mem->mostrar();
            } break;

            case 6: {
                delete mem;
                mem = nullptr;
                cout << "Saliendo...\n"
                     << endl;
            } break;

            default:
                cout << "Opción no válida. Inténtalo de nuevo.\n";
                break;
        }
    } while (opcion != 6);

    delete mem;
}

void mostrarListaV() {
    UListaVector::ListaVector v;
    v.inserta_primero(10);
    v.inserta_primero(32);
    v.inserta_primero(43);
    v.inserta_primero(3829);
    v.inserta_primero(43);
    v.inserta_primero(3829);
    v.inserta_primero(43);
    v.inserta_primero(10);
    v.inserta_primero(32);
    cout << v.mostrar() << endl;
    v.bubble_sort();
    cout << v.mostrar() << endl;
}

// [12,11,10]
// [555,12,11,10,25]
// [12,11,10,25]
// [12,11,29,25]
void mostrarListaP() {
    UListaPuntero::ListaPuntero* lista = new UListaPuntero::ListaPuntero();
    lista->inserta(lista->primero(), 11);
    lista->inserta(lista->primero(), 12);
    cout << lista->mostrar() << endl;
    lista->inserta(lista->primero(), 10);
    cout << lista->mostrar() << endl;
    lista->inserta_ultimo(50);
    lista->inserta_ultimo(50);
    lista->inserta_primero(555);
    lista->inserta_ultimo(50);
    lista->inserta_ultimo(50);
    lista->inserta_primero(555);
    lista->inserta_ultimo(50);
    lista->inserta_ultimo(50);
    lista->inserta_primero(555);
    cout << lista->mostrar() << endl;
    lista->suprime(lista->primero());
    cout << lista->mostrar() << endl;
    lista->modifica(lista->anterior(lista->fin()), 29);
    cout << lista->mostrar() << endl;
    cout << lista->siguiente(lista->primero())->elemento << endl;
    cout << lista->mostrar() << endl;
    lista->elimina_dato(555);
    cout << lista->mostrar() << endl;
    delete lista;
}

void mostrarListaSM() {
    UListaSM::ListaSM* lista = new UListaSM::ListaSM();
    lista->inserta_primero(100);
    lista->inserta_primero(100);
    lista->inserta_primero(300);
    cout << lista->mostrar() << endl;
    lista->elimina_dato(100);
    cout << lista->mostrar() << endl;

    delete lista;
}

void mostrarPolinomioVector() {
    UPolinomioVector::PolinomioVector* polinomio = new UPolinomioVector::PolinomioVector;

    std::cout << polinomio->mostrar() << std::endl;

    delete polinomio;
}

void mostrarPolinomioPuntero() {
    UPolinomioPuntero::PolinomioPuntero* polinomio = new UPolinomioPuntero::PolinomioPuntero;
    UPolinomioPuntero::PolinomioPuntero* polinomio1;
    UPolinomioPuntero::PolinomioPuntero* polinomio2;
    // P1 * P2 = (2x + 1) * (3x + 3)
    // 2x * 3x + 2x * 3 + 1 * 3x + 1 * 3;
    // 6x^2 + 9x + 3

    polinomio->restar(polinomio1, polinomio2);
    std::cout << polinomio->mostrar() << std::endl;

    delete polinomio;
}

void mostrarPolinomioLista() {
    UPolinomioLista::PolinomioLista* p1 = new UPolinomioLista::PolinomioLista;
    UPolinomioLista::PolinomioLista* p2 = new UPolinomioLista::PolinomioLista;
    UPolinomioLista::PolinomioLista* p = new UPolinomioLista::PolinomioLista;

    // std::cout << p->es_cero() << std::endl;
    // p->poner_termino(1, 2);
    // p1->poner_termino(4, 5);
    // p1->poner_termino(4, 1);
    // p2->poner_termino(10, 5);
    // p2->poner_termino(11, 2);
    // = (2x + 1) * (3x + 3)
    // = 2x * 3x + 2x * 3 + 1 * 3x + 1 * 3;
    // = 6x^2 + 9x + 3
    p1->poner_termino(2, 1);
    p1->poner_termino(1, 0);
    p2->poner_termino(3, 1);
    p2->poner_termino(3, 0);
    p->multiplicar(p1, p2);
    std::cout << p->mostrar() << std::endl;

    // int re = p->evaludar(2);
    // std::cout << p->mostrar() << std::endl;
    // std::cout << p->mostrar() << std::endl;
    // std::cout << p->es_cero() << std::endl;
}

int main() {
    // mostrarPolinomioLista();
    // UConjuntoSM ::ConjuntoSM* c = new UConjuntoSM::ConjuntoSM();
    // UConjuntoLista ::ConjuntoLista* c = new UConjuntoLista ::ConjuntoLista;
    // c->inserta(2);
    // c->inserta(4);

    // c->inserta(10);

    // std::cout << c->mostrar() << std::endl;

    // c->suprime(2);
    // std::cout << c->mostrar() << std::endl;
    // std::cout << c->muestrea() << std::endl;
    // delete c;
    UConjuntoSM ::ConjuntoSM* c;
    if (c == NULL) {
        std::cout << "entro" << std::endl;
    }
    int x = 10;
    c = new UConjuntoSM::ConjuntoSM();
    delete c;
    std::cout << "borrado" << std::endl;
    return 0;
}
