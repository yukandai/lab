/**
 * ¿Qué valor tiene la variable "saldo" al finalizar los dos procesos?
 * Rta:
 *
 * ¿Depende del orden de ejecución?
 * Rta:
 */
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int pid;
    int saldo = 1000;
    
    pid = fork();
    if (pid == 0) {
        saldo = saldo + 100;
        return 0;
    }

    saldo = saldo - 100;

    return 0;
}

