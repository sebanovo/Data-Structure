//---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaGenerica.h"
#include <stdexcept>

//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaGenerica
{
    template <typename T>
    ColaGenerica<T>::ColaGenerica()
    {
        fin = 0;
        ini = 1;
        v = new T[MAX];
    }

    template <typename T>
    bool ColaGenerica<T>::vacia()
    {
        return ini > fin;
    }

    template <typename T>
    void ColaGenerica<T>::poner(T e)
    {
        if (fin >= MAX) throw std::runtime_error("No hay espacio en la cola");
        v[++fin] = e;
    }

    template <typename T>
    void ColaGenerica<T>::sacar(T& e)
    {
        if (vacia()) throw std::runtime_error("No hay elementos que sacar");
        e = v[ini];
        for (int i = ini; i < fin; i++)
            v[i] = v[i + 1];
        fin--;
    }

    template <typename T>
    T ColaGenerica<T>::primero()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cola");
        return v[ini];
    }

    template <typename T>
    std::string ColaGenerica<T>::mostrar()
    {
        std::string s = "<<";
        ColaGenerica aux;
        while (!vacia())
        {
            T e;
            sacar(e);
            aux.poner(e);
            // Usamos `if constexpr` para verificar el tipo en tiempo de compilación
            if constexpr (std::is_same<T, int>::value)
            {
                s += std::to_string(e);
            }
            else if constexpr (std::is_same<T, char>::value)
            {
                s += e;
            }
            else if constexpr (std::is_same<T, std::string>::value)
            {
                s += e;
            }
            else if constexpr (std::is_same<T, bool>::value)
            {
                s += e ? "true" : "false";
            }
            else
            {
                // tipo no especificado
                s += "| Tipo no soportado |\n";
            }
            if (!vacia())
                s += ",";
        }
        while (!aux.vacia())
        {
            T e;
            aux.sacar(e);
            poner(e);
        }
        return s + "<<";
    }

    template <typename T>
    ColaGenerica<T>::~ColaGenerica()
    {
        delete[] v;
    }

    template <typename T>
    T ColaGenerica<T>::ultimo()
    {
        if (vacia()) throw std::runtime_error("No hay elementos en la cola");
        return v[fin];
    }

    template <typename T>
    void ColaGenerica<T>::poner_frente(T e)
    {
        if (fin >= MAX) throw std::runtime_error("No hay espacio en la cola");
        fin++;
        for (int i = fin; i > ini; i--)
        {
            v[i] = v[i - 1];
        }
        v[ini] = e;
    }

    template <typename T>
    void ColaGenerica<T>::sacar_final(T& e)
    {
        if (vacia()) throw std::runtime_error("No hay elementos que sacar");
        e = v[fin];
        fin--;
    }
}  // namespace UColaGenerica
// Añadir mas instancias si se lo desea
template class UColaGenerica::ColaGenerica<int>;
template class UColaGenerica::ColaGenerica<char>;
template class UColaGenerica::ColaGenerica<std::string>;
template class UColaGenerica::ColaGenerica<bool>;