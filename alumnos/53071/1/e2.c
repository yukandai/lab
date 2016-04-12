#include <unistd.h>
#include <stdio.h>
#define SIZE 14

int main(int argc, char **argv)
{
    int sample[SIZE] = {0, 9, 8, 2, 2, 2, 5, 9, 5, 0, 3, 2, 3, 7};    
    int i;
    int j; //contador de pasadas
    int pasada; //contador de pasadas
    int almacena; //ubicacion temporal para intercambiar los elementos  
    printf("Arreglo Desordenado\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d\n", sample[i]);
        // TODO ...
    }
    for (pasada=1; pasada < SIZE; pasada++){ //ciclo para controlar el numero de pasadas
        for (j=0; j < SIZE; j++) { //ciclo para controlar el mumero de comparaciones por pasada
            if (sample[j] > sample[j+1]){
                almacena = sample[j];
                sample[j] = sample[j+1];
                sample[j+1] = almacena;
            }
        }
    }

    printf("Arreglo Ordenado y elementos no duplicados removidos\n");
    for (j = 0; j < SIZE; j++) {
        if (sample[j]==sample[j+1])
            printf("%d\n", sample[j]);
        // TODO ... 
    } 

    return 0;
}

