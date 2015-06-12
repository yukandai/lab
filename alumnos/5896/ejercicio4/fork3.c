/**
 * Explique el estado de los procesos hijos de este código.
 * El proceso padre se encuentra en estado  S osea durmiendo (sleeping) y
 los dos hijos que tiene estan en estado Z, procesos zombie.
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *const argv[])
{
    if (fork() == 0) {
	printf("hola soy el hijo %d y mi parde es %d\n",getpid(), getppid());
        return 0;
    }
    if (fork() == 0) {
	printf("hola soy el hijo %d y mi parde es %d\n",getpid(), getppid());
        return 0;
    }

    printf("En otra pantalla ejecutar \"ps f\". Cualquier tecla para terminar \n");
    getchar();
    return 0;
}

