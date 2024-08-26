# Memoria

Es un simulador de memoria que empieza desde 0 hasta MAX - 1

TODO: el eliminar_flecha no funciona

```cpp
#include <iostream>
#include <string>

namespace UCSMemoria {
    using std::string;

    const int NULO = -1;

    struct Nodo {
        int dato = 0;
        string id;
        int link;

        Nodo();
    };

    class CSMemoria {
       private:
        const int MAX = 11;
        int libre;
        Nodo *mem;

       public:
        CSMemoria();
        // importantes
        int new_espacio(string cadena);
        void delete_espacio(int dir);
        void poner_dato(int dir, string id, int valor);
        int obtener_dato(int dir, string lugar);

        // relleno
        int espacio_disponible();
        int espacio_ocupado();
        bool dir_libre(int dir);
        void mostrar();
        ~CSMemoria();

        // metodos auxiliares
        int numero_ids(string id);
        string obtener_id(string cadena, int n);
        bool hay_al_menos_un_id(string cadena);
        bool hay_un_id_repetido(string cadena);
        string eliminar_flecha(string cadena);
    };

}  // namespace UCSMemoria
```

# Lista Vector 

Es un vector sin mas que empieza en la posicion 1 hasta la n

```cpp
#include <string>

namespace UListaVector {
    using std::string;
    typedef int direccion;
    class ListaVector {
       private:
        static constexpr int MAX = 100;
        int elementos[MAX];
        int longitud;

       public:
        ListaVector();                       //
        direccion fin();                     //
        direccion primero();                 //
        direccion siguiente(direccion dir);  //
        direccion anterior(direccion dir);   //
        bool vacia();                        //
        int recupera(direccion dir);
        int _longitud();                            //
        void inserta(direccion dir, int element);   //
        void inserta_primero(int element);          //
        void inserta_ultimo(int element);           //
        void suprime(direccion dir);                //
        void modifica(direccion dir, int element);  //
        void mostrar();                             //

        // extra
        direccion localiza(int element);  //
        void elimina_dato(int element);   //
        void anula();                     //
    };
}  // namespace UListaVector
```

# Lista Puntero 

Es una lista enlazada de toda la vida con punteros
```cpp
#include <iostream>
#include <string>

namespace UListaPuntero {
    using std::runtime_error;
    using std::string;

    struct Nodo;
    typedef Nodo *direccion;
    struct Nodo {
       public:
        int elemento;
        Nodo *sig;
    };

    class ListaPuntero {
       private:
        direccion PtrElementos;
        int longitud;

       public:
        ListaPuntero();                             //
        direccion fin();                            //
        direccion primero();                        //
        direccion siguiente(direccion dir);         //
        direccion anterior(direccion dir);          //
        bool vacia();                               //
        int recupera(direccion dir);                //
        int _longitud();                            //
        void inserta(direccion dir, int element);   //
        void inserta_primero(int element);          //
        void inserta_ultimo(int element);           //
        void suprime(direccion dir);                //
        void modifica(direccion dir, int element);  //
        string mostrar();                           //
        ~ListaPuntero();                            //

        // extra
        direccion localiza(int element);
        void elimina_dato(int element);
        void anula();

        bool es_direccion_valida(direccion dir);
    };

}  // namespace UListaPuntero
```

# Lista simulador de memoria (SM)

Algoritmos usando el simulador de memori y listas enlazadas

```cpp
include <string>

#include "UCSMemoria.h"

namespace UListaSM {
    using std::string;
    const string elemento_sig = "elemento,sig";
    const string elemento = "->elemento";
    const string sig = "->sig";

    class ListaSM {
       private:
        int PtrElementos;
        int longitud;
        UCSMemoria::CSMemoria* mem;

       public:
        ListaSM();
        int fin();
        int primero();
        int siguiente(int dir);
        int anterior(int dir);
        bool vacia();
        int recupera(int dir);
        int _longitud();
        void inserta(int dir, int element);
        void inserta_primero(int element);
        void inserta_ultimo(int element);
        void suprime(int dir);
        void modifica(int dir, int element);
        string mostrar();
        ~ListaSM();

        // extra
        int localiza(int element);
        void elimina_dato(int element);
        void anula();

        bool es_direccion_valida(int dir);
    };

}  // namespace UListaSM

```