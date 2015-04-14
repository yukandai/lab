/* 
 * File:   main.c
 * Author: francisco
 *
 * Created on March 18, 2015, 6:07 PM
 */

// EJERCICIO 1 y 2


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 14

int main(int argc, char** argv) {

    int sample[SIZE] = {0, 9, 8, 2, 2, 2, 5, 9, 5, 0, 3, 2, 3, 7};

    int dup[SIZE][2] = {};

    int i = 0, j = 0, aux = 0, k = 0, cont = 0, unic = 0;



    printf("Array Sin ordenar y con duplicados \n");

    for (i = 0; i < SIZE; i++) {
        printf(" %d", sample[i]);
    }

    printf("\n\n");

    printf("Array Ordenado y con duplicados \n");


    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE - 1; j++) {
            if (sample[j] < sample[j + 1]) {
                aux = sample[j];
                sample[j] = sample[j + 1];
                sample[j + 1] = aux;
            }

        }
    }

    for (i = 0; i < SIZE; i++) {
        printf(" %d", sample[i]);
    }

    printf("\n\n");

    //Busco la cantidad de valores unicos

    for (j = 1; j <= SIZE; j++) {
        k = j - 1;
        if (sample[k] != sample[j]) {
            unic++;
        }
    }

    //Sabiendo la cantidad de valores únicos creo el nuevo array

    int* narray = calloc(unic, sizeof (int));

    k = 0;

    i = 0;

    //hago un for similar al anterior para cargar cada valor que sea distinto en el nuevo array
    
    for (j = 1; j <= SIZE; j++) {
        k = j - 1;
        if (sample[k] != sample[j]) {
            narray[i] = sample[k];
            i++;
        }
    }


    printf("Array Ordenado y sin duplicados \n");

    for (i = 0; i < unic; i++) {
        printf(" %d", narray[i]);

    }

    printf("\n\n");
    
    for (i = 0; i < unic; i++) {
        cont = 0;
        for (j = 0; j < SIZE; j++) {
            if(narray[i] == sample[j]) {
                cont++;
            }
        }
        dup[i][0] = narray[i];
        dup[i][1] = cont;
    }
     
    aux = 0;
    
    int aux2 = 0;
    
    i = 0;
    
    j = 0;
    
    //Ordenamos el vector de dos dimensiones que contiene los numeros y cuantas veces estan duplicados
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE - 1; j++) {
            if (dup[j][1] < dup[j+1][1]) {
                aux = dup[j][1];
                dup[j][1] = dup[j+1][1];
                dup[j+1][1] = aux;
                
                aux2 = dup[j][0];
                dup[j][0] = dup[j+1][0];
                dup[j+1][0] = aux2;
            }

        }
    }
  
    //Al estar ordenado el mayor es el primero, lo imprimimos.
    
    printf("El numero con mas repeticiones fue: %d (Repetido %d veces)", dup[0][0], dup[0][1]);
    
    printf("\n\n");
    
    realloc(0,narray);

    return 0;
}
