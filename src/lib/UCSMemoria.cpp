//---------------------------------------------------------------------------

#pragma hdrstop

#include "UCSMemoria.h"

#include <set>
#include <sstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UCSMemoria {
    using std::cout;
    using std::set;
    using std::stringstream;
    using std::to_string;

    Nodo::Nodo() {
        dato = 0;  // necesario para mostrar la memoria
    }

    // inicializa el constructor
    CSMemoria::CSMemoria() {
        mem = new Nodo[MAX];
        for (int i = 0; i < MAX - 1; i++)
            mem[i].link = i + 1;

        mem[MAX - 1].link = NULO;
        libre = 0;
    }

    // retorna el inicio de la dirección donde se colocaron los ids
    int CSMemoria::new_espacio(string cadena) {
        if (numero_ids(cadena) > espacio_disponible())
            throw std::runtime_error("Exediste el limite del espacio disponible");
        if (cadena.empty())
            throw std::runtime_error("La cadena esta vacía");
        if (!hay_al_menos_un_id(cadena))
            throw std::runtime_error("Tiene que haber almenos un id");
        if (hay_un_id_repetido(cadena))
            throw std::runtime_error("Hay un id repetido en la cadena");

        int cant = numero_ids(cadena);
        int dir = libre;
        int d = libre;
        for (int i = 1; i < cant; i++) {
            mem[d].id = obtener_id(cadena, i);
            d = mem[d].link;
        }
        libre = mem[d].link;
        mem[d].link = NULO;
        mem[d].id = obtener_id(cadena, cant);
        return dir;
    }

    // libera un espacio de la memoria
    void CSMemoria::delete_espacio(int dir) {
        if (dir < 0 || dir > MAX - 1)
            throw std::runtime_error("Esta dirección no existe");

        int x = dir;
        while (mem[x].link != NULO)
            x = mem[x].link;
        mem[x].link = libre;
        libre = dir;
    }

    // pone un dato desde la dirección de memoria que quieras
    void CSMemoria::poner_dato(int dir, string cadena_id, int valor) {
        cadena_id = eliminar_flecha(cadena_id);
        if (dir < 0 || dir > MAX - 1)
            throw std::runtime_error("Esta dirección no es valida");
        if (cadena_id.empty())
            throw std::runtime_error("La cadena ID esta vacía");
        if (!hay_al_menos_un_id(cadena_id))
            throw std::runtime_error("Tiene que haber almenos un id");

        int z = dir;
        while (z != NULO) {
            if (mem[z].id == cadena_id) {
                mem[z].dato = valor;
                break;
            }
            z = mem[z].link;
        }
    }

    // obtiene un dato desde la dirección de memoria
    int CSMemoria::obtener_dato(int dir, string cadena_id) {
        cadena_id = eliminar_flecha(cadena_id);
        if (dir < 0 || dir > MAX - 1)
            throw std::runtime_error("Esta dirección no es valida");
        if (cadena_id.empty())
            throw std::runtime_error("La cadena ID esta vacía");
        if (!hay_al_menos_un_id(cadena_id))
            throw std::runtime_error("Tiene que haber almenos un id");

        int z = dir;
        while (z != NULO) {
            if (mem[z].id == cadena_id)
                return mem[z].dato;
            z = mem[z].link;
        }
        return NULO;
    }

    // calcula el espacio disponible
    int CSMemoria::espacio_disponible() {
        int x = libre;
        int c = 0;
        while (x != NULO) {
            c++;
            x = mem[x].link;
        }
        return c;
    }

    // calcula el espacio ocupado
    int CSMemoria::espacio_ocupado() {
        int c = MAX - espacio_disponible();
        return c;
    }

    // verifica si la dirección esta libre
    bool CSMemoria::dir_libre(int dir) {
        int x = libre;
        bool c = false;
        while (x != NULO && !c) {
            if (x == dir)
                c = true;
            x = mem[x].link;
        }
        return c;
    }

    // muestra en la consola la dirección de memoria
    void CSMemoria::mostrar() {
        string cab = "       | DIR |  DATO  |    ID    | LINK |\n";
        string lin = "       +" + string(cab.length() - 10, '-') + "+\n";
        string out = lin + cab + lin;
        int edir = 3, edat = 8, eid = 10;  // eid variable
        for (int i = 0; i < MAX; i++) {
            string ocup = !dir_libre(i) ? "ocupado" : "       ";
            int rel = edir - to_string(i).length();
            string dir = " " + string(rel, '0') + to_string(i) + " ";
            rel = edat - to_string(mem[i].dato).length();
            string dat = string(rel, ' ') + to_string(mem[i].dato);
            rel = eid - mem[i].id.length();
            string id = string(rel, ' ') + mem[i].id;
            rel = edir - to_string(mem[i].link).length();
            string lnk = "  " + string(rel, ' ') + to_string(mem[i].link) + " ";
            out += ocup + "|" + dir + "|" + dat + "|" + id + "|" + lnk + "|\n";
        }
        out += lin;
        out += "Libre = " + to_string(libre) + "\n";
        out += "Espacios libres = " + to_string(espacio_disponible()) + "\n";
        out += "Espacios ocupados = " + to_string(espacio_ocupado()) + "\n";
        cout << out;
    }

    CSMemoria::~CSMemoria() {
        delete[] mem;
    }

    // -----------------------------------------------------------------------------

    // devuelve el número de ids
    int CSMemoria::numero_ids(string ids) {
        // a,b,c,d
        // ,,,a,b,c,d,,,
        // a,,,b,,,c,,,d
        bool b = false;
        int c = 0;
        for (int i = 0; i < ids.length(); i++) {
            if (ids[i] != ',') {
                if (!b)
                    c++;
                b = true;
            } else
                b = false;
        }
        return c;
    }

    // Obtiene el id indicando el número del id que es
    string CSMemoria::obtener_id(string cadena, int n) {
        string palabra = "";
        int contador = 0;
        int i = 0;
        while ((contador < n - 1) && (i < cadena.length())) {
            if (cadena.at(i) == ',') {
                contador++;
                cadena = cadena.substr(
                    i + 1, cadena.length() - cadena.substr(0, i).length());
                i = NULO;
            }
            i++;
        }
        i = 0;
        while (cadena[i] != ',' && i < cadena.length()) {
            i++;
        }
        palabra = cadena.substr(0, i);
        return palabra;
    }

    // verifica si hay almenos un id
    bool CSMemoria::hay_al_menos_un_id(string cadena) {
        for (int i = 0; i < cadena.length(); i++) {
            if (cadena[i] != ',')
                return true;
        }
        return false;
    }

    // verifica que no se repitan ids ejem: "fono,x,y,,fono"
    bool CSMemoria::hay_un_id_repetido(string cadena) {
        set<string> idsUnicos;
        stringstream ss(cadena);
        string id;

        while (getline(ss, id, ',')) {
            if (id.empty())
                continue;
            if (idsUnicos.find(id) != idsUnicos.end())
                return true;
            idsUnicos.insert(id);
        }

        return false;
    }

    // elimina la flecha
    string CSMemoria::eliminar_flecha(string cadena) {
        int pos = 0;
        if (cadena.empty())
            return "";
        while (cadena[pos] != '-' && cadena[pos + 1] != '>') {
            pos++;
        }
        return cadena.substr(pos + 2, cadena.length() - cadena.substr(0, pos + 1).length());
    }
}  // namespace UCSMemoria