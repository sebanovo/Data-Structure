cmake_minimum_required(VERSION 3.10)
project(TDA)

include_directories(src)
include_directories(src/lib)

set(CMAKE_CXX_STANDARD 17)
set(
    SOURCES src/main.cpp
            src/1.-UCSMemoria/CSMemoria.cpp
            src/2.-ULista/ListaVector.cpp
            src/2.-ULista/ListaPuntero.cpp
            src/2.-ULista/ListaSM.cpp
            src/3.-UPolinomio/PolinomioVector.cpp
            src/3.-UPolinomio/PolinomioLista.cpp
            src/3.-UPolinomio/PolinomioSM.cpp
            src/3.-UPolinomio/PolinomioPuntero.cpp
            src/4.-UConjunto/ConjuntoVector.cpp
            src/4.-UConjunto/ConjuntoPuntero.cpp
            src/4.-UConjunto/ConjuntoLista.cpp
            src/4.-UConjunto/ConjuntoSM.cpp
)

add_executable(TDA ${SOURCES})