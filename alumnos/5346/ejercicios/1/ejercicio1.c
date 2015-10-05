//Ejercicio 2) Encontrar el elemento que más ocurrencias tiene.

#include <unistd.h>
#include <stdio.h>

#define SIZE 14

typedef struct result {
    int key;
    int count;
} result_t;

int main(int argc, char **argv){
    int sample[SIZE] = {0, 9, 8, 2, 2, 2, 5, 9, 5, 0, 3, 2, 3, 7};
    int sample2[SIZE]; 
    result_t sample3[SIZE]; 
    int i, j, canCont, aux = 1, mayor, valor_mayor;

    //elimino duplicados    
    sample2[0] = sample[0];
	
    for (i = 1; i < SIZE; i++) {
    	canCont=1;
    	for(j = 0; j < SIZE; j++){
    	    if(canCont){
    	        if(sample[i] != sample2[j]){
    	          canCont = 1;
                }else{
    		      canCont = 0;	
    	        }
            }
    	}
    	
    	if(canCont){
    	    sample2[aux] = sample[i];
            aux++;
    	}
    }

    //creo arreglo de estructuras para cada valor unico del arreglo
    for (i = 0; i < aux; i++) {
		sample3[i].key = sample2[i];
		sample3[i].count = 0;      
    }
    //verifico cantidad de repeticiones de cada valor
    for(i = 0; i < aux ; i++){
    	for(j = 0; j < SIZE; j++){
    		if( sample3[i].key == sample[j]){
    			sample3[i].count++;
    		}
    	}
    }

    //encuentro el elemento que más ocurrencias tiene.
    mayor = sample3[0].key;
    valor_mayor = sample3[0].count;
    
    for(i = 1; i < aux; i++){
    	if(sample3[i].count > valor_mayor){
    		valor_mayor = sample3[i].count;
    		mayor = sample3[i].key;
    	}
    }
    
	//imprimo arreglo original
    printf("\nArreglo original: [");    
    for(i = 0; i < SIZE; i++){
       printf(" %d ", sample[i]);
    }
    printf("]\n\n");

    //imprimo resultado 
    printf("El elemento con mayor ocurrencia es: %d, que se encuentra: %d veces. \n\n", mayor, valor_mayor);

    return 0;
}

