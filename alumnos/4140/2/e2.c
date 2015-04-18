/**
 * Ejercicio 2) Leer de standard input, modificar el input usando la función process() y
 * mostrar el resultado de la transformación por standard output.
 */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 80

int process(char *input, int len);

int main(int argc, char **argv)
{
    int nchars = 0;
    char buff[SIZE];
    void *memoria;

    memoria = memset(buff, 0, sizeof buff);
    while ((nchars = read(STDIN_FILENO, buff, sizeof buff)) > 0) {
        process(memoria, nchars);
    }

    return 0;
}

int process(char *input, int len)
{
    int i;
    for (i=0; i<len; i++) {
        if (input[i] != 32)
            input[i] = input[i] - 32;
    }

    return write(STDOUT_FILENO, input, len);
}
