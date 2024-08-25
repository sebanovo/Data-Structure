//---------------------------------------------------------------------------

#ifndef UListavectorH
#define UListavectorH
//---------------------------------------------------------------------------
#include <string>
using namespace std;

typedef int direccion;

class ListaV {
   private:
    static constexpr int MAX = 100;
    int elementos[MAX];
    int longitud;

   public:
    ListaV();                            //
    direccion fin();                     //
    direccion primero();                 //
    direccion siguiente(direccion dir);  //
    direccion anterior(direccion dir);   //
    bool vacia();                        //
    int recupera(direccion dir);
    int longuitud();                            //
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
#endif
