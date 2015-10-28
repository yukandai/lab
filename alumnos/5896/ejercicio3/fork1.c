/**
 * Indique y justifique la cantidad  de procesos creados en el siguiente programa. 
 *Los procesos creados son 8, ya que al ejecutarse el primer fork, el proceso padre crea otro proceso en paralelo denominado hijo1, luego al llegar al segundo fork el proceso padre crea otro proceso hijo denominado hijo2 y el proceso hijo1 crea otro denominado hijo3,al llegar al 3er fork el proceso padre crea hijo4,el proceso hijo2 crea al proceso hijo5, el proceso hijo1 al proceso hijo6, el proceso hijo3 al proceso hijo7, por lo tanto contamos de 8  procesos, padre, hijo1, hijo2, hijo3, hijo4, hijo5, hijo6, hijo7.  
 * ¿Cómo sería la jerarquía de los procesos creados?
 * padre	           					//proceso principal
 * |-------------------+
 * |                  hijo1					//fork()
 * |                   |
 * |---------+         |------+
 * |        hijo2      |      hijo3	  			//fork()
 * |          |        |        |
 * |------+   |---+    |---+    |---+
 * |   hijo4  |  hijo5 |  hijo6 |  hijo7			//fork()
 * |      |   |   |    |   |    |    | 

 */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    fork();
    fork();
    fork();
    
    printf(" [x] proceso HIJO nro %d y PADRE nro %d \n", getpid(), getppid());
    
    sleep(1);

    return 0;
}
