# Memoria

Es un simulador de memoria que empieza desde 0 hasta MAX - 1

TODO: el eliminar_flecha no funciona

```cpp
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
          importantes
        int new_espacio(string cadena);
        void delete_espacio(int dir);
        void poner_dato(int dir, string id, int valor);
        int obtener_dato(int dir, string lugar);

          relleno
        int espacio_disponible();
        int espacio_ocupado();
        bool dir_libre(int dir);
        void mostrar();
        ~CSMemoria();

          metodos auxiliares
        int numero_ids(string id);
        string obtener_id(string cadena, int n);
        bool hay_al_menos_un_id(string cadena);
        bool hay_un_id_repetido(string cadena);
        string eliminar_flecha(string cadena);
    };

}    namespace UCSMemoria
```

# Lista Vector 

Es un vector sin mas que empieza en la posicion 1 hasta la n

```cpp
namespace UListaVector {
    using std::string;
    typedef int direccion;
    class ListaVector {
       private:
        const int MAX = 100;
        int* elementos[MAX];
        int longitud;

       public:
        ListaVector();                        
        direccion fin();                      
        direccion primero();                  
        direccion siguiente(direccion dir);
        direccion anterior(direccion dir);    
        bool vacia();                         
        int recupera(direccion dir);
        int _longitud();                             
        void inserta(direccion dir, int element);    
        void inserta_primero(int element);           
        void inserta_ultimo(int element);            
        void suprime(direccion dir);                 
        void modifica(direccion dir, int element);   
        void mostrar();                              
        ~ListaVector();                        

          extra
        direccion localiza(int element);   
        void elimina_dato(int element);    
        void anula();                      
    };
} // namespace UListaVector
```

# Lista Puntero 

Es una lista enlazada de toda la vida con punteros
```cpp
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
        ListaPuntero();                              
        direccion fin();                             
        direccion primero();                         
        direccion siguiente(direccion dir);          
        direccion anterior(direccion dir);           
        bool vacia();                                
        int recupera(direccion dir);                 
        int _longitud();                             
        void inserta(direccion dir, int element);    
        void inserta_primero(int element);           
        void inserta_ultimo(int element);            
        void suprime(direccion dir);                 
        void modifica(direccion dir, int element);   
        string mostrar();                            
        ~ListaPuntero();                             

          extra
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

          extra
        int localiza(int element);
        void elimina_dato(int element);
        void anula();

        bool es_direccion_valida(int dir);
    };

} // namespace UListaSM
```

# Polinomio Lista

```cpp
// POLINOMIO LISTA
// SOLO FUNCIONA PARA UNA (LISTA SM) Y (LISTA VECTOR)

namespace UPolinomioLista {
    class PolinomioLista {
       private:
        // UListaSM::ListaSM* ls;
        UCSMemoria::CSMemoria* mem;
        UListaVector::ListaVector* ls;

        int buscar_exponente(int exp);
        int buscar_termino_n(int n);

       public:
        PolinomioLista();
        PolinomioLista(UCSMemoria::CSMemoria* m);
        bool es_cero();
        int grado();
        void poner_en_cero();
        int coeficiente(int exp);
        void asignar_coeficiente(int coef, int exp);
        void poner_termino(int coef, int exp);
        int numero_terminos();
        int exponente(int nroTerm);
        void sumar(PolinomioLista* p1, PolinomioLista* p2);
        void restar(PolinomioLista* p1, PolinomioLista* p2);
        void multiplicar(PolinomioLista* P1, PolinomioLista* P2);
        int evaluar(int x);
        std::string mostrar();
        ~PolinomioLista();
    };

    void derivada(PolinomioLista* p, PolinomioLista* p1);
    std::string mostrar_integral(PolinomioLista* p);
}  // namespace UPolinomioLista
```

# Polinomio Puntero

```cpp
namespace UPolinomioPuntero {
    using std::string;
    struct Nodo;
    typedef Nodo *direccion;
    struct Nodo {
        int coef;
        int exp;
        Nodo *sig;
    };

    class PolinomioPuntero {
       private:
        direccion PtrPoli;
        int nt;
        direccion buscar_exponente(int exp);
        direccion buscar_termino_n(int n);

       public:
        PolinomioPuntero();
        bool es_cero();
        int grado();
        int coeficiente(int exp);
        void sumar(PolinomioPuntero *p1, PolinomioPuntero *p2);
        void restar(PolinomioPuntero *p1, PolinomioPuntero *p2);
        void multiplicar(PolinomioPuntero *p1, PolinomioPuntero *p2);
        void poner_termino(int coef, int exp);
        int numero_terminos();
        int exponente(int nroTer);
        void asignar_coeficiente(int coef, int exp);
        string mostrar();
        ~PolinomioPuntero();
    };
    void derivada(PolinomioPuntero *p, PolinomioPuntero *p1);
    std::string mostrar_integral(PolinomioPuntero *p);
}  // namespace UPolinomioPuntero
```

