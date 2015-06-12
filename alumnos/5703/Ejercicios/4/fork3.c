/**
 * Explique el estado de los procesos hijos de este código.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *const argv[])
{
    if (fork() == 0) {
        return 0;
    }
    if (fork() == 0) {
        return 0;
    }

    printf("En otra pantalla ejecutar \"ps f\". Cualquier tecla para terminar \n");
    getchar();
    return 0;
}

/*
	Los procesos hijos estan en estado zombie o defunct, ya que los mismos
	terminaron su ejecución pero aún tienen una entrada en la tabla de procesos
	ya que sus padres no han terminado su ejecución y pueden consultar el estado
	de su salida.
	Podemos verificar esto ejecutando el comando ps y observando una Z en la 
	columna de estado de los procesos.

    Estados posibles:   
        S : sleeping
        R : running
        D : waiting
        T : gestopt (suspended)
        Z : zombie (defunct)

*/