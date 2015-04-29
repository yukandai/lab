/**
 * Ejercicio 2) 
 */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

#define SIZE 80

int process(char *input, int len);

int main(int argc, char **argv)
{
    char buff[SIZE];
    int nchars;

    memset(buff, 0, sizeof buff);
    while ((nchars = read(STDIN_FILENO, buff, sizeof buff)) > 0) {
        process(buff, nchars);
    }

    return 0;
}

int process(char *input, int len)
{
    int i;

    for (i = 0; i < len; i++) {
        input[i] = toupper(input[i]);
    }

#if DEBUG
    printf("%s\n", input);
#endif

    return write(STDOUT_FILENO, input, len);
}
