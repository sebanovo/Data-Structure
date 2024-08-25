//---------------------------------------------------------------------------

#ifndef UMemoriaH
#define UMemoriaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int NULO = -1;

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
#endif