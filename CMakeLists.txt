cmake_minimum_required(VERSION 3.10)
project(TDA)

include_directories(src)
include_directories(src/lib)

set(CMAKE_CXX_STANDARD 17)
set(
    SOURCES src/main.cpp

            src/UCSMemoria/CSMemoria.cpp

            src/ULista/ListaVector.cpp
            src/ULista/ListaPuntero.cpp
            src/ULista/ListaSM.cpp

            src/UPolinomio/PolinomioVector.cpp
            src/UPolinomio/PolinomioLista.cpp
            src/UPolinomio/PolinomioSM.cpp
            src/UPolinomio/PolinomioPuntero.cpp

            src/UConjunto/ConjuntoVector.cpp
            src/UConjunto/ConjuntoPuntero.cpp
            src/UConjunto/ConjuntoLista.cpp
            src/UConjunto/ConjuntoSM.cpp

            src/UMatrizDispersa/MatrizDispersaVector.cpp
            src/UMatrizDispersa/MatrizDispersaCSR.cpp
            src/UMatrizDispersa/MatrizDispersaSM.cpp
            src/UMatrizDispersa/MatrizDispersaPuntero.cpp
            src/UMatrizDispersa/MatrizDispersaPunteroDoble.cpp
            src/UMatrizDispersa/MatrizDispersaSMDoble.cpp

            src/UPila/PilaVector.cpp
            src/UPila/PilaLista.cpp
            src/UPila/PilaPuntero.cpp
            src/UPila/PilaSM.cpp
            src/UPila/PilaEntero.cpp
            src/UPila/PilaCadena.cpp
            src/UPila/PilaGenerica.cpp
)

add_executable(TDA ${SOURCES})