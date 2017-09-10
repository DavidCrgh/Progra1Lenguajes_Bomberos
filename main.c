#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "manejoArchivos.h"

struct grafo *mapa;
char pathArchivo[100];
int i;

int main()
{
    printf("Ingerese el camino al archivo: \n");
    gets(pathArchivo);
    resolverCasos(pathArchivo);

    /*mapa = nuevoGrafo(20);
    agregarVertice(2, mapa);
    agregarVertice(3, mapa);
    agregarVertice(4, mapa);
    agregarVertice(5, mapa);
    agregarVertice(1, mapa);
    agregarVertice(6, mapa);
    agregarVertice(7, mapa);
    agregarVertice(8, mapa);
    agregarVertice(9, mapa);
    agregarAristaBidireccional(2, 3, 1, mapa);
    agregarAristaBidireccional(3, 4, 1, mapa);
    agregarAristaBidireccional(5, 1, 1, mapa);
    agregarAristaBidireccional(1, 6, 1, mapa);
    agregarAristaBidireccional(7, 8, 1, mapa);
    agregarAristaBidireccional(8, 9, 1, mapa);
    agregarAristaBidireccional(2, 5, 1, mapa);
    agregarAristaBidireccional(5, 7, 1, mapa);
    agregarAristaBidireccional(3, 1, 1, mapa);
    agregarAristaBidireccional(1, 8, 1, mapa);
    agregarAristaBidireccional(4, 6, 1, mapa);
    agregarAristaBidireccional(6, 9, 1, mapa);
    imprimir(mapa);
    printf("\n");
    determinarCaminos(1, 4, mapa);*/
    return 0;
}