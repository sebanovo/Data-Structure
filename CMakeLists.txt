cmake_minimum_required(VERSION 3.10)
project(TDAMemoria)

include_directories(src)
include_directories(src/lib)

set(CMAKE_CXX_STANDARD 17)
set(
    SOURCES src/main.cpp
            src/1.-Memoria/UCSMemoria.cpp
            src/2.-Lista/UListaVector.cpp
            src/2.-Lista/UListaPuntero.cpp
            src/2.-Lista/UListaSM.cpp
            src/3.-Polinomio/PolinomioVector.cpp
            src/3.-Polinomio/PolinomioLista.cpp
            src/3.-Polinomio/PolinomioSM.cpp
            src/3.-Polinomio/PolinomioPuntero.cpp
)

add_executable(TDAMemoria ${SOURCES})