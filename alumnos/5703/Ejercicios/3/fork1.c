/**
 * Indique y justifique la cantidad de procesos creados en el siguiente programa. 
 *
 * ¿Cómo sería la jerarquía de los procesos creados?
 */

#include <stdio.h>
#include <unistd.h>

int main(void){
    fork(); //crea p2 hijo de p1
    fork(); //crea p3 hijo de p1, p4 hijo de p2
    fork(); //crea p5 hijo de p1, p6 hijo de p2, p7 hijo de p3, p8 hijo de p4
    
    printf(" [x] proceso nro %d y nro %d \n", getpid(), getppid());
    
    sleep(1);

    return 0;
}

/*
Se crean 8 procesos con la jerarquía graficada a continuación:
	main
		|_p1
			|_p2
			|	|_p4
			|	|	|_p8
			|	|	
			|	|_p6
			|
			|_p3
			|	|_p7
			|
			|_p5
*/
