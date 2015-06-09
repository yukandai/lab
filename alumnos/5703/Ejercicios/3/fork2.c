/**
 * ¿Qué valor tiene la variable "saldo" al finalizar los dos procesos? 
 *
 * ¿Depende del orden de ejecución?
 */
#include <stdio.h>
#include <unistd.h>

int main(void){
    int pid;
    int saldo = 1000;
    
    pid = fork();
    if (pid == 0) {
        saldo = saldo + 100;
        return 0;
    }

    saldo = saldo - 100;
    
    /*
    *saldo termina con valor de 900 ya que esta modificando la variable saldo del proceso padre
	*por lo que no depende del orden de ejecución ni del tiempo de espera entre los procesos
    */

    return 0;
}

