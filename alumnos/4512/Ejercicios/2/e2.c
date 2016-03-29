/**
 * Ejercicio 2) Encontrar el elemento que más ocurrencias tiene.
 */
#include <unistd.h>
#include <stdio.h>

#define SIZE 14

typedef struct result {
    int key;
    int count;
} result_t;

int main(int argc, char **argv)
{
    int sample[SIZE] = {0, 9, 8, 2, 2, 2, 5, 9, 5, 0, 3, 2, 3, 7};
    int i, j;

    for (i = 0; i < SIZE; i++) {
        printf("%d\n", sample[i]);
        // TODO ...
    }

    return 0;
}

