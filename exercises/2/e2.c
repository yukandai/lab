/**
 * Ejercicio 2) 
 */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80

int process(char *input, int len);

int main(int argc, char **argv)
{
    int nchars = 0;
    char buff[SIZE];

    // TODO ...

    memset(buff, 0, sizeof buff);
    nchars = read(STDIN_FILENO, buff, sizeof buff);

    //printf("buff: %s\n", buff);
    //printf("bytes: %d\n", nchars);

    return 0;
}

int process(char *input, int len)
{
    // TODO: convertir el input a mayúsculas (upper case)
    // ...

    return write(STDOUT_FILENO, input, len);
}
