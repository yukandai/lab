/* @anaquinpm
 * Pablo Anaquín 	10/05/2015
 * 
 * Explique el estado de los procesos hijos de este código.
 * 
 * Los procesos hijos terminan antes que el padre, de tal manera que el kernel le da la posibilidad 
 * de saber como terminan sus hijos convirtiendolos en Zombies.
 * De los procesos zombies solo queda una entrada en una tabla del proceso kernel la cual retiene la 
 * información que devuelven,id del hijo, junto con otra información de uso de recursos.
 * Los recursos usados por los hijos son en mayoria devueltos al sistema para ser usados por otros procesos.
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

