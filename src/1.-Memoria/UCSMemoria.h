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
    };

    class CSMemoria {
       private:
        const int MAX = 30;
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

       private:
        // metodos auxiliares
        int numero_ids(string id);
        string obtener_id(string cadena, int n);
        bool hay_al_menos_un_id(string cadena);
        bool hay_un_id_repetido(string cadena);
        string eliminar_flecha(string cadena);
    };

}  // namespace UCSMemoria

#endif