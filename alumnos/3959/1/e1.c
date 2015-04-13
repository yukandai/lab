/**
  * Ejercicio 1) Remover elementos duplicados.
 
 @Anaquin
 * agregué--> Encontrar el elemento que más ocurrencias tiene.
 */

#include <unistd.h>
#include <stdio.h>

#define SIZE 14
#define N 10

void blank(int *ord){
   int i;
   for(i=0;i<N;i++){
    	ord[i]=0;
   }
}

void noRepetidos(int *ord){
    int i;
    printf("Los números no repetidos son:\n");
    for (i = 0; i < N; i++) {
	if(ord[i]==1){  printf(" %d \n", i);}
    }
}
void mayor(int *ord){
    int i,j=0;
    
    for (i=1;i<N;i++){
    	if(ord[i]>ord[j]){
		j=i;
	}
    }
    printf("El número con mas ocurrencia es: %d\n",j);
    
}

int main(int argc, char **argv)
{
    int sample[SIZE] = {0, 9, 8, 2, 2, 2, 5, 9, 5, 0, 3, 2, 3, 7};
    int ord[N];
    int i,val;

    blank(ord);				//Iniciar vector en 0
 
    for (i = 0; i < SIZE; i++) {	//recorremos el vector
        val=sample[i];			
	ord[val]++;			//contamos la cant. de orcurrencias del n° val 
    }    
 
   noRepetidos(ord);
   mayor(ord);
   return 0;
}

