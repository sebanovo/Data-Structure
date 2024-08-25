#include <iostream>
#include <string>

#include "UCSMemoria.h"
#include "UListaPuntero.h"
#include "UListaSM.h"
#include "UListaVector.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

// #include <limits>
// void mostrarMemoria() {
//     UCSMemoria::CSMemoria* mem = nullptr;
//     int opcion;
//     do {
//         cout << "1. Crear Memoria" << endl;
//         cout << "2. Pedir espacio" << endl;
//         cout << "3. Liberar espacio" << endl;
//         cout << "4. Poner dato" << endl;
//         cout << "5. Mostrar Memoria" << endl;
//         cout << "6. Salir" << endl;
//         cout << "Opcion: ";
//         cin >> opcion;

//         if (cin.fail()) {
//             cin.clear();
//             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//             cout << "Entrada no válida. Inténtalo de nuevo.\n";
//             continue;
//         }

//         switch (opcion) {
//             case 1: {
//                 if (mem != nullptr) {
//                     delete mem;
//                 }
//                 mem = new UCSMemoria::CSMemoria();
//                 cout << "Memoria Creada\n";
//             } break;

//             case 2: {
//                 if (mem == nullptr) {
//                     cout << "Error: Debes crear la memoria primero (opcion 1)." << endl;
//                     break;
//                 }
//                 string ids;
//                 cout << "Ids: ";
//                 cin.ignore();
//                 getline(cin, ids);
//                 mem->new_espacio(ids);
//             } break;

//             case 3: {
//                 if (mem == nullptr) {
//                     cout << "Error: Debes crear la memoria primero (opcion 1)." << endl;
//                     break;
//                 }
//                 int dir_delete;
//                 cout << "Direccion a liberar: ";
//                 cin >> dir_delete;
//                 mem->delete_espacio(dir_delete);
//             } break;

//             case 4: {
//                 if (mem == nullptr) {
//                     cout << "Error: Debes crear la memoria primero (opcion 1)." << endl;
//                     break;
//                 }
//                 int dir;
//                 cout << "Direccion: ";
//                 cin >> dir;
//                 string id;
//                 cout << "Id: ";
//                 cin.ignore();
//                 getline(cin, id);
//                 int valor;
//                 cout << "Valor: ";
//                 cin >> valor;
//                 mem->poner_dato(dir, id, valor);
//             } break;

//             case 5: {
//                 if (mem == nullptr) {
//                     cout << "Error: Debes crear la memoria primero (opcion 1)." << endl;
//                     break;
//                 }
//                 mem->mostrar();
//             } break;

//             case 6: {
//                 delete mem;
//                 mem = nullptr;
//                 cout << "Saliendo...\n"
//                      << endl;
//             } break;

//             default:
//                 cout << "Opción no válida. Inténtalo de nuevo.\n";
//                 break;
//         }
//     } while (opcion != 6);

//     delete mem;
// }

// void mostrarListaV() {
//     UListaVector::ListaVector v;
//     v.inserta_primero(10);
//     v.inserta_primero(32);
//     v.inserta_primero(43);
//     v.inserta_primero(3829);
//     v.inserta_primero(3289);
//     v.mostrar();
//     std::cout << v.fin() << std::endl;
//     std::cout << v.primero() << std::endl;
//     std::cout << v.siguiente(3) << std::endl;
//     std::cout << v.anterior(3) << std::endl;
//     std::cout << v.vacia() << std::endl;
//     std::cout << v.recupera(4) << std::endl;
//     std::cout << v._longitud() << std::endl;
//     v.mostrar();
//     v.inserta(4, 12);
//     v.mostrar();
//     v.inserta_primero(100);
//     v.mostrar();
//     v.inserta_ultimo(200);
//     v.mostrar();
//     v.suprime(1);
//     v.mostrar();
//     v.modifica(4, 1000000);
//     v.mostrar();
// }

// [12,11,10]
// [555,12,11,10,25]
// [12,11,10,25]
// [12,11,29,25]
// void mostrarListaP() {
//     UListaPuntero::ListaPuntero* lista = new UListaPuntero::ListaPuntero();
//     lista->inserta(lista->primero(), 11);
//     lista->inserta(lista->primero(), 12);
//     cout << lista->mostrar() << endl;
//     lista->inserta(lista->primero(), 10);
//     cout << lista->mostrar() << endl;
//     lista->inserta_ultimo(50);
//     lista->inserta_ultimo(25);
//     lista->inserta_primero(555);
//     cout << lista->mostrar() << endl;
//     lista->suprime(lista->primero());
//     cout << lista->mostrar() << endl;
//     lista->modifica(lista->anterior(lista->fin()), 29);
//     cout << lista->mostrar() << endl;
//     cout << lista->siguiente(lista->primero())->elemento << endl;
//     std::cout << &lista << std::endl;

//     delete lista;
// }

// void mostrarListaSM() {
//     UListaSM::ListaSM* lista = new UListaSM::ListaSM();
//     lista->inserta_primero(100);
//     lista->inserta_primero(200);
//     lista->inserta_primero(300);
//     cout << lista->mostrar() << endl;
//     lista->elimina_dato(200);
//     cout << lista->mostrar() << endl;

//     delete lista;
// }

int main() {
    cout << "pause" << endl;
    return 0;
}
