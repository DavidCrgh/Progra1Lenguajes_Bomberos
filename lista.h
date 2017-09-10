#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdlib.h>

struct nodo{
    int dato;
    struct nodo *siguiente;
};

//Dado un dato, retorna la referencia a un nuevo nodo
struct nodo *nuevoNodo(int dato);

struct listaSimple{
    struct nodo *primerNodo, *ultimoNodo;
};

struct listaSimple *nuevaLista();

void agregarAlFinal(int dato, struct listaSimple *lista);

struct nodo *borrarAlFinal(struct listaSimple *lista);

void imprimirLista(struct listaSimple *lista);

int buscarEnLista(int valor, struct listaSimple *lista);

#endif // LISTA_H_INCLUDED
