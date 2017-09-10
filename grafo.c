#include <stdio.h>
#include "grafo.h"

struct grafo *nuevoGrafo(int max){
    struct grafo *nuevo = malloc(sizeof(struct grafo));
    nuevo->max = max;
    nuevo->cantidadVertices = 0;
    nuevo->vertices = calloc(nuevo->max, sizeof(int));
    nuevo->matriz = calloc(nuevo->max * nuevo->max, sizeof(int));
    return nuevo;
};

void recorrer(struct grafo *grafo){
    int i, j;
    for (i = 0; i < grafo->max; i++){
        for (j = 0; j < grafo->max; j++){
            printf("%d\n" , *(grafo->matriz + j));
        }
    }
}

void imprimir(struct grafo *grafo){
    int i, j;
    printf("\t");
    for (i = 0; i < grafo->cantidadVertices; i++){
        printf("%d\t", *(grafo->vertices + i));
    }
    printf("\n");
    for (i = 0; i < grafo->cantidadVertices; i++){
        printf("%d\t", *(grafo->vertices + i));
        for (j = 0; j < grafo->cantidadVertices; j++){
            printf("%d\t" , *(grafo->matriz + i * grafo->cantidadVertices + j));
        }
        printf("\n");
    }
}

//Básicamente recorrer los vertices, si encuentra el vértice (su identificador) retorna
//el índice donde este fue colocado, si no lo encuentra retorna -1 (para saber si agregar)
int indiceDeVertice(int valor, struct grafo *grafo){
    int i;
    for (i = 0; i < grafo->cantidadVertices; i++){
        if (*(grafo->vertices + i) == valor)
            return i;
    }
    return -1;
}

//El int v funciona como un identificador, no corresponde a la posición en la matriz
void agregarVertice(int v, struct grafo *grafo){
    if (grafo->cantidadVertices < grafo->max && indiceDeVertice(v, grafo) == -1){
        *(grafo->vertices + grafo->cantidadVertices) = v;
        grafo->cantidadVertices++;
    }
}

//Agrega un camino dado un peso entre dos vértices a un grafo
//Verifica la existencia de ambos véritces
void agregarArista(int origen, int destino, int peso, struct grafo *grafo){
    int indiceOrigen, indiceDestino;
    indiceOrigen = indiceDeVertice(origen, grafo);
    indiceDestino = indiceDeVertice(destino, grafo);
    if (indiceOrigen != -1 && indiceDestino != -1){
        *(grafo->matriz + indiceOrigen * grafo->cantidadVertices + indiceDestino) = peso;
    }
}

//Agrega un camino en ambas direcciones, como una arista bidireccional
void agregarAristaBidireccional(int origen, int destino, int peso, struct grafo *grafo){
    int indiceOrigen, indiceDestino;
    indiceOrigen = indiceDeVertice(origen, grafo);
    indiceDestino = indiceDeVertice(destino, grafo);
    if (indiceOrigen != -1 && indiceDestino != -1){
        *(grafo->matriz + indiceOrigen * grafo->cantidadVertices + indiceDestino) = peso;
        *(grafo->matriz + indiceDestino * grafo->cantidadVertices + indiceOrigen) = peso;
    }
}

//Determina si hay un camino entre dos aristas
int hayArista(int indiceOrigen, int indiceDestino, struct grafo *grafo){
    if (*(grafo->matriz + indiceOrigen * grafo->cantidadVertices + indiceDestino) != 0)
        return 1;
    return 0;
}

void determinarCaminosAux(int indiceOrigen, int indiceDestino, struct listaSimple *lista, struct grafo *grafo){
    int i;
    if (indiceOrigen == indiceDestino)
        return;
    //El índice que entra al inicio de cada recursión se agrega al posible camino
    agregarAlFinal(*(grafo->vertices + indiceOrigen), lista);
    //Determino si desde mi índice actual puede llegar a mí destino
    if (hayArista(indiceOrigen, indiceDestino, grafo)){
        //Agrego el destino temporalmente para completar el camino
        agregarAlFinal(*(grafo->vertices + indiceDestino), lista);
        //Agrego a consola
        imprimirLista(lista);
        //Libero la memoria usada por el nodo
        free(borrarAlFinal(lista));
    }
    //Debo verificar todos los posibles caminos desde el vertice actual a todos los que se comuniquen con él
    for (i = 0; i < grafo->cantidadVertices; i++){
        //Si encuentro un camino a dónde ir y este no está en la cola, puedo vijar desde este nuevo camino
        if(!buscarEnLista(*(grafo->vertices + i), lista) && hayArista(indiceOrigen, i, grafo)){
            determinarCaminosAux(i, indiceDestino, lista, grafo);
        }
    }
    //Si el for se termina, no hubieron más posibles caminos a donde ir desde el actual
    free(borrarAlFinal(lista));
}

void determinarCaminos(int verticeOrigen, int verticeDestino, struct grafo *grafo){
    struct listaSimple *lista;
    //Se determinan los índices de los vertices deseados
    int indiceOrigen = indiceDeVertice(verticeOrigen, grafo);
    int indiceDestino = indiceDeVertice(verticeDestino, grafo);
    //Si los vertices existen cree la lista necesaria y llame a la función que determina los caminos
    if (indiceOrigen != -1 && indiceDestino != -1){
        lista = nuevaLista();
        determinarCaminosAux(indiceOrigen, indiceDestino, lista, grafo);
    }
    else {
        printf("Verifique la validez de los vértices");
    }
}