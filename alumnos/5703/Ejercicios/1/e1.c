/**
 * Ejercicio 1) Remover elementos duplicados y ordenar.
 * Autor: German Moyano
 */
#include <unistd.h>
#include <stdio.h>

#define SIZE 14

int main(int argc, char **argv){

    int sample[SIZE] = {0, 9, 8, 2, 2, 2, 5, 9, 5, 0, 3, 2, 3, 7};
    int sample2[SIZE];  
    int i,j,menor,canCont, aux = 1;

//elimino duplicados    
    sample2[0] = sample[0];
	
    for (i = 0; i < SIZE; i++) {
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

//imprimo arreglo original
    printf("\nArreglo original: [");    

    for(i = 0; i < SIZE; i++){
       printf(" %d ", sample[i]);
    }
    
    printf("]\n\n");

//imprimo arreglo sin elementos duplicados
    printf("Arreglo sin duplicados: [");	

    for(i = 0; i < aux; i++){
	   printf(" %d ", sample2[i]);
    }
	
    printf("]\n\n");

//ordeno arreglo
    for(i = 0; i < aux; i++){
	   for(j = 0; j < aux; j++){
	       if(sample2[i] < sample2[j]){
	   	       menor = sample2[i];
        	   sample2[i] = sample2[j];
        	   sample2[j] = menor;
            }   
	   }
    }

//imprimo arreglo ordenado	
    printf("Arreglo ordenado: [");	
  
    for(i = 0; i < aux; i++){
       printf(" %d ", sample2[i]);		
    }

    printf("]\n\n");

    return 0;
}
