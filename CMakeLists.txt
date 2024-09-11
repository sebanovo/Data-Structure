cmake_minimum_required(VERSION 3.10)
project(TDA)

include_directories(src)
include_directories(src/lib)

set(CMAKE_CXX_STANDARD 17)
set(
    SOURCES src/main.cpp
            src/1.-Memoria/UCSMemoria.cpp
            src/2.-Lista/UListaVector.cpp
            src/2.-Lista/UListaPuntero.cpp
            src/2.-Lista/UListaSM.cpp
            src/3.-Polinomio/UPolinomioVector.cpp
            src/3.-Polinomio/UPolinomioLista.cpp
            src/3.-Polinomio/UPolinomioSM.cpp
            src/3.-Polinomio/UPolinomioPuntero.cpp
            src/4.-Conjunto/UConjuntoVector.cpp
            src/4.-Conjunto/UConjuntoPuntero.cpp
            src/4.-Conjunto/UConjuntoLista.cpp
            src/4.-Conjunto/UConjuntoSM.cpp
)

add_executable(TDA ${SOURCES})