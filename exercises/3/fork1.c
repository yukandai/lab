/**
 * Indique y justifique la cantidad  de procesos creados en el siguiente programa. 
 *
 * ¿Cómo sería la jerarquía de los procesos creados?
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