# Polinomio simulador de memoria (SM)

```cpp
namespace UPolinomioSM {
    using std::string;

    const string _coef_exp_sig = "coef,exp,sig";
    const string _coef = "->coef";
    const string _exp = "->exp";
    const string _sig = "->sig";

    class PolinomioSM {
       private:
        int PtrPoli;
        UCSMemoria::CSMemoria *mem;
        int nt;

        int buscar_exponente(int exp);
        int buscar_termino_n(int n);

       public:
        PolinomioSM();
        PolinomioSM(UCSMemoria::CSMemoria *m);
        bool es_cero();
        int grado();
        int coeficiente(int exp);
        void sumar(PolinomioSM *p1, PolinomioSM *p2);
        void restar(PolinomioSM *p1, PolinomioSM *p2);
        void multiplicar(PolinomioSM *p1, PolinomioSM *p3);
        void poner_termino(int coef, int exp);
        int numero_terminos();
        int exponente(int nroTer);
        void asignar_coeficiente(int coef, int exp);
        string mostrar();
        ~PolinomioSM();
    };
    void derivada(PolinomioSM *p, PolinomioSM *p1);
    std::string mostrar_integral(PolinomioSM *p);
}  // namespace UPolinomioSM
```

# Polinomio Vector

```cpp
namespace UPolinomioVector {
    using std::string;
    class PolinomioVector {
       private:
        const int MAX = 100;
        int *vc;
        int *ve;
        int nt;

        int buscar_exponente(int exp);
        int buscar_termino_n(int n);

       public:
        PolinomioVector();
        bool es_cero();
        int grado();
        int coeficiente(int exp);
        void sumar(PolinomioVector *p1, PolinomioVector *p2);
        void restar(PolinomioVector *p1, PolinomioVector *p2);
        void multiplicar(PolinomioVector *p1, PolinomioVector *p3);
        void poner_termino(int coef, int exp);
        int numero_terminos();
        int exponente(int nroTer);
        void asignar_coeficiente(int coef, int exp);
        string mostrar();
        ~PolinomioVector();
        int evaluar(int x);
    };
    void derivada(PolinomioVector *p, PolinomioVector *p1);
    string mostrar_integral(PolinomioVector *p);
}  // namespace UPolinomioVector
```

# Conjunto Lista 

```cpp
namespace UConjuntoLista {
    struct Nodo {
        int dato;
        Nodo* sig;
    };

    class ConjuntoLista {
       private:
        UListaVector::ListaVector* elem;
        // UListaPuntero::ListaPuntero* elem;

       public:
        ConjuntoLista();
        int cardinal();
        bool vacio();
        int ordinal(int e);
        void inserta(int e);
        void suprime(int e);
        bool pertenece(int e);
        int muestrea();
        ~ConjuntoLista();
        std::string mostrar();
    };
}  // namespace UConjuntoLista
```

# Conjunto Puntero

```cpp
namespace UConjuntoLista {
    struct Nodo {
        int dato;
        Nodo* sig;
    };

    class ConjuntoLista {
       private:
        UListaVector::ListaVector* elem;
        // UListaPuntero::ListaPuntero* elem;

       public:
        ConjuntoLista();
        int cardinal();
        bool vacio();
        int ordinal(int e);
        void inserta(int e);
        void suprime(int e);
        bool pertenece(int e);
        int muestrea();
        ~ConjuntoLista();
        std::string mostrar();
    };
}  // namespace UConjuntoLista
```

# Conjunto simulador de memoria (SM)

```cpp
namespace UConjuntoSM {
    const std::string _dato_sig = "dato,sig";
    const std::string _dato = "->dato";
    const std::string _sig = "->sig";

    class ConjuntoSM {
       private:
        UCSMemoria::CSMemoria* mem;
        int PtrConj;
        int cant;

       public:
        ConjuntoSM();
        int cardinal();
        bool vacio();
        int ordinal(int e);
        void inserta(int e);
        void suprime(int e);
        bool pertenece(int e);
        int muestrea();
        ~ConjuntoSM();
        std::string mostrar();
    };

}  // namespace UConjuntoSM
```

# Conjunto Vector 

```cpp
namespace UConjuntoVector {
    class ConjuntoVector {
       private:
        const int MAX = 100;
        bool* v;
        int cant;

       public:
        ConjuntoVector();
        int cardinal();
        bool vacio();
        int ordinal(int e);
        void inserta(int e);
        void suprime(int e);
        bool pertenece(int e);
        int muestrea();
        ~ConjuntoVector();
        std::string mostrar();
    };

}  // namespace UConjuntoVector
```
