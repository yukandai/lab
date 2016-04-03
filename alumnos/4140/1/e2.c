/** Remover los elementos del arreglo que no estén duplicados. */

#include <stdio.h>
#include <unistd.h>
#define SIZE 14

int main(int argc, char **argv) {
    int sample[SIZE] = {0, 9, 8, 2, 2, 2, 5, 9, 5, 0, 3, 2, 3, 7};
    int i, aux, flag=0;

    /* PRIMERO LOS ORDENO DE MENOR A MAYOR */
    while (flag == 0) {
        flag = 1;
        for (i=0; i<SIZE-1; i++) {
            if (sample[i] > sample[i+1]) {
                aux = sample[i];
                sample[i] = sample[i+1];
                sample[i+1] = aux;
                flag = 0;
            }
        }
    }

    /* AHORA REMUEVO LOS Q NO ESTEN REPETIDOS */
    for (i=0; i<SIZE; i++) {
        if (i==0 && sample[i] == sample[i+1]) {                             // primero
	    printf("%d\n", sample[i]);
        } else if (i==SIZE-1 && sample[i] == sample[i-1]) {                 // ultimo
	    printf("%d\n", sample[i]);
        } else if (sample[i] == sample[i-1] || sample[i] == sample[i+1]) {  // resto
            printf("%d\n", sample[i]);
        }
    }

    return 0;
}

