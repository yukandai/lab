/**
 * ¿Qué valor tiene la variable "saldo" al finalizar los dos procesos? 
 *
 * ¿Depende del orden de ejecución?
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


Va tener dos valores uno 900 y otro 1100.
No depende del orden ya que son distintos procesos.   

