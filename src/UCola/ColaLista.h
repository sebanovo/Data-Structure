// ---------------------------------------------------------------------------

#ifndef ColaListaH
#define ColaListaH
// ---------------------------------------------------------------------------
#include <string>
#include "ULista/ListaSM.h"
#include "ULista/ListaVector.h"
// SOLO FUNCIONA CON SIMULADOR DE MEMORIA (SM) Y VECTOR

namespace UColaLista {
	class ColaLista
	{
	private:
		// UListaSM::ListaSM* ls;
		// UCSMemoria::CSMemoria* mem;
		UListaVector::ListaVector* ls;

	public:
		ColaLista();
		ColaLista(UCSMemoria::CSMemoria* m);
		bool vacia();
		void poner(int e);
		void sacar(int& e);
		int primero();
		std::string mostrar();

		~ColaLista();
	};
};
#endif
