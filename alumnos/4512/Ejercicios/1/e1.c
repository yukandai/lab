/**
 Ejercicio 1) Remover elementos duplicados.
*/
#include <unistd.h>
#include <stdio.h>
#define SIZE 14

void mostrarVector(int tamano,int * _vector){

    int i;
    printf("\nindices:\t");
    for (i = 0; i < tamano; i++) {
        printf("%d- ", i);
    }
    printf("\nvectores:\t");
    for (i = 0; i < tamano; i++) {
        printf("%d, ", _vector[i]);
    }
    printf("\n\n");
}

int main(int argc, char **argv){

    int sample[SIZE] = {0, 9, 8, 2, 2, 2, 5, 9, 5, 0, 3, 2, 3, 7};
    int i,j=0,n=0,aux,unicidad=0;
    int * vsindupl;

    printf("Vector virgen:\n");
    mostrarVector(SIZE,sample);

    //1) Ordeno vector Virgen
    //-----------------------------------------------

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE - 1; j++) {
            if (sample[j] < sample[j + 1]) {
                aux = sample[j];
                sample[j] = sample[j + 1];
                sample[j + 1] = aux;
            }
        }
    }
    //-----------------------------------------------

    printf("Vector ordenado:\n");
    mostrarVector(SIZE,sample);

    //2)Busco la cantidad de valores unicos

    //-----------------------------------------------
    for (i = 0; i < SIZE-1; i++) {
        if(sample[i] != sample[i + 1])
                unicidad++;
    }
    //-----------------------------------------------

    printf("Cantidad de Valores unicos: \n%d\n\n",unicidad);


    //3)Asigno el espacio en memoria necesario

    //-----------------------------------------------
    vsindupl = calloc(unicidad,sizeof(int));
    //-----------------------------------------------

    //4)Escribo el nuevo vector

    //-----------------------------------------------
    for (i = 0; i < SIZE-1; i++){
        if( sample[i] != sample[i+1]){
            *(vsindupl+n)=sample[i];
            n++;
        }
    }
    //este if es porque siguiendo el for de arriba el ultimo elemento se compararia con basura
    if  (sample[SIZE-1] != sample[SIZE-2] || sample[SIZE-1] !=  *(vsindupl+unicidad-1)){
        *(vsindupl+unicidad)=sample[SIZE-1];}
    //-----------------------------------------------

    printf("Vector Ordenado y sin elementos duplicados:\n");
    mostrarVector(unicidad+1,vsindupl);

    //5)Libero memoria
    //-----------------------------------------------
    realloc(0,vsindupl);
    //-----------------------------------------------

    return 0;
}
