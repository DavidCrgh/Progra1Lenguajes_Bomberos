#include <stdio.h>
#include "lista.h"

struct nodo *nuevoNodo(int dato){
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
};

struct listaSimple *nuevaLista(){
    struct listaSimple *lista = malloc(sizeof(struct listaSimple));
    lista->primerNodo = NULL;
    lista->ultimoNodo = NULL;
    return lista;
};

void agregarAlFinal(int dato, struct listaSimple *lista){
    struct nodo *nuevo = nuevoNodo(dato);
    if (!lista->primerNodo){
        lista->primerNodo = nuevo;
        lista->ultimoNodo = nuevo;
    }
    else {
        lista->ultimoNodo->siguiente = nuevo;
        lista->ultimoNodo = nuevo;
    }
}

struct nodo *borrarAlFinal(struct listaSimple *lista){
    struct nodo *actual;
    struct nodo *tmp;
    if (!lista->primerNodo)
        return NULL;
    else if (!lista->primerNodo->siguiente){
        actual = lista->primerNodo;
        lista->primerNodo = NULL;
        lista->ultimoNodo = NULL;
        return actual;
    }
    else {
        actual = lista->primerNodo;
        while (actual->siguiente->siguiente)
            actual = actual->siguiente;
        tmp = lista->ultimoNodo;
        lista->ultimoNodo = actual;
        actual->siguiente = NULL;
        return tmp;
    }
}

void imprimirLista(struct listaSimple *lista){
    struct nodo *tmp = lista->primerNodo;
    while(tmp){
        printf("%d ", tmp->dato);
        tmp = tmp->siguiente;
    }
    printf("\n");
}

int buscarEnLista(int valor, struct listaSimple *lista){
    struct nodo *tmp = lista->primerNodo;
    while (tmp){
        if (tmp->dato == valor)
            return 1;
        tmp = tmp->siguiente;
    }
    return 0;
}