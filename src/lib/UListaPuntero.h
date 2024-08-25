//---------------------------------------------------------------------------

#ifndef UListapunteroH
#define UListapunteroH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

struct NodoL;
typedef NodoL *direccionP;

struct NodoL {
   public:
    int elemento;
    NodoL *sig;
};

class ListaP {
   private:
    direccionP PtrElementos;
    int longitud;

   public:
    ListaP();                                    //
    direccionP fin();                            //
    direccionP primero();                        //
    direccionP siguiente(direccionP dir);        //
    direccionP anterior(direccionP dir);         //
    bool vacia();                                //
    int recupera(direccionP dir);                //
    int longuitud();                             //
    void inserta(direccionP dir, int element);   //
    void inserta_primero(int element);           //
    void inserta_ultimo(int element);            //
    void suprime(direccionP dir);                //
    void modifica(direccionP dir, int element);  //
    string mostrar();                            //
    ~ListaP();                                   //

    // extra
    direccionP localiza(int element);
    void elimina_dato(int element);
    void anula();

    bool esDireccionValida(direccionP dir);
};
#endif
