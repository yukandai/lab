/*
 * ¿Qué valor tiene la variable "saldo" al finalizar los dos procesos? 
 * Al crear el proceso hijo, el proceso hijo va a sumarle 100 a la variable "saldo" por lo tanto para ese proceso la variable va a tener el valor de 1100, en cambio en el proceso padre la variable va a tener el valor de 1100. Son dos procesos corriendo en paralelo con SU variable saldo.
 * ¿Depende del orden de ejecución?
 * No depende del orden de ejecución, ya que fork crea proceso hijo que funcionan en paralelo. Osea que ese proceso hijo contiene las mismas variables del padre (copia), siendo asi un proceso completamente aparte realizando sus modificaciones.  
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
	printf("%d saldo del hijo\n",saldo);
        return 0;
    }

    saldo = saldo - 100;
	printf("%d saldo del padre\n",saldo);
    return 0;
}

