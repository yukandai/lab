/**
 * Indique y justifique la cantidad  de procesos creados en el siguiente programa.
 * Rta: Se crea un proceso al ejecutar el main, y luego 3 procesos mas (c/u de ellos mediante la instruccion 'fork()')
 *
 * ¿Cómo sería la jerarquía de los procesos creados?
 * Rta:
 */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    fork();
    fork();
    fork();
    
    printf(" [x] proceso nro %d y nro %d \n", getpid(), getppid());
    
    sleep(1);

    return 0;
}
