/**
 * Ejercicio 1) Remover elementos duplicados.
 */
#include <unistd.h>
#include <stdio.h>

#define SIZE 14

int main(int argc, char **argv)
{
	int sample[SIZE] = {0, 9, 8, 2, 2, 2, 5, 9, 5, 0, 3, 2, 3, 7};
	int destino[SIZE];
	int i, j, flag;

	for (i = 0; i < SIZE; i++) {
		flag = 0;
		for (j=0; j<SIZE; j++) {
			if (sample[i] == destino[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			destino[i] = sample[i];
			printf("%d\n", destino[i]); /* Elementos desordenados */
		}
	}

	return 0;
}

