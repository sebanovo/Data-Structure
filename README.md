# Memoria

Es un simulador de memoria que empieza desde 0 hasta MAX - 1

```cpp
struct NodoM {
    int dato = 0;
    string id;
    int link;

    NodoM();
};

class CSMemoria {
   private:
    const int MAX = 11;
    int libre;
    NodoM *mem;

   public:
    CSMemoria();
    // importantes
    int new_espacio(string cad);
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
    bool hayAlmenosUnId(string cadena);
    bool hayUnIdRepetido(string cadena);
    // bool hayUnIdRepetidoEnLaMemoria(string cadena);
    string eliminarflecha(string cadena);
};
```

# Lista Vector 

Es un vector sin mas que empieza en la posicion 1 hasta la n

```cpp
ListaV(); // bien
direccion fin(); //bien
direccion primero(); //bien
direccion siguiente(direccion dir); //bien
direccion anterior(direccion dir); //bien
bool vacia(); //bien
int recupera(direccion dir);//bien
int longuitud(); //bien
void inserta(direccion dir, int element); //bien
void inserta_primero(int element); //bien
void inserta_ultimo(int element); //bien
void suprime(direccion dir); //bien
void modifica(direccion dir, int element); //bien
void mostrar(); //bien
```

# Lista Puntero 

Es una lista enlazada de toda la vida con punteros
```cpp
ListaP(); //  bien 
direccionP fin(); // bien
direccionP primero(); // bien
direccionP siguiente(direccionP dir); // bien
direccionP anterior(direccionP dir); // bien
bool vacia(); // bien
int recupera(direccionP dir); //Saca elemento del nodo dir
int longuitud(); // bien
void inserta(direccionP dir, int element); // bien
void inserta_primero(int element); // bien
void inserta_ultimo(int element); // bien
void suprime(direccionP dir); // bien 
void modifica(direccionP dir, int element); // bien
string mostrar(); // bien
bool esDireccionValida(); // bien


bool esDireccionValida(direccionP dir);
```

# Lista simulador de memoria (SM)

Algoritmos usando el simulador de memori y listas enlazadas

```cpp
const string datoL = "elemento,sig";
const string elementL = "->elemento";
const string sigL = "->sig";

class ListaSM {
   private:
    int PtrElementos;
    int longitud;
    CSMemoria* mem;

   public:
    ListaSM();
    int fin();
    int primero();
    int siguiente(int dir);
    int anterior(int dir);
    bool vacia();
    int recupera(int dir);
    int longuitud();
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

    bool esDireccionValida(int dir);
};
```