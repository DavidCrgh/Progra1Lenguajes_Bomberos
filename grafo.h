#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "lista.h"

struct grafo{
    int *vertices;
    int *matriz;
    int max;
    int cantidadVertices;
};

struct grafo *nuevoGrafo(int max);

void recorrer(struct grafo *grafo);

void imprimir(struct grafo *grafo);

//Básicamente recorrer los vertices, si encuentra el vértice (su identificador) retorna
//el índice donde este fue colocado, si no lo encuentra retorna -1 (para saber si agregar)
int indiceDeVertice(int valor, struct grafo *grafo);

//El int v funciona como un identificador, no corresponde a la posición en la matriz
void agregarVertice(int v, struct grafo *grafo);

//Agrega un camino dado un peso entre dos vértices a un grafo
//Verifica la existencia de ambos véritces
void agregarArista(int origen, int destino, int peso, struct grafo *grafo);

//Agrega un camino en ambas direcciones, como una arista bidireccional
void agregarAristaBidireccional(int origen, int destino, int peso, struct grafo *grafo);

//Determina si hay un camino entre dos aristas
int hayArista(int indiceOrigen, int indiceDestino, struct grafo *grafo);

void determinarCaminosAux(int indiceOrigen, int indiceDestino, struct listaSimple *lista, struct grafo *grafo);

void determinarCaminos(int verticeOrigen, int verticeDestino, struct grafo *grafo);

#endif // GRAFO_H_INCLUDED
