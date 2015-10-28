/**
00222233557899

* Ejercicio 1) Remover elementos duplicados.
*/
#include <unistd.h>
#include <stdio.h>
#define SIZE 14
int main(int argc, char **argv)
{
int sample[SIZE] = {0, 9, 8, 2, 2, 2, 5, 9, 5, 0, 3, 2, 3, 7};
int samplec[SIZE];
int i;
int j;
int temp;
int contador=0;
for (i = 0; i < SIZE; i++) {
printf("%d", sample[i]);
// TODO ...
}
printf("\n");
//Ordenamos el vector
for(i=0; i<SIZE; i++){
			for(j=i+1; j<SIZE; j++){
						if(sample[j]<sample[i]){
						temp=sample[j];
						sample[j]=sample[i];
						sample[i]=temp;
									}
						}
			}


//mostramos vector ordenado
for(i=0;i<SIZE;i++){
printf("%d",sample[i]);
	}
printf("\n");
//mostramos elementos no repetidos (funciona solo con vectores ordenados)
for(i=0;i<SIZE;i++){
if (sample[i] != sample[i+1]){
				printf("%d\n",sample[i]);
			
				samplec[i]=sample[i];
				contador++;
			//	printf("%d\n",contador);
        			}
}
printf("\n");
//manijaa
for(i=0;i<=contador;i++){
printf("%d",samplec[i]);
        }
printf("\n");

//eliminamos elementos repetidos y lo guardamos en un nuevo vector

int sample_copia[SIZE];
int sample_final[SIZE];
int cont;
int num;
int aux=0;
for(i=0;i<SIZE;i++){
		cont=0;
		num=sample[i];
		sample_copia[i]=num;
	

		
		for(j=0;j<SIZE;j++){
					if(sample_copia[j]==num)
					cont++;
					
				}
		if(cont==1){
		sample_final[aux]=num;
		aux++;
				}	
}
//mostramos vector final con elementos no repetidos
for(i=0;i<aux;i++){
printf("%d",sample_final[i]);
        }
printf("\n");
			

return 0;
}
