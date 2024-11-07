// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ColaPrioridad.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UColaPrioridad {
	using UColaSM::ColaSM;
	ColaPrioridad::ColaPrioridad() {
		vc = new ColaSM*[MAXCP];
		vf = new int[MAXCP];
		for (int i = 0; i < MAXCP; i++) {
			vc[i] = new ColaSM();
			vf[i] = 1;
		}
		colaAct = 0;
		cant = 0;
	}

	ColaPrioridad::ColaPrioridad(UCSMemoria::CSMemoria* m) {
		vc = new ColaSM*[MAXCP];
		vf = new int[MAXCP];
		for (int i = 0; i < MAXCP; i++) {
			vc[i] = new ColaSM(m);
			vf[i] = 1;
		}
		colaAct = 0;
		cant = 0;
	}

	bool ColaPrioridad::vacia() {
		for (int i = 0; i < MAXCP; i++) {
			if (!vc[i]->vacia())
				return false;
		}
		return true;
	}

	int ColaPrioridad::primero() {
		if (!vacia()) {
			int ca = cant;
			int act = colaAct;
			bool saco = false;
			while (!saco) {
				if (ca == vf[act] || vc[act]->vacia()) {
					if (act == MAXCP - 1)
						act = 0;
					else
						act++;
					ca = 0;
				}
				else
					return vc[act]->primero();
			}
		}
	}

	void ColaPrioridad::poner(int e, int prioridad) {
		vc[prioridad]->poner(e);
	}

	void ColaPrioridad::asignar_frec_prioridad(int frec, int prioridad) {
		vf[prioridad] = frec;
	}

	void ColaPrioridad::sacar(int &e) {
		if (!vacia()) {
			bool saco = false;
			while (!saco) {
				if (cant == vf[colaAct] || vc[colaAct]->vacia()) {
					if (colaAct == MAXCP - 1)
						colaAct = 0;
					else
						colaAct++;
					cant = 0;
				}
				else {
					cant++;
					vc[colaAct]->sacar(e);
					saco = true;
				}
			}
		}
	}

	string ColaPrioridad::mostrar() {
		string s = "";
		for (int i = 0; i < MAXCP; i++)
			s += vc[i]->mostrar() + "\n";
		return s;
	}
};