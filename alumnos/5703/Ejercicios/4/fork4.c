/**
 * Explique por que cambia el proceso padre del hijo.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *const argv[]){
	//p1 y el padre
    printf ("pid proceso %d, y el padre (bash) %d\n", getpid(), getppid());
	    
    if (fork() == 0) {
    	//p2 hijo de p1
        printf ("pid proceso hijo %d, y el padre %d\n", getpid(), getppid());
        sleep(2); //mientras espero termina el proceso padre:p1
        //como ya termino el proceso padre, p2 queda huerfano y toma otro padre 
        printf ("pid proceso hijo %d, y el padre %d ???\n", getpid(), getppid());
        //termina el proceso hijo:p2
        return 0;
    }

    sleep(1);
    //termina el proceso padre:p1
    return 0;
}

/*
	El proceso p2 cambia de padre ya que el padre de p2 termina antes de que 
	p2 termine su ejecución y este queda huerfano u Orphan y es tomado por el 
	proceso init.
*/
