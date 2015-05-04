/**
 * Indique y justifique la cantidad  de procesos creados en el siguiente programa. 
 *
 * ¿Cómo sería la jerarquía de los procesos creados?
 *
 * Los procesos creados son 8.
 * El proceso Principal (11) del programa en el primer llamado a Fork() crea un proceso hijo (12) igual a él y
 * ambos siguen la ejecucion del código desde del punto que fue llamado el fork, de manera tal que en el 2° 
 * llamado al Fork() lo realiza el hijo(12) y el proceso padre (11) creando asi 2 procesos más. Tenemos ahora los 
 * procesos 11-12-13-14.
 * Esto se repite en la siguiente llamada a fork() quedando la siguiente jerarquía de procesos.
 *
 * 11						//proceso principal
 * |-------------+
 * |		12				//fork()
 * |		 |
 * |-----+   	 |------+
 * |     13    	 |     14			//fork()
 * |  	  |	 |      |
 * |---+  |---+  |---+  |---+
 * |  15  |  16	 |  17  |  18			//fork()
 * |   |  |   |  |   |  |   |
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
