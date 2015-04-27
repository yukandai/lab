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
    int rchars = 0, wchars=0;
    char buff[SIZE];

   

    memset(buff, 0, sizeof buff);
    rchars = read(0, buff, sizeof buff);
    wchars=process (&buff[0], rchars);
   
    if (rchars==wchars)
        printf ("Número de caracteres leídos igual a escritos=%d\n", wchars);
    return 0;
}

int process(char *input, int len)
{
    int i;

    for (i=0; i<len; i++)
    {
        *(input+i)=toupper (*(input+i));
    
    
    }

    
    return write(1, input, len);
}
