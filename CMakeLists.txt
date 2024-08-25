cmake_minimum_required(VERSION 3.10)
project(TDAMemoria)

include_directories(src)
include_directories(src/lib)

set(CMAKE_CXX_STANDARD 17)
set(
    SOURCES src/main.cpp
            src/lib/UCSMemoria.cpp
            src/lib/UListaVector.cpp
            src/lib/UListaPuntero.cpp
            src/lib/UListaSM.cpp
)

add_executable(TDAMemoria ${SOURCES})