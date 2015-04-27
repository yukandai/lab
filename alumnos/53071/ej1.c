/**
 * Ejercicio 1) Remover elementos duplicados.
 */
#include <unistd.h>
#include <stdio.h>

#define SIZE 14

int main(int argc, char **argv)
{
    int sample[SIZE] = {0, 9, 8, 2, 2, 2, 5, 9, 5, 0, 3, 2, 3, 7};
    int i;
    //int nuevo[SIZE];
    int aux;
    int j;
    //int a;
    for (i = 0; i < SIZE; i++) {
         
        	for (j=i; j < SIZE; j++) {
                		
				if (sample[i]>sample[j]){
						
						aux=sample[i];
		
						sample[i]=sample[j];
		
						sample[j]=aux;
	
						}
					}
				}

for (i=0;i<SIZE;i++)
	
	if (sample[i]!=sample[i+1])

	printf("%d\n",sample[i]);				
					
				


return 0;			
}
