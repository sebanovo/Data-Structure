//---------------------------------------------------------------------------

#ifndef UCSMemoriaH
#define UCSMemoriaH
//---------------------------------------------------------------------------
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
        bool hayAlmenosUnId(string cadena);
        bool hayUnIdRepetido(string cadena);
        string eliminarflecha(string cadena);
    };

}  // namespace UCSMemoria

#endif