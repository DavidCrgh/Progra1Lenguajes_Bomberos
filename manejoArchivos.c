//
// Created by User on 10-Sep-17.
//

#include "manejoArchivos.h"

void resolverCasos(char* pathArchivo){
    struct grafo *mapa = inicializarMapa();
    //inicializarMapa(mapa);

    FILE *archivoEntrada = fopen("C:\\Users\\User\\Desktop\\Incendios.txt", "r");
    char bufferLinea[8];
    int tuplaCalle[2] = {0,0};

    int esquinaIncendio = 0;

    while(1){
        fgets(bufferLinea, 3, archivoEntrada); //Lee primer numero del caso, la esquina del incendio.
        if(bufferLinea[0] == '0'){
            break;
        }
        esquinaIncendio = strToInt(bufferLinea);    //Convierte de STR a equivalente INT.
        fgets(bufferLinea, 3, archivoEntrada);      //Lee el \r\n (cambio de linea en Windows)

        while(1){
            fgets(bufferLinea, 8, archivoEntrada);  //Lee una linea
            strToTuplaDos(bufferLinea, tuplaCalle); //Convierte la linea a una tupla de dos numeros

            if(tuplaCalle[0] == 0 & tuplaCalle[1] == 0){
                break;
            }

            agregarAristaBidireccional(tuplaCalle[0], tuplaCalle[1], 1, mapa);
            imprimir(mapa);
        }
        determinarCaminos(1, esquinaIncendio, mapa);
        //eliminarGrafo(mapa);
        inicializarMapa(mapa);
    }







    //caracter = fgets(bufferLinea, 4, archivoEntrada);


    /*while(1){
        caracter = (fgetc(archivoEntrada));
        if(caracter == EOF)
            break;
        printf("%c", caracter);
    }*/

}

struct grafo* inicializarMapa(){
    const int numeroEsquinas = 20;

    struct grafo* mapa;

    mapa = nuevoGrafo(numeroEsquinas); //Crea nuevo grafo de 20 nodos
    for(int i = 2; i <= numeroEsquinas; i++){
        agregarVertice(i, mapa);
    }

    return mapa;
    //imprimir(mapa);
}

int contarDigitos(char* str, int i){
    int digitos = 0;
    while(1){
        if(str[i] >= 48 & str[i] <= 57) {
            digitos++;
        }else{
            break;
        }
        i++;
    }
    return digitos;
}

int strToInt(char* str){
    int digitos = contarDigitos(str, 0);
    switch (digitos){
        case 1:
            return str[0] - 48;
        case 2:
            return (str[0] - 48) * 10 + (str[1] - 48);
        default:
            return 0;
    }
}

void strToTuplaDos(char* str, int* tuplaNula){
    int digitosActuales = contarDigitos(str, 0);
    int i = digitosActuales + 1; //Pos. del segundo numero

    tuplaNula[0] = strToInt(str);
    tuplaNula[1] = strToInt(str + i); //Mueve el puntero al segundo numero del string
}