/**
 * ¿Qué valor tiene la variable "saldo" al finalizar los dos procesos? 
 * En el proceso padre 900 y en el proceso hijo 1100
 *
 * ¿Depende del orden de ejecución?
 * No depende del orden de ejecución, ya que al momento de creación del hijo se copian todas las variables
 * al nuevo proceso, siendo independientes de las modificaciones que realice el proceso padre.
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

