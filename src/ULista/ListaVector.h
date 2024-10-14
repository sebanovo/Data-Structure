//---------------------------------------------------------------------------

#ifndef ListavectorH
#define ListavectorH
//---------------------------------------------------------------------------
#include <string>

namespace UListaVector {
    using std::string;
    typedef int direccion;
    class ListaVector {
       private:
        const int MAX = 100;
        int* elementos;
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
        string mostrar();
        ~ListaVector();

        // extra
        direccion localiza(int element);
        void elimina_dato(int element);
        void anula();

        // ejercicio
        void bubble_sort();
    };
}  // namespace UListaVector
#endif
