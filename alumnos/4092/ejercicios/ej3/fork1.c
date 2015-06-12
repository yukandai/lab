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


Se crean 8 procesos. Cuando se hace la primer llamada a la funcion fork() hace un duplicado del proceso actual teniendo un proceso PADRE y otro proceso HIJO, al segundo llamado al tener dos procesos cuando se llama a la segunda funcion fork() se crean 2 procesos mas teniendo en ese momento 4 procesos y la ultima llamada a fork() crea 4 procesos mas, teniendo al final 8 procesos.

La jerarquia de ejecucion para el uso del procesador es la misma para los 8 procesos, pero para que el proceso padre finalize el programa debe esperar que primero termine el programa el proceso hijo.
