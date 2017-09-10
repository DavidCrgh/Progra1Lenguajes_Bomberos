#ifndef PROGRA1LENGUAJES_BOMBEROS_MANEJOARCHIVOS_H
#define PROGRA1LENGUAJES_BOMBEROS_MANEJOARCHIVOS_H

#include <stdio.h>
#include "grafo.h"


void resolverCasos(char* pathArchivo);

struct grafo* inicializarMapa();

//Cuenta cuantos digitos hay a partir de i
int contarDigitos(char* str, int i);

int strToInt(char* str);

void strToTuplaDos(char* str, int* tuplaNula);

#endif //PROGRA1LENGUAJES_BOMBEROS_MANEJOARCHIVOS_H
