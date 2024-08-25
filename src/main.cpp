#include <iostream>

#include "UListaMemoria.h"
#include "UListaPuntero.h"
#include "UListaVector.h"
#include "UMemoria.h"

using namespace std;

int main() {
    CSMemoria* mem = new CSMemoria();
    mem->mostrar();
    return 0;
}
