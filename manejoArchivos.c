//
// Created by User on 10-Sep-17.
//

#include "manejoArchivos.h"

void resolverCasos(char* pathArchivo){
    struct grafo *mapa = NULL;
    inicializarMapa(mapa);

    FILE *archivoEntrada = fopen(pathArchivo, "r");
    char buffer[5];
    int caracter;

    int esquinaIncendio;

    caracter = fgetc(archivoEntrada);
    esquinaIncendio = caracter - 48;
    /*while(1){
        caracter = (fgetc(archivoEntrada));
        if(caracter == EOF)
            break;
        printf("%c", caracter);
    }*/

}

void inicializarMapa(struct grafo *mapa){
    const int numeroEsquinas = 20;

    mapa = nuevoGrafo(numeroEsquinas); //Crea nuevo grafo de 20 nodos
    for(int i = 2; i <= numeroEsquinas; i++){
        agregarVertice(i, mapa);
    }

    imprimir(mapa);
}