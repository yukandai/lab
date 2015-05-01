/**
 * Ejercicio 1) Remover elementos duplicados.
 */
#include <unistd.h>
#include <stdio.h>

#define SIZE 14

int main(int argc, char **argv)
{
    int sample[SIZE] = {0, 9, 8, 2, 2, 2, 5, 9, 5, 0, 3, 2, 3, 7};
    int arrAux[SIZE];	
    int pos;
    int i;
    int j;
    int aux;
    int bandera;
    
    i=0;
    while(i<SIZE){
        aux = sample[i];
        pos = i;
        bandera = 0;
        for(j = 0; j < SIZE; j++){
                if(aux > sample[j]){
                        pos = j;
                        bandera = 1;
                }
        }
        sample[i] = sample[pos];
        sample[pos] = aux;
        if (bandera == 0){
                i=i+1;
        }
    }

    for (i = 0; i < SIZE; i++) {
	aux = sample[i];
	bandera = 0;
	for (j = 0; j < SIZE; j++){
		if (aux == arrAux[j]){
			bandera = 1;
	  	}
	}
	if (bandera == 0 || i == 0){
	  	arrAux[i] = aux;
		printf("%d\n", aux);
	}
    }    
    return 0;
}

