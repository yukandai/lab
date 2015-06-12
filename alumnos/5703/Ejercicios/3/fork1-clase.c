/**
 * Crear un proceso que tenga un hijo y el hijo tenga 3 hijos 
 */

#include <stdio.h>
#include <unistd.h>

int main(void){
	int i,j,k;
	
	i = fork();

	if(i==0){
		j=fork();
		if(j!=0){
			k=fork();
			if(k!=0){
				fork();
			}
		}				
	
	}
	
    printf(" hijo= %d - padre= %d \n", getpid(), getppid());
    
    sleep(1);

    return 0;
}

/*
main
	|_p1
		|_p2
			|_p3
			|_p4
			|_p5
*/