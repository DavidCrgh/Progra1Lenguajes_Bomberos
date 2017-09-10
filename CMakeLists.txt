cmake_minimum_required(VERSION 3.8)
project(Progra1Lenguajes_Bomberos)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c grafo.h lista.h manejoArchivos.h manejoArchivos.c lista.c grafo.c)
add_executable(Progra1Lenguajes_Bomberos ${SOURCE_FILES})